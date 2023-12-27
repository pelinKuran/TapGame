#pragma once

#include "DataContainer.h"
#include "AchievementDefinition.h"
#include "SimpleGameTypes.h"
#include "AchievementPopup.h"

namespace Achievement
{
	class AchievementSystem
	{
	public:
		AchievementSystem(){ }
		~AchievementSystem() {}
		bool isAchievementAcquired(const Achievement::AchievementDefinition& ach);
		
		std::vector<const Achievement::AchievementDefinition*> Tapped();
		std::vector<const Achievement::AchievementDefinition*> Scored();
		std::vector<const Achievement::AchievementDefinition*> Won();
		
		void addAchievementDefiniton(const Achievement::AchievementDefinition* pAchievement);
	private:
		std::vector<const Achievement::AchievementDefinition*> mAchievements;
		std::vector<const Achievement::AchievementDefinition*> gatherAchieveds();
		int mTapCounter;
		int mScoreCounter;
		int mWinCounter;
	};
}