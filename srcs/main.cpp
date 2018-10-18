#include "Module.hpp"
#include "Display.hpp"
#include "CpuModule.hpp"
#include "DateTimeModule.hpp"
#include "DisksModule.hpp"
#include "HostnameModule.hpp"
#include "MemRegionsModule.hpp"
#include "NetworkModule.hpp"
#include "OSinfoModule.hpp"
#include "RamModule.hpp"
#include "VmModule.hpp"
#include "CatModule.hpp"

bool parseInput(int ac, char *av[], std::vector<Module *> &modules, bool *n, bool *s, bool *c)
{
	std::string opt;
	std::string temp;

	if (ac == 2 && strcmp(av[1], "-c") == 0) {
		*c = true;
		return true;
	}
	if (ac < 3)
		return (false);
	opt = av[1];
	if (opt.empty())
		return (false);
	if (opt.find('-') == std::string::npos)
		return (false);
	if (opt.find('n') != std::string::npos)
		*n = true;
	if (opt.find('s') != std::string::npos)
		*s = true;
	for (int i = 2; i < ac; i++) {
		temp = av[i];
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp == "hostname")
			modules.push_back(new HostnameModule("Hostname"));
		else if (temp == "osinfo")
			modules.push_back(new OSinfoModule("OSinfo"));
		else if (temp == "time")
			modules.push_back(new DateTimeModule("DateTime"));
		else if (temp == "cpu")
			modules.push_back(new CpuModule("Cpu"));
		else if (temp == "ram")
			modules.push_back(new RamModule("Ram"));
		else if (temp == "network")
			modules.push_back(new NetworkModule("Network"));
		else if (temp == "disk")
			modules.push_back(new DisksModule("Disks"));
		else if (temp == "memregions")
			modules.push_back(new MemRegionsModule("MemRegions"));
		else if (temp == "vm")
			modules.push_back(new VmModule("Vm"));
		else if (temp == "cat")
			modules.push_back(new CatModule("Cat"));
	}
	return (true);
}

int main(int ac, char *av[]) {
	std::vector<Module *> modules;
	Display display;
	std::vector<std::string> data;
	bool n = false;
	bool s = false;
	bool c = false;

	if (!parseInput(ac, av, modules, &n, &s, &c))
		std::cout << "./ft_gkrellm -[ns] " <<
				  "hostname|osinfo|time|cpu|ram|network|disk|memregions|vm"
				  << std::endl;
	if (n)
		display.updateDisplay(modules, 'n');
	else if (s)
		display.updateDisplay(modules, 's');
	else if (c)
		system("curl https://gist.githubusercontent.com/moshen/1417991/raw/nyan.pl | perl");
	return (0);
}
