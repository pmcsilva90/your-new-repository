expression = input("Expression: ")

x, y, z = expression.split(" ")

x = int(x)
z = int(z)

if y == "+":
    print(x + z)
elif y == "-":
    print(x - z)
elif y == "*":
    print(x * z)
elif y == "/":
    print(x / z)
else:
    print("Expression not supported")