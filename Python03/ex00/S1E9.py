from abc import ABC, abstractmethod


class Character(ABC):
    """Abstract base class representing a character"""

    @abstractmethod
    def __init__(self, first_name: str, is_alive: bool = True):
        """
        Initialize a character with a name and alive status.

        Args:
            first_name (str): The character's first name.
            is_alive (bool, optional): Whether the character is alive.
            Defaults to True.
        """
        self.first_name = first_name
        self.is_alive = is_alive

    @abstractmethod
    def die(self) -> None:
        """Method that passes is_alive from True to False"""
        self.is_alive = False


class Stark(Character):
    """Class herites from Class Character, representing a Stark."""

    def __init__(self, first_name: str, is_alive: bool = True):
        """
        Initialize a Stark family member.

        Args:
            first_name (str): The Stark's first name.
            is_alive (bool, optional): Whether the Stark is alive.
            Defaults to True.
        """
        super().__init__(first_name, is_alive)

    def die(self) -> None:
        """Methode that kill a Stack,
        passes is_alive from True to False
        """
        self.is_alive = False
