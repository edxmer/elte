// Kötelező feladatok
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define STUD_CNT 32

struct stud {
    short age;
    int id;
    double avg;
};
typedef struct stud Student;


int init_students (Student *s, int length) {
    int i;

    
    for (i = 0; i < length; ++i) {

        (s+i)->id = rand()%1000000+1000000;
        (s+i)->avg = ((double)(rand()%40+10))/10.0;
        (s+i)->age = rand()%10+10;

    }
    
    return 1;
}


Student* student_init() {
    
    Student* s = malloc(sizeof(Student));

    s->id = rand()%1000000+1000000;
    s->avg = ((double)(rand()%40+10)) / 10.0;
    s->age = rand()%10 + 10;

    return s;
}

int student_print(Student* student) {
    printf("id: %d | avg: %f | age: %d\n", student->id, student->avg, student->age);
    return 1;
}


Student* student_search(Student* students, int length) {
    int i;
    float max_value;
    int max_ind;

    max_ind = 0;
    max_value = students->avg;

    for (i=1; i<length; ++i) {
        if (max_value < (students+i)->avg) {
            max_ind = i;
            max_value = (students+i)->avg;
        }
    }
    
    return (students+max_ind);
}


struct AdvStudent {
    enum Type = {BSc, MSc, PhD};


};













int main() {
    int i;
    Student students[STUD_CNT];



    srand(time(NULL));


    init_students(students, STUD_CNT);
    
    printf("sizeof Student: %lu, sizeof students: %lu\n\n", sizeof(Student), sizeof(students));


    
    for (i = 0; i < STUD_CNT; ++i) {
        
        student_print(students+i);
    }
    

    ///-------///

    Student* s1 = student_init();
    Student* s2 = student_init();
    Student* s3 = student_init();
    
    printf("\n---------\n");

    student_print(s1);
    student_print(s2);
    student_print(s3);

    //////////////
    

    printf("\n----\n");

    Student* best_avg = student_search(students, STUD_CNT);

    student_print(best_avg);

    return 0;
}
