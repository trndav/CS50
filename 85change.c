
//Calculate change cents up to 99 cents
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int change;
    do
    {
        printf("Change owed: ");
        scanf("%i", &change);
    } while ( change <= 0 );
    return change;
}

int calculate_quarters(int cents)
{
    int c25;
    c25 = cents / 25;
    return c25;
}

int calculate_dimes(int cents)
{
    int c10;
    c10 = cents / 10;
    return c10;
}

int calculate_nickels(int cents)
{
    int c05;
    c05 = cents / 5;
    return c05;
}

int calculate_pennies(int cents)
{
    int c01;
    c01 = cents / 1;
    return c01;
}
