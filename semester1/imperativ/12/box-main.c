#include <stdio.h>
#include "box.h"

int main() {
    initialize();

    printf("Is empty? %d\n", isEmpty());
    
    push(5);

    printf("Peek: %d\n", peek());

    printf("Pop: %d\n", pop());
    push(3);
    push(6);
    printf("Pop: %d\n", pop());
    copyTop();
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Is empty? %d\n", isEmpty());
}
