#ifndef CPPRUSH1_MEMREGIONSMODULE_HPP
# define CPPRUSH1_MEMREGIONSMODULE_HPP

# include "Module.hpp"

class MemRegionsModule : public Module
{
public:
	MemRegionsModule(void);
	MemRegionsModule(std::string name);
	virtual ~MemRegionsModule(void);
	void updateData();
	MemRegionsModule(MemRegionsModule const &src);
	MemRegionsModule	&operator=(MemRegionsModule const &rhs);
};


#endif
