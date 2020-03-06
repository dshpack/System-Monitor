/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUMod.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:49:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:49:05 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CPUMOD_HPP
#define CPUMOD_HPP

#include "IMonitorModule.hpp"

class CPUMod : IMonitorModule
{
private:
	std::string const           _moduleName;
	std::vector<std::string>    _moduleData;
	unsigned long long _1previousTotalTicks;
	unsigned long long _1previousIdleTicks;

	float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
	float GetCPULoad();


	CPUMod( void );
	CPUMod( CPUMod const & );
	CPUMod & operator=( CPUMod const & );

public:
	virtual ~CPUMod( void );
	CPUMod( std::string const & );

	void                                updateData( void );
	std::string const &                 getModulName( void ) const;
	std::vector<std::string> const &    getModulData(void) const;
	std::string							initCoreCount();
	std::string							activityCpu();

};


#endif //CPUMOD_HPP
