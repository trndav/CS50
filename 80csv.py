import csv
# Or more precise
# from csv import DictReader

names = []
with open("phonebook.csv") as file:
    # text = file.read()
    # print(text)
    file_reader = csv.DictReader(file) # Or cs.reader(file) then later print(row[0])
    for something in file_reader:
        print(something["name"])
        names.append(something["name"])

print(names)

# file = open("phonebook.csv")
...
# close(file)