#pragma once

#include "UIElement.h"
#include <iostream>
class Button : public UI::UIElement
{
public:
	Button() {};
	~Button() {}
	Button(int x, int y, int mWidth, int mHeight, std::string pImagePath);

	void setDestXY(int x, int y) override;
	//UI element
	bool getState() override;
	void setState(bool state) const override;
	void changeImage(std::string pImagePath) const;
	void draw() const override;
	void remove() const override;
	SDL_Rect sRect, dRect;
	int mWidth;
	int mHeight;
	enum buttonType { None, Score, Win };
	buttonType mType = None;
private:
	mutable bool mSelected = false;
	mutable	SDL_Surface* mImageSurface;
	SDL_Renderer* mButtonRenderer;
	mutable SDL_Texture* mTexture;
};

