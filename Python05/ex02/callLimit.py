def callLimit(limit: int):
    """Decorator that limits the number of times
    a function can be called"""

    count = limit

    def callLimiter(function):

        def limit_function(*args: any, **kwds: any):
            nonlocal count
            if count > 0:
                count -= 1
                return function(*args, **kwds)
            else:
                print(f"Error: {function} call too many times")
        return limit_function
    return callLimiter


# def main():
#     """ Main entry point and test """

#     @callLimit(3)
#     def f():
#         print("f()")

#     @callLimit(1)
#     def g():
#         print("g()")
#     for i in range(3):
#         f()
#         g()

#     print("-----------")

#     @callLimit(1)
#     def do_outer():

#         def pow(x: int | float) -> int | float:
#             """Return x raised to the power of x"""
#             return x ** x

#         def outer(x: int | float, function) -> object:
#             """Return a closure that applies function
#                 cumulatively on x"""
#             count = x

#             def inner() -> float:
#                 nonlocal count
#                 count = function(count)
#                 return count
#             return inner
#         return outer(3, pow)

#     try:
#         res = do_outer()
#         print(res())
#         do_outer()
#     except Exception as e:
#         print(f"Error: {e}")


# if __name__ == "__main__":
#     main()
