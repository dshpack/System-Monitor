/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkMod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:50:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:50:01 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "NetworkMod.hpp"

# include <sstream>
#include <curl/curl.h>
#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>

NetworkMod::NetworkMod( std::string const & moduleName ) : IMonitorModule(),
																 _moduleName(moduleName), _moduleData()
{
	_moduleData.resize(4);
}

NetworkMod::~NetworkMod( void ) {}

void                                NetworkMod::updateData( void )
{
	int         mib[6];
	char         *lim;
	char         *next;
	size_t         len;
	struct         if_msghdr *ifm;

	long int     ipackets = 0;
	long int     opackets = 0;
	long int     ibytes = 0;
	long int     obytes = 0;

	mib[0]= CTL_NET;// networking subsystem
	mib[1]= PF_ROUTE;// type of information
	mib[2]= 0;// protocol (IPPROTO_xxx)
	mib[3]= 0;// address family
	mib[4]= NET_RT_IFLIST2;// operation
	mib[5]= 0;

	sysctl(mib, 6, NULL, &len, NULL, 0);
	char buf[len];
	sysctl(mib, 6, buf, &len, NULL, 0);

	lim = buf + len;
	for (next = buf; next < lim; ) {
		ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;

		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;

			if(if2m->ifm_data.ifi_type!=18) {
				opackets += if2m->ifm_data.ifi_opackets;
				ipackets += if2m->ifm_data.ifi_ipackets;
				obytes   += if2m->ifm_data.ifi_obytes;
				ibytes   += if2m->ifm_data.ifi_ibytes;
			}
		}
	}

	std::stringstream ss[4];
	ss[0] << "packets in: " << ipackets;
	ss[1] << "packets out: " << opackets;
	_moduleData[0] = ss[0].str();
	_moduleData[1] = ss[1].str();

	ss[2].str(std::string());
	ss[2].precision(2);
	ss[2].setf(std::ios::fixed);
	ss[2] << "data resived: " << static_cast<double>(ibytes) / 1024 / 1024 / 1024 << "GB";
	_moduleData[2] = ss[2].str();
	ss[3] << "data sent: " << static_cast<double>(obytes) / 1024 / 1024 / 1024;
	ss[3] << "GB";
	_moduleData[3] = ss[3].str();
}

std::vector<std::string> const &    NetworkMod::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 NetworkMod::getModulName( void ) const
{
	return _moduleName;
}       
