def lp100km2mp(europejski: float) -> float:
    """
        Pozwalająca na przeliczenie spalania z systemu Europejskiego l/100km
    (litry na 100 kilometrów) na system Ameryka«ski mi/1g (mile ameryka«skie na jeden
    galon),
    """
    return 235.215 / europejski


def mpg2lp100km(amerykanski: float) -> float:
    """
    konwersja odwrotna
    """
    return 235.21 / amerykanski
