#include "bitmap.h"

namespace Graphics
{
	Bitmap::Bitmap(const Bitmap &bitmap)
		:m_width(bitmap.m_width),
		m_height(bitmap.m_height)
	{
		if (colorMap) delete colorMap;
		colorMap = new Color[m_width * m_height];


		// copy pixels
		for (unsigned int x = 0; x < m_width; x++)
		{
			for (unsigned int y = 0; y < m_height; y++)
			{
				SetPixel(x, y, bitmap.GetPixel(x, y));
			}
		}
	}
	Bitmap::Bitmap(Bitmap &&bitmap) noexcept
		:m_width(bitmap.m_width),
		m_height(bitmap.m_height)
	{
		if (bitmap.colorMap)
		{
			this->colorMap = bitmap.colorMap;
			bitmap.colorMap = nullptr;
		}
	}
	Bitmap::Bitmap(
		size_t width, size_t height,
		const Color& fill_color)
		:m_width(width),
		m_height(height)
	{
		colorMap = new Color[m_width * m_height];
		for (size_t x = 0u; x < m_width; ++x)
		{
			for (size_t y = 0u; y < m_height; ++y)
			{
				SetPixel(x, y, fill_color);
			}
		}
	}
	Bitmap::~Bitmap()
	{
		if (colorMap) delete colorMap;
	}

	Bitmap& Bitmap::operator=(const Bitmap& bitmap)
	{
		if (m_width != bitmap.m_width || m_height != bitmap.m_height)
		{
			m_width = bitmap.m_width;
			m_height = bitmap.m_height;

			if (colorMap) delete[] colorMap;
			colorMap = new Color[m_width * m_height];
		}		

		// copy pixels
		Color* ptr1 = this->GetMapAddress();
		Color* end = ptr1 + m_width * m_height;
		Color* ptr2 = bitmap.GetMapAddress();
		while(ptr1 < end)
		{
			*ptr1 = *ptr2;
			++ptr1;
			++ptr2;
		}

		return *this;
	}
	Bitmap& Bitmap::operator=(Bitmap&& bitmap) noexcept
	{
		m_width = bitmap.m_width;
		m_height = bitmap.m_height;

		if (bitmap.colorMap)
		{
			if (this->colorMap) delete[] colorMap;
			this->colorMap = bitmap.colorMap;
			bitmap.colorMap = nullptr;
		}

		return *this;
	}

	void Bitmap::Resize(size_t newWidth, size_t newHeight)
	{
		if (newWidth == m_width && newHeight == m_height)
			return; 

		m_width = newWidth;
		m_height = newHeight;

		if (colorMap) delete[] colorMap;
		colorMap = new Color[m_width * m_height];
		for (size_t x = 0; x < m_width; ++x)
		{
			for (size_t y = 0; y < m_height; ++y)
			{
				SetPixel(x, y, Color(255, 255, 255, 255));
			}
		}
	}
	Color* Bitmap::GetMapAddress() const
	{
		return colorMap;
	}
	void Bitmap::Clear(const Color& color)
	{
		Color* begin = this->GetMapAddress();
		Color* end = begin + m_width * m_height;
		while (begin < end)
		{
			*begin = color;
			++begin;
		}
	}
	void Bitmap::Clear(const unsigned int& colorValue)
	{
		Clear(Color(colorValue));
	}
	void Bitmap::Clear(const unsigned char& red,
		const unsigned char& green,
		const unsigned char& blue,
		const unsigned char& alpha)
	{
		Clear(Color(red, green, blue, alpha));
	}

	const Color& Bitmap::GetPixel(const size_t& x, const size_t& y) const
	{
		return colorMap[y * m_width + x];
	}
	void Bitmap::SetPixel(const size_t& x, const size_t& y, const Color& color)
	{
		colorMap[y * m_width + x] = color;
	}
	void Bitmap::SetPixel(const size_t& x, const size_t& y, const unsigned int& colorValue)
	{
		colorMap[y * m_width + x] = Color(colorValue);
	}
	void Bitmap::SetPixel(
		const size_t& x, const size_t& y,
		const unsigned char& r, 
		const unsigned char& g, 
		const unsigned char& b, 
		const unsigned char& a)
	{
		colorMap[y * m_width + x] = Color(r, g, b, a);
	}

	size_t Bitmap::GetWidth() const
	{
		return m_width;
	}
	size_t Bitmap::GetHeight() const
	{
		return m_height;
	}
}