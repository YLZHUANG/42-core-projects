from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""

    def __init__(self, first_name: str, is_alive: bool = True):
        """
        Initialize a Baratheon family member.

        Args:
            first_name (str): The Baratheon's first name.
            is_alive (bool, optional): Whether the character is alive.
                Defaults to True.
        """
        super().__init__(first_name, is_alive)
        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hairs = "dark"

    def die(self) -> None:
        """Kill the Baratheon by setting is_alive to False."""
        self.is_alive = False

    def __str__(self) -> str:
        """Return a string representation of the Baratheon."""
        return f"Vector: ({self.family_name}, {self.eyes}, {self.hairs})"

    def __repr__(self) -> str:
        """Return an official string representation of the Baratheon."""
        return self.__str__()


class Lannister(Character):
    """Representing the Lanniste family."""

    def __init__(self, first_name: str, is_alive: bool = True):
        """
        Initialize a Lannister family member.

        Args:
            first_name (str): The Lannister's first name.
            is_alive (bool, optional): Whether the character is alive.
                Defaults to True.
        """
        super().__init__(first_name, is_alive)
        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hairs = "light"

    def die(self) -> None:
        """Kill the Lannister by setting is_alive to False."""
        self.is_alive = False

    def __str__(self) -> str:
        """Return a string representation of the Lannister."""
        return f"Vector: ({self.family_name}, {self.eyes}, {self.hairs})"

    def __repr__(self) -> str:
        """Return an official string representation of the Lannister."""
        return self.__str__()

    @classmethod
    def create_lannister(cls, first_name: str, is_alive: bool = True):
        """
        Class method to create a Lannister quickly.

        Args:
            first_name (str): The Lannister's first name.
            is_alive (bool, optional): Whether the character is alive.
                Defaults to True.
        """
        return cls(first_name, is_alive)
