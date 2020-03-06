/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:30:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 10:24:44 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "modules/IMonitorModule.hpp"
#include "IEvent.hpp"

class	IMonitorDisplay : public IEvent
{
	public:
	IMonitorDisplay();
	virtual ~IMonitorDisplay( void ) = 0;

	virtual int		onExecute();
	virtual void	onExit();

	private:
	virtual bool	onInit();
	virtual void	onLoop();
	virtual void	onRender();
	virtual void	onQuit();

};


#endif
