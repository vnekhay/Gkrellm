#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <iostream>
# include <vector>
# include "Module.hpp"

class IMonitorDisplay
{
public:
	virtual void	updateDisplay(std::vector<Module *>, char choice) = 0;
};

#endif