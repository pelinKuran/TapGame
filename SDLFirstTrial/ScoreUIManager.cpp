#include "ScoreUIManager.h"
#include <string>

ScoreUIManager::ScoreUIManager()
{
	render = Renderer::GetRendererInstance()->GetRenderer();
#pragma region IMG
	SDL_Surface* tGold = IMG_Load("Resources/gold.png");
	imageTextureGold = SDL_CreateTextureFromSurface(render, tGold);
	dRectImageGold.x = 250;
	dRectImageGold.y = 35;
	dRectImageGold.w = 25;
	dRectImageGold.h = 25;

	SDL_Surface* tDiamond = IMG_Load("Resources/diamond.png");
	imageTextureDiamond = SDL_CreateTextureFromSurface(render, tDiamond);
	dRectImageDiamond.x = dRectImageGold.x +100 + dRectTextGold.w;
	dRectImageDiamond.y = 35;
	dRectImageDiamond.w = 25;
	dRectImageDiamond.h = 25;
	//create text
#pragma endregion IMG
#pragma region FONT

	font = TTF_OpenFont("Resources/JOKERMAN.TTF", 25);
	auto text = "Total: ";
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
	textTexture = SDL_CreateTextureFromSurface(render, textSurface);
	SDL_FreeSurface(textSurface);
	SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
	drectTitle.x = 150;
	drectTitle.y = 30;
	drectTitle.w = textW;
	drectTitle.h = textH;
#pragma endregion FONT
#pragma region TITLE

	//create title
	textScoreGold = TTF_RenderText_Solid(font, "0", textColor);
	scoreTextureGold = SDL_CreateTextureFromSurface(render, textScoreGold);
	SDL_FreeSurface(textScoreGold);
	SDL_QueryTexture(scoreTextureGold, NULL, NULL, &textW, &textH);
	dRectTextGold.x = dRectImageGold.x + 50;
	dRectTextGold.y = 30;
	dRectTextGold.w = textW;
	dRectTextGold.h = textH;

	textScoreDiamond = TTF_RenderText_Solid(font, "0", textColor);
	scoreTextureDiamond = SDL_CreateTextureFromSurface(render, textScoreDiamond);
	SDL_FreeSurface(textScoreDiamond);
	SDL_QueryTexture(scoreTextureDiamond, NULL, NULL, &textW, &textH);
	dRectTextDiamond.x = dRectImageDiamond.x + 50;
	dRectTextDiamond.y = 30;
	dRectTextDiamond.w = textW;
	dRectTextDiamond.h = textH;
#pragma endregion TITLE

}
ScoreUIManager::~ScoreUIManager()
{
	TTF_CloseFont(font);

}
void ScoreUIManager::draw() const
{
	SDL_RenderCopy(render, imageTextureGold, NULL, &dRectImageGold);
	SDL_RenderCopy(render, imageTextureDiamond, NULL, &dRectImageDiamond);
	SDL_RenderCopy(render, textTexture, NULL, &drectTitle);
	SDL_RenderCopy(render, scoreTextureGold, NULL, &dRectTextGold);
	SDL_RenderCopy(render, scoreTextureDiamond, NULL, &dRectTextDiamond);
}

void ScoreUIManager::remove() const
{
	SDL_DestroyTexture(imageTextureGold);
	SDL_DestroyTexture(imageTextureDiamond);
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(scoreTextureGold);
	SDL_DestroyTexture(scoreTextureDiamond);
}

void ScoreUIManager::prepareItems()
{

}
void ScoreUIManager::setDestXY(int x, int y)
{
	
}

void ScoreUIManager::setState(bool state) const
{
}

bool ScoreUIManager::getState()
{
	return false;
}

void ScoreUIManager::updateScore(Data::PlayerDataHandler& pScore)
{
	auto tGoldAmount = pScore.getCurrency(GameTypes::eCurrencyType::GOLD);
	auto tDiamondAmount = pScore.getCurrency(GameTypes::eCurrencyType::DIAMOND);
	// Remove old textures to prevent memory leak 
	SDL_DestroyTexture(scoreTextureGold);
	SDL_DestroyTexture(scoreTextureDiamond);

	// Update gold score
	textScoreGold = TTF_RenderText_Solid(font, std::to_string(tGoldAmount).c_str(), textColor);
	scoreTextureGold = SDL_CreateTextureFromSurface(render, textScoreGold);
	SDL_FreeSurface(textScoreGold);
	SDL_QueryTexture(scoreTextureGold, NULL, NULL, &textW, &textH);
	dRectTextGold.x = dRectImageGold.x + 50;
	dRectTextGold.w = textW;
	dRectTextGold.h = textH;
	// Shift diamond ui 
	dRectImageDiamond.x = dRectImageGold.x + 100 + dRectTextGold.w;

	// Update diamond score
	textScoreDiamond = TTF_RenderText_Solid(font, std::to_string(tDiamondAmount).c_str(), textColor);
	scoreTextureDiamond = SDL_CreateTextureFromSurface(render, textScoreDiamond);
	SDL_FreeSurface(textScoreDiamond);
	SDL_QueryTexture(scoreTextureDiamond, NULL, NULL, &textW, &textH);
	dRectTextDiamond.x = dRectImageDiamond.x + 40;
	dRectTextDiamond.w = textW;
	dRectTextDiamond.h = textH;
	
}


