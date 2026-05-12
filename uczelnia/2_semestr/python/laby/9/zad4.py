from random import randint


class DList:
    class Element:
        def __init__(self, value, next=None, prev=None):
            self.__value = value
            self.next = next
            self.prev = prev

        @property
        def value(self):
            return self.__value

    def __init__(self, args: list[int]) -> None:
        self.__root = None
        self.__end = None
        for i in args:
            self.insert(i)

    def insert(self, value: int) -> None:
        new_element = self.Element(value)

        if self.__root is None:
            self.__root = new_element
            self.__end = new_element
            return

        current = self.__root

        while current is not None and current.value < value:
            current = current.next

        if current == self.__root:
            new_element.next = self.__root
            self.__root.prev = new_element
            self.__root = new_element
        elif current is None:
            new_element.prev = self.__end
            self.__end.next = new_element
            self.__end = new_element
        else:
            new_element.next = current
            new_element.prev = current.prev
            current.prev.next = new_element
            current.prev = new_element

    def __iter__(self):
        curr = self.__root
        while curr is not None:
            yield curr.value  # - zwraca generator
            curr = curr.next

    def __reversed__(self):
        curr = self.__end
        while curr is not None:
            yield curr.value
            curr = curr.prev

    def __contains__(self, value):
        current = self.__root
        while current is not None and current.value < value:
            current = current.next
        return current is not None and current.value == value


# - - - - - - - - - - - - - - - - - TESTY - - - - - - - ----------
dlista = DList([2, 3, 4, 5])
for i in dlista:
    print(i)
print("\n - - - - - - - -\n")

dlista = DList([8, 10, 9, 13])
dlista.insert(7)
dlista.insert(12)
dlista.insert(15)

for i in reversed(dlista):
    print(i)

print("\n - - - - - - - -\n")
print(" Contain 8: ", 8 in dlista)
print(" Contain 13: ", 13 in dlista)
print(" Contain 15: ", 15 in dlista)
print(" Contain 6: ", 6 in dlista)
print(" Contain 11: ", 11 in dlista)
print(" Contain 17: ", 17 in dlista)

nowa_lista = DList([])
for i in range(1000):
    nowa_lista.insert(randint(0, 100))

for i in nowa_lista:
    print(i)
