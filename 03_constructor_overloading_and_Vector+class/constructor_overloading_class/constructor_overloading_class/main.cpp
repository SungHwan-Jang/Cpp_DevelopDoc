// constructor_overloading_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "CopyConstructorExample.h"
#include "FunctionOverloadExample.h"
#include "InheritanceExample.h"
#include "OperatorOverloadExample.h"
/*
기본적으로 new, delete - malloc, free 의 차이점은 생성자와 소멸자를 호출하냐 마냐의 차이이다.
생성자와 소멸자에서 메모리 반환에 대한 내용을 담는 순간 new와 delete는 메모리 맄에 안전하다.

일반적으로 RALL 이라하여 메소드 호출에서 힙에 할당한 메모리는 해당 힙에서 해제시켜줘야 안전하다.
다만 FACTOTY 패턴이라고 하여 힙 할당 메모리를 반환하는 기법이 존재한다. ex) factort.create(); -> 개체 반환
*/

/*
자바의 경우 Vector[] a = new Vector[10] 은 10개의 포인터를 힙에 만듦
CPP의 경우 Vector[] *a = new Vector[10]은 10개의 벡터 개체를 힙에 만듦 첫 주소를 a 전달
			Vector[] **a = new Vector*[10]의 경우 10개의 포인터를 힘에 만듦.
*/
using namespace samples;

int main()
{

	// 1. Copy Constructor with char Array
	CopyConstructorExample();

	// 2. Multiplying with a Vector or Scalar in Vector Class
	FunctionOverloadExample();

	// 3. Multiplying with a Vector or Scalar in Vector Class
	OperatorOverloadExample();

	// 4. Animal, Cat, Dog Classes
	InheritanceExample();
}