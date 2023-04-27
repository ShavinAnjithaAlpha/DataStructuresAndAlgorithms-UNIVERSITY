#include<stdio.h>

struct card {
    int size;
    char c;
};

enum month {
    JAN = 10, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

union storage {
    int x;
    int y;
};
    
typedef struct card Card;

int main() {

    enum month Month1 = JAN;
    printf("JAN month: %d\n", Month1);

    // declare the struct card
    struct card *cardPtr, cards[5];
    Card card1 = {45, 'c'};
    cardPtr = &card1;

    printf("value of struct card :%d %c\n", card1.size, card1.c);
    printf("value of struct thiugh array operator: %d %c\n", cardPtr->size, cardPtr->c);
    printf("size of the card: %d\n", sizeof(card1));

    // convert an strct to an integer array
    int* arr = (int*) &card1;
    printf("array values : %d %d\n", arr[0], arr[1]);

    union storage str1 = {44};
    printf("storage 1: %d %d\n", str1.x, str1.y);

    union storage str2 = {77};
    printf("storage 1: %d %d\n", str2.x, str2.y);

}