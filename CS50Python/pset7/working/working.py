import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    matches = re.search(r"^(\d{1,2}):?(\d{2})? (AM|PM) (to|-) (\d{1,2}):?(\d{2})? (AM|PM)", s)
    print(matches.groups())

    for n in range(1, len(matches.groups())):
        print(matches.group(n), type(matches.group(n)))


if __name__ == "__main__":
    main()
