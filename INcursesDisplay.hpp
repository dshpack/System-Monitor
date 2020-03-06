/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INcursesDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:39:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 10:43:33 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCURSESDISPLAY_HPP
#define INCURSESDISPLAY_HPP

#include "IMonitorDisplay.hpp"

#include "modules/CPUMod.hpp"
#include "modules/DateTimeMod.hpp"
#include "modules/HostnameUsernameMod.hpp"
#include "modules/NetworkMod.hpp"
#include "modules/OSInfosMod.hpp"
#include "modules/RAMMod.hpp"

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>

class INcursesDisplay : public IMonitorDisplay
		{
private:
	WINDOW		*_wd;

	int			_run;

	INcursesDisplay( INcursesDisplay const & );
	INcursesDisplay & operator=( INcursesDisplay const & );

	void addStrWind(int y, int x, std::string str);
	void  printVector( std::vector<std::string> const & vec, int y, int x);

public:
	INcursesDisplay( void );
	virtual ~INcursesDisplay( void );
	int		onExecute();
	void    init( void );
	void    run( void );

};



#endif
