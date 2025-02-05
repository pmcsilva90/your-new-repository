import sys
from tabulate import tabulate
import csv


def main():

    if len(sys.argv) == 2:
        if is_csv(sys.argv[1]):
            try:
                table(sys.argv[1])
            except FileNotFoundError:
                sys.exit("File does not exist")
        else:
            sys.exit("Not a CSV file")
    elif len(sys.argv) < 2:
        sys.exit("Too few arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many arguments")


def is_csv(filename):
    if filename.endswith(".csv"):
        return True
    return False


def table(filename):

    data = []

    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            data.append(row)

    print()
    print(tabulate(data, headers="keys", tablefmt="grid"))
    print()


if __name__ == "__main__":
    main()
