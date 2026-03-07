#ifndef BOX_H
#define BOX_H


struct Box {
    int weight;
    struct Box *next;
};

typedef struct Box Box;

Box *top;

void initialize();

int isEmpty();

int peek();

void push(int w);

int pop();

void copyTop();

#endif
