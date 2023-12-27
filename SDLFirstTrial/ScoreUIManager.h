#pragma once
#include <iostream>
#include "UIElement.h"
#include "Renderer.h"
#include "Tap.h"
#include "PlayerDataHandler.h"
class ScoreUIManager : public UI::UIElement
{
public:
	ScoreUIManager();
	~ScoreUIManager();
	void draw() const override;
	void remove() const override;
	void setDestXY(int x, int y) override;
	void setState(bool state) const override;
	bool getState() override;
	void updateScore(Data::PlayerDataHandler& pScore);
	void prepareItems();
	
private:
	int score;
	int textW = 0;
	int textH = 0;
	TTF_Font* font;
	SDL_Renderer* render;
	SDL_Texture* imageTextureDiamond;
	SDL_Texture* imageTextureGold;
	SDL_Texture* textTexture;
	SDL_Texture* scoreTextureGold;
	SDL_Texture* scoreTextureDiamond;
	SDL_Surface* textScoreGold;
	SDL_Surface* textScoreDiamond;
	SDL_Color textColor = { 255,255,255,0 };
	SDL_Rect sRect, dRectImageGold, dRectImageDiamond, dRectTextGold, dRectTextDiamond, drectTitle;

};

