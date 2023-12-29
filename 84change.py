def calculate_change_coins(change):
    quarters = 25
    dimes = 10
    nickels = 5
    pennies = 1

    # Calculate the number of quarters
    num_quarters = change // quarters
    #change %= quarters
    change = change - (num_quarters*quarters)

    num_dimes = change // dimes
    change %= dimes

    num_nickels = change // nickels
    change %= nickels

    # The remaining change will be in pennies
    num_pennies = change

    return num_quarters, num_dimes, num_nickels, num_pennies

def main():
    while True:
        try:
            # Get input from the user
            amount = float(input("Change owed: "))

            if amount < 0:
                raise ValueError("Amount cannot be less than 0.")

            # Convert dollar and cent amount to cents
            change = int(amount * 100)

            # Calculate minimum number of coins needed
            quarters, dimes, nickels, pennies = calculate_change_coins(change)

            # Print the result
            print(quarters + dimes + nickels + pennies)
            break

        except ValueError as e:
            print(f"Invalid input: {e}")

if __name__ == "__main__":
    main()
