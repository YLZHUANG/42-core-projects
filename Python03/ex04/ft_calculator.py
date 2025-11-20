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

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """Compute and print dot product of two vectors."""
        res = 0.0
        for i in range(len(V1)):
            res += (V1[i] * V2[i])
        print(f"Dot product is: {float(res)}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """Compute and print element-wise vector addition."""
        res = [float(v1 + v2) for v1, v2 in zip(V1, V2)]
        print(f"Add Vector is : {res}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """Compute and print element-wise vector subtraction."""
        res = []
        for i in range(len(V1)):
            res.append(float(V1[i] - V2[i]))
        print(f"Sous Vector is: {res}")
