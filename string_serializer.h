/**
  ******************************************************************************
  * @file           : string_serializer.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/23
  ******************************************************************************
  */



#ifndef SERIALIZATION_TOOLS_STRING_SERIALIZER_H
#define SERIALIZATION_TOOLS_STRING_SERIALIZER_H

#define DEFAULT_SERIALIZED_BUF_SIZE 1024

#include <memory>

class StringSerializer {
public:
    explicit StringSerializer(int bufSize = DEFAULT_SERIALIZED_BUF_SIZE);
    ~StringSerializer();

    char* GetString();

    template<typename T>
    StringSerializer& operator<<(T t);

    template<typename T>
    StringSerializer& operator>>(T& t);

private:
    char *_buf;
    int _bufSize, _dataSize;
};

StringSerializer::StringSerializer(int bufSize) : _bufSize(bufSize), _dataSize(0) {
    _buf = new char[_bufSize];
    memset(_buf,0x00, _bufSize);
}

StringSerializer::~StringSerializer() {
    delete[] _buf;
}

char *StringSerializer::GetString() {
    return _buf;
}

template<typename T>
StringSerializer &StringSerializer::operator<<(T t) {
    memcpy(_buf + _dataSize, (char*)&t, sizeof(t));
    _dataSize += sizeof(t);
    return *this;
}

template<typename T>
StringSerializer &StringSerializer::operator>>(T &t) {
    memcpy((char*)&t, _buf + _dataSize, sizeof(t));
    _dataSize += sizeof(t);
    return *this;
}


#endif //SERIALIZATION_TOOLS_STRING_SERIALIZER_H
