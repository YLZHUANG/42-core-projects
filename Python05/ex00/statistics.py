def ft_statistics(*args: any, **kwargs: any) -> None:
    """Compute stats (mean, median, quartile, std, var)
    on *numbers depending on **kwargs"""

    if not args:
        for _ in kwargs:
            print("ERROR")
        return

    if not kwargs:
        print("Error: no kwargs provided")
        return

    numbers = []
    for num in args:
        if isinstance(num, (int, float)):
            numbers.append(num)
        else:
            for _ in kwargs:
                print("Error")
            return
    n = len(numbers)

    def mean():
        return sum(numbers) / n

    def median(num=None):
        if num is None:
            num = numbers
        num.sort()
        n_median = len(num)
        if n_median == 1:
            return num[0]
        mid = n_median // 2
        if n_median % 2 == 0:
            return (num[mid - 1] + num[mid]) / 2
        else:
            return num[mid]

    def quartile():
        if n < 2:
            return None
        sorted_num = sorted(numbers)
        mid = n // 2
        res = []
        if n % 2 > 0:
            res.append(float(median(sorted_num[:mid + 1])))
            res.append(float(median(sorted_num[mid:])))
        else:
            res.append(float(median(sorted_num[:mid])))
            res.append(float(median(sorted_num[mid:])))
        return res

    def var():
        if n < 2:
            return None
        return sum((v - mean()) ** 2 for v in numbers) / n

    def std():
        if n < 2:
            return None
        return var() ** 0.5

    operations = {
        "mean": mean,
        "median": median,
        "quartile": quartile,
        "var": var,
        "std": std,
    }

    for op in kwargs.values():
        if op in operations:
            res = operations[op]()
            if res is None:
                print(f"Error: {op} operation non valid")
            else:
                print(f"{op} : {res}")


# def main():
#     """ Main entry point and test """

#     print("--- Test with error --")
#     ft_statistics(0, toto="mean",
#                   tutu="median", tata="quartile")

#     print("--- Test with error --")
#     ft_statistics(1, toto="mean", tutu="median", tata="quartile")


# if __name__ == "__main__":
#     main()
