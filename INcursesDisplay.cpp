/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INcursesDisplay.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshpack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:39:00 by dshpack           #+#    #+#             */
/*   Updated: 2019/10/13 10:23:22 by dshpack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "INcursesDisplay.hpp"

INcursesDisplay::INcursesDisplay( void ) : _run(1) { }

INcursesDisplay::~INcursesDisplay( void ) { endwin(); }

void    INcursesDisplay::init( void )
{
	_wd = initscr();
	cbreak();
	noecho();
	clear();
	refresh();
	keypad(_wd, true);
	nodelay(_wd, true);
	curs_set(0);
	start_color();
	attron(A_BOLD);
	box(_wd, 0, 0);
	attroff(A_BOLD);
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	wbkgd(_wd, COLOR_PAIR(1));
}

int		INcursesDisplay::onExecute() {
	init();
	run();
	return 1;
}

void    INcursesDisplay::run( void )
{
	HostnameUsernameMod host("Hostname/username module");
	CPUMod				cpu("CPU Module:");
	DateTimeMod			date("Date and Time Module:");
	OSInfosMod			os("OS info Module:");
	RAMMod				mem("RAM Module:");
	NetworkMod			net("Network Module:");



	while (_run)
	{
		if (wgetch(_wd) == 27)
			_run = 0;

		clear();

		struct winsize size;
		ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
		attron(COLOR_PAIR(4));
		attron(A_REVERSE);
		addStrWind(2, size.ws_col / 2 - 12, "S Y S T E M   M O N I T O R");
		attroff(A_REVERSE);
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(3));

		host.updateData();
		attron(A_BOLD);
		addStrWind( 6, 5,  host.getModulName() );
		attroff(A_BOLD);
		printVector(host.getModulData(), 8, 5);

		os.updateData();
		attron(A_BOLD);
		addStrWind(12, 5, os.getModulName() );
		attroff(A_BOLD);
		printVector(os.getModulData(), 14, 5);

		date.updateData();
		attron(A_BOLD);
		addStrWind (18, 5, date.getModulName() );
		attroff(A_BOLD);
		printVector(date.getModulData(), 20, 5);
		attron(A_BOLD);
		addStrWind(24, 5,  cpu.getModulName() );
		attroff(A_BOLD);

		cpu.updateData();
		printVector(cpu.getModulData(), 26, 5);
		attron(COLOR_PAIR(3));
		mem.updateData();
		attron(A_BOLD);
		addStrWind( 32, 5, mem.getModulName() );
		attroff(A_BOLD);
		printVector(mem.getModulData(), 34, 5);

		attron(COLOR_PAIR(3));
		net.updateData();
		attron(A_BOLD);
		addStrWind ( 38, 5, net.getModulName() );
		attroff(A_BOLD);
		printVector(net.getModulData(), 40, 5);
		attroff(COLOR_PAIR(3));
		usleep(100000);
		refresh();
	}
}

void            INcursesDisplay::addStrWind(int y, int x, std::string str)
{

	for (size_t i = 0; i < str.size(); i++)
	{
		mvaddch(y, x + i, str[i]);
	}
}

void  INcursesDisplay::printVector( std::vector<std::string> const & vec, int y, int x)
{
	for ( size_t i = 0; i < vec.size(); i++ )
	{
		addStrWind(y + i, x, vec[i]);
	}
}
