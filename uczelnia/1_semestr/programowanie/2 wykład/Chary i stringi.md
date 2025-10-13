`char` to znak.
`char zmienna[20]` to tablica znaków o nazwie zmienna i rozmiarze 20.
`string zmienna` to string o nazwie zmienna. Nie trzeba tam dawać rozmiaru, w przeciwieństwie do tablicy charów.

W ascii nie ma `0`, bo to oznacza koniec tekstu.

Przy `scanf("%s", char zmienna[])` nie ma &, bo zmienna będąca tablicą znaków przetrzymuje już sama w sobie adres pierwszego elementu tablicy.

[[Strcpy]]