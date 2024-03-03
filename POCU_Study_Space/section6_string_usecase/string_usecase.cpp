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
    
    /* 주로 size를 쓴다 STL container 때문..? 이라고 한다 "HWAN" 인경우 size 는 4 */
    std::cout << fullName.size() << std::endl;
    std::cout << fullName.length() << std::endl;
    
    /* 해당 string이 가지고 있는 문자 배열의 시작 주소를 가리키는 포인터를 반환 */
    std::string line;
    line = "HELLO WORLD!";
    const char* cLine = line.c_str(); /* string class가 내부적으로 size, 내용 등을 관리하니 const로 받아라  */
    std::cout << cLine << std::endl;
    
    /* string class
     * line[2] 의 경우 [2] 가 사실 함수 호출이다. 따라서 반환값을 전달하는데
     * 반환값에 = 'E'와 같은 수행을 하고 있고 실제로 원본 값이 바뀐다.
     * 따라서 해당 반환 값은 참조를 반환 하고 있구나 라고 알 수 있다. */
    char letter = line[1U];
    std::cout << letter << std::endl;
    line[2] = 'E';
    std::cout << line << std::endl;
    
    /* 한줄 읽기 */
//    std::string mailHeader;
    /* getline(std::cin, mailHeader); */
//    (void) getline(std::cin, mailHeader, '@'); /* delimiter @ 까지 읽는다. @는 버려진다. */
//    std::cout << mailHeader << std::endl; // Added this line to print mailHeader
    
    
    /* std::isringstream - cin과 비슷 키보드 대신 string으로 읽어옴 sscanf와 비슷 */
    /* std::osringstream - cout과 비슷 키보드 대신 string으로 출력함 sprintf와 비슷 */
    /* 현업의 c++ application에서는 여전히 성능상의 이유로 많은 c함수들이 사용 */
    /* string class 의 작동 방식
     * platform, compiler 마다 다르겠지만 예를 들면,
     * 16 byte 힙메모리 할당 그 이상 추가 될때 새로 32byte 메모리 할당 이후 복사 이전 힙 메모리는 해제하는 과정으로 수행됨
     * 힙 메모리 할당은 느리고 메모리 단편화 문제가 발생 내부 버퍼의 증가는 멀티 스레드 환경에서 안전하지 않을 수 있다.
     * 그래서 여전히 sprintf와 함계 char[] 를 매우 많이 사용 */
    
    std::cout << line << std::endl;
    
    for (int i = (int) line.size(); i >= 0; --i) {
        line += line[i];
    }
    
    std::cout << line << std::endl;
    
}

