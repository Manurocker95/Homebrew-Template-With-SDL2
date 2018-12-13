#include "GameScreen.hpp"
#include "SceneManager.hpp"
#include "Colors.h"
#include "Filepaths.h"
#include "Settings.h"

GameScreen::GameScreen() : Scene()
{

}

GameScreen::~GameScreen()
{

}

void GameScreen::Start(SDL_Helper * helper)
{
	m_changeScene = false;
	m_helper = helper;
	m_helper->SDL_LoadImage(&m_background, IMG_BG_GAME);
}

void GameScreen::Draw()
{
	m_helper->SDL_DrawImage(m_background, 0, 0);

}

void GameScreen::Update()
{
	if (m_changeScene)
		NextScene();
}

void GameScreen::CheckInputs(u64 kDown)
{
	if (kDown & KEY_B)
		m_changeScene = true;
}

// * We go to the next scene = GameScreen
void GameScreen::NextScene()
{
	SceneManager::Instance()->setActualScene(SceneManager::TITLE);
	delete(this);
}
