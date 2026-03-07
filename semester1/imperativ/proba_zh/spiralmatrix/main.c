#include <stdio.h>
#include "matrix.h"
#include "menu.h"

int main(void) {
    Matrix mx;
    
    initMatrix(&mx, 1);
    
    printUserGuide();

    while (takeUserInput(&mx));
    
    freeMatrix(&mx);

    return 0;
}
