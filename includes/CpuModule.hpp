#ifndef CPPRUSH1_CPUMODULE_HPP
# define CPPRUSH1_CPUMODULE_HPP

# include "Module.hpp"
# include <sys/sysctl.h>
# include <unistd.h>

class CpuModule : public Module
{
public:
	CpuModule(void);
	CpuModule(std::string name);
	virtual ~CpuModule(void);
	void updateData();
	CpuModule(CpuModule const &src);
	CpuModule	&operator=(CpuModule const &rhs);
};


#endif
