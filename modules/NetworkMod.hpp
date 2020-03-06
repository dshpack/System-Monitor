/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkMod.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:50:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:50:01 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef NETWORKMOD_HPP
#define NETWORKMOD_HPP

#include "IMonitorModule.hpp"

class NetworkMod : IMonitorModule
{
private:
	std::string const           _moduleName;
	std::vector<std::string>    _moduleData;

	NetworkMod( void );
	NetworkMod( NetworkMod const & );
	NetworkMod & operator=( NetworkMod const & );

public:
	virtual ~NetworkMod( void );
	NetworkMod( std::string const & );

	void                                updateData( void );
	std::string const &                 getModulName( void ) const;
	std::vector<std::string> const &    getModulData(void) const;
};


#endif //NETWORKMOD_HPP
