#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>    
#include <vector>
#include <random>
#include <sys/time.h>

const int RUN_TIMES = 1000000000;

/**
 * @brief 测试从vector中获取size的速度
*/
void test_get_from_vector_function() {
    auto start = std::chrono::system_clock::now();
    std::vector<int> a(rand()%10000, 0);
    int m = 0;
    for (int i = 0; i < RUN_TIMES; i++) {
        m += a.size();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    printf("std::chrono::system_clock::now() run %d times need: %lfs, %d\n", RUN_TIMES, 
        elapsed_seconds.count(), m);
}

/**
 * @brief 测试直接拿本地int的速度
*/
void test_no_get_from_vector_function() {
    auto start = std::chrono::system_clock::now();
    std::vector<int> a(rand()%100000, 0);
    int a_size = a.size();
    int m = 0;
    for (int i = 0; i < RUN_TIMES; i++) {
        m += a_size;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    printf("std::chrono::system_clock::now() run %d times need: %lfs, %d\n", RUN_TIMES, 
        elapsed_seconds.count(), m);
}

// 结论：存在栈上更快，但是都是一秒跑1亿+次的级别
int main() {
    test_get_from_vector_function();
    test_no_get_from_vector_function();
}       