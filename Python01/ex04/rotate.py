'''
    Program load the image "animal.jpeg", print some information
    about it and display it after "zooming" and transpose it
'''

import matplotlib.pyplot as plt
from load_image import ft_load
from numpy import ndarray


def ft_transpose(image):
    """
    Transpose the given image.

    Args:
        image (np.ndarray): The input image array.

    Returns:
        np.ndarray: The transposed image array.
    """
    rows, cols = image.shape
    result = ndarray((cols, rows), dtype=image.dtype)
    for r in range(rows):
        for c in range(cols):
            result[c, r] = image[r, c]
    return result


def main():
    """
    Main entry point.
    """
    try:
        img = ft_load("animal.jpeg")
        if img is None:
            return
        if img.size == 0:
            print("Error: Loaded image is empty")
            return
        print(f"The shape of the image is {img.shape}")
        print(img)

        h, w = img.shape[:2]
        zoomed = img[100:500, 470:870, 0]
        if zoomed.size == 0:
            print("Error: Zoomed image is empty")
            return

        transposed = ft_transpose(zoomed)
        if transposed.size == 0:
            print("Error: Transposed image is empty")
            return

        print(f"New shape after Transpose: {transposed.shape}")
        print(transposed)

        plt.imshow(transposed, cmap="gray")
        plt.show()

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
