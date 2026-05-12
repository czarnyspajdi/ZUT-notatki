class PowerOfNumber:
    def __init__(
        self, number: int, exp: int, min_exp: int = 0, max_exp: int = 10
    ) -> None:
        self.exp: int = exp
        self.number: int = number
        self.min_exp: int = min_exp
        self.max_exp: int = max_exp

    def __call__(self) -> int | None:
        if self.min_exp < self.exp < self.max_exp:
            result: int = self.number**self.exp
            self.exp += 1
            return result
        return None


if __name__ == "__main__":
    power = PowerOfNumber(3, 1)
    for _ in range(20):
        result: int | None = power()
        if result:
            print(result)
