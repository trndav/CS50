# If banker does not respond with hello, customer get 100$.
# If banker responds with first letter "h", customer get 20$.
# If banker responds with hello, customer get 0$.

greet = input("You are banker, and customer approach and say 'Hello'. What you say? \n")
lst = greet.lower().split()
if lst[0] == "hello":
    print("0$")

elif lst[0][0] == "h":
        print("20$")

else:
    print("100$")

