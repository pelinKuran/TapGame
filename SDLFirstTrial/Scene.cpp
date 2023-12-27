#include <iostream>
#include "Scene.h"
#include "Renderer.h"
#include "Tap.h"
#include "DataContainer.h"
#include "AchievementDefinition.h"
#include "AchievementPopup.h"
bool UI::Scene::Init(Data::DataContainer& data)
{
	//get renderer
	auto instance = Renderer::GetRendererInstance();
	sceneRenderer = instance->GetRenderer();
	if (sceneRenderer)
	{
		createUIElements(data);
		return true;
	}
	return false;

}
void UI::Scene::Add(const UIElement& elem)
{
	uiElements.push_back(&elem);
}

void UI::Scene::Remove(const UIElement& elem)
{
	auto it = std::find(uiElements.cbegin(), uiElements.cend(), &elem);
	if (it != uiElements.cend())
	{
		uiElements.erase(it);
	}
}

void UI::Scene::RenderScene()
{
	SDL_RenderClear(sceneRenderer);
	for (auto elem : uiElements)
	{
		elem->draw();
	}
	SDL_RenderPresent(sceneRenderer);
}

Button::buttonType UI::Scene::sceneOnTap(const Interaction::Tap& tap)
{
	for (auto uiElem : uiElements)
	{
		auto button = dynamic_cast<const Button*>(uiElem);
		if (button != nullptr)
		{
			if (tap.getPositionX() < (button->dRect.x + button->mWidth)
				&& tap.getPositionX() > button->dRect.x && tap.getPositionY() > button->dRect.y
				&& tap.getPositionY() < (button->dRect.y + button->mHeight))
			{
				if (button->mType == Button::buttonType::Score)
				{
					button->changeImage("Resources/button_scored.png");
					return Button::buttonType::Score;
				}

				else if (button->mType == Button::buttonType::Win)
				{
					button->changeImage("Resources/button_won.png");
					return Button::buttonType::Win;
				}
			}
		}
	}
	return Button::buttonType::None;
}

void UI::Scene::createUIElements(Data::DataContainer& data)
{
	// Generic ui elements
	uiButtonWin = new Button(0, 0, 150, 50, "Resources/button_win.png");
	uiButtonWin->setDestXY(50, 170);
	uiButtonWin->mType = Button::buttonType::Win;
	uiButtonScore = new Button(0, 0, 150, 50, "Resources/button_score.png");
	uiButtonScore->setDestXY(400, 170);
	uiButtonScore->mType = Button::buttonType::Score;
	Add(*uiButtonWin);
	Add(*uiButtonScore);

}

AchievementPopup* UI::Scene::addAchievementPopup(const Achievement::AchievementDefinition& achv)
{
	AchievementPopup* tobj = new AchievementPopup(&achv);
	achievementPopUps.push_back(tobj);
	Add(*tobj);
	return tobj;
}

std::vector<AchievementPopup*> UI::Scene::getAchievementPopup()
{
	return achievementPopUps;
}


