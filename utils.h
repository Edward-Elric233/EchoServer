// Copyright(C), Edward-Elric233
// Author: Edward-Elric233
// Version: 1.0
// Date: 2022/6/2
// Description: 
#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <iostream>

namespace utils {
    inline void print() {std::cout << "\n";}
    template<typename T, typename... Args>
    void print(T &&first, Args&& ...args) {
        std::cout << first << " ";
        print(std::forward<Args>(args)...);
    }
}


#endif //SERVER_UTILS_H
