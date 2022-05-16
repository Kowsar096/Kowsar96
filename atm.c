#include "stdio.h"
#include "windows.h"
#include "time.h"
int main()
{
    int pin = 1234, option, enteredPin, count = 0;
    int amount = 1;
    float balance = 5000;
    int continueTransaction = 1;
    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t%s", ctime(&now));
    printf("\n\t\t======Welcome to Adv. Learning ATM=======\n");
    while (pin != enteredPin)
    {
        printf("\nPlease enter your pin : ");

        scanf("%d", &enteredPin);
        if (enteredPin != pin)
        {
            printf("Invalid Pin!!!");
            count++;
            if (count == 3 && pin != enteredPin)
            {
                break;
            }
        }
    }
    while (continueTransaction != 0)
    {
        printf("\n\t\t==========*Available Transactions*=========");
        printf("\n\n\t\t1.Withdrawal");
        printf("\n\t\t2.Deposit");
        printf("\n\t\t3.Check Balance");
        printf("\n\n\tPlease select an option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            while (amount % 500 != 0)
            {
                printf("\n\t\tEnter the amount : ");
                scanf("%d", &amount);
                if (amount % 500 != 0)
                {
                    printf("\n\t The amount should be multiple of 500");
                }
            }
            if (balance < amount)
            {
                printf("\n\t Sorry insufficient balance");
                amount = 1;
                break;
            }
            else
            {
                balance -= amount;
                printf("\n\tYou have withdrwan TK. %d. Your new balance is %.2f", amount, balance);
                amount = 1;
                printf("\n\n\t=====Thank you for your banking with Adv. Learning=======\n");
                break;
            }
        case 2:
            printf("\n\t\t Please enter the amount : ");
            scanf("%d", &amount);
            balance += amount;
            printf("\n\tYou have deposited TK. %d. Your new balance is %.2f", amount, balance);
            amount = 1;
            printf("\n\n\t=======Thank you for your banking with Adv. Learning=======\n");
            break;
        case 3:
            printf("\n\t\tYou have TK. %.2f", balance);
            break;
        default:
            printf("\n\t\tInvalid Option!!!");
            break;
        }
        printf("\n\n  Do you wish to perform another transaction?Press 1[yes] , 2[No]");
        scanf("%d", &continueTransaction);
        system("cls");
    }

    return 0;
}
