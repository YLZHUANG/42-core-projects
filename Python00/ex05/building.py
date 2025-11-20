import sys


def get_result(text: str) -> dict:
    """
    Takes a single string argument and returns a dict with the sums of
    its upper-case letters, lower-case letters, punctuation marks, digits,
    and spaces.
    """

    res = {"upper letters": 0, "lower letters": 0, "punctuation marks": 0,
           "spaces": 0, "digits": 0, }
    punctuationmarks = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

    for c in text:
        if c.isupper():
            res["upper letters"] += 1
        elif c.islower():
            res["lower letters"] += 1
        elif c in punctuationmarks:
            res["punctuation marks"] += 1
        elif c.isspace():
            res["spaces"] += 1
        elif c.isdigit():
            res["digits"] += 1
        else:
            pass

    return res


def main():
    """
    Main entry point.
    - If None or nothing is provided, prompt user and read from stdin.
    - If more than one argument is provided, raise AssertionError.
    - Otherwise, analyze the text and print the report.

    Expected result:
    $>python building.py
    What is the text to count?
    Hello World!
    The text contains 13 characters:
    2 upper letters
    8 lower letters
    1 punctuation marks
    2 spaces
    0 digits

    pip install flake8
◦   alias norminette=flake8
    or python -m flake8
    """

    try:
        ac = len(sys.argv)
        if ac > 2:
            raise AssertionError("More than one argument is provided")
            return 1

        text = ""
        if ac < 2:
            while text == "":
                print("What is the text to count?")
                text = sys.stdin.readline()
        else:
            text = sys.argv[1]

        res = get_result(text)
        print(f"The text contains {len(text)} characters:")
        for k, v in res.items():
            print(f"{v} {k}")
        return 0

    except AssertionError as e:
        print(f"AssertionError: {e}")
        return 1
    except Exception as e:
        print(f"Error: {e}")
        return 1


if __name__ == "__main__":
    main()
