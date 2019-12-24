#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn()
		:mRadius(0)
	{

	}

	CircleLawn::CircleLawn(double radius)
		:mRadius(radius)
		,Lawn(radius * radius * PI)
	{

	}

	CircleLawn::~CircleLawn()
	{

	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(ceil(*mArea));
	}

	unsigned int CircleLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}