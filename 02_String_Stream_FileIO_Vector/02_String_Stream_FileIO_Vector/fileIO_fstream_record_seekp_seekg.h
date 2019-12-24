#pragma once
#ifndef _FILE_IO_
#define _FILE_IO_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#endif // !_FILE_IO_

struct Record
{
	std::string FirstName;
	std::string LastName;
	std::string StudentID;
	std::string Score;
};


namespace sample2 
{
	Record ReadRecord(std::istream& stream, bool bPrompt);

	void WriteFileRecord(std::fstream& outputStream, const Record& record);

	void DisplayRecords(std::fstream& fileStream);

	void ManageRecordsExample();
}