/**
  ******************************************************************************
  * @file           : byte_serializer.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/25
  ******************************************************************************
  */



#ifndef SERIALIZATION_TOOLS_BYTE_SERIALIZER_HPP
#define SERIALIZATION_TOOLS_BYTE_SERIALIZER_HPP

#include "buffer.hpp"

typedef char                int8;
typedef unsigned char       uint8;
typedef short               int16;
typedef unsigned short      uint16;
typedef int                 int32;
typedef unsigned int        uint32;
typedef float               float32;
typedef double              float64;
typedef long long           int64;
typedef unsigned long long  uint64;


class ByteSerializer {
public:
    ByteSerializer();
    explicit ByteSerializer(Buffer buf);

    // basic types write
    inline void Write(int8 val) { _buf.Write(val); }
    inline void Write(uint8 val) { _buf.Write(val); }
    inline void Write(int16 val) { _buf.Write(val); }
    inline void Write(uint16 val) { _buf.Write(val); }
    inline void Write(int32 val) { _buf.Write(val); }
    inline void Write(uint32 val) { _buf.Write(val); }
    inline void Write(float32 val) { _buf.Write(val); }
    inline void Write(float64 val) { _buf.Write(val); }
    inline void Write(int64 val) { _buf.Write(val); }
    inline void Write(uint64 val) { _buf.Write(val); }
    inline void Write(bool val) { _buf.Write(val); }

    // array write
//    inline void Write(int8 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(uint8 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(int16 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(uint16 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void WriteArr(int32 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(uint32 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(float32 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(float64 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(int64 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(uint64 arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }
//    inline void Write(bool arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }

    template<class T>
    inline void Write(T arr[], int count){ for (int i = 0; i < count; i++) Write(arr[i]); }

    // basic types read
    inline void Read(int8 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(uint8 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(int16 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(uint16 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(int32 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(uint32 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(float32 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(float64 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(int64 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(uint64 &val){ _buf.Read(val, _offset); _offset += sizeof(val); }
    inline void Read(bool &val){ _buf.Read(val, _offset); _offset += sizeof(val); }

    // array read
//    inline void Read(int8 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(uint8 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(int16 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(uint16 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(int32 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(uint32 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(float32 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(float64 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(int64 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(uint64 arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }
//    inline void Read(bool arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }

    template<class T>
    inline void Read(T arr[], int count){ for (int i = 0; i < count; i++) Read(arr[i]); }

    Buffer GetBuffer();

private:
    Buffer _buf;
    int _offset;
};

ByteSerializer::ByteSerializer() :
    _offset(0),
    _buf() { }

ByteSerializer::ByteSerializer(Buffer buf) :
    _buf(std::move(buf)),
    _offset(0) { }

Buffer ByteSerializer::GetBuffer() {
    return _buf;
}


#endif //SERIALIZATION_TOOLS_BYTE_SERIALIZER_HPP
