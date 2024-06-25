/**
  ******************************************************************************
  * @file           : type_helper.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/25
  ******************************************************************************
  */



#ifndef SERIALIZATION_TOOLS_TYPE_HELPER_H
#define SERIALIZATION_TOOLS_TYPE_HELPER_H


template<typename T>
struct TypeHelper {
    static const bool isPointer = false;
};

template<typename T>
struct TypeHelper<T*> {
    static const bool isPointer = true;
};

template<typename T>
bool IsPointer(T &t){
    return TypeHelper<T>::isPointer;
}

#endif //SERIALIZATION_TOOLS_TYPE_HELPER_H
