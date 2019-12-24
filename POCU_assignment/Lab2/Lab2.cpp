#define _CIN_TEST_ 1
// #define _CIN_GETLINE_TEST_ 2

#include "Lab2.h"

using namespace std;

namespace lab2
{
	const char* OCT_MENU = "oct";
	const char* DEC_MENU = "dec";
	const char* HEX_MENU = "hex";

	const char* MAX_MENU = "max: ";

	const size_t OCT_LENGTH = 12;
	const size_t DEC_LENGTH = 10;
	const size_t HEX_LENGTH = 8;

	const size_t FIXED_FLOAT_SECTION = 14;
	const size_t SIGN_SECTION = 6;

	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int value = 0;

		out << right << setfill(' ');
		out << setw(OCT_LENGTH) << OCT_MENU << ' '
			<< setw(DEC_LENGTH) << DEC_MENU << ' '
			<< setw(HEX_LENGTH) << HEX_MENU << endl;

		out << setfill('-');
		out << setw(OCT_LENGTH + 1) << ' '
			<< setw(DEC_LENGTH + 1) << ' '
			<< setw(HEX_LENGTH + 1) << '\n';

#if _CIN_TEST_
		while (true)
		{
			if (in.eof() == true) // 스트림의 끝이다!
			{
				break;
			}
			else
			{
				in >> value;

				if (in.fail() == true) // 원하지 않는 값을 만났다!
				{
					in.clear();
					in.ignore(LLONG_MAX, ' '); // 'f','f','\n','1','2' 검출 불가.
					continue;
				}

				out << setfill(' ') << uppercase;
				out << setw(OCT_LENGTH) << oct << value << ' '
					<< setw(DEC_LENGTH) << dec << value << ' '
					<< setw(HEX_LENGTH) << hex << value << endl;
			}

		}

#elif _CIN_GETLINE_TEST_
		// cin.getline() 으로 파싱해야 하나 ?

		cin.getline(str, LLONG_MAX, '\0');

		cout << str;

#endif
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float value = 0;
		float maxValue = FLT_MIN_10_EXP;
		char sign = '+';

		out << fixed << showpoint << setprecision(3);

		while (true)
		{
			if (in.eof() == true)
			{
				// max 값 출력
				out << setw(SIGN_SECTION - 1) << MAX_MENU << sign 
					<< setw(FIXED_FLOAT_SECTION) << abs(maxValue) << endl;

				break;
			}
			else
			{
				in >> value;

				if (in.fail() == true)
				{
					in.clear();
					in.ignore(LLONG_MAX, ' '); // 'f','f','\n','1','2' 검출 불가.

					continue;
				}

				if (maxValue == FLT_MIN_10_EXP)
				{
					maxValue = value;
				}
				else
				{
					if (maxValue < value)
					{
						maxValue = value;
					}
				}

				if (value >= 0)
				{
					sign = '+';
				}
				else
				{
					sign = '-';
				}

				out << setfill(' ');
				out << setw(SIGN_SECTION) << sign
					<< setw(FIXED_FLOAT_SECTION) << abs(value) << endl;
			}
		}
	}
}