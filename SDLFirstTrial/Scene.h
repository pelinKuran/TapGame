#pragma once
#include <vector>
#include <queue>
#include "Button.h"
#include "Tap.h"
#include "AchievementPopup.h"
#include "ScoreUIManager.h"
#include "PlayerDataHandler.h"
namespace Data
{
	class DataContainer;
}

namespace UI
{
	class UIElement;

	class Scene
	{
	public:
		//A UIElement added by Scene::Add() stays on the UI
		// until it is removed via Scene::Remove()
		void Add(const UIElement& elem);
		void Remove(const UIElement& elem);

		bool Init(Data::DataContainer& data);
		void RenderScene();
		void createUIElements(Data::DataContainer& data);
		Button::buttonType sceneOnTap(const Interaction::Tap& tap);
		std::vector<AchievementPopup*> getAchievementPopup();
		AchievementPopup* addAchievementPopup(const Achievement::AchievementDefinition& achv);
	private:
		SDL_Renderer* sceneRenderer;
		SDL_Texture* buttonTex;
		SDL_Rect destRect;
		Button* uiButtonWin;
		Button* uiButtonScore;
		ScoreUIManager* scoreObject;
		std::vector<const UI::UIElement*> uiElements;
		std::vector<AchievementPopup*> achievementPopUps;
	};
}