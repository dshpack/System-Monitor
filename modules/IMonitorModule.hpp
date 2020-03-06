/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:30:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:53:25 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <iostream>
#include <vector>

class   IMonitorModule {

private:

	IMonitorModule( IMonitorModule const & );
	IMonitorModule & operator=( IMonitorModule const & );

public:

	IMonitorModule( void ) { };
	virtual         ~IMonitorModule( void ) { };

	virtual void                                updateData( void ) = 0;
	virtual std::string const &                 getModulName( void ) const = 0;
	virtual std::vector<std::string> const &    getModulData(void) const = 0;

};


#endif
