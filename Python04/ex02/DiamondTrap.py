from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """Representing King Joffrey, inheriting from both
    Baratheon and Lannister."""

    def __init__(self, first_name: str, is_alive: bool = True):
        """
        Initialize a King family member.

        Args:
            first_name (str): The King's first name.
            is_alive (bool, optional): Whether the character is alive.
                Defaults to True.
        """
        super().__init__(first_name, is_alive)

    def set_eyes(self, color: str) -> None:
        """Set the eye color of the king."""
        self.eyes = color

    def get_eyes(self) -> str:
        """Get the eye color of the king."""
        return self.eyes

    def set_hairs(self, color: str) -> None:
        """Set the hair color of the king."""
        self.hairs = color

    def get_hairs(self) -> str:
        """Get the hair color of the king."""
        return self.hairs
