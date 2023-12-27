#pragma once
#include <chrono>
#include "Scene.h"
#include "SimpleGameTypes.h"
#include "AchievementDefinition.h"
#include "AchievementSystem.h"

class AchievementPopup;

namespace Data
{
    class DataContainer;
}

namespace Interaction
{
    class Tap;
}

namespace Game
{
    class GameLoop 
    {
      public:
        void ReceiveData(Data::DataContainer& data);
        void Run(); // Starts the game loop
        void OnTap(const Interaction::Tap& tap); // Called when a tapping event happens
        void OnScore(const int score, const GameTypes::eGameSide); // Called when one of the sides scores
        void OnMatchResult(const GameTypes::eGameSide); // Called when the game session finishes

        void HandleEvents();
        void Render();
        void Update();
        void UpdateWallet(const Achievement::AchievementDefinition* achv); //Updates total score when achievement succeeds

    private:
        bool mIsRunning = false;   
        bool isGained = false;
        UI::Scene scene;
        SDL_Event mEvent;
        Button::buttonType mButtonType;
        std::vector<AchievementPopup*> mAddedPopups;
        Achievement::AchievementSystem mAchievementSystem;
        ScoreUIManager* mScoreObject = new ScoreUIManager();
        std::chrono::steady_clock::time_point mAchievementBegin;
        Data::PlayerDataHandler* mScoreData = new Data::PlayerDataHandler();
        GameTypes::eCurrencyType convertStringToCurrency(const std::string& pString);
    };
}