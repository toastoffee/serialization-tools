/**
  ******************************************************************************
  * @file           : buffer.cpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/25
  ******************************************************************************
  */



#include "buffer.h"

Buffer::Buffer(int BufferCapacity) :
    _data(new Byte[BufferCapacity] {0}),
    _bufCapacity(BufferCapacity),
    _bufSize(0) {
}

Buffer::~Buffer() {
    delete[] _data;
}

Buffer::Buffer(const Buffer& other){
    _bufCapacity = other.GetCapacity();
    _bufSize = other.GetSize();
    _data = new Byte [_bufCapacity];
    memcpy(_data, other.GetData(), _bufSize);
}

Buffer& Buffer::operator=(const Buffer &other) {
    if(this == &other){
        return *this;
    }

    delete[] _data;
    _bufCapacity = other.GetCapacity();
    _bufSize = other.GetSize();
    _data = new Byte [_bufCapacity];
    memcpy(_data, other.GetData(), _bufSize);

    return *this;
}

Buffer::Buffer(Buffer &&other) {
    _bufCapacity = other.GetCapacity();
    _bufSize = other.GetSize();
    _data = other.GetData();
}

Buffer& Buffer::operator=(Buffer &&other) {
    _bufCapacity = other.GetCapacity();
    _bufSize = other.GetSize();
    _data = other.GetData();

    return *this;
}
