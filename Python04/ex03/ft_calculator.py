class calculator:
    """A simple vector calculator for scalar operations."""

    def __init__(self, object: list):
        """
        Initialize with a list of numbers (ints/floats allowed).
        Internally stored as floats.
        """
        self.object = [float(x) for x in object]

    def __add__(self, scalar: int | float) -> None:
        """Add scalar to all elements."""
        self.object = [x + scalar for x in self.object]
        print(self.object)

    def __sub__(self, scalar: int | float) -> None:
        """Subtract scalar from all elements."""
        self.object = [x - scalar for x in self.object]
        print(self.object)

    def __mul__(self, scalar: int | float) -> None:
        """Multiply all elements by scalar."""
        self.object = [x * scalar for x in self.object]
        print(self.object)

    def __truediv__(self, scalar: int | float) -> None:
        """Divide all elements by scalar, handle division by zero)."""
        try:
            self.object = [x / scalar for x in self.object]
            print(self.object)
        except ZeroDivisionError:
            print("Error: Division by zero is not allowed")
