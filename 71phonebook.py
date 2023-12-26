# people = dict()
# Or
people = {
    "Carter": "+1-232-334-352",
    "Ron": "+387-344-223-442"
}
name = input("Type name: ")
if name in people:
    number = people[name]
    print(f"Name : {name} is in dictionary. Number is: {number}.")
else:
    print("Name is not in dictionary.")