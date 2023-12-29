text = " some TExt wiTh whiTEspaces   "
x = text.strip()
print(x)

y = text.strip().capitalize()
print(y)

for c in text:
    print(c, end="")

print()

lst = text.split()
print(lst)

for word in lst:
    print(f"{word}, ", end="")