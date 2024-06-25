/**
  ******************************************************************************
  * @file           : buffer.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/25
  ******************************************************************************
  */



#ifndef SERIALIZATION_TOOLS_BUFFER_H
#define SERIALIZATION_TOOLS_BUFFER_H


#include <memory>

typedef unsigned char Byte;

#define DEFAULT_BUFFER_MAX_SIZE 1024

class Buffer {
    explicit Buffer(int bufferCapacity = DEFAULT_BUFFER_MAX_SIZE);
    ~Buffer();

    // copy constructor and assignment
    Buffer(const Buffer& other);
    Buffer& operator=(const Buffer& other);

    // move constructor and assignment
    Buffer(Buffer&& other);
    Buffer& operator=(Buffer&& other);

    template<typename T>
    void Write(T value, int offset);

    template<typename T>
    void Write(T Value);
    

    int GetCapacity() const { return _bufCapacity; }
    int GetSize() const { return _bufSize; }
    Byte* GetData() const { return _data; }

private:
    Byte *_data;
    int _bufCapacity,_bufSize;

};

template<typename T>
void Buffer::Write(const T value, int offset) {

    if(offset < 0){
        throw std::length_error("can't write buffer to negative offset");
    }

    memcpy(_data + offset, &value, sizeof(T));

    _bufSize = (offset + sizeof(T) > _bufSize) ? (offset + sizeof(T)) : _bufSize;
}

template<typename T>
void Buffer::Write(const T value) {
    Write(value, _bufSize);
}



#endif //SERIALIZATION_TOOLS_BUFFER_H
