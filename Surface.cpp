/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Surface.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:41:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 04:32:47 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Surface.hpp"

Surface::Surface()
{
}

SDL_Surface	*Surface::loadSurface(char *fname, SDL_Surface *screen)
{
	SDL_Surface		*tmp = SDL_LoadBMP(fname);
	if (!tmp)
		return NULL;
	SDL_Surface		*newSurface = SDL_ConvertSurface(tmp, screen->format, 0);
	SDL_FreeSurface(tmp);
	return newSurface;
}

SDL_Surface	*
Surface::loadSurface(char *fname, SDL_Surface *screen, int r, int g, int b)
{
	SDL_Surface		*tmp = SDL_LoadBMP(fname);
	if (!tmp)
		return NULL;
	SDL_Surface		*newSurface = SDL_ConvertSurface(tmp, screen->format, 0);
	SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format, r, g, b));
	SDL_FreeSurface(tmp);
	return newSurface;
}

void Surface::drawSurface(SDL_Surface *src, SDL_Surface *dst, int x, int y)
{
	if (!src || !dst)
		return ;
	SDL_Rect	rcDest;
	rcDest.x = x;
	rcDest.y = y;

	/*SDL_Rect	rcSrc;
	rcSrc.x = 100;
	rcSrc.y = 100;
	rcSrc.w = 300;
	rcSrc.h = 300;*/

	//SDL_BlitSurface(src, &rcSrc, dst, &rcDest);
	SDL_BlitSurface(src, NULL, dst, &rcDest);
}

void Surface::drawSurface(SDL_Surface *src, SDL_Surface *dst,  SDL_Rect *clip,
																int x, int y)
{
	if (!src || !dst)
		return;
	SDL_Rect rcDest;
	rcDest.x = x;
	rcDest.y = y;

	/*SDL_Rect	rcSrc;
	rcSrc.x = 100;
	rcSrc.y = 100;
	rcSrc.w = 300;
	rcSrc.h = 300;*/

	//SDL_BlitSurface(src, &rcSrc, dst, &rcDest);
	SDL_BlitSurface(src, clip, dst, &rcDest);
}

void Surface::drawSurface(SDL_Surface *src, SDL_Surface *dst, SDL_Rect *clip,
																SDL_Rect *scale)
{
	if (!src || !dst)
		return;
	SDL_BlitSurface(src, clip, dst, scale);
}

void Surface::drawTextSurface(TTF_Font *font, SDL_Surface *screen,
							const char *str, int x, int y, int r, int g, int b)
{
	if (!font || !screen)
		return ;
	SDL_Color color = {r, g, b, 0};

	SDL_Rect rcDest;
	rcDest.x = x;
	rcDest.y = y;

	SDL_Surface *txtSurf = TTF_RenderText_Solid(font, str, color);
	if (!txtSurf)
		return ;
	SDL_BlitSurface(txtSurf, NULL, screen, &rcDest);
	SDL_FreeSurface(txtSurf);
}