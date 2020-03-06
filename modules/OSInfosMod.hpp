/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfosMod.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:48:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:48:11 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OSINFOSMOD_HPP
#define OSINFOSMOD_HPP

#include "IMonitorModule.hpp"
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

class OSInfosMod : IMonitorModule
{
private:
	std::string const           _moduleName;
	std::vector<std::string>    _moduleData;

	OSInfosMod( void );
	OSInfosMod( OSInfosMod const & );
	OSInfosMod & operator=( OSInfosMod const & );

public:
	virtual ~OSInfosMod( void );
	OSInfosMod( std::string const & );

	void                                updateData( void );
	std::string const &                 getModulName( void ) const;
	std::vector<std::string> const &    getModulData(void) const;

};


#endif //OSINFOSMOD_HPP
