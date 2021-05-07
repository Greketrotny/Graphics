#include <iostream>

#include "color.h"

void PrintColor(const Graphics::Color& c)
{
	std::cout << "Color(" << int(c.red) << ", " << int(c.green) << ", " << int(c.blue) << ", " << int(c.alpha) << ")" << std::endl;
}

int main()
{
	PrintColor(Graphics::Color::Palette::SeaShell);

	std::cin.get();
	return 0;
}
