#ifndef CPPRUSH1_MODULE_HPP
# define CPPRUSH1_MODULE_HPP

# include <iostream>
# include <vector>
# include <unistd.h>
# include "IMonitorModule.hpp"

class Module : public IMonitorModule
{
protected:
	std::string _name;
	std::vector<std::string> _data;

public:
	Module();
	Module(std::string & name);
	virtual ~Module();
	const std::string &getName() const;
	const std::vector<std::string> &getData() const;
	void setName(const std::string &_name);
	void setData(const std::vector<std::string> &_data);
	virtual void updateData() = 0;
	std::string	getDataTop(const char *command);
	Module(Module const &src);
	Module	&operator=(Module const &rhs);
};


#endif
