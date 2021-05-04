#include "Color.h"
#include <minmax.h>

namespace Graphics
{
	// [CLASS] Color -------------------------------|
	const Color Color::White = Color(0xFFFFFFFF);
	const Color Color::Red = Color(0xFFFF0000);
	const Color Color::Green = Color(0xFF00FF00);
	const Color Color::Blue = Color(0xFF0000FF);
	const Color Color::Yellow = Color(0xFFFFFF00);
	const Color Color::Purple = Color(0xFFFF00FF);
	const Color Color::Aqua = Color(0xFF00FFFF);
	const Color Color::Black = Color(0xFF000000);

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

	Color& Color::operator=(const Color &color)
	{
		this->color = color.color;
		return *this;
	}
	Color& Color::operator=(Color&& color) noexcept
	{
		// transfer data
		this->color = color.color;
		return *this;
	}


	Color Color::BlendAverage(const Color& color1, const Color& color2)
	{
		return Color
		(
			(color1.GetR() + color2.GetR()) / 2.0f,
			(color1.GetG() + color2.GetG()) / 2.0f,
			(color1.GetB() + color2.GetB()) / 2.0f,
			(color1.GetA() + color2.GetA()) / 2.0f
		);
	}
	Color Color::BlendAddition(const Color& color1, const Color& color2)
	{
		return Color
		(
			max(color1.GetR(), color2.GetR()),
			max(color1.GetG(), color2.GetG()),
			max(color1.GetB(), color2.GetB()),
			max(color1.GetA(), color2.GetA())
		);
	}
	Color Color::BlendProduct(const Color& color1, const Color& color2)
	{
		return Color
		(
			color1.GetR() * color2.GetR() / 255u,
			color1.GetG() * color2.GetG() / 255u,
			color1.GetB() * color2.GetB() / 255u,
			color1.GetA() * color2.GetA() / 255u
		);
	}

	Color Color::BlendAverage(const Color& color)
	{
		return Color::BlendAverage(*this, color);
	}
	Color Color::BlendAddition(const Color& color)
	{
		return Color::BlendAddition(*this, color);
	}
	Color Color::BlendProduct(const Color& color)
	{
		return Color::BlendProduct(*this, color);
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
	unsigned char Color::GetA() const
	{
		return (color & 0xFF000000u) >> 24u;
	}
	unsigned int Color::GetColor() const
	{
		return color;
	}

	void Color::SetR(const unsigned char& red)
	{
		color = (color & 0xFF00FFFFu) | (red << 16u);
	}
	void Color::SetG(const unsigned char& green)
	{
		color = (color & 0xFFFF00FFu) | (green << 8u);
	}
	void Color::SetB(const unsigned char& blue)
	{
		color = (color & 0xFFFFFF00u) | (blue);
	}
	void Color::SetA(const unsigned char& alpha)
	{
		color = (color & 0x00FFFFFFu) | (alpha << 24u);
	}
	void Color::SetColor(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha)
	{
		color = ((alpha << 24u) | (red << 16u) | (green << 8u) | blue);
	}
	// [CLASS] Color -------------------------------|
}