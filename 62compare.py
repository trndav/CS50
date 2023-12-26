x = input("Do you agree? (Y or N) ")
if x == "Y" or x == "y":
    print("Agreed!")
elif x in ["N", "n", "NO", "No"]:
    print("Not agreed!")
elif x.lower() in ["G", "g"]:
    print("Typed G!")
else:
    print("Not correct input!")
