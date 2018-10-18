#ifndef CPPRUSH1_OSINFOMODULE_HPP
# define CPPRUSH1_OSINFOMODULE_HPP

# include "Module.hpp"
# include <sys/sysctl.h>

class OSinfoModule : public Module
{
public:
	OSinfoModule(void);
	OSinfoModule(std::string name);
	virtual ~OSinfoModule();
	void updateData();
	OSinfoModule(OSinfoModule const &src);
	OSinfoModule	&operator=(OSinfoModule const &rhs);
};


#endif
