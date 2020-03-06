/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEvent.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:14:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 02:38:45 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IEVENT_HPP
#define IEVENT_HPP

#include <SDL2/SDL.h>

class IEvent
{
	public:
	IEvent();
	virtual ~IEvent();

	virtual void onExit();


	private:
};


#endif
