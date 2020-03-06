/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUMod.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:49:05 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "CPUMod.hpp"

#include <sstream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

#include <math.h>

#include <sys/ioctl.h>
#include <unistd.h>



CPUMod::CPUMod( std::string const & moduleName ) : IMonitorModule(),
														 _moduleName(moduleName), _moduleData(), _1previousTotalTicks(0),  _1previousIdleTicks(0)
{
	_moduleData.resize(5);
}

CPUMod::~CPUMod( void ) {}

float CPUMod::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks-_1previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks-_1previousIdleTicks;
	float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
	_1previousTotalTicks = totalTicks;
	_1previousIdleTicks  = idleTicks;
	return ret;
}

float CPUMod::GetCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{
		unsigned long long totalTicks = 0;
		for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
		return CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
	}
	else return -1.0f;
}


void                                CPUMod::updateData( void )
{
	char buffer[256];
	size_t bufferlen = 256;

	sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferlen, NULL, 0);
	std::stringstream ss[3];
	ss[0] << buffer;
	_moduleData[0] = ss[0].str();

	float cpuLoad = GetCPULoad() * 100.0f;

	ss[1].str(std::string());
	ss[1].precision(2);
	ss[1].setf(std::ios::fixed);
	ss[1] << cpuLoad;
	_moduleData[1] = ss[1].str();
	ss[2].str(std::string());
	ss[2] << "[ ";

	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	int max  = size.ws_col - 15;
	int ret = static_cast< int >(round(cpuLoad));

	int ret1 = ret * max / 100;


	for (int i = 0; i < ret1; ++i)
	{
		ss[2] << "|";
	}
	for (int i = ret1; i < max; ++i)
	{
		ss[2] << " ";
	}
	ss[2] << " ]";
	_moduleData[2] = ss[2].str();

	_moduleData[3] = initCoreCount();
	_moduleData[4] = activityCpu();

}

std::string		CPUMod::initCoreCount(){

	std::stringstream	coreCount;
	int					freeq;
	size_t				bufferlen = sizeof(freeq);
	std::stringstream	ss;

	ss << "Core Count ";
	sysctlbyname("machdep.cpu.core_count", &freeq, &bufferlen, NULL, 0);
	ss << freeq;
	coreCount << ss.str();
	return coreCount.str();
}

std::string CPUMod::activityCpu() {

	unsigned long		freeq;
	size_t				bufferlen = sizeof(freeq);
	std::stringstream	ss;

	sysctlbyname("hw.cpufrequency", &freeq, &bufferlen, NULL, 0);
	ss << "Clock Speed " << static_cast<float>(freeq) / 1000000000;
	return ss.str();
}

std::vector<std::string> const &    CPUMod::getModulData( void ) const
{
	return _moduleData;
}

std::string const &                 CPUMod::getModulName( void ) const
{
	return _moduleName;
}