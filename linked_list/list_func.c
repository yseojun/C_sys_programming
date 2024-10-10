#include "mylist.h"

/*** iter func ***/

LINK str_to_list_iter(char s[]) {
    LINK head = NULL, tail;
    int i;
    if (s[0] != '\0') {
        head = malloc(sizeof(ELEMENT));
        head->d = s[0];
        tail = head;
        for (i = 1; s[i] != '\0'; i++) {
            tail->next = malloc(sizeof(ELEMENT));
            tail = tail->next;
            tail->d = s[i];
        }
        tail->next = NULL;
    }
    return head;
}

int count_iter(LINK head) {
    int cnt = 0;
    for (; head != NULL; head = head->next) {
        cnt++;
    }
    return cnt;
}

void print_list_iter(LINK head) {
    while (head != NULL) {
        // printf("%c --> ", head->d);
        head = head->next;
    }
    // printf("NULL");
}

void concatenate_iter(LINK a, LINK b) {
    assert(a != NULL);
    while (a->next) {
        a = a->next;
    }
    a->next = b;
}

void delete_list_iter(LINK head) {
    LINK tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void insert_iter(LINK a, LINK b, LINK insert) {
    LINK current = insert;
    while (current->next != NULL) {
        current = current->next;
    }
    a->next = insert;
    current->next = b;
}

/*** recur func ***/

LINK str_to_list_recur(char s[]) {
    LINK head;
    if (s[0] == '\0')
        return NULL;
    head = malloc(sizeof(ELEMENT));
    head->d = s[0];
    head->next = str_to_list_recur(s + 1);
    return head;
}

int count_recur(LINK head) {
    if (head == NULL)
        return 0;
    else
        return 1 + count_recur(head->next);
}

void print_list_recur(LINK head) {
    if (head == NULL) {
        // printf("NULL");
    } else {
        // printf("%c --> ", head->d);
        print_list_recur(head->next);
    }
}

void concatenate_recur(LINK a, LINK b) {
    assert(a != NULL);
    if (a->next == NULL)
        a->next = b;
    else
        concatenate_recur(a->next, b);
}

void delete_list_recur(LINK head) {
    if (head != NULL) {
        delete_list_recur(head->next);
        free(head);
    }
}

void insert_recur(LINK a, LINK b, LINK insert) {
    if (insert->next == NULL) {
        insert->next = b;
        a->next = insert;
    } else {
        insert_recur(insert, b, insert->next);
    }
}