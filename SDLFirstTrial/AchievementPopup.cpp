#include "AchievementPopup.h"
#include "Renderer.h"
#include "AchievementDefinition.h"

AchievementPopup::AchievementPopup(const Achievement::AchievementDefinition* obj)
{
	imagePath = obj->ImagePath;
	title = obj->Title;
	text = obj->Text;
	rewardTypes = obj->RewardTypes;
	rewardAmount = obj->RewardAmount;
	isAchieved = obj->isGained;
	mPopupRenderer = Renderer::GetRendererInstance()->GetRenderer();
	prepareItems();
}

void AchievementPopup::draw() const
{
	SDL_RenderCopy(mPopupRenderer, imageTexture, NULL, &dRectImage);
	SDL_RenderCopy(mPopupRenderer, textTexture, NULL, &dRectText);
	SDL_RenderCopy(mPopupRenderer, titleTexture, NULL, &drectTitle);
}

void AchievementPopup::remove() const
{
	SDL_DestroyTexture(imageTexture);
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(titleTexture);
}

bool AchievementPopup::getState()
{
	return isAchieved;
}

void AchievementPopup::setState(bool state) const
{
	isAchieved = state;
}

void AchievementPopup::setDestXY(int x, int y)
{

}

void AchievementPopup::prepareItems()
{
	// Create image
	SDL_Surface* t = IMG_Load(imagePath.c_str());
	imageTexture = SDL_CreateTextureFromSurface(mPopupRenderer, t);
	dRectImage.x = 250;
	dRectImage.y = 150;
	dRectImage.w = 100;
	dRectImage.h = 100;

	// Create text
	int textW = 0;
	int textH = 0;
	TTF_Font* tFont_20 = TTF_OpenFont("Resources/JOKERMAN.TTF", 20);
	SDL_Color textColor = { 255,255,255,0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(tFont_20, text.c_str(), textColor);
	textTexture = SDL_CreateTextureFromSurface(mPopupRenderer, textSurface);
	SDL_FreeSurface(textSurface);
	SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
	dRectText.x = 250;
	dRectText.y = 250;
	dRectText.w = textW;
	dRectText.h = textH;

	// Create title
	TTF_Font* tFont_25 = TTF_OpenFont("Resources/JOKERMAN.TTF", 25);
	SDL_Surface* textSurface_ = TTF_RenderText_Solid(tFont_25, title.c_str(), textColor);
	titleTexture = SDL_CreateTextureFromSurface(mPopupRenderer, textSurface_);
	SDL_FreeSurface(textSurface_);
	SDL_QueryTexture(titleTexture, NULL, NULL, &textW, &textH);
	drectTitle.x = 250;
	drectTitle.y = 100;
	drectTitle.w = textW;
	drectTitle.h = textH;
	TTF_CloseFont(tFont_20);
	TTF_CloseFont(tFont_25);

}
