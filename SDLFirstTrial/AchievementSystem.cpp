#include "AchievementSystem.h"

bool Achievement::AchievementSystem::isAchievementAcquired(const Achievement::AchievementDefinition& ach)
{
    bool isAchieved = false;
    if (!ach.isGained)
    {
        isAchieved = true; 
        if (ach.TapRequirement.has_value())
        {
            isAchieved &= ach.TapRequirement.value() == mTapCounter;
        }
        if (ach.ScoreRequirement.has_value())
        {
            isAchieved &= ach.ScoreRequirement.value() == mScoreCounter;

        }
        if (ach.WinRequirement.has_value())
        {
            isAchieved &= ach.WinRequirement.value() == mWinCounter;
        }
    }
    return isAchieved;
}

std::vector<const Achievement::AchievementDefinition*> Achievement::AchievementSystem::Tapped()
{
    mTapCounter++;
    
    return gatherAchieveds();
}

std::vector<const Achievement::AchievementDefinition*> Achievement::AchievementSystem::Scored()
{

    mScoreCounter++;
    return gatherAchieveds();

}

std::vector<const Achievement::AchievementDefinition*> Achievement::AchievementSystem::Won()
{

    mWinCounter++;
    return gatherAchieveds();

}

void Achievement::AchievementSystem::addAchievementDefiniton(const Achievement::AchievementDefinition* pAchievements)
{
    mAchievements.push_back(pAchievements);
}

std::vector<const Achievement::AchievementDefinition*> Achievement::AchievementSystem::gatherAchieveds()
{
    std::vector<const Achievement::AchievementDefinition*> result = {};
    for (auto& ach : mAchievements)
    {
        if (!ach->isGained && isAchievementAcquired(*ach))
        {
            ach->isGained = true;
            result.push_back(ach);
        }
    }
    return result;
}

