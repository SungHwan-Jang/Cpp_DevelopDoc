//
// Created by redmk on 2024-02-22.
//

#include <iostream>
#include "initial_new_cpp_features.h"

struct MyStruct{
    int number;
};

/* call by value */
void swap_call_by_value(int arg1, int arg2){
    int temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

void swap_call_by_value(MyStruct argument){
    argument.number = argument.number+1;
}

/* call by pointer */
void swap_call_by_pointer(int* arg1, int* arg2){
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

void swap_call_by_reference(int& a, int& b){

}

void initial_new_cpp_features(void){

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
}