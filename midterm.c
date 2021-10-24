//Ajito, Monika Section 1776 Midterm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readysetgo(int* myarray, int n) {
    static int init = 0;
    time_t t;
    if (!init) {
        srand((unsigned)time(&t));
        init = 1;
    }

    for (int i = 0; i < n; i++) {
        int randomValue = i + (rand() % (n - i));
        int randomElement = myarray[randomValue];
        myarray[randomValue] = myarray[i];
        myarray[i] = randomElement;

    }
} 


int main()
{
    int myarray[4] = { 1, 2, 3, 4 };
    int choice, bet1, bet2, bet3;
    int add1 = 0, add2 = 0, add3 = 0, add4 = 0; //Winning amts
    int cost1 = 0, cost2 = 0, cost3 = 0, cost4 = 0; //Initial bets
    int endBal = 0;

    printf("\nWelcome to the CS50 betting grounds.\n\n");
    printf("You have a starting balance of $200.\n");

    while (1) {
        printf("\nPlease select from the following options 1-6\n");
        printf("   1 to place an Exacta Bet\n");
        printf("   2 to place an Exactabox Bet\n");
        printf("   3 to place a Trifecta Bet\n");
        printf("   4 to place a Trifectabox Bet\n");
        printf("   5 to see your USD balance\n");
        printf("   6 to exit\n");
        printf("Enter your choice> ");
        scanf_s("%d", &choice);
        printf("\n");

        if (choice == 1) //Exacta Bet
        {
            cost1--;

            readysetgo(myarray, 4);
            printf("Winning order %d %d %d %d\n",
                myarray[0], myarray[1], myarray[2], myarray[3]);

            printf("Choose two horses to bet on: \n"); 
            scanf_s("%d %d", &bet1, &bet2); 

            
            if (bet1 == myarray[0] && bet2 == myarray[1])  
            {
              printf("Congrats you won! $100 has been added to your balance.");
              add1++;
                    
            } 
            else
            {
                printf("Sorry you lost\n");
            }
            
        } 
        if (choice == 2) //Exactabox 
        {
            cost2--;

            readysetgo(myarray, 4);
            printf("Winning order %d %d %d %d\n",
                myarray[0], myarray[1], myarray[2], myarray[3]);

            printf("Choose two horses to bet on: \n");
            scanf_s("%d %d", &bet1, &bet2);

            if ((bet1 == myarray[0] && bet2 == myarray[1]) || (bet1 == myarray[1] && bet2 == myarray[0]))
            {
                printf("Congrats you won! $50 has been added to your balance.");
                add2++;

            }
            else
            {
                printf("Sorry you lost\n");
            }
            
        } //Exactabox End
        if (choice == 3) //Trifecta
        {
            cost3--;

            readysetgo(myarray, 4);
            printf("Winning order %d %d %d %d\n",
                myarray[0], myarray[1], myarray[2], myarray[3]);

            printf("Choose three horses to bet on: \n");
            scanf_s("%d %d %d", &bet1, &bet2, &bet3);

            if (bet1 == myarray[0] && bet2 == myarray[1] && bet3 == myarray[2])
            {
                printf("Congrats you won! $200 has been added to your balance.");
                add3++;

            }
            else
            {
                printf("Sorry you lost\n");
            }

        } //Trifecta End
        if (choice == 4) //Trifectabox
        {
            cost4--;

            readysetgo(myarray, 4);
            printf("Winning order %d %d %d %d\n",
                myarray[0], myarray[1], myarray[2], myarray[3]);

            printf("Choose three horses to bet on: \n");
            scanf_s("%d %d %d", &bet1, &bet2, &bet3);

            if ((bet1 == myarray[0] && bet2 == myarray[1] && bet3 == myarray[2]) || (bet1 == myarray[0] && bet2 == myarray[2] && bet3 == myarray[1]) || (bet1 == myarray[1] && bet2 == myarray[0] && bet3 == myarray[2]))
            {
                printf("Congrats you won! $150 has been added to your balance.");
                add4++;

            }
            else if ((bet1 == myarray[1] && bet2 == myarray[2] && bet3 == myarray[0]) || (bet1 == myarray[2] && bet2 == myarray[0] && bet3 == myarray[1]) || (bet1 == myarray[2] && bet2 == myarray[1] && bet3 == myarray[0]))
            {
                printf("Congrats you won! $150 has been added to your balance.");
                add4++;

            }
            else
            {
                printf("Sorry you lost\n");
            }
        }  //Trifectabox End
        if (choice == 5) //USD balance
        {
            int win1 = 100 * add1;
            int win2 = 50 * add2;
            int win3 = 200 * add3;
            int win4 = 150 * add4;

            int loss1 = 10 * cost1;
            int loss2 = 5 * cost2;
            int loss3 = 25 * cost3;
            int loss4 = 20 * cost4;

            endBal = 200 + win1 + win2 + win3 + win4 + loss1 + loss2 + loss3 + loss4;

            printf_s("Your Balance is $%d", endBal);
            printf("\n");
        }
        else if (choice == 6) {
            return 0;
        }
    } // ending for while loop 
        return 0;
    }
