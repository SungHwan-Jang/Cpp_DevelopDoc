#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn()
		:mWidth(0)
		,mHeight(0)
	{

	}

	RectangleLawn::RectangleLawn(double width, double height)
		:mWidth(width)
		,mHeight(height)
		,Lawn(width*height)
	{

	}

	RectangleLawn::~RectangleLawn()
	{

	}

	unsigned int RectangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(ceil(*mArea));
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const // 이것도 올림
	{
		double realFencesCount = (2 * mWidth + 2 * mHeight) / WIDTH_OF_FENCE;
		int roundFencesCount = static_cast<int>(realFencesCount);

		if (realFencesCount > roundFencesCount)
			return roundFencesCount + 1;
		else
			return roundFencesCount;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const // 이건 올림이어야함.
	{
		double realFencesCount = (2 * mWidth + 2 * mHeight) / WIDTH_OF_FENCE;

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