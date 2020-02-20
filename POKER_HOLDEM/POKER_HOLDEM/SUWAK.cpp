#include "SUWAK.h"

SUWAK::SUWAK(int x,int y)
{
	xCord = x;
	yCord = y;
	axisHeight = 20;
	axisWidth = 400;
	sliderWidth = 50;
	sliderHeight = 80;
	try
	{
		if (!Ffont1.loadFromFile("images/czcionki/poker_font.otf"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania poker_font.otf" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	text.setFont(Ffont1);
	text.setFillColor(sf::Color::Green);
	axis.setPosition(x, y);
	axis.setOrigin(0, axisHeight / 2);
	axis.setSize(sf::Vector2f(axisWidth, axisHeight));
	axis.setFillColor(sf::Color(63, 63, 63));
	slider.setPosition(x, y);
	slider.setOrigin(sliderWidth / 2, sliderHeight / 2);
	slider.setSize(sf::Vector2f(sliderWidth, sliderHeight));
	slider.setFillColor(sf::Color(192, 192, 192));
	value.setFont(Ffont1);
	value.setCharacterSize(50);
	value.setFillColor(sf::Color::Green);
	value.setPosition(800, 970);
}

sf::Text SUWAK::returnText(int x, int y, std::string z, int fontSize)
{
	text.setCharacterSize(fontSize);
	text.setPosition(x, y);
	text.setString(z);
	return text;
}

void SUWAK::create(int min, int max)
{
	sliderValue = min;
	minValue = min;
	maxValue = max;
}

void SUWAK::logic(sf::RenderWindow &app)
{
	if (slider.getGlobalBounds().contains(sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))  //
	{
		if (sf::Mouse::getPosition(app).x >= xCord && sf::Mouse::getPosition(app).x <= xCord + axisWidth)
		{
			slider.setPosition(sf::Mouse::getPosition(app).x, yCord);
			sliderValue = (minValue + ((slider.getPosition().x - xCord) / axisWidth * (maxValue - minValue)));
			oldSliderValue = sliderValue;
		}
	}
}

void SUWAK::resetOldSliderValue()
{
	oldSliderValue = 0;
	slider.setPosition(320, 1000);
}

void SUWAK::myDraw(sf::RenderWindow &app)
{
	std::stringstream ss;
	ss << this->oldSliderValue;
	std::string str = ss.str();
	value.setString(str);
	app.draw(value);
}

int SUWAK::getSliderValue()
{
	return sliderValue;
}

int SUWAK::getOldSliderValue()
{
	return oldSliderValue;
}

void SUWAK::setSliderValue(int newValue)
{
	if (newValue >= minValue && newValue <= maxValue)
	{
		sliderValue = newValue;
		float diff = maxValue - minValue;
		float diff2 = newValue - minValue;
		float zzz = axisWidth / diff;
		float posX = zzz * diff2;
		posX += xCord;
		slider.setPosition(posX, yCord);
	}
}

void SUWAK::setSliderPercentValue(float newPercentValue)
{
	if (newPercentValue >= 0 && newPercentValue <= 100)
	{
		sliderValue = newPercentValue / 100 * maxValue;
		slider.setPosition(xCord + (axisWidth*newPercentValue / 100), yCord);
	}
}

void SUWAK::draw(sf::RenderWindow &app)
{
	logic(app);
	app.draw(returnText(xCord - 10, yCord + 5, std::to_string(minValue), 20));
	app.draw(axis);
	app.draw(returnText(xCord + axisWidth - 10, yCord + 5, std::to_string(maxValue), 20));
	app.draw(slider);
	myDraw(app);
}

SUWAK::~SUWAK()
{
}
