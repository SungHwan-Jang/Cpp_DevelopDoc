#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		:mName(NULL)
		, mEntries(maxEntries)
		, mTimeSheet(NULL)
	{
		int nameLength = strlen(name) + 1;
		mName = new char[nameLength];
		memcpy(mName, name, nameLength);

		mTimeSheet = new int[mEntries];
		
		for (int i = 0; i < mEntries; i++) 
		{
			mTimeSheet[i] = 0;
		}
	}

	TimeSheet::~TimeSheet() 
	{
		delete[] mName;
		delete[] mTimeSheet;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10) 
		{
			mTimeSheet[mIndex] = timeInHours;
			mIndex++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		return mTimeSheet[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;

		for (int i = 0; i < mIndex; i++)
		{
			sum += mTimeSheet[i];
		}

		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		float average = 0;

		//average = (float)this->GetTotalTime() / (float)(mIndex + 1) ;
		float sum = 0;

		for (int i = 0; i < mIndex; i++)
		{
			sum += mTimeSheet[i];
		}

		average = sum / (mIndex + 1);

		return average;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		return 0.0f;
	}

	const std::string& TimeSheet::GetName() const
	{	
		return "temporary";
	}
}