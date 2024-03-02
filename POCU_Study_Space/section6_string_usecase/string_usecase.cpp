//
// Created by redmk on 2024-03-03.
//

#include <string>
#include <iostream>
#include "string_usecase.h"

void string_usecase_test() {
    /* char line[256];
     * cin.getline(line, 256); 의 경우 아래 두 경우에 작동하지 않음
     * 1. 아무것도 읽지 못했을때,
     * 2. 한 줄에 문자가 256자 이상일 때 ( 즉 버퍼의 크기가 충분히 크지 않을 때 ) */
    
    /* std::string class를 이용한 문자열은 길이가 증가할 수 있음 */
    std::string firstName = "[JSH] ";
    std::string fullName = "SUNG HWAN";
    
    fullName = firstName;
    fullName += " JANG";
    
    std::cout << fullName << std::endl;
    
    std::string stringA = "A";
    std::string stringB = "B";
    
    if (stringA == stringB) {
        std::cout << "equal string" << std::endl;
    }
    
    if (stringA < stringB) {
        /* 사전 상의 순서를 비교 */
        std::cout << "stringA is fast" << std::endl;
    }
    
    /* 주로 size를 쓴다 STL 때문..? 이라고 한다 */
    std::cout << fullName.size() << std::endl;
    std::cout << fullName.length() << std::endl;
    
    /* 해당 string이 가지고 있는 문자 배열의 시작 주소를 가리키는 포인터를 반환 */
    std::string line;
    line = "HELLO WORLD!";
    const char* cLine = line.c_str();
    std::cout << cLine << std::endl;
    
    
}

