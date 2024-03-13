import sys

def main():

    line_count = 0

    if len(sys.argv) == 2:
        try:
            with open(sys.argv[1]) as file:
                for line in file:
                    line = line.strip()
                    if line.startswith('"""') or line.startswith("#"):
                        continue
                    else:
                        line_count += 1
        except FileNotFoundError:
            sys.exit("File does not exist")
    elif len(sys.argv) < 2:
        sys.exit("Too few command-line arguments")
    else:
        sys.exit("Too many command-line arguments")

    print(line_count)

if __name__ == "__main__":
    main()
