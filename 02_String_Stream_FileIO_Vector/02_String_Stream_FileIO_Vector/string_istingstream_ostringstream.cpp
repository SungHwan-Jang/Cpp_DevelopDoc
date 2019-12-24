
#include "string_istingstream_ostringstream.h"

using namespace std;

namespace sample 
{
	void MirrorString() 
	{
		cout << "+------------------------------+" << endl;
		cout << "|    Mirror String Example     |" << endl;
		cout << "+------------------------------+" << endl;

		string line = "Hello World!";

		cout << "string to mirror: " << line << endl;

		for (int i = (int)line.size() - 1; i >= 0; --i) //line.size() 는 문자의 수 0부터 시작이므로 -1 해야한다.
		{
			line += line[i]; //string object 는 + 연산이 char를 하나씩 붙여 나가는 연산이다.
		}
		cout << "mirrored string" << line << endl;
	}

	void PrintRecord()
	{
		cout << "+------------------------------+" << endl;
		cout << "|     Print Record Example     |" << endl;
		cout << "+------------------------------+" << endl;

		string firstName;
		string lastName;
		string studentID;
		int score;

		istringstream inputStream("Pope Kim A12345678 80"); //인풋 스트링 스트림 개체 초기화
		ostringstream outputStream; //아웃풋 스트링 스트림 개체 생성

		//* 스트림 타입별 차이점은 뭔가 ?

		inputStream >> firstName >> lastName >> studentID >> score; // 공백을 기준으로 단어를 구별한다. (기본 cpp 파싱 스타일)
		outputStream << firstName << " " << lastName << " " << studentID << " " << score; //아웃풋 스트림에 값을 넣어둔다.
		cout << outputStream.str() << endl; //아웃풋 스트림을 문자열로 하여 stdout에 출력

	}
}