from abc import ABC, abstractmethod
class Animal(ABC):
    @abstractmethod
    def __init__(self, name):
        self.name = name
    def info(self):
        print(f"I am an animal. My name is {self.name}.")
    def sound():
        pass
class Cat(Animal):
    def __init__(self, name):
        super().__init__(name)
    def info(self):
        print(f"I am a cat. My name is {self.name}.")
    def sound(self):
        print("Meow")
class Dog(Animal):
    def __init__(self, name):
        super().__init__(name)
    def info(self):
        print(f"I am a dog. My name is {self.name}.")
    def sound(self):
        print("Woof")
A = Cat("Win")
B = Dog("Wan")
A.sound()
B.sound()