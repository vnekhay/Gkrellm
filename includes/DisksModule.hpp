#ifndef CPPRUSH1_DISKSMODULE_HPP
# define CPPRUSH1_DISKSMODULE_HPP

# include "Module.hpp"
# include <sstream>

class DisksModule : public Module
{
public:
	DisksModule(void);
	DisksModule(std::string name);
	virtual ~DisksModule(void);
	void updateData();
	DisksModule(DisksModule const &src);
	DisksModule	&operator=(DisksModule const &rhs);
};


#endif
