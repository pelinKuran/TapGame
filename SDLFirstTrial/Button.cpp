#include "Button.h"

#include "SDL_image.h"
#include "Renderer.h"

Button::Button(int x, int y, int mWidth, int mHeight, std::string pImagePath) : mWidth(mWidth), mHeight(mHeight), sRect{x,y, mWidth ,mHeight}, dRect{x,y, mWidth ,mHeight}
{
	mButtonRenderer = Renderer::GetRendererInstance()->GetRenderer();
	mImageSurface = IMG_Load(pImagePath.c_str());
	mTexture = SDL_CreateTextureFromSurface(mButtonRenderer, mImageSurface);
	mSelected = true;
}

void Button::setDestXY(int x, int y)
{
	dRect.x = x;
	dRect.y = y;
}

bool Button::getState()
{
	return mSelected;
}

void Button::setState(bool state) const
{
	mSelected = state;
}

void Button::changeImage(std::string pImagePath) const
{
	mImageSurface = IMG_Load(pImagePath.c_str());
	mTexture = SDL_CreateTextureFromSurface(mButtonRenderer, mImageSurface);

}

void Button::draw() const
{
	SDL_RenderCopy(mButtonRenderer,mTexture, &sRect, &dRect);

}

void Button::remove() const
{
	SDL_DestroyTexture(mTexture);
}
