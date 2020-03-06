/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfosMod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 08:48:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 08:48:11 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "OSInfosMod.hpp"

OSInfosMod::OSInfosMod(std::string const & moduleName ) : IMonitorModule(),
														  _moduleName(moduleName), _moduleData()
{
	_moduleData.resize(2);
}

OSInfosMod::~OSInfosMod() {}

void OSInfosMod::updateData() {
	char buffer[255];
	size_t bufferlen = 255;

	std::stringstream ss;
	sysctlbyname("kern.ostype", &buffer, &bufferlen, NULL, 0);
	ss << "OS type: " << buffer;
	_moduleData[0] = ss.str();

	ss.str(std::string());
	sysctlbyname("kern.osrelease", &buffer, &bufferlen, NULL, 0);
	ss << "OS release: " << buffer;
	_moduleData[1] = ss.str();
}

std::string const& OSInfosMod::getModulName() const {
	return _moduleName;
}

std::vector<std::string> const& OSInfosMod::getModulData() const {
	return _moduleData;
}