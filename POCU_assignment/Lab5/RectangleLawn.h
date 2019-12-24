#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	private:
		double mWidth;
		double mHeight;
	public:
		RectangleLawn();
		RectangleLawn(double width, double height);
		virtual ~RectangleLawn();

		virtual unsigned int GetArea() const;
		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}