'''
Functions to apply simple filters to an RGB image.
'''

import numpy as np
import matplotlib.pyplot as plt


def ft_invert(array: np.ndarray) -> np.ndarray:
    """
    Inverts the color of the image received.
    Allowed operators: =, +, -, *
    """
    try:
        if not isinstance(array, np.ndarray) or array.ndim != 3 \
           or array.shape[2] != 3:
            raise TypeError("Array must be 3D RGB numpy array")
        new_array = 255 - array
        plt.imshow(new_array)
        plt.axis("off")
        plt.show()
        return new_array
    except TypeError as e:
        print(f"Error: {e}")
        return np.array([])


def ft_red(array: np.ndarray) -> np.ndarray:
    """
    Keeps only the red channel of the image.
    Allowed operators: =, *
    """
    try:
        if not isinstance(array, np.ndarray) or array.ndim != 3 \
           or array.shape[2] != 3:
            raise TypeError("Array must be 3D RGB numpy array")
        new_array = array.copy()
        new_array[:, :, 1] *= 0
        new_array[:, :, 2] *= 0
        plt.imshow(new_array)
        plt.axis("off")
        plt.show()
        return new_array
    except TypeError as e:
        print(f"Error: {e}")
        return np.array([])


def ft_green(array: np.ndarray) -> np.ndarray:
    """
    Keeps only the green channel of the image.
    Allowed operators: =, -
    """
    try:
        if not isinstance(array, np.ndarray) or array.ndim != 3 \
           or array.shape[2] != 3:
            raise TypeError("Array must be 3D RGB numpy array")
        new_array = array.copy()
        new_array[:, :, 0] -= new_array[:, :, 0]
        new_array[:, :, 2] -= new_array[:, :, 2]
        plt.imshow(new_array)
        plt.axis("off")
        plt.show()
        return new_array
    except TypeError as e:
        print(f"Error: {e}")
        return np.array([])


def ft_blue(array: np.ndarray) -> np.ndarray:
    """
    Keeps only the blue channel of the image.
    Allowed operators: =
    """
    try:
        if not isinstance(array, np.ndarray) or array.ndim != 3 \
           or array.shape[2] != 3:
            raise TypeError("Array must be 3D RGB numpy array")
        new_array = np.zeros_like(array)
        new_array[:, :, 2] = array[:, :, 2]
        plt.imshow(new_array)
        plt.axis("off")
        plt.show()
        return new_array
    except TypeError as e:
        print(f"Error: {e}")
        return np.array([])


def ft_grey(array: np.ndarray) -> np.ndarray:
    """
    Converts the image to greyscale by averaging the RGB channels.
    Allowed operators: =, /
    """
    try:
        if not isinstance(array, np.ndarray) or array.ndim != 3 \
           or array.shape[2] != 3:
            raise TypeError("Array must be 3D RGB numpy array")
        new_array = array.mean(axis=2, keepdims=True)
        new_array = new_array.astype(np.uint8)
        new_array = np.repeat(new_array, 3, axis=2)
        plt.imshow(new_array)
        plt.axis("off")
        plt.show()
        return new_array
    except TypeError as e:
        print(f"Error: {e}")
        return np.array([])
