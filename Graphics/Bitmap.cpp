#include "Bitmap.h"

namespace Graphics
{
	// [CLASS] Bitmap -----------------------------|
	// -- constructors -- //
	Bitmap::Bitmap(const Bitmap &bitmap)
		:width(bitmap.width),
		height(bitmap.height)
	{
		if (colorMap) delete colorMap;
		colorMap = new Color[width * height];


		// copy pixels
		for (unsigned int x = 0; x < width; x++)
		{
			for (unsigned int y = 0; y < height; y++)
			{
				SetPixel(x, y, bitmap.GetPixel(x, y));
			}
		}
	}
	Bitmap::Bitmap(Bitmap &&bitmap)
		:width(bitmap.width),
		height(bitmap.height)
	{
		if (bitmap.colorMap)
		{
			this->colorMap = bitmap.colorMap;
			bitmap.colorMap = nullptr;
		}
	}
	Bitmap::Bitmap(unsigned int width, unsigned int height)
		:width(width),
		height(height)
	{
		colorMap = new Color[width * height];
		for (unsigned int x = 0; x < width; ++x)
		{
			for (unsigned int y = 0; y < height; ++y)
			{
				SetPixel(x, y, Color(255, 255, 255, 255));
			}
		}
	}
	Bitmap::~Bitmap()
	{
		if (colorMap) delete colorMap;
	}

	// -- operators -- //
	Bitmap& Bitmap::operator=(const Bitmap& bitmap)
	{
		this->width = bitmap.width;
		this->height = bitmap.height;

		if (colorMap) delete[] colorMap;
		colorMap = new Color[width * height];

		// copy pixels
		for (unsigned int x = 0; x < width; x++)
		{
			for (unsigned int y = 0; y < height; y++)
			{
				SetPixel(x, y, bitmap.GetPixel(x, y));
			}
		}
		return *this;
	}
	Bitmap& Bitmap::operator=(Bitmap&& bitmap)
	{
		this->width = bitmap.width;
		this->height = bitmap.height;

		if (bitmap.colorMap)
		{
			if (this->colorMap) delete[] colorMap;
			this->colorMap = bitmap.colorMap;
			bitmap.colorMap = nullptr;
		}

		return *this;
	}

	// -- methods -- //
	void Bitmap::Resize(unsigned int newWidth, unsigned int newHeight)
	{
		this->width = newWidth;
		this->height = newHeight;

		if (colorMap) delete[] colorMap;
		colorMap = new Color[width * height];
		for (unsigned int x = 0; x < width; ++x)
		{
			for (unsigned int y = 0; y < height; ++y)
			{
				SetPixel(x, y, Color(255, 255, 255, 255));
			}
		}
	}
	Color* Bitmap::GetMapAddress()
	{
		return colorMap;
	}

	// -- getters and seters -- //
	const Color& Bitmap::GetPixel(const unsigned int& x, const unsigned int& y) const
	{
		return colorMap[y * width + x];
	}
	void Bitmap::SetPixel(const unsigned int& x, const unsigned int& y, const Color& color)
	{
		colorMap[y * width + x] = color;
	}
	void Bitmap::SetPixel(
		const unsigned int& x, const unsigned int& y,
		const unsigned char& r, 
		const unsigned char& g, 
		const unsigned char& b, 
		const unsigned char& a)
	{
		colorMap[y * width + x] = Color(r, g, b, a);
	}
	// [CLASS] Bitmap -----------------------------|
}