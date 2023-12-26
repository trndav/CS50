def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:   
        try:    
            a = int(input("Type height: "))
            if a > 0:
                return a
        except ValueError:
            print("Not an integer")

main()


# x = int(input("Type number of blocks: "))
# for i in range(x):
#     print("#")

# while True:
#     x = int(input("Type number of blocks: "))
#     if x > 0:
#         break

# for i in range(x):
#     print("#")

# def main():
#     height = get_height()
#     for i in range(height):
#         print("#")

# def get_height():
#     while True:       
#         a = int(input("Type height: "))
#         if a > 0:
#             return a

# main()