from load_csv import load
import matplotlib.pyplot as plt


def main():
    """
    Main entry point.
    Plot and compare life expectancy over time for 2 countries.
    """
    try:
        df = load("population_total.csv")
        if df is None:
            print("Failed loading data")
            return

        if "France" not in df["country"].values:
            print("Data not available for France")
            return

        if "Belgium" not in df["country"].values:
            print("Data not available for Belgium")
            return

        def to_number(val: str):
            if val.endswith("M"):
                return float(val[:-1]) * 1_000_000
            elif val.endswith("B"):
                return float(val[:-1]) * 1_000_000_000
            else:
                return float(val)

        values_France = df[df["country"] == "France"].iloc[0, 1:]
        values_belgium = df[df["country"] == "Belgium"].iloc[0, 1:]

        mask = (
            (values_France.index.astype(int) >= 1800)
            & (values_France.index.astype(int) <= 2050)
        )

        values_belgium = values_belgium[mask].apply(to_number)
        values_France = values_France[mask].apply(to_number)
        years = values_France.index

        plt.figure()
        plt.plot(years, values_belgium, label="Belgium", color="blue")
        plt.plot(years, values_France, label="France", color="green")
        plt.title("Population Projections")
        plt.xlabel("Year")
        plt.ylabel("Population")
        plt.xticks(years[::40])
        plt.yticks([20000000, 40000000, 60000000], ["20M", "40M", "60M"])
        plt.legend()
        plt.show()

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
