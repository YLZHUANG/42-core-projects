"""
Module for BMI calculation and filtering.
"""


def give_bmi(
    height: list[int | float],
    weight: list[int | float]
) -> list[int | float]:

    """
    Compute the BMI for each (height, weight) pair.

    Args:
        height (list[int | float]): List of heights in meters.
        weight (list[int | float]): List of weights in kilograms.

    Returns:
        list[int | float]: List of BMI values.

    Raises:
        TypeError: If inputs are not lists of int/float.
        ValueError: If lists are not the same length or contain invalid values.
    """
    try:
        if not isinstance(height, list) or not isinstance(weight, list):
            raise TypeError("Height and weight must be lists")
        if len(height) != len(weight):
            raise ValueError("Height and weight must have the same length")

        bmi: [int | float] = []
        for h, w in zip(height, weight):
            if h <= 0:
                raise ValueError("Height must be positive")
            if w <= 0:
                raise ValueError("Weight must be positive")
            bmi.append(w / (h ** 2))
        return bmi
    except Exception as e:
        print(f"Error: {e}")
        return []


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:

    """
    Apply a BMI limit to check if values exceed it.

    Args:
        bmi (list[int | float]): List of BMI values.
        limit (int): BMI threshold.

    Returns:
        list[bool]: List of booleans (True if above the limit).

    Raises:
        TypeError: If BMI values are not int/float or limit not int.
    """

    try:
        if not isinstance(bmi, list) or not isinstance(limit, int):
            raise TypeError("Bmi must be list, limit must be integer")

        res: list[bool] = []
        for value in bmi:
            if not isinstance(value, (int, float)):
                raise ValueError("Bmi must be integer or float")
            res.append(value > limit)
        return res
    except Exception as e:
        print(f"Error: {e}")
        return []


def main():

    try:
        height = [2, 1]
        weight = [165.3, 38.4]
        bmi = give_bmi(height, weight)

        print("=== Test 1, not ok ===")
        print(bmi, type(bmi))
        print(apply_limit(2, "notok"))

        print("=== Test 2, ok ===")
        print(bmi, type(bmi))
        print(apply_limit(bmi, 20))

        print("=== Test 3, ok ===")
        print(bmi, type(bmi))
        print(apply_limit(bmi, 50))

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
