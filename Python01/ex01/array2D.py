"""
Module for slicing 2D arrays.
"""


def slice_me(family: list, start: int, end: int) -> list:
    """
    Slice a 2D array between start and end indices.

    Args:
        family (list): 2D array (list of lists).
        start (int): Starting index for slicing.
        end (int): Ending index for slicing.

    Returns:
        list: Truncated 2D array.

    Raises:
        TypeError: If family is not a list of lists or
        start/end are not integers.
        ValueError: If inner lists are not the same length.
    """
    try:
        if not isinstance(family, list):
            raise TypeError("Family must be list")
        if not isinstance(start, int) or not isinstance(end, int):
            raise TypeError("Start and end must be int")
        if not all(isinstance(row, list) for row in family):
            raise TypeError("Lists in family must be list")
        if len({len(row) for row in family}) > 1:
            raise TypeError("Lists in family must be list")

        rows, cols = len(family), len(family[0]) if family else 0
        print(f"My shape is : ({rows}, {cols})")

        new_family = family[start:end]

        new_rows, new_cols = (
            len(new_family),
            len(new_family[0]) if new_family else 0
        )

        print(f"My new shape is : ({new_rows}, {new_cols})")

        return new_family

    except Exception as e:
        print(f"Error: {e}")
        return []


# def main():

#     """
#     Main entry point for manual testing.
#     """
#     try:
#         family = [[-1.80, -78.4],
#                   [2.15, 102.7],
#                   [0, 98.5],
#                   [1.88, 75.2]]
#         print(slice_me(family, 1, 2))
#         print(slice_me(family, 1, -2))
#     except Exception as e:
#         print(f"Error: {e}")


# if __name__ == "__main__":
#     main()
