#pragma once
#include <string>
#include <vector>
#include <optional>
namespace Achievement
{
    // A data class holding the definition of an achievement.
    class AchievementDefinition
    {
     public:
         std::optional<int> TapRequirement;
         std::optional<int> ScoreRequirement;
         std::optional<int> WinRequirement;

        std::string ImagePath = "";
        std::string Title = "";
        std::string Text = "";
        // RewardTypes and RewardAmounts map one to one, which means
        // RewardTypes[0] has its reward amount at RewardAmount[0],
        // RewardTypes[1] has its reward amount at RewardAmount[1],
        // and so on.
        //why not pair? map?

        std::vector<std::string> RewardTypes;
        std::vector<std::string> RewardAmount;
        mutable bool isGained = false;
    };
}