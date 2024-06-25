#include <iostream>
#include <utility>

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

struct B{
    int a;
    double b;
    float c;

    Buffer Serialize() const{
        ByteSerializer bs;
        bs.Write(a);
        bs.Write(b);
        bs.Write(c);
        return bs.GetBuffer();
    }

    void UnSerialize(Buffer buffer){
        ByteSerializer bs(std::move(buffer));
        bs.Read(a);
        bs.Read(b);
        bs.Read(c);
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

    B test1;
    test1.a = 10;
    test1.b = 20.2;
    test1.c = 30.3;
    Buffer buf1 = test1.Serialize();

    B test2;
    test2.UnSerialize(buf1);

    std::cout << test2.a << " " << test2.b << " " << test2.c << std::endl;

    return 0;
}
