#include "TitleScreen.hpp"
#include "SceneManager.hpp"
#include "Filepaths.h"
#include "Settings.h"
#include "Colors.h"

TitleScreen::TitleScreen() : Scene()
{

}

TitleScreen::~TitleScreen()
{
	//m_helper->
}

void TitleScreen::Start(SDL_Helper * helper)
{
	m_changeScene = false;
	m_helper = helper;
	m_helper->SDL_LoadImage(&m_background, IMG_BG_TITLE);
	m_helper->SDL_LoadImage(&m_logo, IMG_LOGO);
}

void TitleScreen::Draw()
{
	m_helper->SDL_DrawImage(m_background, 0, 0);
	m_helper->SDL_DrawImage(m_logo, 250, 70);
	this->m_helper->SDL_DrawText(600, 680, VERSION_TEXT_SIZE, BLACK, "Manurocker95 (C) 2018");
}

void TitleScreen::Update()
{
	if (m_changeScene)
		NextScene();
}

void TitleScreen::CheckInputs(u64 kDown)
{
	if (kDown & KEY_A)
		m_changeScene = true; // We do it this wait so Update is called
}

// * We go to the next scene = GameScreen
void TitleScreen::NextScene()
{
	SceneManager::Instance()->setActualScene(SceneManager::GAME);
	delete(this);
}

