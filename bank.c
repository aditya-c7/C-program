#include <stdio.h>
#include <unistd.h>  

void checkBalance(float balance);
float deposit();
float withdraw(float balance);
void loadingEffect();

int main() {
    int choice = 0;
    float balance = 0.0f;

    printf("\033[1;34m*** WELCOME TO THE BANK ***\033[0m\n");

    do {
        printf("\033[1;33mSelect Option\033[0m\n");
        printf("\n1.Check Balance\n");
        printf("\n2.Deposit Money\n");
        printf("\n3.Withdraw Money\n");
        printf("\n4.Exit Bank\n");
        printf("\033[1;36mEnter\033[0m option: ");

        if (scanf("%d", &choice) != 1) {
            printf("\033[1;31mInvalid input! Please enter a number (1-4).\033[0m\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("\033[1;31mThanx bye\033[0m\n");
                break;
            default:
                printf("\033[1;31mInvalid choice! Please select between (1-4).\033[0m\n");
                break;
        }

    } while (choice != 4);

    return 0;
}

void checkBalance(float balance) {
    printf("\033[1;32mYour current Balance is: %.2f\033[0m\n", balance);
}

float deposit() {
    float amount = 0.0f;
    
    printf("Enter \033[1;32mamount\033[0m to deposit: ");

    if (scanf("%f", &amount) != 1) {
        printf("\033[1;31mInvalid input! Please enter a valid number.\033[0m\n");
        while (getchar() != '\n');
        return 0.0f;
    }

    if (amount < 0) {
        printf("\033[1;31mInvalid amount. Must be positive.\033[0m\n");
        return 0.0f;
    }

    loadingEffect();  //effect 
    printf("\033[1;32mSuccessfully deposited: %.2f\033[0m\n", amount);
    
    return amount;
}

float withdraw(float balance) {
    float amount = 0.0f;
    printf("Enter amount to withdraw: ");

    if (scanf("%f", &amount) != 1) {
        printf("\033[1;31mInvalid input! Please enter a valid number.\033[0m\n");
        while (getchar() != '\n');
        return 0.0f;
    }

    if (amount < 0) {
        printf("\033[1;31mInvalid amount!\033[0m\n");
        return 0.0f;
    } else if (amount > balance) {
        printf("\033[1;31mInsufficient funds! Your balance is: %.2f\033[0m\n", balance);
        return 0.0f;
    }

    loadingEffect();  //effect 
    printf("\033[1;32m! Successfully withdrew: %.2f\033[0m\n", amount);
    printf("\033[1;32mCurrent Balance is: %.2f\033[0m\n", balance);
    return amount;
}

void loadingEffect() {
    printf("Processing");
    fflush(stdout);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}
