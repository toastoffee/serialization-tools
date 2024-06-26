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

class ByteSerializer {
public:
    ByteSerializer();
    explicit ByteSerializer(Buffer buf);

    template<typename T> void Write(T t);

    template<typename T> void Read(T& t);

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

template<typename T>
void ByteSerializer::Write(T t) {
    _buf.Write(t);
}

template<typename T>
void ByteSerializer::Read(T &t) {
//    t = _buf.Read<T>(_offset);
//    _offset += sizeof(t);

    _buf.Read(t, _offset);
    _offset += sizeof(t);
}


Buffer ByteSerializer::GetBuffer() {
    return _buf;
}

#endif //SERIALIZATION_TOOLS_BYTE_SERIALIZER_HPP
