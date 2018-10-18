#include "DisksModule.hpp"

DisksModule::DisksModule(void) : Module() {
	std::string	string;
	int			read = 0;
	int			written = 0;
	char		buf[255] = {0};

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep Disks | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());

	std::istringstream buffer(string);
	buffer >> read;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> written;

	std::sprintf(buf, "%d", read);
	this->_data.push_back("Read: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", written);
	this->_data.push_back("Used: " + std::string(buf) + "M");
}

DisksModule::DisksModule(std::string name) : Module(name) {
	std::string	string;
	int			read = 0;
	int			written = 0;
	char		buf[255] = {0};

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep Disks | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());

	std::istringstream buffer(string);
	buffer >> read;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> written;

	std::sprintf(buf, "%d", read);
	this->_data.push_back("Read: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", written);
	this->_data.push_back("Used: " + std::string(buf) + "M");
}

DisksModule::~DisksModule(){}


void DisksModule::updateData() {
	std::string	string;
	int			read = 0;
	int			written = 0;
	char		buf[255] = {0};

	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep Disks | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());

	std::istringstream buffer(string);
	buffer >> read;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> written;

	std::sprintf(buf, "%d", read);
	this->_data.push_back("Read: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", written);
	this->_data.push_back("Used: " + std::string(buf) + "M");
}

DisksModule::DisksModule(DisksModule const &src) {
	*this = src;
}

DisksModule	&DisksModule::operator=(DisksModule const &rhs) {
	(void)rhs;
	return (*this);
}
