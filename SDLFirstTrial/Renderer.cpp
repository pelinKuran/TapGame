#include "Renderer.h"
Renderer* Renderer::mRenderer = nullptr;
Renderer* Renderer::GetRendererInstance()
{
	if (mRenderer == nullptr)
		mRenderer = new Renderer();
	return mRenderer;
}

SDL_Renderer* Renderer::GetRenderer()
{
	if (mSdlRenderer == nullptr)
	{
		SDL_Window* window = SDL_CreateWindow("Interview", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_ALWAYS_ON_TOP);


		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			mSdlRenderer = SDL_CreateRenderer(window, -1, NULL);
			if (mRenderer)
			{
				SDL_SetRenderDrawColor(mSdlRenderer, 10, 10, 10, 0);
			}
		}

	}
	return mSdlRenderer;
}

void Renderer::RenderScene()
{
	SDL_RenderClear(mSdlRenderer);
	SDL_RenderPresent(mSdlRenderer);
}
Renderer::Renderer() {}
Renderer::~Renderer()
{
}

