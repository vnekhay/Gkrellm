#ifndef CPPRUSH1_DATETIMEMODULE_HPP
# define CPPRUSH1_DATETIMEMODULE_HPP

# include "Module.hpp"

class DateTimeModule : public Module
{
public:
	DateTimeModule(void);
	DateTimeModule(std::string name);
	virtual ~DateTimeModule(void);
	void updateData();
	DateTimeModule(DateTimeModule const &src);
	DateTimeModule	&operator=(DateTimeModule const &rhs);
};


#endif
