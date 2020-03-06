/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:30:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/12 18:34:39 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{}
IMonitorDisplay::~IMonitorDisplay( void ) {}

int		IMonitorDisplay::onExecute()
{return 0;}

void	IMonitorDisplay::onExit()
{}
//
//void	IMonitorDisplay::onKeyDown()
//{}

bool	IMonitorDisplay::onInit()
{return true;}

void	IMonitorDisplay::onLoop()
{}

void	IMonitorDisplay::onRender()
{}

void	IMonitorDisplay::onQuit()
{}
