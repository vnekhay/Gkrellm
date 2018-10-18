#include "RamModule.hpp"

RamModule::RamModule(void) : Module() {
	std::string	string;
	int			used = 0;
	int			unused = 0;
	char		buf[255] = {0};

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep PhysMem | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}

	std::istringstream buffer(string);
	buffer >> used;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> unused;
	std::sprintf(buf, "%d", used + unused);
	this->_data.push_back("Total: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", used);
	this->_data.push_back("Used: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", unused);
	this->_data.push_back("Unused: " + std::string(buf) + "M");
}

RamModule::RamModule(std::string name) : Module(name) {
	std::string	string;
	int			used = 0;
	int			unused = 0;
	char		buf[255] = {0};

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep PhysMem | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}

	std::istringstream buffer(string);
	buffer >> used;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> unused;
	std::sprintf(buf, "%d", used + unused);
	this->_data.push_back("Total: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", used);
	this->_data.push_back("Used: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", unused);
	this->_data.push_back("Unused: " + std::string(buf) + "M");
}

RamModule::~RamModule(){}


void RamModule::updateData() {
	std::string	string;
	int			used = 0;
	int			unused = 0;
	char		buf[255] = {0};

	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep PhysMem | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}

	std::istringstream buffer(string);
	buffer >> used;
	unsigned long coma = string.find(",");
	string = string.substr(coma + 1);
	std::istringstream buffer2(string);
	buffer2 >> unused;
	std::sprintf(buf, "%d", used + unused);
	this->_data.push_back("Total: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", used);
	this->_data.push_back("Used: " + std::string(buf) + "M");
	std::fill(buf, buf + 255, '\0');
	std::sprintf(buf, "%d", unused);
	this->_data.push_back("Unused: " + std::string(buf) + "M");
}

RamModule::RamModule(RamModule const &src) {
	*this = src;
}

RamModule	&RamModule::operator=(RamModule const &rhs) {
	(void)rhs;
	return (*this);
}
