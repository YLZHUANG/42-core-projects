'''
    Program load the image "animal.jpeg", print some information
    about it and display it after "zooming"

    pip3 install matplotlib
'''

import matplotlib.pyplot as plt
from load_image import ft_load


def main():
    """
    Main entry point.
    """
    try:
        img = ft_load("animal.jpeg")
        if img.size == 0:
            return
        print(f"The shape of the image is {img.shape}")
        print(img)

        h, w = img.shape[:2]
        zoomed = img[100:500, 470:870, 0]

        print(f"New shape after slicing: {zoomed.shape}")
        print(zoomed)

        plt.imshow(zoomed, cmap="gray")
        plt.show()

    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
