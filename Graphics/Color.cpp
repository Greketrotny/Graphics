#include "Color.h"

namespace Graphics
{
	// [CLASS] Color -------------------------------|
	// -- fields -- //
	const Color Color::White	= Color(0xFFFFFFFF);
	const Color Color::Red		= Color(0xFFFF0000);
	const Color Color::Green	= Color(0xFF00FF00);
	const Color Color::Blue		= Color(0xFF0000FF);
	const Color Color::Yellow	= Color(0xFFFFFF00);
	const Color Color::Purple	= Color(0xFFFF00FF);
	const Color Color::Aqua		= Color(0xFF00FFFF);
	const Color Color::Black	= Color(0xFF000000);

	// -- constructors -- //
	Color::Color()
	{
		color = 0;
	}
	Color::Color(const Color &col)
		:color(col.color)
	{
	}
	Color::Color(const unsigned int& col)
		: color(col)
	{}
	Color::Color(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha)
		: color((alpha << 24u) | (red << 16u) | (green << 8u) | blue)
	{
	}

	// -- operators -- //
	Color& Color::operator=(const Color &color)
	{
		this->color = color.color;
		return *this;
	}
	Color& Color::operator=(Color&& color)
	{
		// self assignment
		if (&color == this)
			return *this;

		// transfer data
		this->color = color.color;

		return *this;
	}

	// -- static methods -- //
	Color Color::Blend(const Color& color1, const Color& color2, float balance)
	{
		balance += 1.0f;
		unsigned char red = (color1.GetR() * balance + color2.GetR() * (2.0f - balance)) / 2.0f;
		unsigned char green = (color1.GetG() * balance + color2.GetG() * (2.0f - balance)) / 2.0f;
		unsigned char blue = (color1.GetB() * balance + color2.GetB() * (2.0f - balance)) / 2.0f;
		unsigned char alpha = (color1.GetA() * balance + color2.GetA() * (2.0f - balance)) / 2.0f;
		return Color(red, green, blue, alpha);
	}

	// -- nonstatic methods -- //
	Color Color::Blend(const Color& color, float balance)
	{
		return Color::Blend(*this, color, balance);
	}

	// -- getters and setters -- //
	unsigned char Color::GetA() const
	{
		return (color & 0xFF000000u) >> 24u;
	}
	unsigned char Color::GetR() const
	{
		return (color & 0x00FF0000u) >> 16u;
	}
	unsigned char Color::GetG() const
	{
		return (color & 0x0000FF00u) >> 8u;
	}
	unsigned char Color::GetB() const
	{
		return (color & 0x000000FFu);
	}
	unsigned int Color::GetColor() const
	{
		return color;
	}

	void Color::SetA(unsigned char alpha)
	{
		color = (color & 0xFFFFFFu) | (alpha << 24u);
	}
	void Color::SetR(unsigned char red)
	{
		color = (color & 0xFFFFFFu) | (red << 16u);
	}
	void Color::SetG(unsigned char green)
	{
		color = (color & 0xFFFFFFu) | (green << 8u);
	}
	void Color::SetB(unsigned char blue)
	{
		color = (color & 0xFFFFFFu) | blue;
	}
	void Color::SetColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	{
		color = ((alpha << 24u) | (red << 16u) | (green << 8u) | blue);
	}
	// [CLASS] Color -------------------------------|
}