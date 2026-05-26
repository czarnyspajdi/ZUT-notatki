import numpy as np


def zad2(n: int) -> np.ndarray:
    n_2 = n**2
    a: np.ndarray = np.arange(1, n_2 + 1)
    a = a.reshape(n, n)

    for i in range(1, n + 1):
        if i % 2 != 0:
            a[i, :] = np.flip(a[i, :])
    return a


if __name__ == "__main__":
    a = zad2(4)
    print(a)
