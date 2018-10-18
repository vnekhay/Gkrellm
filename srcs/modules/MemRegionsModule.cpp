#include "MemRegionsModule.hpp"

MemRegionsModule::MemRegionsModule(void) : Module() {
	std::string	string;

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep MemRegions | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());
	for (int i = 0; i < 3; i++) {
		this->_data.push_back(string.substr(0, string.find(',')).substr(1));
		string.erase(0, string.find(',') + 1);
	}
}

MemRegionsModule::MemRegionsModule(std::string name) : Module(name) {
	std::string	string;

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep MemRegions | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());
	for (int i = 0; i < 3; i++) {
		this->_data.push_back(string.substr(0, string.find(',')).substr(1));
		string.erase(0, string.find(',') + 1);
	}
}

MemRegionsModule::~MemRegionsModule(){}


void MemRegionsModule::updateData() {
	std::string	string;

	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());

	string = this->getDataTop("top -l 1 -n 0 -s 0 -c n| grep MemRegions | awk '{$1 = \"\"; print $0}'");
	if (string.empty()) {
		this->_data.push_back("Error");
		return ;
	}
	string.erase(string.size() - 2, string.size());
	for (int i = 0; i < 3; i++) {
		this->_data.push_back(string.substr(0, string.find(',')).substr(1));
		string.erase(0, string.find(',') + 1);
	}
}

MemRegionsModule::MemRegionsModule(MemRegionsModule const &src) {
	*this = src;
}

MemRegionsModule	&MemRegionsModule::operator=(MemRegionsModule const &rhs) {
	(void)rhs;
	return (*this);
}
