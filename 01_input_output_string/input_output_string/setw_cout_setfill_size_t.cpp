
#include "setw_cout_setfill_size_t.h"

using namespace std;

namespace lecture1
{

	void PrintMenuExample()
	{
		const float coffeePrice = 1.25f;
		const float breakfastComboPrice = 12.104f;

		const size_t nameColumnLength = 20;
		const size_t priceColumnLength = 10; // unsigned int 타입 사이즈 지정시 사용 (함수 이용이 용이하도록 타입을 적절히 사용)

		cout << left << fixed << showpoint << setprecision(2); //고정 소수점 2자리, 왼쪽정렬

		cout << setfill('-') << setw(nameColumnLength + priceColumnLength) << "" << endl << setfill(' '); //setw는 출력 길이 설정, setfill은 공백 칸을 무엇으로 채울지 결정
		cout << right; // 오른쪽 정렬
		cout << setw(nameColumnLength) << coffeePrice << setw(priceColumnLength) << breakfastComboPrice << endl;


	}
}
