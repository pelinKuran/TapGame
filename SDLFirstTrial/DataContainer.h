#pragma once
#include <vector>

namespace Achievement
{
	class AchievementDefinition;
}

namespace Data
{
	// A dedicated data-container class holding all the required game data
	class DataContainer
	{
	public:
		std::vector<const Achievement::AchievementDefinition*>& GetAchievementDefinitions();
		void SetAchievementDefinitions(std::vector<Achievement::AchievementDefinition*>& achvObj);

	private:
		std::vector<const Achievement::AchievementDefinition*> achievementDefs;
	};

}