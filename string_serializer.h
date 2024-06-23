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


#endif //SERIALIZATION_TOOLS_STRING_SERIALIZER_H
