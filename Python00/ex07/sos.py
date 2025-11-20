import sys


def main():
    """
    Main entry point.
    takes a string as an argument and encodes it into Morse Code.
    """

    NESTED_MORSE = {
        " ": "/ ", "A": ".- ", "B": "-... ", "C": "-.-. ",
        "D": "-.. ", "E": ". ", "F": "..-. ", "G": "--. ",
        "H": ".... ", "I": ".. ", "J": ".--- ", "K": "-.- ",
        "L": ".-.. ", "M": "-- ", "N": "-. ", "O": "--- ",
        "P": ".--. ", "Q": "--.- ", "R": ".-. ", "S": "... ",
        "T": "- ", "U": "..- ", "V": "...- ", "W": ".-- ",
        "X": "-..- ", "Y": "-.-- ", "Z": "--.. ",
        "0": "----- ", "1": ".---- ", "2": "..--- ",
        "3": "...-- ", "4": "....- ", "5": "..... ",
        "6": "-.... ", "7": "--... ", "8": "---.. ",
        "9": "----. ",
    }

    try:

        ac = len(sys.argv)

        if ac != 2:
            raise AssertionError("the arguments are bad")

        res = []

        string = sys.argv[1].upper()
        for c in string:
            if c not in NESTED_MORSE:
                raise AssertionError("the arguments are bad")
            res.append(NESTED_MORSE[c])

        print(''.join(res).strip())

    except AssertionError as e:
        print(f"AssertionError: {e}")
    except Exception as e:
        print(f"Error: no supported characters / {e}")


if __name__ == "__main__":
    main()
