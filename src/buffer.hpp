/**
  ******************************************************************************
  * @file           : buffer.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/25
  ******************************************************************************
  */



#ifndef SERIALIZATION_TOOLS_BUFFER_HPP
#define SERIALIZATION_TOOLS_BUFFER_HPP


#include <memory>

typedef unsigned char Byte;

#define DEFAULT_BUFFER_MAX_SIZE 1024

class Buffer {
public:
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

    template<typename T>
    T Read(int offset);

    int GetCapacity() const { return _bufCapacity; }
    int GetSize() const { return _bufSize; }
    Byte* GetData() const { return _data; }

private:
    void ExpandCapacity();

private:
    Byte *_data;
    int _bufCapacity,_bufSize;

};


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

template<typename T>
void Buffer::Write(const T value, int offset) {

    if(offset < 0){
        throw std::length_error("can't write buffer to negative offset");
    }

    while(_bufCapacity < offset + sizeof(T)){
        ExpandCapacity();
    }

    memcpy(_data + offset, &value, sizeof(T));

    _bufSize = (offset + sizeof(T) > _bufSize) ? (offset + sizeof(T)) : _bufSize;
}

template<typename T>
void Buffer::Write(const T value) {
    Write(value, _bufSize);
}

template<typename T>
T Buffer::Read(int offset) {

    if(offset + sizeof(T) >= _bufCapacity || offset < 0){
        throw std::length_error("buffer read out of bounds");
    }

    return static_cast<T>(_data[offset]);
}

void Buffer::ExpandCapacity() {

    // exponential expand
    Byte *former = _data;

    _bufCapacity *= 2;
    _data = new Byte[_bufCapacity] {0};

    memcpy(_data, former, _bufSize);
    delete[] former;
}

#endif //SERIALIZATION_TOOLS_BUFFER_HPP
