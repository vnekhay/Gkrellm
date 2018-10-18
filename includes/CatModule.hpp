#ifndef CPPRUSH1_CATMODULE_HPP
# define CPPRUSH1_CATMODULE_HPP

# include "Module.hpp"

class CatModule : public Module
{
public:
	CatModule();
	CatModule(std::string name);
	virtual ~CatModule();
	void updateData();
	CatModule(CatModule const &src);
	CatModule	&operator=(CatModule const &rhs);
};


#endif
