import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) == 3 and sys.argv[1].endswith(".csv") and sys.argv[2].endswith(".txt"):
        pass
    else:
        sys.exit(f"usage: {sys.argv[0]} file.csv file.txt")

    csv_file = sys.argv[1]
    txt_file = sys.argv[2]

    # TODO: Read database file into a variable

    database = []
    with open(csv_file) as file:
        reader = csv.DictReader(file)
        for row in reader:
            data = {}
            keys = []
            for key, value in row.items():
                try:
                    data[key] = int(value)
                except ValueError:
                    data[key] = value
                keys.append(key)
            database.append(data)

    # print(database)
    # print()
    # print(keys)


    # TODO: Read DNA sequence file into a variable

    with open(txt_file) as file:
        sequence = file.readline().strip()

    # print(sequence)

    # TODO: Find longest match of each STR in DNA sequence

    longest_STR = []
    for key in keys:
        if key == "name":
            continue
        else:
            longest_STR.append({key: longest_match(sequence, key)})
    #         print(f"{key}:", longest_match(sequence, str(key)))
    # print()
    # print(longest_STR)

    # TODO: Check database for matching profiles

    for profile in database:
        match = True
        for STR_dict in longest_STR:
            for k, v in STR_dict.items():
                if v != profile[k]:
                    match = False
                    break
            if not match:
                break
        if match:
            print(profile["name"])
            return


    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
