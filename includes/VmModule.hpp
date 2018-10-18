#ifndef CPPRUSH1_VMMODULE_HPP
# define CPPRUSH1_VMMODULE_HPP

# include "Module.hpp"
# include <sstream>

class VmModule : public Module
{
public:
	VmModule(void);
	VmModule(std::string name);
	virtual ~VmModule(void);
	void updateData();
	VmModule(VmModule const &src);
	VmModule	&operator=(VmModule const &rhs);
};

#endif
