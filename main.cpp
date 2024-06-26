#include <iostream>
#include <utility>

#include "src/buffer.hpp"
#include "src/type_helper.h"
#include "src/byte_serializer.hpp"

struct B{
    int a;
    double b;
    float c;
    int arr[3];

    Buffer Serialize() const{
        ByteSerializer bs;
        bs.Write(a);
        bs.Write(b);
        bs.Write(c);
        bs.Write(arr,3);
        return bs.GetBuffer();
    }

    void UnSerialize(Buffer buffer){
        ByteSerializer bs(std::move(buffer));
        bs.Read(a);
        bs.Read(b);
        bs.Read(c);
        bs.Read(arr,3);
    }

};

int main() {

    B test1;
    test1.a = 10;
    test1.b = 20.2;
    test1.c = 30.3;
    test1.arr[0] = 1;
    test1.arr[1] = 2;
    test1.arr[2] = 3;

    Buffer buf1 = test1.Serialize();

    B test2;
    test2.UnSerialize(buf1);

    std::cout << test2.a << " " << test2.b << " " << test2.c << std::endl;
    std::cout << test2.arr[0] << test2.arr[1] << test2.arr[2] << std::endl;


    return 0;
}
