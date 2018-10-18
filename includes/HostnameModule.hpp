#ifndef CPPRUSH1_HOSTNAMEMODULE_HPP
# define CPPRUSH1_HOSTNAMEMODULE_HPP

# include "Module.hpp"
# include <unistd.h>

class HostnameModule : public Module
{
public:
	HostnameModule(void);
	HostnameModule(std::string name);
	virtual ~HostnameModule();
	void updateData();
	HostnameModule(HostnameModule const &src);
	HostnameModule	&operator=(HostnameModule const &rhs);

};


#endif
