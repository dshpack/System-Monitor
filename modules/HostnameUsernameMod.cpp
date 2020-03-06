/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameUsernameMod.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:47:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:47:38 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "HostnameUsernameMod.hpp"

#include <sstream>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

HostnameUsernameMod::HostnameUsernameMod( std::string const & moduleName ) : IMonitorModule(),
																   _moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

HostnameUsernameMod::~HostnameUsernameMod( void ) {}

void                                HostnameUsernameMod::updateData( void )
{
	struct passwd *pw;
	char buffer[255];
	size_t bufferlen = 255;

	pw = getpwuid(getuid());
	std::stringstream ss;
	ss << "User: " << pw->pw_name;
	_moduleData[0] = ss.str();

	ss.str(std::string());
	sysctlbyname("kern.hostname", &buffer, &bufferlen, NULL, 0);
	ss << "Hostname: " << buffer;
	_moduleData[1] = ss.str();

}

std::vector<std::string> const &    HostnameUsernameMod::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 HostnameUsernameMod::getModulName( void ) const
{
	return _moduleName;
}