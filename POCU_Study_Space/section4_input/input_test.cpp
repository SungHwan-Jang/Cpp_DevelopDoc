//
// Created by redmk on 2024-02-18.
//
#include "input_test.h"
#include "debug.h"

using namespace std;


namespace intput_test {
    void input_test(void) {
        char firstName[4];
        cin >> firstName;
        
        /* eof - end of file  */
        if(!cin.eof()){
        
        }
        
        /* 입력을 여러 신호 state로 보는 방법이 있음 ( 누락 ) */
        
        /* stream을 good state로 돌려줌 */
        cin.clear();
        
        /* 문자 1개 버림 */
        cin.ignore();
        /* 문자 2개 버림 */
        cin.ignore(2);
    }
}