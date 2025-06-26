#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n* Welcome to TAX calculator *                       ---------press>|Enter|\n");
    getchar();
    system("cls");

    double income = 0.0, tax = 0.0, surcharge = 0.0, cess = 0.0;
    int valid_input = 0;

    // Input 
    while (!valid_input)
    {
        printf("Enter your Income / Salary: Rs.");
        if (scanf("%lf", &income) != 1 || income < 0)
        {
            printf("Invalid input! Please enter a valid income.\n");

            // Clear input buffer
            while (getchar() != '\n');
        }
        else
        {
            valid_input = 1;
        }
    }

    // ----Tax Slabs----
    if (income <= 400000)
    {
        tax = 0.0;
        printf("\n0%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else if (income <= 800000)
    {
        tax = (income - 400000) * 0.05;
        printf("\n5%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else if (income <= 1200000)
    {
        tax = (400000 * 0.05) + (income - 800000) * 0.10;
        printf("\n10%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else if (income <= 1600000)
    {
        tax = (400000 * 0.05) + (400000 * 0.10) + (income - 1200000) * 0.15;
        printf("\n15%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else if (income <= 2000000)
    {
        tax = (400000 * 0.05) + (400000 * 0.10) + (400000 * 0.15) + (income - 1600000) * 0.20;
        printf("\n20%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else if (income <= 2400000)
    {
        tax = (400000 * 0.05) + (400000 * 0.10) + (400000 * 0.15) + (400000 * 0.20) + (income - 2000000) * 0.25;
        printf("\n25%% Tax applicable | Tax = Rs.%.2lf", tax);
    }
    else
    {
        tax = (400000 * 0.05) + (400000 * 0.10) + (400000 * 0.15) + (400000 * 0.20) + (400000 * 0.25) + (income - 2400000) * 0.30;
        printf("\n30%% Tax applicable | Tax = Rs.%.2lf", tax);
    }

    // ----Surcharge----
    if (income > 5000000 && income <= 10000000)
    {
        surcharge = tax * 0.10;
        tax += surcharge;
        printf("\n10%% Surcharge Applied | Tax = Rs.%.2lf", tax);
    }
    else if (income > 10000000 && income <= 20000000)
    {
        surcharge = tax * 0.15;
        tax += surcharge;
        printf("\n15%% Surcharge Applied | Tax = Rs.%.2lf", tax);
    }
    else if (income > 20000000 && income <= 50000000)
    {
        surcharge = tax * 0.25;
        tax += surcharge;
        printf("\n25%% Surcharge Applied | Tax = Rs.%.2lf", tax);
    }
    else if (income > 50000000)
    {
        surcharge = tax * 0.37;
        tax += surcharge;
        printf("\n37%% Surcharge Applied | Tax = Rs.%.2lf", tax);
    }

    // ----Cess----
    cess = tax * 0.04;
    tax += cess;
    printf("\n4%% Health & Education Cess Applied \n Final Tax = Rs.%.2lf\n", tax);

    return 0;
}
