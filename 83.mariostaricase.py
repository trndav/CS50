# # Prints one side staircase pyramid
# blocks = int(input("Enter height 1-10: "))

# # Blocks start from 1 and end with blocks+1
# for num in range(1, blocks+1):
#     spaces = " " * (blocks-num)
#     print(spaces + "#" *num)

# TODO
# Prints one side staircase pyramid
def get_valid_input():
    while True:
        try:
            blocks = int(input("Enter height 1 to 8: "))
            if blocks >= 1 and blocks <= 8:
                return blocks
            else:
                print("Invalid input. Try again.")
        except ValueError:
            print("Input must be integer - number.")

# Blocks start from 1 and end with blocks+1
number = get_valid_input()
for num in range(1, number+1):
    spaces = " " * (number-num)
    print(spaces + "#" *num)
