//
// Created by redmk on 2024-02-18.
//

#include <iostream>
#include "output_test.h"

using namespace std;

namespace output_test {
    void output_test(void) {
        /* << is insertion operation */
        cout << "hello world" << endl;
        cout << "Hello" << 123 << endl
             << " endl test " << endl;
        cout << endl;
        
        /* output formatting - manipulator */
        int number = 1255;
        
        cout << showbase << hex << number << endl; // 0x 보이게
        cout << endl;
        
        cout << dec << showpos << number << endl; // + 보이게
        cout << dec << noshowpos << number << endl; // + 안보이게
        cout << dec << number << endl;
        cout << hex << number << endl;
        cout << oct << number << endl;
        cout << endl;
        
        cout << hex << uppercase << number << endl; // 0x4E7 대문자
        cout << hex << nouppercase << number << endl; // 04e7 소문자
        
        /* 이후 setw 와 같이 글자수나 나머지에 채우는 등 다양한 옵션이 있으니 필요할 때 찾아보길 */
    }
}

