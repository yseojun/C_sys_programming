#include "calclock.h"
#include "mylist.h"

#define ITER 100
unsigned long long loop_count = 0;

void test_iter(int n, unsigned long long *str_to_list_time,
               unsigned long long *count_time, unsigned long long *print_time,
               unsigned long long *concatenate_time,
               unsigned long long *insert_time,
               unsigned long long *delete_time) {
    struct timespec local_time[2];
    char test_str[n];
    LINK head, second_list, insert_list;

    // 테스트용 문자열 생성
    for (int i = 0; i < n - 1; i++) {
        test_str[i] = 'a' + (i % 26);
    }
    test_str[n - 1] = '\0';

    // str_to_list_iter 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    head = str_to_list_iter(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, str_to_list_time, &loop_count);

    // count_iter 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    count_iter(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, count_time, &loop_count);

    // print_list_iter 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    print_list_iter(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, print_time, &loop_count);

    // concatenate_iter 테스트
    second_list = str_to_list_iter(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    concatenate_iter(head, second_list);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, concatenate_time, &loop_count);

    // insert_iter 테스트
    insert_list = str_to_list_iter(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    insert_iter(head, head->next, insert_list);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, insert_time, &loop_count);

    // delete_list_iter 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    delete_list_iter(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, delete_time, &loop_count);
}

void test_recur(int n, unsigned long long *str_to_list_time,
                unsigned long long *count_time, unsigned long long *print_time,
                unsigned long long *concatenate_time,
                unsigned long long *insert_time,
                unsigned long long *delete_time) {
    struct timespec local_time[2];
    char test_str[n];
    LINK head, second_list, insert_list;

    // 테스트용 문자열 생성
    for (int i = 0; i < n - 1; i++) {
        test_str[i] = 'a' + (i % 26);
    }
    test_str[n - 1] = '\0';

    // str_to_list_recur 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    head = str_to_list_recur(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, str_to_list_time, &loop_count);

    // count_recur 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    count_recur(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, count_time, &loop_count);

    // print_list_recur 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    print_list_recur(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, print_time, &loop_count);

    // concatenate_recur 테스트
    second_list = str_to_list_recur(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    concatenate_recur(head, second_list);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, concatenate_time, &loop_count);

    // insert_recur 테스트
    insert_list = str_to_list_recur(test_str);
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    insert_recur(head, head->next, insert_list);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, insert_time, &loop_count);

    // delete_list_recur 테스트
    clock_gettime(CLOCK_MONOTONIC, &local_time[0]);
    delete_list_recur(head);
    clock_gettime(CLOCK_MONOTONIC, &local_time[1]);
    calclock(local_time, delete_time, &loop_count);
}

void run_tests(int n) {
    unsigned long long total_str_to_list_iter = 0, total_count_iter = 0,
                       total_print_iter = 0, total_concatenate_iter = 0,
                       total_insert_iter = 0, total_delete_iter = 0;
    unsigned long long total_str_to_list_recur = 0, total_count_recur = 0,
                       total_print_recur = 0, total_concatenate_recur = 0,
                       total_insert_recur = 0, total_delete_recur = 0;

    for (int i = 0; i < ITER; i++) {
        unsigned long long current_str_to_list = 0, current_count = 0,
                           current_print = 0, current_concatenate = 0,
                           current_insert = 0, current_delete = 0;

        test_iter(n, &current_str_to_list, &current_count, &current_print,
                  &current_concatenate, &current_insert, &current_delete);
        total_str_to_list_iter += current_str_to_list;
        total_count_iter += current_count;
        total_print_iter += current_print;
        total_concatenate_iter += current_concatenate;
        total_insert_iter += current_insert;
        total_delete_iter += current_delete;

        current_str_to_list = 0;
        current_count = 0;
        current_print = 0;
        current_concatenate = 0;
        current_insert = 0;
        current_delete = 0;

        test_recur(n, &current_str_to_list, &current_count, &current_print,
                   &current_concatenate, &current_insert, &current_delete);
        total_str_to_list_recur += current_str_to_list;
        total_count_recur += current_count;
        total_print_recur += current_print;
        total_concatenate_recur += current_concatenate;
        total_insert_recur += current_insert;
        total_delete_recur += current_delete;
    }

    // printf("----- N is %d (평균 %d 회) -----\n", n, ITER);

    printf("%llu %llu %llu %llu %llu %llu\n",
           total_str_to_list_iter / ITER, total_count_iter / ITER,
           total_print_iter / ITER, total_concatenate_iter / ITER,
           total_insert_iter / ITER, total_delete_iter / ITER);

    printf("%llu %llu %llu %llu %llu %llu\n",
           total_str_to_list_recur / ITER, total_count_recur / ITER,
           total_print_recur / ITER, total_concatenate_recur / ITER,
           total_insert_recur / ITER, total_delete_recur / ITER);

    // printf("\n");
}

int main() {
    run_tests(100);
    run_tests(1000);
    run_tests(10000);
    run_tests(100000);
    return 0;
}