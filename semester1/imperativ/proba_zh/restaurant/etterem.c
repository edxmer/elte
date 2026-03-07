#include <stdio.h>
#include <stdlib.h>
#include <time.h>



double arak[] = {40.5, 30.15, 55.3, 24.65, 29.43};


int dailyDiscountMenu() {
    return rand()%(sizeof(arak)/sizeof(*arak));
}

double modifiedPrice(int id, double modifier) {
    return arak[id] * modifier;
}

int generateReview() {
    return rand()%10+1;
}

void printMenuData(int menu, double netto, double brutto, int review) {


    printf("Menu #%d\nNet price: %.2f\nGross price: %.2f\nCustomer review: %d\n",
        menu,
        netto,
        brutto,
        review
    );



}

void printDailyData(int orders, double netto_inc, double brutto_inc, double avg_review) {
    printf("\n\n\tDAILY DATA:\nNumber of daily orders: %d\nDaily net income: %.2f\n\
Daily gross income: %.2f\nDaily average review: %.2f\n",
        orders,
        netto_inc,
        brutto_inc,
        avg_review
    );

    if (avg_review < 3.5) {
        printf("The restaurant did poorly today.\n");
    } else if (avg_review < 6.5) {
        printf("The restaurant did fine today.\n");
    } else {
        printf("The restaurant did great today.\n");
    }
}

void dailyIncome(int *rendelesek, int rendelesek_len) {
     int arak_len = sizeof(arak)/sizeof(*arak);
    int discounted_menu = dailyDiscountMenu();
    int i;
    double review_sum = 0;
    double netto_sum = 0;
    double brutto_sum = 0;
    double review_average;


    printf("A napi kedvezmény a %d. menüre lesz ma.\n\n", discounted_menu);


    for (i=0; i<rendelesek_len; ++i) {
        int menu = rendelesek[i];
        if (!(0 <= menu && menu <= arak_len)) {
            fprintf(stderr, "\nHiba 1: A %d. rendelés menüje (%d) nem létezik!\n", i, menu);
        } else {
            double discount_modifier = menu == discounted_menu ? 0.8 : 1;
            double ar = arak[menu-1];
            double netto = ar * discount_modifier;
            double brutto = netto * 1.27;

            int review = generateReview();

            printf("\n%d. rendelés:\n", i+1);
            printMenuData(menu, netto, brutto, review);

            review_sum += (double) review;
            netto_sum += (double) netto;
            brutto_sum += (double) brutto;
        }
    }

    review_average = review_sum / (double)rendelesek_len;

    printDailyData(rendelesek_len, netto_sum, brutto_sum, review_average);
}

int main() {
    srand(time(NULL));

    int rendelesek[] = {1, 3, 4, 2, 2, 1, 5, 8, 4, 3, 5};
    int rendelesek_len = sizeof(rendelesek)/sizeof(*rendelesek);
   
    dailyIncome(rendelesek, rendelesek_len);

    return 0;
}
