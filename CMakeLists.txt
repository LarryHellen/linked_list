cmake_minimum_required(VERSION 3.29)
project(linked_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(linked_list main.cpp
                Node.h
                LinkedList.h
                LinkedList.cpp
                NodeIterator.h
                NodeIterator.cpp
        ReverseIterator.cpp
        ReverseIterator.h
        ConstIterator.cpp
        ConstIterator.h)

