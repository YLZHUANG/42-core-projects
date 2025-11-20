def square(x: int | float) -> int | float:
    """Return the square of x"""
    return x * x


def pow(x: int | float) -> int | float:
    """Return x raised to the power of x"""
    if x == 0:
        return 1
    return x ** x


def outer(x: int | float, function) -> object:
    """Return a closure that applies function
        cumulatively on x"""
    count = x

    def inner() -> float:
        nonlocal count
        count = function(count)
        return count
    return inner


# def main():
#     """ Main entry point and test """

#     operation = (square, pow)
#     op_to_test = square

#     if op_to_test not in operation:
#         print("Not available operation")
#         return

#     my_counter = outer(3, square)
#     print(my_counter())
#     print(my_counter())
#     print(my_counter())
#     print("---")
#     another_counter = outer(1.5, pow)
#     print(another_counter())
#     print(another_counter())
#     print(another_counter())
#     print("---")
#     test_counter = outer(100, op_to_test)
#     print(test_counter())
#     print(test_counter())
#     print(test_counter())


# if __name__ == "__main__":
#     main()
