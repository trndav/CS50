i = 0
while i < 3:
    print("Repeat " + str(i) + " times.")
    i += 1

for i in [0, 1, 2]:
    print("I is: " + str(i) + ".") 

# def main():
#     for i in range(2):
#         repeat() 

# def repeat():
#     print("Repeater")

# main()

def main():   
    repeat(2) 

def repeat(n):
    for i in range(n):
        print("Repeater")

main()