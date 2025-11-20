import pandas as pd


def load(path: str) -> pd.DataFrame | None:
    """
    pip3 install pandas

    Loads a dataset from a CSV file using pandas.

    Args:
        path (str): Path to the CSV file.

    Returns:
        pd.DataFrame | None: The loaded DataFrame
        if successful, else None.
    """
    try:
        data = pd.read_csv(path)
        print(f"Loading dataset of dimensions {data.shape}")
        return data
    except (
        FileNotFoundError,
        pd.errors.EmptyDataError,
        pd.errors.ParserError
    ) as e:
        print(f"Error: {e}")
        return None
    except Exception as e:
        print(f"Unexpected error: {e}")
        return None


def main():
    """
    Main entry point.
    """
    try:
        pass
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
