/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateTimeMod.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:48:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:48:41 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DATETIMEMOD_HPP
#define DATETIMEMOD_HPP

#include "IMonitorModule.hpp"

class DateTimeMod : IMonitorModule
{
private:
	std::string const           _moduleName;
	std::vector<std::string>    _moduleData;

	DateTimeMod( void );
	DateTimeMod( DateTimeMod const & );
	DateTimeMod & operator=( DateTimeMod const & );

public:
	virtual ~DateTimeMod( void );
	DateTimeMod( std::string const & );

	void                                updateData( void );
	std::string const &                 getModulName( void ) const;
	std::vector<std::string> const &    getModulData(void) const;
	
};


#endif //DATETIMEMOD_HPP
