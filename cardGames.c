#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char suit[10];
    char face[10];

} Card;
void makePoke(Card cards[], char *faces[], char *suits[])
{
    for (int i = 0; i < 52; i++)
    {
        strcpy(cards[i].face, faces[i % 13]);
        strcpy(cards[i].suit, suits[i / 13]);
    }
}

void shuffle(Card cards[])
{
    srand(time(NULL));
    for (int i = 0; i < 52; i++)
    {
        // 结构体内部的数组变量进行内存拷贝
        int j = rand() % 52;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void deal(Card cards[])
{
    for (int i = 0; i < 52; i++)
    {
        printf("%s %s\n", cards[i].suit, cards[i].face);
    }
}

int main()
{
    char *faces[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"spades",
                     "hearts",
                     "clubs",
                     "diamonds"};
    Card cards[52];
    makePoke(cards, faces, suits);
    shuffle(cards);
    deal(cards);
    return 0;
}