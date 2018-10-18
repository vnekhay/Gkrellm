#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : Module() {
	char		buffer[255] = {0};
	std::string	hostname;

	buffer[0] = '\0';
	if (gethostname(buffer, sizeof(buffer) - 1) != 0)
		this->_data.push_back("Error");
	else
		hostname = buffer;
		this->_data.push_back(buffer);
}

HostnameModule::HostnameModule(std::string name) : Module(name) {
	char		buffer[255] = {0};

	if (gethostname(buffer, sizeof(buffer) - 1) != 0)
		this->_data.push_back("Error");
	else
		this->_data.push_back(buffer);
}

HostnameModule::~HostnameModule() {}

void HostnameModule::updateData(void) {
	char		buffer[255] = {0};

	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());
	if (gethostname(buffer, sizeof(buffer) - 1) != 0)
		this->_data.push_back("Error");
	else
		this->_data.push_back(buffer);
}

HostnameModule::HostnameModule(HostnameModule const &src) {
	*this = src;
}

HostnameModule	&HostnameModule::operator=(HostnameModule const &rhs) {
	(void)rhs;
	return (*this);
}
