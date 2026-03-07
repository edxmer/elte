#include <stdio.h>
#include <stdlib.h>
#include "box.h"


void initialize() {

    top = NULL;

}


int isEmpty() {
    return (top == NULL);
}


int peek() {
    if (isEmpty()) {
        printf("Hiba! A verem üres, nem lehet belenézni!\n");
        exit(1);
    }

    return top->weight;
}

void push(int w) {

    Box *new;
    new = (Box*)malloc(sizeof(Box));
    new->weight = w;
    new->next = top;

    top = new;

}


int pop() {

    if (isEmpty()) {
        printf("Hiba! A verem üres, nem lehet levenni a tetejét.\n");
        exit(2);
    }

    int w = top->weight;
    Box *next = top->next;
    free(top);
    top = next;
    
    return w;
}

void copyTop() {

    if (isEmpty()) {
        printf("Hiba! A verem üres, nem lehet másolni a tetejére.\n");
        exit(3);
    }

    Box *current = top;
    while (current->next)
        current = current->next;

    push(current->weight);
}
