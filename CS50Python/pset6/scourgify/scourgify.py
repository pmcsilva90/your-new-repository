import sys
import csv


def main():

    if len(sys.argv) == 3:
        if is_csv(sys.argv[1]) and is_csv(sys.argv[2]):
            try:
                convert(sys.argv[1], sys.argv[2])
            except FileNotFoundError:
                sys.exit("File does not exist")
        else:
            sys.exit("Not a CSV file")
    elif len(sys.argv) < 3:
        sys.exit("Too few arguments")
    elif len(sys.argv) > 3:
        sys.exit("Too many arguments")


def is_csv(filename):
    if filename.endswith(".csv"):
        return True
    return False


def convert(finput, foutput):
    data = []

    with open(finput) as file:
        reader = csv.DictReader(file)
        for row in reader:
            data.append(row)

    for val in data:
        val = val.replace('"', '')


    with open(foutput, "a") as file:
        writer = csv.DictWriter


if __name__ == "__main__":
    main()
