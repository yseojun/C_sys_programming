#include "calclock.h"
#include <stdio.h>

#define ITER 1000

unsigned long long loop_time = 0;
unsigned long long loop_count = 0;

void test_int_add(int n, unsigned long long *baseline,
                  unsigned long long *loop_unrolling,
                  unsigned long long *reassociation,
                  unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    int sum = 0;
    int i = 0;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 0; i < n; i++) {
        sum += i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0;
    for (i = 0; i < n; i = i + 2) {
        sum += i;
        sum += i + 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0;
    for (i = 0; i < n; i = i + 2) {
        sum = sum + (i + (i + 1));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (i = 0; i < n; i = i + 2) {
        sum1 += i;
        sum2 += i + 1;
    }
    sum = sum1 + sum2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_int_multiply(int n, unsigned long long *baseline,
                       unsigned long long *loop_unrolling,
                       unsigned long long *reassociation,
                       unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    int product = 1;
    int i = 1;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 1; i < n; i++) {
        product *= i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1;
    for (i = 1; i < n; i = i + 2) {
        product *= i;
        product *= (i + 1);
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1;
    for (i = 1; i < n; i = i + 2) {
        product = product * (i * (i + 1));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1;
    int product1 = 1;
    int product2 = 1;
    for (i = 1; i < n; i = i + 2) {
        product1 *= i;
        product2 *= (i + 1);
    }
    product = product1 * product2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_double_add(double n, unsigned long long *baseline,
                     unsigned long long *loop_unrolling,
                     unsigned long long *reassociation,
                     unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    double sum = 0.0;
    double i = 0;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 0; i < n; i++) {
        sum += i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0;
    for (i = 0; i < n; i = i + 2) {
        sum += i;
        sum += i + 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0;
    for (i = 0; i < n; i = i + 2) {
        sum = sum + (i + (i + 1));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0;
    double sum1 = 0.0;
    double sum2 = 0.0;
    for (i = 0; i < n; i = i + 2) {
        sum1 += i;
        sum2 += i + 1;
    }
    sum = sum1 + sum2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_double_multiply(double n, unsigned long long *baseline,
                          unsigned long long *loop_unrolling,
                          unsigned long long *reassociation,
                          unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    double product = 1.0;
    double i = 1.0;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 1.0; i < n; i++) {
        product *= i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0;
    for (i = 1.0; i < n; i = i + 2) {
        product *= i;
        product *= (i + 1.0);
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0;
    for (i = 1.0; i < n; i = i + 2) {
        product = product * (i * (i + 1.0));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0;
    double product1 = 1.0;
    double product2 = 1.0;
    for (i = 1.0; i < n; i = i + 2) {
        product1 *= i;
        product2 *= (i + 1.0);
    }
    product = product1 * product2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_float_add(float n, unsigned long long *baseline,
                    unsigned long long *loop_unrolling,
                    unsigned long long *reassociation,
                    unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    float sum = 0.0f;
    float i = 0.0f;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 0.0f; i < n; i++) {
        sum += i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0f;
    for (i = 0.0f; i < n; i = i + 2.0f) {
        sum += i;
        sum += i + 1.0f;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0f;
    for (i = 0.0f; i < n; i = i + 2.0f) {
        sum = sum + (i + (i + 1.0f));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0.0f;
    float sum1 = 0.0f;
    float sum2 = 0.0f;
    for (i = 0.0f; i < n; i = i + 2.0f) {
        sum1 += i;
        sum2 += i + 1.0f;
    }
    sum = sum1 + sum2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_float_multiply(float n, unsigned long long *baseline,
                         unsigned long long *loop_unrolling,
                         unsigned long long *reassociation,
                         unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    float product = 1.0f;
    float i = 1.0f;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 1.0f; i < n; i++) {
        product *= i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0f;
    for (i = 1.0f; i < n; i = i + 2.0f) {
        product *= i;
        product *= (i + 1.0f);
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0f;
    for (i = 1.0f; i < n; i = i + 2.0f) {
        product = product * (i * (i + 1.0f));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1.0f;
    float product1 = 1.0f;
    float product2 = 1.0f;
    for (i = 1.0f; i < n; i = i + 2.0f) {
        product1 *= i;
        product2 *= (i + 1.0f);
    }
    product = product1 * product2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_long_add(long n, unsigned long long *baseline,
                   unsigned long long *loop_unrolling,
                   unsigned long long *reassociation,
                   unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    long sum = 0L;
    long i = 0L;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 0L; i < n; i++) {
        sum += i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0L;
    for (i = 0L; i < n; i = i + 2L) {
        sum += i;
        sum += i + 1L;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0L;
    for (i = 0L; i < n; i = i + 2L) {
        sum = sum + (i + (i + 1L));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    sum = 0L;
    long sum1 = 0L;
    long sum2 = 0L;
    for (i = 0L; i < n; i = i + 2L) {
        sum1 += i;
        sum2 += i + 1L;
    }
    sum = sum1 + sum2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void test_long_multiply(long n, unsigned long long *baseline,
                        unsigned long long *loop_unrolling,
                        unsigned long long *reassociation,
                        unsigned long long *separate_accumulators) {
    struct timespec local_time[2];
    long product = 1L;
    long i = 1L;

    // Baseline
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    for (i = 1L; i < n; i++) {
        product *= i;
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, baseline, &loop_count);

    // Loop Unrolling
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1L;
    for (i = 1L; i < n; i = i + 2L) {
        product *= i;
        product *= (i + 1L);
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, loop_unrolling, &loop_count);

    // Reassociation
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1L;
    for (i = 1L; i < n; i = i + 2L) {
        product = product * (i * (i + 1L));
    }
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, reassociation, &loop_count);

    // Separate Accumulators
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    product = 1L;
    long product1 = 1L;
    long product2 = 1L;
    for (i = 1L; i < n; i = i + 2L) {
        product1 *= i;
        product2 *= (i + 1L);
    }
    product = product1 * product2;
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, separate_accumulators, &loop_count);
}

void run_tests(int n) {
    unsigned long long total_baseline = 0, total_loop_unrolling = 0,
                       total_reassociation = 0, total_separate_accumulators = 0;

    for (int i = 0; i < ITER; i++) {
        unsigned long long current_baseline = 0, current_loop_unrolling = 0,
                           current_reassociation = 0,
                           current_separate_accumulators = 0;
        // test_int_add(n, &current_baseline, &current_loop_unrolling,
        //              &current_reassociation, &current_separate_accumulators);
        // test_int_multiply(n, &current_baseline, &current_loop_unrolling,
        //                   &current_reassociation,
        //                   &current_separate_accumulators);
        // test_double_add(n, &current_baseline, &current_loop_unrolling,
        //                &current_reassociation,
        //                &current_separate_accumulators);
        // test_double_multiply(n, &current_baseline, &current_loop_unrolling,
        //                      &current_reassociation,
        //                      &current_separate_accumulators);
        // test_float_add(n, &current_baseline, &current_loop_unrolling,
        //               &current_reassociation,
        //               &current_separate_accumulators);
        // test_float_multiply(n, &current_baseline, &current_loop_unrolling,
        //                     &current_reassociation,
        //                     &current_separate_accumulators);
        // test_long_add(n, &current_baseline, &current_loop_unrolling,
        //             &current_reassociation, &current_separate_accumulators);
        test_long_multiply(n, &current_baseline, &current_loop_unrolling,
                           &current_reassociation,
                           &current_separate_accumulators);
        total_baseline += current_baseline;
        total_loop_unrolling += current_loop_unrolling;
        total_reassociation += current_reassociation;
        total_separate_accumulators += current_separate_accumulators;
    }

    printf("%llu    %llu    %llu    %llu\n", total_baseline / ITER,
           total_loop_unrolling / ITER, total_reassociation / ITER,
           total_separate_accumulators / ITER);
}

int main() {
    run_tests(100);
    run_tests(1000);
    run_tests(10000);
    run_tests(100000);
    run_tests(1000000);
    return 0;
}