import numpy as np


def policz_wyznaczniki(wspolczynniki: np.ndarray, wolne: np.ndarray):
    for i in range(0, wspolczynniki.shape[1]):
        j = wspolczynniki.copy()
        j = j[:, i] = wolne.copy()
        yield np.linalg.det(j)


def zad5(wspolczynniki: np.ndarray, wolne: np.ndarray):
    glowny = np.linalg.det(wspolczynniki)
    wyniki = []

    for wyznacznik in policz_wyznaczniki(wspolczynniki, wolne):
        wyniki.append(wyznacznik / glowny)

    print(wyniki)


a = np.array([8, 1, 2, 5, -3, -7, 0, -5, 7])
a = a.reshape(3, 3)
b = np.array([16, -22, 11]).T
zad5(a, b)
