#include "cin_getline_fail_eof_strlen_clear_ignore.h"

using namespace std;

namespace lecture1
{
	void AddIntergersExmaple()
	{
		/* scanf는 경계검사를 하지 않는다. cin 에는 무슨 문제가 있을까 ? -> 같은 null문자 경계검사 문제가 존재한다. -> 해결방법은 ?  */
		// char[4] str에 "HWAN"을 넣을 경우 발생하는 문제점.

		// C Style 해결 방법은 다음과 같다.
		/*
		char line[512];
		char temp[512];
		char firstName[4];

		if (fgets(line, 512, stdin) != NULL)  //fgets 는 마지막에 null을 넣어주는 기능까지 수행
		{
			if (sscanf(line, "%s", temp) == 1 && strlen(temp) < 4)
			{
				strcpy(firstName, temp);
			}
		}

		// cpp 에서 간단한 방법이 있다.
		/*
		char firstName[4];
		cin >> setw(4) >> firstName; // 4글자만 읽어오고 마지막에 null을 붙여준다.
		*/


		// 입력 데이터가 _______Hello____123 인 경우 space를 무시하고 sscanf는 읽어 들인다. (space로 구분한다는 것)
		// ex) sscanf(line, "%s%d", firstData, &secondData);
		// cpp 스타일인 cin << firstData << secondData 도 마찬가지로 공백을 기준으로 구분한다. 


		/* 스트림 상태 구분 */

		////C Style
		//
		//if (fgets(line, 10, stdin) != NULL)
		//{
		//	//...
		//}

		//cin >> line;
		//if (!cin.eof()) //End of file CHAR를 만나면 상태가 true가 된다.
		//{
		//	//...
		//}

		/*istream 상태 - namesapce :ios_base */

		// goodbit - good() 잘동작했다., eofbit - eof() 파일의 끝을 만났다., failbit - fail() 스트링을 정수로 읽는 경우 , badbit - bad() 잘 동작하지 않았다.
		// ex) 456abc 를 int로 읽는 경우 -> eof = x, fail = x
		// ex) 456 를 int로 읽는 경우 -> eof = x or o (콘솔은 \n 파일은 eof일수도 있어서) , fail = x
		// ex) abc 를 int로 읽는 경우 -> eof = x, fail = o
		// ex) eof 를 int로 읽는 경우 -> eof = o, fail = o

		/* 입력 버리기 */
		
		//cin.clear() stream 상태를 좋은(good)상태로 돌려줌

		//cin.ignore(x) 파일의 끝에 도달하거나 지정된 x 만큼 문자를 버리면 멈춤
		// -> int 입력받고 싶은데 char인 경우, 해당 문자열을 버리고 싶을때 
		//cin.ignore(10, '\n') -> 문자 10개를 버림 단, 그전에 \n를 만나면 멈춤
		//cin.ignore(LLONG_MAX, '\n') -> 최대 문자수를 버림, 그전에 \n 만나면 멈춤


		/* cin.get() 함수의 사용 */

		//\n 문자를 만나기 전까지 모든 문자를 가져옴
		//\n 문자는 입력 스트림에 남아있음.
		// get(firstName, 100); -> 99개(+null) 문자를 가져오거나 \n 까지의 문자를 가져옴 해당 문자를 firstName char 배열에 저장
		// get(firstName, 100, '#') -> 99개(+null) 문자를 가져오거나 '#' 문자가 나올떄가지 가져오고 배치

		/* cin.getline() 함수의 사용 */

		// \n 문자를 만나기 전까지 모든 문자를 가져옴, \n 문자는 입력 스트림에서 버림
		// getline(firstName, 100);
		// getline(firstName, 100, '#');

		cout << "+------------------------------+" << endl;
		cout << "|     Add Integers Example     |" << endl;
		cout << "+------------------------------+" << endl;

		int number;
		int sum = 0;

		while (true)
		{
			cout << "Please Enter Interger or EOF ";
			cin >> number;

			if (cin.eof())
			{
				break;
			}

			if (cin.fail())
			{
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(LLONG_MAX, '\n');
				continue;
			}

			sum += number;
		}

		cin.clear();

		cout << "The sum is" << sum << endl;
	}
	void ReverseInputString()
	{
		cout << "+------------------------------+" << endl;
		cout << "|    Reverse String Example    |" << endl;
		cout << "+------------------------------+" << endl;

		const int LINE_SIZE = 512;
		char line[LINE_SIZE];

		cout << "Please enter a string to reverse" << endl
			<< "or EOF to quit: ";

		cin.getline(line, LINE_SIZE);
		if (cin.fail()) //getline은 모든 문자열을 읽을 수 있다. 만일 fail이라면 eof를 읽은 것이다.
		{
			cin.clear();
			return;
		}

		char* p = line;
		char* q = line + strlen(line) - 1; //

		while (p < q)
		{
			char temp = *p;
			*p = *q;
			*q = temp;

			++p;
			--q;
		}

		cout << "Reversed string: " << line << endl;
	}
}