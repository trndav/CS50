books = []
for i in range(2):
    book = dict()
    book["title"] = input("Add title: ").strip().capitalize()
    book["author"] = input("Add author: ").strip().capitalize()
    print(book)
    books.append(book)

print(f"Books in list are: {books}.")

for book in books:
    print(book["title"])

