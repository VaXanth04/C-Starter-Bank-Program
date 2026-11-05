#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    float balance = 53.41;
    int answerpin;
    int code = 9691;
    int attempts = 3;
    float addmoney;
    int y;

    printf("========================================================================================================================\n");
    printf("                                                         BANK MENU\n");
    printf("========================================================================================================================\n\n");
    printf("                                                          WELCOME\n\n");
    printf("                                                    1. Check Balance\n");
    printf("                                                    2. Deposit Money\n");
    printf("                                                    3. Withdraw Money\n");
    printf("                                                    4. Change PIN\n");
    printf("                                                    5. Exit\n\n");
    printf("========================================================================================================================\n\n");
    Sleep(1000);
    printf("                                                         Loading...\n\n");
    Sleep(2000);
    printf("                                             Please enter your 4 digit PIN code: \n");

    while(code != answerpin && attempts > 0){
        scanf("%d", &answerpin);

        if(code != answerpin ){
            attempts--;
            printf("                                               \033[31mWrong PIN!(%d attempts remaining)\033[0m\n", attempts);

            if(attempts == 0){
                printf("\033[31mSession Terminated!\033[0m\n");
                return 0;

            }
        }else printf("                                                       Welcome user04!\n\n");

    }
    printf("                                                       Initializing...\n\n");
    Sleep(2000);
    printf("                             \033[32mYou are now logged into your account! Choose an option from the menu!\033[0m\n");
    scanf("%d", &y);
    while (y != 5){
        if (y == 1){
            printf("=======================================================================================================================\n");
            printf("                                               Your balance is at %.2f $ !\n", balance);
            printf("=======================================================================================================================\n");
            printf("\nChoose another option: ");
            scanf("%d", &y);
        }else if(y == 2){
            printf("                                          How much money would you like to deposit?\n");
            scanf("%f", &addmoney);

            while(addmoney <= 0){
                printf("\033[31mThat is not a valid amount! Please try again!\033[0m\n");
                scanf("%f", &addmoney);
            }
            printf("Processing...\n");
            Sleep(1000);
            printf("                                    \033[32m%.2f $ has been successfully added to your account!\033[0m\n", addmoney);
            balance += addmoney;
            printf("\nChoose another option: ");
            scanf("%d", &y);

        }else if(y == 3){
            printf("How much money would you like to withdraw?\n");
            scanf("%f", &addmoney);
            while(addmoney <= 0){
                printf("                                       \033[31mThat is not a valid amount! Please try again!\033[0m\n");
                scanf("%f", &addmoney);
            }
            if(balance < addmoney){
                printf("\033[31mInsufficient funds!\033[0m\n");
            }
            else{
                printf("Processing...\n");
                Sleep(1000);
                printf("                                  \033[32m%.2f $ has been successfully withdrawn from your account!\033[0m\n", addmoney);
                balance -= addmoney;
            }
            printf("\nChoose another option: ");
            scanf("%d", &y);
        }else if(y == 4){
            printf("Please type you current PIN: \n");
            scanf("%d", &answerpin);
            if(answerpin == code){
                printf("Yoy may proceed!\n");
                printf("Please type your new PIN: \n");
                scanf("%d", &answerpin);
                code == answerpin;
                printf("Your PIN has changed successfully!\n");
                printf("\nChoose another option: ");
                scanf("%d", &y);

            }else{
                while(answerpin != code){
                    printf("That is not the right PIN! Please try again!\n");
                    scanf("%d", &answerpin);
                }

            }

        }else if(y == 5){
        printf("Session Terminated!");
            return 0;}
        while (y > 4 || y < 1){
            printf("\033[31mThat is not an option! Please try again!\033[0m\n");
            scanf("%d", &y); }



    }

}
