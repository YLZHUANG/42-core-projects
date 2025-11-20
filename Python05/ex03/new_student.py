import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    """Dataclass representing a student with auto-generated login and ID.

    Fields:
        name (str): Student's first name.
        surname (str): Student's surname.
        active (bool): Active status, defaults to True.
        login (str): Auto-generated login (first letter of name + surname).
        id (str): Auto-generated random 15-character string.
    """
    name: str
    surname: str
    active: bool = True
    login: str = field(init=False)
    id: str = field(init=False)

    def __post_init__(self):
        self.login = self.name[0].upper() + self.surname.lower()
        self.id = generate_id()


# def main():
#     """ Main entry point and test """

#     try:
#         student = Student(name="Edward", surname="agle")
#         print(student)

#         student = Student(name="Edward", surname="agle", id="toto")
#         print(student)

# #        student = Student()
# #        print(student)
#     except TypeError as e:
#         print(f"TypeError: {e}")


# if __name__ == "__main__":
#     main()
