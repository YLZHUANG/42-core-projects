def count_in_list(lst: list, item):

    """
    Count occurrences of `item` in `lst`.

    Args:
        lst (list): The list in which to search.
        item (Any): The item to count.

    Returns:
        int: Number of times item appears in lst.
    """

    if not isinstance(lst, list):
        raise TypeError("First argument must be a list")

    return lst.count(item)

# def main():
#     """
#     Main entry point.
#     """
#     try:
#         pass
#         # print(count_in_list(["toto", "tata", "toto"], "toto")) # 2
#         # print(count_in_list(["toto", "tata", "toto"], "tutu")) # 0

#         # print(count_in_list([1, 2, 3, 1, 1], 1))                # 3
#         # print(count_in_list([], "foo"))                         # 0
#     except Exception as e:
#         print(f"Error: {e}")


# if __name__ == "__main__":
#     main()
