//Ajito, Monika Assignment 3 Section 1776

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma warning(disable : 4996)

typedef struct node {
    char data[100];
    struct node* next;
}*nodePtr;

void printlist(nodePtr l) {
    nodePtr curr = l;
    printf("Transaction History: \n");
    while (curr != NULL) {
        printf("   %s\n", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
nodePtr addnode(nodePtr head, char* data) {
    // create a new node
    nodePtr n = malloc(sizeof(struct node));
    strcpy(n->data, data);
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return head;
    }

    nodePtr curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    // glue him on
    curr->next = n;

    return head;
}

int price1(int max, int min) {

    srand(time(0));

    int num = (rand() % (max - min + 1)) + min;

    return num;
}

int price2(int maxS, int minS) {

    srand(time(0));

    int nums = (rand() % (maxS - minS + 1)) + minS;

    return nums;
}

void MyDate(char* buffer, unsigned long len) {
    time_t rawtime;
    struct tm* info;

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(buffer, len, "%x at %I:%M%p", info);
}


int main() {
    int min = 10000;
    int max = 12000;
    int minS = 100;
    int maxS = 500;

    char date[50];
    char transaction[100];
    nodePtr head = NULL;

    char sentence[256];
    char sentenceTwo[256];
    char word[256];
    int args_assigned;
    int int1;
    int cost;
    args_assigned = 0;
    int balance;
    int add = 0, sell = 0, bitcoin = 0, sakura = 0, add1 = 0, sell1 = 0;
    int price = 0;
    price = price1(min, max);
    int priceS = 0;
    priceS = price2(minS, maxS);

    while (strcmp(sentence, "quit") != 0) {

        printf("Welcome to CS 50 BITPLAY");
        printf("\nUse the following syntax\n");
        printf("   Buy #\n");
        printf("   Sell #\n");
        printf("   Price\n");
        printf("   History\n");
        printf("   Wallet\n");
        printf("   Exit\n");
        printf("Please Select One Of The Following\n");
        gets(sentence);

        args_assigned = sscanf(sentence, "%s", word);
        if (strcmp(word, "Buy") == 0) {

            printf("Which coin would you like to buy?");
            printf("\nUse the following syntax\n");
            printf("       Bitcoin\n");
            printf("       Sakura\n");
            printf("Please Select One Of The Following\n");
            gets(sentenceTwo);
            args_assigned = sscanf(sentenceTwo, "%s", word);
            if (strcmp(word, "Bitcoin") == 0) {
                args_assigned = sscanf(sentence, "%s %d", word, &int1);
                if (args_assigned == 2) {
                    for (int i = 0; i < int1; i++) {
                        add--;
                        bitcoin++;
                    }

                    printf("Great!, thanks for buying %d Bitcoin(s). \n", int1);

                    MyDate(date, 50);
                    sprintf(transaction,
                        "You bought %d Bitcoin(s) for $%d each on %s -($%d)",
                        int1, price, date, int1 * price);

                    head = addnode(head, transaction);
                    printf("\n");
                }
                else
                {
                    puts("Invalid Input!!");
                    printf("\n");
                }
            }

            args_assigned = sscanf(sentenceTwo, "%s", word);
            if (strcmp(word, "Sakura") == 0) {
                args_assigned = sscanf(sentence, "%s %d", word, &int1);
                if (args_assigned == 2) {
                    for (int i = 0; i < int1; i++) {
                        add1--;
                        sakura++;
                    }

                    printf("Great!, thanks for buying %d Sakura Coin(s). \n", int1);

                    MyDate(date, 50);
                    sprintf(transaction,
                        "You bought %d Sakura Coin(s) for $%d each on %s -($%d)",
                        int1, priceS, date, int1 * priceS);

                    head = addnode(head, transaction);
                    printf("\n");
                }
                else
                {
                    puts("Invalid Input!!");
                    printf("\n");
                }
            }
        }//end if statement
        else if (strcmp(word, "Sell") == 0) {

            printf("Which coin would you like to sell?");
            printf("\nUse the following syntax\n");
            printf("       Bitcoin\n");
            printf("       Sakura\n");
            printf("Please Select One Of The Following\n");
            gets(sentenceTwo);

            args_assigned = sscanf(sentenceTwo, "%s", word);
            if (strcmp(word, "Bitcoin") == 0) {
                args_assigned = sscanf(sentence, "%s %d", word, &int1);
                if (args_assigned == 2)
                {
                    for (int i = 0; i < int1; i++) {
                        sell++;
                        bitcoin--;

                    }
                    printf("Great!, thanks for selling %d Bitcoin(s). \n", int1);

                    MyDate(date, 50);
                    sprintf(transaction,
                        "You sold %d Bitcoin(s) for $%d each on %s -($%d)",
                        int1, price, date, int1 * price);

                    head = addnode(head, transaction);
                    printf("\n");
                }
                else {
                    puts("Invalid Input!!");
                    printf("\n");
                }
            }

           args_assigned = sscanf(sentenceTwo, "%s", word);
            if (strcmp(word, "Sakura") == 0) {
                args_assigned = sscanf(sentence, "%s %d", word, &int1);
                if (args_assigned == 2) {
                    for (int i = 0; i < int1; i++) {
                        sell1++;
                        sakura--;

                    }
                    printf("Great!, thanks for selling %d Sakura Coin(s). \n", int1);

                    MyDate(date, 50);
                    sprintf(transaction,
                        "You sold %d Sakura Coin(s) for $%d each on %s -($%d)",
                        int1, priceS, date, int1 * priceS);

                    head = addnode(head, transaction);
                    printf("\n");
                }
                else {
                    puts("Invalid Input!!");
                    printf("\n");
                }
            } 

        } 
        else if (strcmp(word, "Price") == 0) {

            args_assigned = sscanf(sentence, "%s", word);
            if (args_assigned == 1)
            {
                printf("The current price of Bitcoin(s) is: %d\n", price);
                printf("The current price of Sakura Coin(s) is: %d\n", priceS);
                printf("\n");
            }
            else {
                puts("Invalid Input!!\n");
                printf("\n");
            }

        }
        else if (strcmp(word, "History") == 0) {

            FILE* fopen(const char* filename, const char* mode);

            args_assigned = sscanf(sentence, "%s", word);
            if (args_assigned == 1)
            {
                printlist(head);
            }
            else {
                puts("Invalid Input!!\n");
                printf("\n");
            }

        }
        else if (strcmp(word, "Wallet") == 0) {

            int current = price * add;
            int currentS = priceS * add1;
            int current1 = price * sell ;
            int current1S = priceS * sell1;
            balance = 20000 + current + current1 + currentS + current1S;
            int coinBal = bitcoin;
            int coinBal1 = sakura;
            
            printf("Your Current Balance Is: $%d\n", balance);
            printf("Your Bitcoin Balance Is: %d BTC\n", coinBal);
            printf("Your Sakura Coin Balance Is: %d SKC\n", coinBal1);
            printf("\n");
        }
        else if (strcmp(word, "Exit") == 0) {
            break;
        }
        else {
            puts("\nInput invalid!");
            printf("\n");
        }
    }

    return 0;
}
