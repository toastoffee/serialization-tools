# serialization-tools
a c++11 tool of serialization

### one-file

Include the byte_serializer.hpp to use

```c++
#include "byte_serializer.hpp"
```

### pact-buffer

the variable will serialize into byte buffer and you can store it

```c++
int a = 1;
double b = 2.0;
float c = 3.0;

// construct byteSerializer and write variables
ByteSerializer bs;
bs.Write(a);
bs.Write(b);
bs.Write(c);

// get the buffer written
Buffer buf = bs.GetBuffer();
```

### serialize and unserialize struct

```c++
struct B{
    int a;
    double b;
    bool c[3];

    Buffer Serialize() const{
        ByteSerializer bs;
        bs.Write(a);
        bs.Write(b);
        bs.Write(c, 3);
        return bs.GetBuffer();
    }

    void UnSerialize(Buffer buffer){
        ByteSerializer bs(std::move(buffer));
        bs.Read(a);
        bs.Read(b);
        bs.Read(c, 3);
    }
};
```

