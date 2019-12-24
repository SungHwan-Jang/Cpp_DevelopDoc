#pragma once

#include "eGrassType.h"
#include <cmath>

namespace lab5
{
	class Lawn
	{
	protected:
		const double PI = 3.14;
		const double AREA_OF_GRASS = 0.3;
		const double WIDTH_OF_FENCE = 0.25;
		
	public:
		double* mArea = new double(0);

		Lawn();
		Lawn(double area);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;
		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
	};
}