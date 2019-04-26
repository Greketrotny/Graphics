#ifndef COLOR_H
#define COLOR_H

namespace Graphics
{
	class Color
	{
		// -- fields -- //
	private:
		unsigned int color;

		// static colors
		static const Color White, Red, Green, Blue, Yellow, Purple, Aqua, Black;


		// -- constructor -- //
	public:
		Color();
		Color(const Color &color);
		Color(const unsigned int& color);
		Color(const unsigned char& red,	const unsigned char& green, const unsigned char& blue, const unsigned char& alpha = 0xFF);


		// -- operators -- //
	public:
		Color& operator=(const Color& color);
		Color& operator=(Color&& color);


		// -- static methods -- //
	public:
		static Color Blend(const Color& color1, const Color& color2, float balance = 0.0f);


		// -- nonstatic methods -- //
	public:
		Color Blend(const Color& color, float balance = 0.0f);


		// -- getters and setters -- //
	public:
		unsigned char GetA() const;
		unsigned char GetR() const;
		unsigned char GetG() const;
		unsigned char GetB() const;
		unsigned int GetColor() const;
		void SetA(unsigned char alpha);
		void SetR(unsigned char red);
		void SetG(unsigned char green);
		void SetB(unsigned char blue);
		void SetColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xFF);
	};
}

#endif // !COLOR_H