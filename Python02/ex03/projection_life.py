import matplotlib.pyplot as plt
# import matplotlib.ticker as ticker
from load_csv import load


def plot_le_vs_gdp(
        gdp_path: str,
        le_path: str
) -> None:
    """
    Plot life expectancy in relation to GDP for 1900.

    Args:
        gdp_path (str): Path to the GDP per person dataset.
        le_path (str): Path to the life expectancy dataset.
        year (str): Year to plot (default "1900").

    Returns:
        None
    """
    try:
        gdp = load(gdp_path)
        if gdp is None:
            return
        le = load(le_path)
        if le is None:
            return

        merged_df = gdp.merge(le, on="country", suffixes=("_gdp", "_le"))
        x_values = merged_df["1900_gdp"]
        y_values = merged_df["1900_le"]

        plt.figure()
        plt.title("1900")
        plt.scatter(x_values, y_values)
        plt.xlabel("Gross domestic product")
        plt.ylabel("Life Expectancy")

        plt.xscale("log")
#       plt.gca().xaxis.set_major_formatter(ticker.FuncFormatter(
#       lambda val, _:f"{int(val):,}".replace(",", "k")
#       if val >= 1000 else str(int(val))
#       ))
        plt.xticks([300, 1000, 10000], ["300", "1k", "10k"])
        plt.show()

    except Exception as e:
        print(f"Error during plotting: {e}")


def main():
    """
    Main entry point: load datasets and plot the projection.
    """
    try:
        plot_le_vs_gdp(
            "income_per_person_gdppercapita_ppp_inflation_adjusted.csv",
            "life_expectancy_years.csv"
        )
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
