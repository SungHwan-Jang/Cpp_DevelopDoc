#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn()
	{

	}

	SquareLawn::SquareLawn(double width)
		:mWidth(width)
		,RectangleLawn(width, width)
	{

	}

	SquareLawn::~SquareLawn()
	{

	}

	unsigned int SquareLawn::GetArea() const
	{
		return static_cast<unsigned int>(ceil(*mArea));
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const // 이것도 올림
	{
		double realFencesCount = (4 * mWidth) / WIDTH_OF_FENCE;
		int roundFencesCount = static_cast<int>(realFencesCount);

		if (realFencesCount > roundFencesCount)
			return roundFencesCount + 1;
		else
			return roundFencesCount;
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const // 이건 올림이어야함.
	{
		double realFencesCount = (4 * mWidth) / WIDTH_OF_FENCE;

		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return static_cast<unsigned int>(ceil((realFencesCount * WIDTH_OF_FENCE) * 6));
			break;
		case lab5::SPRUCE:
			return static_cast<unsigned int>(ceil((realFencesCount * WIDTH_OF_FENCE) * 7));
			break;
		default:
			return 0;
			break;
		}
	}

}