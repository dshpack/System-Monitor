/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMMod.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:49:21 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RAMMOD_HPP
#define RAMMOD_HPP

#include "IMonitorModule.hpp"

# include <sys/sysctl.h>
# include <sstream>
# include <mach/host_info.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>

class RAMMod : IMonitorModule
{

private:
	std::string const           _moduleName;
	std::vector<std::string>    _moduleData;

	RAMMod( void );
	RAMMod( RAMMod const & );
	RAMMod & operator=( RAMMod const & );

public:
	virtual ~RAMMod( void );
	RAMMod( std::string const & );

	void                                updateData( void );
	std::string const &                 getModulName( void ) const;
	std::vector<std::string> const &    getModulData(void) const;
};

#endif //RAMMOD_HPP
