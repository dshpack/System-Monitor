/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISDLDisplay.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:56:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 09:55:25 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISDLDisplay.hpp"
#include "Defines.hpp"

ISDLDisplay::ISDLDisplay()
{
	running = true;
	window = NULL;
	screen = NULL;
	bg = NULL;
}

ISDLDisplay::~ISDLDisplay()
{
}

void ISDLDisplay::onLoop() {}

int		ISDLDisplay::onExecute()
{
	if (!onInit())
		return -1;
	SDL_Event e;
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			onEvent(&e);
		}
		onRender();
		onLoop();
	}
	onQuit();
	return 0;
}

bool	ISDLDisplay::onInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	if (TTF_Init() == -1)
		return false;
	window = SDL_CreateWindow(WIN_CAPTION, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
		return false;
	screen = SDL_GetWindowSurface(window);
	if (!screen)
		return false;
	SDL_SetSurfaceRLE(screen, 1);
	char c[] = {"/images/NewProject.bmp"};
	bg = Surface::loadSurface(c, screen);
	char c2[] = {"/images/8.bmp"};
	img = Surface::loadSurface(c2, screen);
	if (!bg)
		return false;
	font1 = TTF_OpenFont("/fonts/CollegiateBlackFLF.ttf", 20);
	if (!font1)
		return false;
	font2 = TTF_OpenFont("/fonts/Roboto-Black.ttf", 20);
	if (!font2)
		return false;
	return true;
}

void	ISDLDisplay::onEvent(SDL_Event *e)
{
	switch (e->type)
	{
		case SDL_QUIT: onExit();
			break;
		case SDL_KEYDOWN:
			onKeyDown(e->key.keysym.sym);
			break;
		case SDL_KEYUP:
			onKeyDown(e->key.keysym.sym);
			break;

		default:
			break;
	}
}

void	ISDLDisplay::onKeyDown(SDL_Keycode sym)
{
	switch (sym)
	{
		case SDLK_ESCAPE: onExit();
			break;
	}
}

void	ISDLDisplay::onExit()
{
	running = false;
}

void	ISDLDisplay::draw() {

	HostnameUsernameMod host("Host name User name Module:");
	CPUMod				cpu("CPU Module:");
	DateTimeMod			dtm("Date and Time Module:");
	OSInfosMod			os("OS info Module:");
	RAMMod				ram("RAM Module:");
	NetworkMod			net("Network Module:");

	host.updateData();
	cpu.updateData();
	ram.updateData();
	dtm.updateData();
	net.updateData();
	os.updateData();

	Surface::drawTextSurface(font1, screen, cpu.getModulName().c_str(), 10, 20, 0, 255, 0);
	for (size_t i = 0; i < cpu.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, cpu.getModulData()[i].c_str(), 10, 20 + (i+1) *20, 0, 255, 0);

//cpu module
	Surface::drawTextSurface(font1, screen, cpu.getModulName().c_str(), 10, 20, 0, 255, 0);
	for (size_t i = 0; i < cpu.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, cpu.getModulData()[i].c_str(), 10, 20 + (i+1) *20, 0, 255, 0);

//	std::string text1 = "RAM Module:";
	Surface::drawTextSurface(font1, screen, ram.getModulName().c_str(), 950, 20, 0, 255, 0);
	for (size_t i = 0; i < ram.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, ram.getModulData()[i].c_str(), 950, 20+ (i+1) *20, 0, 255, 0);

//	std::string text2 = "Date and Time Module:";
	Surface::drawTextSurface(font1, screen, dtm.getModulName().c_str(), 10, 200, 0, 255, 0);
	for (size_t i = 0; i < dtm.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, dtm.getModulData()[i].c_str(), 10, 200 + (i+1) *20, 0, 255, 0);

//	std::string text3 = "Network Module:";
	Surface::drawTextSurface(font1, screen, net.getModulName().c_str(), 950, 200, 0, 255, 0);
	for (size_t i = 0; i < net.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, net.getModulData()[i].c_str(), 950, 200+ (i+1) *20, 0, 255, 0);

//	std::string text4 = "OS info Module:";
	Surface::drawTextSurface(font1, screen, os.getModulName().c_str(), 10, 500, 0, 255, 0);
	for (size_t i = 0; i < dtm.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, os.getModulData()[i].c_str(), 10, 500+(i+1) *20, 0, 255, 0);

	//Host name User name Module
	Surface::drawTextSurface(font1, screen, host.getModulName().c_str(), 950, 500, 0, 255, 0);
	for (size_t i = 0; i < host.getModulData().size(); i++ )
		Surface::drawTextSurface(font1, screen, host.getModulData()[i].c_str(), 950, 500 + (i+1) *20, 0, 255, 0);

	std::string text8 = "Yes, it`s a zaz's favorite animal";
	Surface::drawTextSurface(font2, screen, text8.c_str(), 500, 210, 0, 255, 0);
}

void	ISDLDisplay::onRender()
{
	Surface::drawSurface(bg, screen, 0, 0);

	draw();
	Uint32 ticks = SDL_GetTicks();
	Uint32 seconds = ticks / 1000;
	Uint32 sprite = seconds % 4;

	SDL_Rect rect = {0, sprite * 229, 164, 80};
	Surface::drawSurface(img, screen, &rect, 550, 295);
	SDL_UpdateWindowSurface(window);
}



void	ISDLDisplay::onQuit()
{
	TTF_CloseFont(font1);
	font1 = NULL;

	SDL_FreeSurface(screen);
	screen = NULL;

	SDL_FreeSurface(bg);
	bg = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	TTF_Quit();
	SDL_Quit();
}