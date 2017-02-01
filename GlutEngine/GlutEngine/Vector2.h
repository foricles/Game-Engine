#ifndef _VECTOR2_
#define _VECTOR2_

#include <math.h>
#include <iostream>

#define PI 3.14159265358979323846

#define VNULL  vec2(PI,PI)
#define VUP    vec2(0,1)
#define VDOWN  vec2(0,-1)
#define VLEFT  vec2(-1,0)
#define VRIGHT vec2(1,0)
#define VZERO  vec2(0,0)

class vec2
{
public:
		double x;
		double y;

//--------------------------------------------

		vec2();
		vec2(double X, double Y);
		vec2(const vec2 & vec);
		~vec2();

//--------------------------------------------

		//нормализировать вектор
		void Normalize();
		//нормализтрованый вектор
		vec2 Normalized();
		//длина вектора
		double Magnitude();

		void operator=(const vec2 &vec);
		void operator+=(const vec2 &vec);
		void operator-=(const vec2 &vec);
		void operator*=(double k);
		double operator*(const vec2 &vec) const;
		bool operator!=(const vec2 &vec)const;
		bool operator==(const vec2 &vec)const;
		vec2  operator*(double k) const;
		vec2  operator+(const vec2 &vec) const;
		vec2  operator-(const vec2 &vec) const;

//----------------------------------------------

		//угол между векторами
		friend double CosAlfa(vec2 vec1, vec2 vec2)
		{
			double znam = vec1.Magnitude()*vec2.Magnitude();
			if (znam == 0)
			{
				return 0;
			}
			else
			{
				double chis = (vec1*vec2);
				return chis / znam;
			}
		}

		friend std::ostream&operator<<(std::ostream &out, const vec2 &vec)
		{
			if(vec != VNULL)
			return (out << "(" << vec.x << "; " << vec.y << ")");
			else
				return (out << "NULL");
		}

		// косое произведение векторов
		friend double Pseudoscalar(vec2 vec1, vec2 vec2)
		{
			return (vec1.x*vec2.y - vec2.x*vec1.y);
		}

		friend double Pseudoscalar(double mA, double mB, double sinAlfa)
		{
			return (mA*mB*sinAlfa);
		}
	};

#endif // !_VECTOR2_
