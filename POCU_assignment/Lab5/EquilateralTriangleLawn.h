#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	private:
		double mLength;
	public:
		EquilateralTriangleLawn();
		EquilateralTriangleLawn(double length);
		virtual ~EquilateralTriangleLawn();

		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}