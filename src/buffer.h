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


    int GetCapacity() const { return _bufCapacity; }
    int GetSize() const { return _bufSize; }
    Byte* GetData() const { return _data; }

private:
    Byte *_data;
    int _bufCapacity,_bufSize;

};



#endif //SERIALIZATION_TOOLS_BUFFER_H
