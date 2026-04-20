import math

from converters import FuelConsumptionConverter as f
from converters import UnitConventer as u
from math_stuff import matrix


def zad1():
    print(dir(math))


def zad2():
    help(math.cos)  # radiany


def zad4_5():
    liczba = 10
    print(u.funt_kg(liczba))
    print(u.stopy_m(liczba))
    print(u.cale_m(liczba))
    print(u.mile_km(liczba))
    print(u.gale_l(liczba))
    print(u.kg_funty(liczba))
    print(u.m_stopy(liczba))
    print(u.m_cale(liczba))
    print(u.km_mile(liczba))
    print(u.l_gale(liczba))


def zad6():
    print(f.lp100km2mp(15))
    print(f.mpg2lp100km(15))


def zad7():
    help(f.lp100km2mp)


def zad8():
    m1: matrix.matrix = matrix.matrix([[1, 1, 1], [1, 2, 3]])
    m2: matrix.matrix = matrix.matrix([[3, 2, 1], [1, 2, 3]])
    matrix.add(m1, m2)
    print(m1.matrix)

    matrix.add_constant(m1, 5)
    print(m1.matrix)

    print(matrix.multiplication(m1, m2).matrix)
    matrix.multiplication_scalar(m1, 5)
    print(m1.matrix)
    print(matrix.multiplication_hadamar(m1, m2).matrix)
    print(matrix.multiplication_kronecker(m1, m2).matrix)


if __name__ == "__main__":
    zad8()
