
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

		for (int i = (int)line.size() - 1; i >= 0; --i) //line.size() �� ������ �� 0���� �����̹Ƿ� -1 �ؾ��Ѵ�.
		{
			line += line[i]; //string object �� + ������ char�� �ϳ��� �ٿ� ������ �����̴�.
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

		istringstream inputStream("Pope Kim A12345678 80"); //��ǲ ��Ʈ�� ��Ʈ�� ��ü �ʱ�ȭ
		ostringstream outputStream; //�ƿ�ǲ ��Ʈ�� ��Ʈ�� ��ü ����

		//* ��Ʈ�� Ÿ�Ժ� �������� ���� ?

		inputStream >> firstName >> lastName >> studentID >> score; // ������ �������� �ܾ �����Ѵ�. (�⺻ cpp �Ľ� ��Ÿ��)
		outputStream << firstName << " " << lastName << " " << studentID << " " << score; //�ƿ�ǲ ��Ʈ���� ���� �־�д�.
		cout << outputStream.str() << endl; //�ƿ�ǲ ��Ʈ���� ���ڿ��� �Ͽ� stdout�� ���

	}
}