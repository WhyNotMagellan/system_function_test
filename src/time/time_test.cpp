#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>    
#include <sys/time.h>

const int RUN_TIMES = 10000000;

/**
 * @brief 时间获取性能测试 system clock
*/
void test_system_clock_function() {
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    for (int i = 0; i < RUN_TIMES; i++) {
        end = std::chrono::system_clock::now();
    }
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    printf("std::chrono::system_clock::now() run %d times need: %lfs\n", RUN_TIMES, 
        elapsed_seconds.count());
}

/**
 * @brief 时间性能获取测试 gettimeofday
*/
void test_gettimeofday_function() {
    timeval tim;
    gettimeofday(&tim,NULL);
    int start_u = tim.tv_usec;
    int start_s = tim.tv_sec;
    double duration;
	int sec, usec;

    for (int i = 0; i < RUN_TIMES; i++) {
        gettimeofday(&tim,NULL);
        int end_u = tim.tv_usec;
        int end_s = tim.tv_sec;
        bool borrow = (end_u < start_u);
        int sec = borrow ? end_s - start_s - 1 : end_s - start_s;
        int usec = borrow ? end_u + 100000 - start_u : end_u - start_u;
    }

    printf("gettimeofday() run %d times need: %d.%ds\n", RUN_TIMES, sec, usec);
}

/**
 *	@brief 时间 
 */

int main() {
    test_system_clock_function();
    test_gettimeofday_function();
}       