from typing import Generator


def power_of_number(number: int, min_exp: int = 0, max_exp: int = 10) -> Generator[int]:
    for i in range(min_exp, max_exp):
        yield number**i


if __name__ == "__main__":
    for i in power_of_number(4):
        print(i)
