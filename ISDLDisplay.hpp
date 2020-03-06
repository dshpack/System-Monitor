/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISDLDisplay.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:56:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 10:17:47 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ISDLDISPLAY_HPP
#define ISDLDISPLAY_HPP

#include <SDL2/SDL.h>
#include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <string>
#include "Surface.hpp"
#include "IMonitorDisplay.hpp"

#include "modules/HostnameUsernameMod.hpp"
#include "modules/CPUMod.hpp"
#include "modules/DateTimeMod.hpp"
#include "modules/OSInfosMod.hpp"
#include "modules/RAMMod.hpp"
#include "modules/NetworkMod.hpp"

class ISDLDisplay  : public IMonitorDisplay
{
	public:
	ISDLDisplay();
	~ISDLDisplay();
	int		onExecute();
	void 	draw();

	void	onEvent(SDL_Event *e);
	void	onExit();
	void	onKeyDown(SDL_Keycode sym);

	private:
	bool			running;
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Surface		*bg;
	SDL_Surface		*img;
	TTF_Font		*font1;
	TTF_Font		*font2;

	virtual bool	onInit();
	virtual void	onLoop();
	virtual void	onRender();
	virtual void	onQuit();
};


#endif
