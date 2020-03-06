/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeMod.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:48:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:48:41 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DateTimeMod.hpp"

#include <ctime>
#include <sstream>

DateTimeMod::DateTimeMod( std::string const & moduleName ) : IMonitorModule(),
														   _moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

DateTimeMod::~DateTimeMod( void ) {}

void	DateTimeMod::updateData( void )
{
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );

	std::stringstream ss, sa;
	ss 	<< now->tm_hour << ':';
	  	if(now->tm_min < 10)
	  		ss << "0";
	  	 ss << now->tm_min << ':';
		if(now->tm_sec < 10)
			ss << "0";
		ss <<  now->tm_sec;
	_moduleData[0] = ss.str();

	sa 	<<  now->tm_mday << '-'
		<< (now->tm_mon + 1) << '-'
		<< (now->tm_year + 1900);

	_moduleData[1] = sa.str();
}

std::vector<std::string> const &    DateTimeMod::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 DateTimeMod::getModulName( void ) const
{
	return _moduleName;
}       
