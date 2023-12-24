x = input("Type number for x: ")
y = input("Type number for y: ")
if x<y:
    print("x: " + x + " is less than y: " + y)
elif x>y:
    print("x: " + x + " is greater than y: " + y)
else:
    print("x: " + x + " is equal to y: " + y)

for i in range(3):
    print("i is: " + str(i))

x = 0
while x<3:
    print("x is: " + str(x))
    x += 1