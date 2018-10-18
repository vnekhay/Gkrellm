#ifndef CPPRUSH1_NETWORKMODULE_HPP
# define CPPRUSH1_NETWORKMODULE_HPP

# include "Module.hpp"
# include <sys/sysctl.h>

class NetworkModule : public Module
{
public:
	NetworkModule(void);
	NetworkModule(std::string name);
	virtual ~NetworkModule(void);
	void updateData();
	NetworkModule(NetworkModule const &src);
	NetworkModule	&operator=(NetworkModule const &rhs);
};


#endif
