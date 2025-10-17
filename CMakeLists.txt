cmake_minimum_required(VERSION 4.0)
project(CPP_Algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPP_Algorithm main.cpp)

#Sort Algorithms
add_executable(BubbleSort Sort_Algorithm/BubbleSort.cpp)
add_executable(SelectionSort Sort_Algorithm/SelectionSort.cpp)
add_executable(InsertionSort Sort_Algorithm/InsertionSort.cpp)
add_executable(MergeSort Sort_Algorithm/MergeSort.cpp)
add_executable(QuickSort Sort_Algorithm/QuickSort.cpp)

#Search Algorithms
add_executable(LinearSearch Search_Algorithm/LinearSearch.cpp)
add_executable(BinarySearch Search_Algorithm/BinarySearch.cpp)

#Data Structure Algorithms
add_executable(Stack Data_Structure_Algorithm/Stack.cpp)
add_executable(Queue Data_Structure_Algorithm/Queue.cpp)
