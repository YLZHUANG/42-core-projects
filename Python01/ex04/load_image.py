"""
Module for loading images and printing their properties.
bash
pip3 install numpy
pip3 install Pillow

"""
import numpy as np
from PIL import Image


def ft_load(path: str) -> np.ndarray:
    """
    Load an image from a file, print its shape, and
    return pixel data as an array.

    Args:
        path (str): Path to the image file.

    Returns:
        np.ndarray: The image data in RGB format.

    Raises:
        FileNotFoundError: If the file does not exist.
        OSError: If the image format is not supported.
    """
    try:
        with Image.open(path) as img:
            img = img.convert("RGB")
            data = np.array(img)
#           print(f"The shape of image is: {data.shape}")
            return data
    except FileNotFoundError:
        print(f"Error: {path} not found")
    except OSError:
        print(f"Error: can not open {path}, maybe wrong format")
        return np.array([])
