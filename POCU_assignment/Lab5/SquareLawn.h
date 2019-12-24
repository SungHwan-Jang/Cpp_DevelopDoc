#pragma once
#include "RectangleLawn.h"
#include "IFenceable.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	private:
		double mWidth;
	public:
		SquareLawn();
		SquareLawn(double width);
		virtual ~SquareLawn();

		virtual unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}