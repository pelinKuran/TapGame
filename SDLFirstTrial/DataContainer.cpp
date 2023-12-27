#include "DataContainer.h"

#include "AchievementDefinition.h"

namespace Data
{
	std::vector<const Achievement::AchievementDefinition*>& DataContainer::GetAchievementDefinitions()
	{
		return achievementDefs;
	}
	void DataContainer::SetAchievementDefinitions(std::vector<Achievement::AchievementDefinition*>& achvObj)
	{
		for (auto it : achvObj)
		{
			achievementDefs.push_back(it);
		}
	}
}