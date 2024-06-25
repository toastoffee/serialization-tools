#include <iostream>

#include "string_serializer.h"
#include "src/buffer.hpp"
#include "src/type_helper.h"
#include "src/byte_serializer.hpp"

struct A{
    int a;
    double b;
    float c;

    char* Serialize(){
        StringSerializer ss;
        ss << a << b << c;
        char *ret;
        ret = ss.GetString();
        return ret;
    }

    void UnSerialize(const char *s){
        StringSerializer ss(s, sizeof(A));
        ss >> a >> b >> c;
    }
};

int main() {
//    A a;
//    a.a = 10;
//    a.b = 20.2;
//    a.c = 30.3;
//    char *s = a.Serialize();
//
//
//    A b;
//    b.UnSerialize(s);
//
//    std::cout << b.a << " " << b.b << " " << b.c << std::endl;

    int a = 1;
    int *b = new int(2);
    int **c = &b;

    std::cout << IsPointer(a) << std::endl;
    std::cout << IsPointer(b) << std::endl;
    std::cout << IsPointer(c) << std::endl;


    return 0;
}
