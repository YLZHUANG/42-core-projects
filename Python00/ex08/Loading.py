from time import sleep
from tqdm import tqdm


def ft_tqdm(lst: range) -> None:
    """
    Copy the function tqdm with the yield operator.
    100%|[==============================================
    =================>]| 333/333
    """

    bar_width = 60
    total = len(lst)
    if total == 0:
        return
    bar = ""

    for i, item in enumerate(lst, 1):
        ratio = i / total
        bar = int(ratio * bar_width) * "=" + (int((1-ratio) * bar_width) * " ")
        print(f"\r{int(ratio * 100):3d}%|[{bar}>]| {i}/{total}", end="",
              flush=True)

        yield i

    print()


def main():
    """
    Main entry point.
    Compare the function ft_tqdm with tqdm.
    """

    for elem in ft_tqdm(range(333)):
        sleep(0.005)
    print()
    for elem in tqdm(range(333)):
        sleep(0.005)
    print()


if __name__ == "__main__":
    main()
