/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameUsernameMod.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:47:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:47:38 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HOSTNAMEUSERNAMEMOD_HPP
#define HOSTNAMEUSERNAMEMOD_HPP

#include <vector>
#include "IMonitorModule.hpp"

class HostnameUsernameMod : public IMonitorModule {

	private:
		std::string const           _moduleName;
		std::vector<std::string>    _moduleData;

	HostnameUsernameMod( void );
	HostnameUsernameMod( HostnameUsernameMod const & );
	HostnameUsernameMod & operator=( HostnameUsernameMod const & );

	public:
		virtual ~HostnameUsernameMod( void );
	HostnameUsernameMod( std::string const & );

		void                                updateData( void );
		std::string const &                 getModulName( void ) const;
		std::vector<std::string> const &    getModulData(void) const;


	};


#endif //HOSTNAMEUSERNAMEMOD_HPP
