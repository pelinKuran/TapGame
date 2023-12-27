#define SDL_MAIN_HANDLED
#include "GameLoop.h"
#include "DataContainer.h"
#include "AchievementDefinition.h"

int main()
{
    if (TTF_Init() < 0) {
        std::cerr << "Error intializing SDL_ttf: " << TTF_GetError() << std::endl;
    }
    Game::GameLoop gameLoop;
    Data::DataContainer theWholeData;
    Achievement::AchievementDefinition* theFirstAchievement = new Achievement::AchievementDefinition();
    Achievement::AchievementDefinition* theHundredTapAchievement = new Achievement::AchievementDefinition();
    Achievement::AchievementDefinition* theFirstScoreAchievement = new Achievement::AchievementDefinition();
    Achievement::AchievementDefinition* theFirstWinAchievement = new Achievement::AchievementDefinition();

    theFirstAchievement->ImagePath = "Resources/firstAchievement.png";
    theFirstAchievement->Text = "5 GOLD!";
    theFirstAchievement->Title = "FIRST TAB!";
    theFirstAchievement->RewardAmount.push_back("5");
    theFirstAchievement->RewardTypes.push_back("GOLD");
    theFirstAchievement->isGained = false;
    theFirstAchievement->TapRequirement = 1;

    theHundredTapAchievement->ImagePath = "Resources/seconAchievement.png";
    theHundredTapAchievement->Text = "500 GOLD!";
    theHundredTapAchievement->Title = "100 CLICK!";
    theHundredTapAchievement->RewardAmount.push_back("500");
    theHundredTapAchievement->RewardTypes.push_back("GOLD");
    theHundredTapAchievement->isGained = false;
    theHundredTapAchievement->TapRequirement = 100;

    theFirstScoreAchievement->ImagePath = "Resources/thirdAchievemnt.png";
    theFirstScoreAchievement->Text = "500 GOLD + 5 DIAMOND!";
    theFirstScoreAchievement->Title = "FIRST SCORE!";
    theFirstScoreAchievement->RewardAmount.push_back("500");
    theFirstScoreAchievement->RewardAmount.push_back("5");
    theFirstScoreAchievement->RewardTypes.push_back("GOLD");
    theFirstScoreAchievement->RewardTypes.push_back("DIAMOND");
    theFirstScoreAchievement->isGained = false;
    theFirstScoreAchievement->ScoreRequirement = 1;

    theFirstWinAchievement->ImagePath = "Resources/fourthAchievement.png";
    theFirstWinAchievement->Text = "15 DIAMONDS!";
    theFirstWinAchievement->Title = "THE WIN!";
    theFirstWinAchievement->RewardAmount.push_back("15");
    theFirstWinAchievement->RewardTypes.push_back("DIAMOND");
    theFirstWinAchievement->isGained = false;
    theFirstWinAchievement->WinRequirement = 1;

    std::vector<Achievement::AchievementDefinition*> achvs;
    achvs.push_back(theFirstAchievement);
    achvs.push_back(theHundredTapAchievement);
    achvs.push_back(theFirstScoreAchievement);
    achvs.push_back(theFirstWinAchievement);

    theWholeData.SetAchievementDefinitions(achvs);
    gameLoop.ReceiveData(theWholeData);
    gameLoop.Run();
   
   
    return 0;
}
