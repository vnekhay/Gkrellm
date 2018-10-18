#ifndef CPPRUSH1_DISPLAY_HPP
# define CPPRUSH1_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "Module.hpp"
# include <SFML/Graphics.hpp>
# include <ncurses.h>

class Display : public IMonitorDisplay
{
private:
	std::vector<sf::RenderWindow *> _windows;

public:
	Display();
	virtual ~Display();
	void	updateDisplay(std::vector<Module *>modules, char choice);
	void	n(std::vector<Module *> modules);
	void	s(std::vector<Module *> modules);
	Display(Display const &src);
	Display	&operator=(Display const &rhs);

};


#endif
