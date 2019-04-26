#ifndef POINT2D_H
#define POINT2D_H

#include <math.h>

namespace Graphics
{
	template<class T> class Point2D
	{
		// -- fields -- //
	public:
		T x, y;


		// -- constructor -- //
	public:
		Point2D(T x, T y)
			:x(x), y(y)
		{
		}
		~Point2D()
		{
		}


		// -- operators -- //
	public:
		Point& operator=(const Point& point)
		{
			this->x = point->x;
			this->y = point->y;

			return *this;
		}
		Point& operator=(const Point&& point)
		{
			this->x = point->x;
			this->y = point->y;

			return *this;
		}
		Point operator+(const Point& point)
		{
			return Point(this->x + point.x, this->y + point.y);
		}
		Point operator-(const Point& point)
		{
			return Point(this->x - point.x, this->y - point.y);
		}
		Point& operator+=(const Point& point)
		{
			this->x += point.x;
			this->y += point.y;
			return *this;
		}
		Point& operator-=(const Point& point)
		{
			this->x -= point.x;
			this->y -= point.y;
			return *this;
		}


		// -- methods -- //
	public:
		T Magnitude()
		{
			return sqrt((x * x) + (y * y));
		}
	};
}

#endif // !POINT2D_H