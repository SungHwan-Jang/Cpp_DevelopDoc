//
// Created by redmk on 2024-02-22.
//

#include <iostream>
#include "initial_new_cpp_features.h"

struct MyStruct {
    int number;
};

/* call by value */
void swap_call_by_value(int arg1, int arg2) {
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

void swap_call_by_value(MyStruct argument) {
    argument.number = argument.number + 1;
}

/* call by pointer */
void swap_call_by_pointer(int* arg1, int* arg2) {
    // arg1, arg2는 null이 올수 있으며 null이 올 경우, 문제가 발생한다.
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

void swap_call_by_reference(int &a, int &b) {
    // a, b는 null이 올 수 없다. null check 불필요.
    // 내맘대로 *(a+1) 으로 읽어 올거야 같은 연산 불가 - 내가 소유하지 않은 메모리 참조 불가
    int temp = a;
    a = b;
    b = temp;
}

void initial_new_cpp_features(void) {
    
    /* c++98, modern c++ 에 추가됨 bool 형 */
    bool booleanDateValue = false;
    
    /* reference type - only c++ and c# */
    /* 포인터를 사용하는 좀 더 안전한 방법 하지만 자바만큼 제한적이지 않음 */
    
    int a = 1;
    int b = 2;
    swap_call_by_value(a, b);
    std::cout << "swap_call_by_value(a:1,b:2)" << std::endl;
    std::cout << "call by value a :" << a << " b: " << b << std::endl;
    
    swap_call_by_pointer(&a, &b);
    std::cout << "swap_call_by_pointer(a:1,b:2)" << std::endl;
    std::cout << "call by pointer a :" << a << " b: " << b << std::endl;
    
    /* JAVA 와 다르게 (int vs Integer 형과 다르게 ) 객체가 들어와도 call by value 처럼 동작한다. */
    MyStruct myStruct = {.number= 1};
    swap_call_by_value(myStruct);
    std::cout << "swap_call_by_value(struct num : 1)" << std::endl;
    std::cout << "call by value struct num  :" << myStruct.number << std::endl;
    
    /* 별칭을 의미한다 reference */
    int num1 = 10;
    int num2 = 20;
    int &refNum = num1;
    
    /* num1, num2, refNum의 값이 모두 20이 된다. */
    /* cpp compiler 특성으로 reference 는 선언한 순간 해당 주소값 만을 참조 하는 변수가 되며 해당 변수 처럼 이용이 가능하다 */
    refNum = num2;
    
    /* c로 번역하면 다음과 같다 */
    int c_num1 = 10;
    int c_num2 = 20;
    int* const c_refNum = &c_num1;
    *c_refNum = c_num2;
    
    swap_call_by_reference(num1, num2);
    std::cout << "swap_call_by_reference(num1:10,num2:20)" << std::endl;
    std::cout << "After swap, num1: " << num1 << ", num2: " << num2 << std::endl;
    
    /* NULL로 초기화 불가능 */
//    int& refNULL = NULL;
    
    /* 초기화 중에 반드시 선언되어야 함 */
//    int& refNot;

    /* coding 표준 + */
    /* output은 pointer로 입력은 참조자로 선언
     * bool DivideVector(Vector* result, const Vector& param1, const Vector& param2);
     * 이런 방식으로 코딩한다. */
}