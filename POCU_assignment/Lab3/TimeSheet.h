#pragma once
#ifndef _TIME_SHEET_
#define _TIME_SHEET_

#include <string>

#endif // !_TIME_SHEET_

namespace lab3 
{
	class TimeSheet 
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries); // TimeSheet p("po",3); -> p.AddTime(3); [3] , p.AddTime(5); [3, 5]
		~TimeSheet();
		void AddTime(int timeInHours); // add w time 1 to 10
		int GetTimeEntry(unsigned int index) const; //find w time. if index X -> return -1
		int GetTotalTime() const; // get all time
		float GetAverageTime() const; // 
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		char* mName;
		int mEntries;
		int* mTimeSheet;
		int mIndex = 0;
	};
}
