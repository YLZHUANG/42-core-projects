import sys
from ft_filter import ft_filter


def main():
    """
    Main entry point.
    Accepts two arguments: a string(S), and an integer(N).
    Output a list of words from S that have a length greater than N.
    • Words are separated from each other by space characters.
    • Strings do not contain any special characters. (Punctuation or invisible)
    • The program must contain at least one list comprehension expression and
    one lambda.
    • If the number of argument is different from 2, or if the type of any
    argument is wrong, the program prints an AssertionError.
    """

    try:

        ac = len(sys.argv)
        if ac != 3:
            raise AssertionError("the arguments are bad")

        S = sys.argv[1]

        try:
            N = int(sys.argv[2])
        except ValueError:
            raise AssertionError("the arguments are bad")

        words = S.split()
        print(list(ft_filter(lambda s: len(s) > N, words)))
        return 0

    except AssertionError:
        print("AssertionError: the arguments are bad")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
