Scanf super duper funkcja która ustawia zmienną na input
```c
int i;
scanf("%d", &i);
```
Dajemy &i, bo scanf jako drugi argument przyjmuje miejsce w pamięci.

W m\*crosoftowym kompilatorze jest `scanf_s("%typ", adres, rozmiar)`, gdzie rozmiar mówi ile znaków wstawić.