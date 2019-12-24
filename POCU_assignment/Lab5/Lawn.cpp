#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
		*mArea = 0;
	}
	Lawn::Lawn(double area)
	{
		*mArea = area;
	}

	Lawn::~Lawn()
	{
		delete mArea;
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		double defualtPrice;
		unsigned int getArea = static_cast<unsigned int>(ceil(*mArea));

		switch (grassType) //this is m^2 price | one roll is 0.3m^2
		{
		case BERMUDA:
			defualtPrice = 800.0;
			break;
		case BAHIA:
			defualtPrice = 500.0;
			break;
		case BENTGRASS:
			defualtPrice = 300.0;
			break;
		case PERENNIAL_RYEGRASS:
			defualtPrice = 250.0;
			break;
		case ST_AUGUSTINE:
			defualtPrice = 450.0;
			break;
		default:
			defualtPrice = 0.0;
			break;
		}

		return static_cast<unsigned int>(ceil(defualtPrice * getArea * 0.3) / 100.0);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const // 이건 올림이어야함
	{
		unsigned int getArea = static_cast<unsigned int>(ceil(*mArea));
		double area = static_cast<double>(getArea) / AREA_OF_GRASS;
		return static_cast<unsigned int>(ceil(area));
	}
}