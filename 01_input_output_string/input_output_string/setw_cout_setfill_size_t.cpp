
#include "setw_cout_setfill_size_t.h"

using namespace std;

namespace lecture1
{

	void PrintMenuExample()
	{
		const float coffeePrice = 1.25f;
		const float breakfastComboPrice = 12.104f;

		const size_t nameColumnLength = 20;
		const size_t priceColumnLength = 10; // unsigned int Ÿ�� ������ ������ ��� (�Լ� �̿��� �����ϵ��� Ÿ���� ������ ���)

		cout << left << fixed << showpoint << setprecision(2); //���� �Ҽ��� 2�ڸ�, ��������

		cout << setfill('-') << setw(nameColumnLength + priceColumnLength) << "" << endl << setfill(' '); //setw�� ��� ���� ����, setfill�� ���� ĭ�� �������� ä���� ����
		cout << right; // ������ ����
		cout << setw(nameColumnLength) << coffeePrice << setw(priceColumnLength) << breakfastComboPrice << endl;


	}
}
