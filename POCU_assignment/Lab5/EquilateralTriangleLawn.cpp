#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn()
		:mLength(0)
	{

	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(double length)
		:mLength(length)
		,Lawn(length * length * 0.5)
	{

	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{

	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(ceil(*mArea));
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const // 이것도 올림
	{
		double realFencesCount = (3 * mLength) / WIDTH_OF_FENCE;
		int roundFencesCount = static_cast<int>(realFencesCount);

		if (realFencesCount > roundFencesCount)
			return roundFencesCount + 1;
		else
			return roundFencesCount;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const // 이건 올림이어야함.
	{
		double realFencesCount = (3 * mLength) / WIDTH_OF_FENCE;

		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return static_cast<unsigned int>(ceil(realFencesCount * WIDTH_OF_FENCE * 6.0));
			break;
		case lab5::SPRUCE:
			return static_cast<unsigned int>(ceil(realFencesCount * WIDTH_OF_FENCE * 7.0));
			break;
		default:
			return 0;
			break;
		}
	}

}