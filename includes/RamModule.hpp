#ifndef CPPRUSH1_RAMMODULE_HPP
# define CPPRUSH1_RAMMODULE_HPP

# include "Module.hpp"
# include <sys/sysctl.h>
# include <sstream>

class RamModule : public Module
{
public:
	RamModule(void);
	RamModule(std::string name);
	virtual ~RamModule(void);
	void updateData();
	RamModule(RamModule const &src);
	RamModule	&operator=(RamModule const &rhs);
};


#endif
