#include "Display.hpp"

Display::Display() {}

Display::~Display() {
	for (; this->_windows.size();)
		this->_windows.erase(this->_windows.begin());
	clear();
	refresh();
	endwin();
}

void	Display::updateDisplay(std::vector<Module *> modules, char choice) {
	if (modules.empty())
		return;

	if (choice == 'n')
		this->n(modules);
	else if (choice == 's')
		this->s(modules);
}

void	Display::n(std::vector<Module *> modules) {
	std::vector<std::string>	data;
	int							key;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);

	while (1) {
		key = getch();
		if (key == 'q' || key == 'Q')
			break;
		clear();
		printw("%s", "FT_GKRELLM");
		printw("%c", '\n');
		printw("%c", '\n');
		for (unsigned long module = 0; module < modules.size(); module++)
			modules[module]->updateData();

		for (unsigned long module = 0; module < modules.size(); module++) {
			printw("%s", modules[module]->getName().c_str());
			printw("%c", '\n');
			data = modules[module]->getData();
			for (unsigned long i = 0; i < data.size(); i++) {
				printw("%s", data[i].c_str());
				printw("%c", '\n');
			}
			printw("%c", '\n');
		}
		refresh();
	}
}

void	Display::s(std::vector<Module *> modules) {
	sf::Image image;
	image.loadFromFile("siniy.jpg");
	sf::Texture image2;
	image2.loadFromImage(image);
	sf::Sprite image3;
	image3.setTexture(image2);

	sf::Font font;
	font.loadFromFile("comicz.ttf");

	sf::Text text("", font, 40);
	text.setStyle(sf::Text::Bold);

	for (unsigned long module = 0; module < modules.size(); module++) {
		sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(500, 250),
														modules[module]->getName());
		sf::Vector2u size = window->getSize();
		window->setPosition(sf::Vector2i(size.x, size.y + module * 270));
		window->setVerticalSyncEnabled(true);
		this->_windows.push_back(window);
	}

	while (this->_windows[0]->isOpen()) {
		for (unsigned long updModule = 0; updModule < modules.size(); updModule++)
			modules[updModule]->updateData();

		for (unsigned long module = 0; module < modules.size(); module++) {
			sf::Event event;
			while (this->_windows[module]->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					this->_windows[module]->close();
			}
			this->_windows[module]->draw(image3);

			std::string res;
			std::vector<std::string> data = modules[module]->getData();

			for (unsigned long i = 0; i < data.size(); i++)
				res += data[i] + "\n";
			text.setString(res);
			this->_windows[module]->draw(text);
			this->_windows[module]->display();
		}

	}
}

Display::Display(Display const &src) {
	*this = src;
}

Display	&Display::operator=(Display const &rhs) {
	(void)rhs;
	return (*this);
}
