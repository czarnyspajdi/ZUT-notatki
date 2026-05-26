import numpy as np


def zad2(n: int) -> np.ndarray:
    n_2 = n**2
    a: np.ndarray = np.arange(1, n_2 + 1)
    a = a.reshape(n, n)

    for i in range(1, n + 1):
        if i % 2 != 0:
            a[i, :] = np.flip(a[i, :])
    return a


def zad3(a: np.ndarray):
    mask = a % 5 == 0
    a[mask] = 0
    mask = a % 3 == 0
    a[mask] = 0
    return a


if __name__ == "__main__":
    a = zad2(4)
    a = zad3(a)
    print(a)
