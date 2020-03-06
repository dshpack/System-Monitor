/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Surface.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:41:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 01:27:20 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SURFACE_HPP
#define SURFACE_HPP

#include <SDL2/SDL.h>
#include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"


class Surface
{
	public:
	Surface();

	static SDL_Surface	*loadSurface(char *fname, SDL_Surface *screen);
	static SDL_Surface	*loadSurface(char *fname, SDL_Surface *screen,
														int r, int g, int b);

	static void drawSurface(SDL_Surface *src, SDL_Surface *dst, int x, int y);
	static void drawSurface(SDL_Surface *src, SDL_Surface *dst, SDL_Rect *clip,
																int x, int y);
	static void drawSurface(SDL_Surface *src, SDL_Surface *dst, SDL_Rect *clip,
																SDL_Rect *scale);
	static void drawTextSurface(TTF_Font *font, SDL_Surface *screen,
							const char *str, int x, int y, int r, int g, int b);
};


#endif
