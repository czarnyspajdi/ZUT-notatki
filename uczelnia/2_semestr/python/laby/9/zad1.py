class PowerOfTwo:
    def __init__(self, exp) -> None:
        self.exp = exp

    def __call__(self) -> int:
        result: int = 2**self.exp
        self.exp += 1
        return result


if __name__ == "__main__":
    power = PowerOfTwo(1)
    for _ in range(10):
        print(power())
