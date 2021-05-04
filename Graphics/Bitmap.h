#ifndef BITMAP_H
#define BITMAP_H

#include "Color.h"

namespace Graphics
{
	class Bitmap
	{
	private:
		Color *colorMap = nullptr;
		size_t m_width, m_height;


	public:
		Bitmap(const Bitmap &bitmap);
		Bitmap(Bitmap &&bitmap) noexcept;
		Bitmap(
			size_t width, size_t height, 
			const Color& fill_color = Color(255u, 255u, 255u, 255u));
		~Bitmap();


		Bitmap& operator=(const Bitmap& bitmap);
		Bitmap& operator=(Bitmap&& bitmap) noexcept;


	public:
		void Resize(size_t width, size_t height);
		Color* GetMapAddress() const;
		void Clear(const Color& color);
		void Clear(const unsigned int& color_value);
		void Clear(
			const unsigned char& red,
			const unsigned char& green,
			const unsigned char& blue,
			const unsigned char& alpha = 0xFF);


	public:
		const Color& GetPixel(const size_t& x, const size_t& y) const;
		void SetPixel(const size_t& x, const size_t& y, const Color& color);
		void SetPixel(const size_t& x, const size_t& y, const unsigned int& color_value);
		void SetPixel(
			const size_t& x, const size_t& y,
			const unsigned char& red,
			const unsigned char& green,
			const unsigned char& blue,
			const unsigned char& alpha = 0xFF);

		size_t GetWidth() const;
		size_t GetHeight() const;
	};
}

#endif // !BITMAP_H