/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMMod.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:49:21 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RAMMod.hpp"

#include <sstream>
#include <mach/mach.h>
#include <sys/sysctl.h>
#include <math.h>
#include <sys/ioctl.h>
#include <unistd.h>

RAMMod::RAMMod( std::string const & moduleName ) : IMonitorModule(),
															   _moduleName(moduleName), _moduleData()
{
	_moduleData.resize(3);
}

RAMMod::~RAMMod( void ) {}

void                                RAMMod::updateData( void )
{
	u_int64_t total_mem;
	float used_mem = 0.0;


	vm_size_t page_size;
	vm_statistics_data_t vm_stats;

	// Get total physical memory
	int mib[] = { CTL_HW, HW_MEMSIZE };
	size_t length = sizeof( total_mem );
	sysctl( mib, 2, &total_mem, &length, NULL, 0 );

	mach_port_t mach_port = mach_host_self();
	mach_msg_type_number_t count = sizeof( vm_stats ) / sizeof( natural_t );
	if( KERN_SUCCESS == host_page_size( mach_port, &page_size ) &&
		KERN_SUCCESS == host_statistics( mach_port, HOST_VM_INFO,
										 ( host_info_t )&vm_stats, &count )
			)
	{
		used_mem = static_cast<float>(( vm_stats.active_count + vm_stats.wire_count ) * page_size);
	}

	float us = static_cast< float >(used_mem) / static_cast<float>(total_mem) * 100.0f;
	std::stringstream ss, as;
	ss << static_cast< int >(used_mem / 1024 / 1024) << "/" << static_cast< int >(total_mem / 1024 / 1024);
	_moduleData[0] = ss.str();
	as << static_cast< int >(((used_mem / 1024 / 1024)/(total_mem/ 1024 / 1024))*100) << " o/o";
	_moduleData[1] = as.str();

	ss.str(std::string());
	ss << "[ ";

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	int max  = size.ws_col - 15;
	int ret = static_cast< int >(round(us));

	int ret1 = ret * max / 100;

	for (int i = 0; i < ret1; ++i)
	{
		ss << "|";
	}
	for (int i = ret1; i < max; ++i)
	{
		ss << " ";
	}
	ss << " ]";
	_moduleData[2] = ss.str();

}

std::vector<std::string> const &    RAMMod::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 RAMMod::getModulName( void ) const
{
	return _moduleName;
}