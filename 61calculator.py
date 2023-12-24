# x = input("Add number value for x: ")
# y = input("Add number value for y: ")
# print(int(x)+int(y))

print("Second way")
a = int(input("Add number value for a: "))
b = int(input("Add number value for b: "))
print(a+b)

z = a / b
print(f"{z:.25f}")
# Or
format_z = format(z, ".25f")
print("Value is " + format_z)