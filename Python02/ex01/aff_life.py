from load_csv import load
import matplotlib.pyplot as plt


def main():
    """
    Main entry point.
    Plot life expectancy over time for a given country.
    """
    try:
        df = load("life_expectancy_years.csv")
        if df is None:
            return

        if "France" not in df["country"].values:
            print("Data not available for this country")
            return

        years = df.columns[1:]
        values = df[df["country"] == "France"].iloc[0, 1:]

        plt.figure()
        plt.plot(years, values)
        plt.title("France Life expectancy Projections")
        plt.xlabel("Year")
        plt.ylabel("Life expectancy")
        plt.xticks(years[::40])
        plt.show()
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
