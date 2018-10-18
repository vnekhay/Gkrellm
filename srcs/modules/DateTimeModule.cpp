#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule(void) : Module() {
	time_t		t;
	char		buffer[255] = {0};

	time(&t);
	std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y", localtime(&t));
	this->_data.push_back(buffer);
	std::fill(buffer, buffer + sizeof(buffer) - 1, '\0');
	std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
	this->_data.push_back(buffer);
}

DateTimeModule::DateTimeModule(std::string name) : Module(name) {
	time_t		t;
	char		buffer[255] = {0};

	time(&t);
	std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y", localtime(&t));
	this->_data.push_back(buffer);
	std::fill(buffer, buffer + sizeof(buffer) - 1, '\0');
	std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
	this->_data.push_back(buffer);
}

DateTimeModule::~DateTimeModule(){}

void DateTimeModule::updateData() {
	time_t		t;
	char		buffer[255] = {0};

	time(&t);
	for (; this->_data.size();)
		this->_data.erase(this->_data.begin());
	std::strftime(buffer, sizeof(buffer) - 1, "%a %d %b %y", localtime(&t));
	this->_data.push_back(buffer);
	std::fill(buffer, buffer + sizeof(buffer) - 1, '\0');
	std::strftime(buffer, sizeof(buffer) - 1, "%r", localtime(&t));
	this->_data.push_back(buffer);
}

DateTimeModule::DateTimeModule(DateTimeModule const &src) {
	*this = src;
}

DateTimeModule	&DateTimeModule::operator=(DateTimeModule const &rhs) {
	(void)rhs;
	return (*this);
}
