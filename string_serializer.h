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

class StringSerializer {
public:
    StringSerializer(int bufSize = DEFAULT_SERIALIZED_BUF_SIZE);
    ~StringSerializer();

    char* GetString();

private:
    char *_buf;
    int _bufSize, _dataSize;
};


#endif //SERIALIZATION_TOOLS_STRING_SERIALIZER_H
