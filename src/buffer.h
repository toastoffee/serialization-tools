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
    explicit Buffer(int bufferSize = DEFAULT_BUFFER_MAX_SIZE);
    ~Buffer();

    // copy constructor and assignment
    Buffer(const Buffer& other);
    Buffer& operator=(const Buffer& other);

    // move constructor and assignment
    Buffer(Buffer&& other);
    Buffer& operator=(Buffer&& other);
    
private:
    Byte *data;


};

Buffer& Buffer::operator=(const Buffer &other) {

}

Buffer& Buffer::operator=(Buffer &&other) {

}


#endif //SERIALIZATION_TOOLS_BUFFER_H
