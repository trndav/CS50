scores = [72, 73, 44]
average = sum(scores) / len(scores)
print(f"Average is: {average}")

emptylist = []
for i in range(3):
    x = int(input("Type number: "))
    # emptylist.append(x)
    # Or
    emptylist += [x]

list = sum(emptylist) / len(emptylist)
print(list)