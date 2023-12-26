for i in range(3):
    print("X", end="") # Override end/new line. end argument by default is \n
print()
print("?" *3)

for i in range(3):
    for j in range(3):
        print("#", end="")
    print()

for i in range(3):
    print("O" *3)