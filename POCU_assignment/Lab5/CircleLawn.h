#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class CircleLawn : public Lawn, public IFenceable
	{
	private:
		double mRadius;
	public:
		CircleLawn();
		CircleLawn(double radius);
		virtual ~CircleLawn();

		unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}