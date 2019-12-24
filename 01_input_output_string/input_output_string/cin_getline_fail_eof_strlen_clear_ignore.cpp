#include "cin_getline_fail_eof_strlen_clear_ignore.h"

using namespace std;

namespace lecture1
{
	void AddIntergersExmaple()
	{
		/* scanf�� ���˻縦 ���� �ʴ´�. cin ���� ���� ������ ������ ? -> ���� null���� ���˻� ������ �����Ѵ�. -> �ذ����� ?  */
		// char[4] str�� "HWAN"�� ���� ��� �߻��ϴ� ������.

		// C Style �ذ� ����� ������ ����.
		/*
		char line[512];
		char temp[512];
		char firstName[4];

		if (fgets(line, 512, stdin) != NULL)  //fgets �� �������� null�� �־��ִ� ��ɱ��� ����
		{
			if (sscanf(line, "%s", temp) == 1 && strlen(temp) < 4)
			{
				strcpy(firstName, temp);
			}
		}

		// cpp ���� ������ ����� �ִ�.
		/*
		char firstName[4];
		cin >> setw(4) >> firstName; // 4���ڸ� �о���� �������� null�� �ٿ��ش�.
		*/


		// �Է� �����Ͱ� _______Hello____123 �� ��� space�� �����ϰ� sscanf�� �о� ���δ�. (space�� �����Ѵٴ� ��)
		// ex) sscanf(line, "%s%d", firstData, &secondData);
		// cpp ��Ÿ���� cin << firstData << secondData �� ���������� ������ �������� �����Ѵ�. 


		/* ��Ʈ�� ���� ���� */

		////C Style
		//
		//if (fgets(line, 10, stdin) != NULL)
		//{
		//	//...
		//}

		//cin >> line;
		//if (!cin.eof()) //End of file CHAR�� ������ ���°� true�� �ȴ�.
		//{
		//	//...
		//}

		/*istream ���� - namesapce :ios_base */

		// goodbit - good() �ߵ����ߴ�., eofbit - eof() ������ ���� ������., failbit - fail() ��Ʈ���� ������ �д� ��� , badbit - bad() �� �������� �ʾҴ�.
		// ex) 456abc �� int�� �д� ��� -> eof = x, fail = x
		// ex) 456 �� int�� �д� ��� -> eof = x or o (�ܼ��� \n ������ eof�ϼ��� �־) , fail = x
		// ex) abc �� int�� �д� ��� -> eof = x, fail = o
		// ex) eof �� int�� �д� ��� -> eof = o, fail = o

		/* �Է� ������ */
		
		//cin.clear() stream ���¸� ����(good)���·� ������

		//cin.ignore(x) ������ ���� �����ϰų� ������ x ��ŭ ���ڸ� ������ ����
		// -> int �Է¹ް� ������ char�� ���, �ش� ���ڿ��� ������ ������ 
		//cin.ignore(10, '\n') -> ���� 10���� ���� ��, ������ \n�� ������ ����
		//cin.ignore(LLONG_MAX, '\n') -> �ִ� ���ڼ��� ����, ������ \n ������ ����


		/* cin.get() �Լ��� ��� */

		//\n ���ڸ� ������ ������ ��� ���ڸ� ������
		//\n ���ڴ� �Է� ��Ʈ���� ��������.
		// get(firstName, 100); -> 99��(+null) ���ڸ� �������ų� \n ������ ���ڸ� ������ �ش� ���ڸ� firstName char �迭�� ����
		// get(firstName, 100, '#') -> 99��(+null) ���ڸ� �������ų� '#' ���ڰ� ���Ë����� �������� ��ġ

		/* cin.getline() �Լ��� ��� */

		// \n ���ڸ� ������ ������ ��� ���ڸ� ������, \n ���ڴ� �Է� ��Ʈ������ ����
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
		if (cin.fail()) //getline�� ��� ���ڿ��� ���� �� �ִ�. ���� fail�̶�� eof�� ���� ���̴�.
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