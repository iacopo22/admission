import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("The name of the csv file and the name of the text file containing "
        "the DNA sequence to identify are required.")

    # TODO: Read database file into a variable
    rows = []
    n_rows = 0

    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)

        for row in reader:
            rows.append(row)
            n_rows += 1


    # TODO: Read DNA sequence file into a variable
    DNA = []

    with open(sys.argv[2]) as file:
        reader_ = csv.reader(file)

        for row in reader_:
            DNA.append(row)

    # TODO: Find longest match of each STR in DNA sequence
    for _ in range(n_rows):
        counter = 0

        for i in range(1, len(reader.fieldnames)):
            match = longest_match(str(DNA[0]), reader.fieldnames[i])

            # Check database for matching profiles
            if (int(rows[_][reader.fieldnames[i]]) == match):
                counter += 1
                if (counter == len(reader.fieldnames) - 1):
                    print(f"{rows[_]["name"]} is the matching individual")
                    return 0;

    # If no match is found
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
