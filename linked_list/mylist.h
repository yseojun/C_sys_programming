#ifndef MYLIST_H
#define MYLIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct s_list {
    DATA d;
    struct s_list *next;
} ELEMENT;

typedef ELEMENT *LINK;

// Iterative functions
LINK str_to_list_iter(char s[]);
int count_iter(LINK head);
void print_list_iter(LINK head);
void concatenate_iter(LINK a, LINK b);
void delete_list_iter(LINK head);
void insert_iter(LINK a, LINK b, LINK insert);

// Recursive functions
LINK str_to_list_recur(char s[]);
int count_recur(LINK head);
void print_list_recur(LINK head);
void concatenate_recur(LINK a, LINK b);
void delete_list_recur(LINK head);
void insert_recur(LINK a, LINK b, LINK insert);

#endif