#include "Module.hpp"

Module::Module() {
	_name = "default";
}

Module::Module(std::string & name) : _name(name) {}

Module::~Module() {
	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());
}

const std::string &Module::getName() const {
	return _name;
}

void Module::setName(const std::string &_name) {
	Module::_name = _name;
}

void Module::setData(const std::vector<std::string> &_data) {
	Module::_data = _data;
}

const std::vector<std::string> &Module::getData() const {
	return _data;
}

std::string	Module::getDataTop(const char *command) {
	FILE		*stream;
	char		buffer[255] = {0};
	std::string	res;

	if ((stream = popen(command, "r"))) {
		if (fgets(buffer, 255, stream) == NULL) {
			pclose(stream);
			return ("");
		}
		res = buffer;
		pclose(stream);
		return res.substr(1);
	}
	return ("");
}

Module::Module(Module const &src) {
	*this = src;
}

Module	&Module::operator=(Module const &rhs) {
	(void)rhs;
	return (*this);
}
