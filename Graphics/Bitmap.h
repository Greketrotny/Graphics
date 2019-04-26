#ifndef BITMAP_H
#define BITMAP_H

#include "Color.h"

namespace Graphics
{
	class Bitmap
	{
		// -- fields -- //
	private:
		Color *colorMap = nullptr;
		unsigned int width, height;

		// -- constructors -- //
	public:
		Bitmap(const Bitmap &bitmap);
		Bitmap(Bitmap &&bitmap);
		Bitmap(unsigned int width, unsigned int height);
		~Bitmap();

		// -- operators -- //
		Bitmap& operator=(const Bitmap& bitmap);
		Bitmap& operator=(Bitmap&& bitmap);

		// -- methods -- //
	public:
		void Resize(unsigned int newWidth, unsigned int newHeight);
		Color* GetMapAddress();

		// -- getters and setters -- //
	public:
		const Color& GetPixel(const unsigned int& x, const unsigned int& y) const;
		void SetPixel(const unsigned int& x, const unsigned int& y, const Color& color);
		void SetPixel(
			const unsigned int& x, const unsigned int& y, 
			const unsigned char& red,
			const unsigned char& green,
			const unsigned char& blue,
			const unsigned char& alpha = 0xFF
		);
	};
}

#endif // !BITMAP_H