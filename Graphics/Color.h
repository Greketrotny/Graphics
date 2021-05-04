#ifndef COLOR_H
#define COLOR_H

namespace Graphics
{
	class Color
	{
	private:
		unsigned int color;

		// static colors
	public:
		static const Color White, Red, Green, Blue, Yellow, Purple, Aqua, Black;


	public:
		Color();
		Color(const Color &color);
		Color(const unsigned int& color);
		Color(const unsigned char& red,	const unsigned char& green, const unsigned char& blue, const unsigned char& alpha = 0xFF);


	public:
		Color& operator=(const Color& color);
		Color& operator=(Color&& color) noexcept;


	public:
		static Color BlendAverage(const Color& color1, const Color& color2);
		static Color BlendAddition(const Color& color1, const Color& color2);
		static Color BlendProduct(const Color& color1, const Color& color2);


	public:
		Color BlendAverage(const Color& color);
		Color BlendAddition(const Color& color);
		Color BlendProduct(const Color& color);


	public:
		unsigned char GetR() const;
		unsigned char GetG() const;
		unsigned char GetB() const;
		unsigned char GetA() const;
		unsigned int GetColor() const;
		void SetR(const unsigned char& red);
		void SetG(const unsigned char& green);
		void SetB(const unsigned char& blue);
		void SetA(const unsigned char& alpha);
		void SetColor(
			const unsigned char& red, 
			const unsigned char& green, 
			const unsigned char& blue, 
			const unsigned char& alpha = 0xFF);
	};
}

#endif // !COLOR_H