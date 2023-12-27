#pragma once
#include <iostream>
#include <vector>
#include "UIElement.h"
namespace Achievement {
	class AchievementDefinition;
}
class AchievementPopup : public UI::UIElement
{
public:
	AchievementPopup() = default;
	AchievementPopup(const Achievement::AchievementDefinition* obj);
	void draw() const override;
	void remove() const override;
	bool getState() override;
	void setState(bool state) const override;
	void setDestXY(int x, int y) override;
	void prepareItems();
public:
	std::string imagePath = "";
	std::string title = "";
	std::string text = "";
	std::vector<std::string> rewardTypes;
	std::vector<std::string> rewardAmount;
private:

	SDL_Renderer* mPopupRenderer;
	SDL_Texture* imageTexture;
	SDL_Texture* textTexture;
	SDL_Texture* titleTexture;
	SDL_Rect sRect, dRectImage, dRectText, drectTitle;
	mutable bool isAchieved = false;

};

