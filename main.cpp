//: C15:Instrument4.cpp
// Extensibility in OOP
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

// added the comments here:
//  in order to test Github,  modified the comments. Total 2 lines

// gcc -o time_6 time_6.c

uint64_t get_tsc()
{
    uint64_t a, d;
    __asm__ volatile("rdtsc" : "=a"(a), "=d"(d));
    return (d << 32) | a;
}

uint64_t get_tscp()
{
    uint64_t a, d;
    __asm__ volatile("rdtscp" : "=a"(a), "=d"(d));
    return (d << 32) | a;
}

#define LOOP_TIMES 1000000000

int main(int argc, char **argv)
{
    uint64_t beg_tsc, end_tsc;
    long loop;
    long sum;

    printf("-------------rdtsc-------------\n");
    loop = LOOP_TIMES;
    sum = 0;
    while(loop--)
    {
        beg_tsc = get_tsc();
        end_tsc = get_tsc();
        sum += (end_tsc - beg_tsc);
    }
    printf("AVG_CYCLE : %ld\n", sum / LOOP_TIMES);

    sleep(1);

    printf("-------------rdtscp-------------\n");
    loop = LOOP_TIMES;
    sum = 0;
    while(loop--)
    {
        beg_tsc = get_tscp();
        end_tsc = get_tscp();
        sum += (end_tsc - beg_tsc);
    }
    printf("AVG_CYCLE : %ld\n", sum / LOOP_TIMES);

    return 0;
}
