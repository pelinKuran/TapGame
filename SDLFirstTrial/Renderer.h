#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <SDL_ttf.h>

class Renderer
{
public:
	static Renderer* GetRendererInstance();
	SDL_Renderer* GetRenderer();
	void RenderScene();
	~Renderer();
private:
	SDL_Renderer* mSdlRenderer = nullptr;
	static Renderer* mRenderer;
	Renderer();

};
