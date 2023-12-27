
#include <iostream>
#include <thread>
#include "Tap.h"
#include "GameLoop.h"
#include "Utilities.h"
#include "DataContainer.h"
#include "AchievementPopup.h"
namespace Game
{
	using clock = std::chrono::steady_clock;
	void GameLoop::ReceiveData(Data::DataContainer& data)
	{
		// Triggers some related code to get and set the game data
		// Initiliaze the game scene
		mIsRunning = scene.Init(data);	
		scene.Add(*mScoreObject);
		// Initialize achievement system
		for (auto achievement : data.GetAchievementDefinitions())
		{
			mAchievementSystem.addAchievementDefiniton(achievement);
		}
	}

	void GameLoop::Run()
	{
		constexpr int FPS{ 30 };
		constexpr auto FrameTime = std::chrono::milliseconds(1000 / FPS);
		while (mIsRunning)
		{
			auto begin = clock::now();
			HandleEvents();	
			Update();
			Render();
			auto end = clock::now();
			auto duration_took = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
			if (duration_took < FrameTime)
			{
				std::this_thread::sleep_for(FrameTime - duration_took);
			}
		}
	}

	void GameLoop::OnTap(const Interaction::Tap& tap)
	{
		// Check if tab is a ui button or not
		mButtonType = scene.sceneOnTap(Interaction::Tap(mEvent.button.x, mEvent.button.y, mEvent.button.button));
		if (mButtonType == Button::buttonType::None) 
		{
			for (auto& achv : mAchievementSystem.Tapped())
			{
				mAchievementBegin = clock::now();
				mAddedPopups.push_back(scene.addAchievementPopup(*achv));
				UpdateWallet(achv);

			}
		}
	}

	void GameLoop::OnScore(const int score, const GameTypes::eGameSide)
	{
		for (auto& achv : mAchievementSystem.Scored())
		{
			mAchievementBegin = clock::now();
			mAddedPopups.push_back(scene.addAchievementPopup(*achv));
			UpdateWallet(achv);
		}

	}

	void GameLoop::OnMatchResult(const GameTypes::eGameSide)
	{
		for (auto& achv : mAchievementSystem.Won())
		{
			mAchievementBegin = clock::now();
			mAddedPopups.push_back(scene.addAchievementPopup(*achv));
			UpdateWallet(achv);
		}
	}

	void GameLoop::HandleEvents()
	{
		while (SDL_PollEvent(&mEvent))
		{
			switch (mEvent.type)
			{
				case SDL_MOUSEBUTTONUP:
					OnTap(Interaction::Tap(mEvent.button.x, mEvent.button.y, mEvent.button.button));
					break;	
				case SDL_WINDOWEVENT:
					switch (mEvent.window.event)
					{
					case SDL_WINDOWEVENT_CLOSE:
					case SDL_QUIT:
						mIsRunning = false;
						break;
					default:
						break;
					}
					break;
				default:
					break;
			}
		}
	}

	void GameLoop::Update()
	{
		constexpr auto achvTimeOut = std::chrono::seconds(5);		
		auto achvEnd = clock::now();

		switch (mButtonType)
		{
		case Button::buttonType::Score:
			OnScore(0,GameTypes::eGameSide::PLAYER);
			break;
		case Button::buttonType::Win:
			OnMatchResult(GameTypes::eGameSide::PLAYER);
			break;
		default:
			break;
		}
		mButtonType = Button::buttonType::None;
	
		mScoreObject->updateScore(*mScoreData);

		if (((achvEnd - mAchievementBegin) > achvTimeOut) )
		{	
			auto it = mAddedPopups.begin();
			while (it != mAddedPopups.end())
			{
				auto pop = *it;				
				scene.Remove(*pop);
				it = mAddedPopups.erase(it);	
				if(it != mAddedPopups.end())
					it++;
				
			}
		}
	}

	void GameLoop::Render()
	{	
		scene.RenderScene();		
	}

	void GameLoop::UpdateWallet(const Achievement::AchievementDefinition* achv)
	{
		for (int i = 0; i < achv->RewardAmount.size(); i++)
		{
			mScoreData->addCurrency(std::stoi(achv->RewardAmount.at(i)), Utilities::convertStringToCurrency(achv->RewardTypes.at(i)));
		}		
	}


}