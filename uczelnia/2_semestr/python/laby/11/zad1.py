import numpy as np


def zad1(n: int) -> None:
    a: np.ndarray = np.ones((n, n))
    exp = np.arange(0, n)

    for i in range(1, n):
        a[i, :] = i + 1
        a[i, :] **= exp
    return a


if __name__ == "__main__":
    a = zad1(5)
    print(a)
