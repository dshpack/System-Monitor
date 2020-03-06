#include "modules/IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "ISDLDisplay.hpp"
#include "INcursesDisplay.hpp"

int main(int argc, char *argv[])
{
	std::string s;
	if(argv[1])
		s = argv[1];
	std::string s1 = "sdl_mod";
	std::string s2 = "ncurses_mod";
	if(argc != 2 || (s != s1 && s != s2))
	{
		std::cout << "Usage: \"sdl_mod\" or \"ncurses_mod\"" << std::endl;
		return 0;
	}
	else if (s == s1)
	{
		ISDLDisplay	sdl;
		return sdl.onExecute();
	}
	else
	{
		INcursesDisplay	ncurse;
		return ncurse.onExecute();
	}
}