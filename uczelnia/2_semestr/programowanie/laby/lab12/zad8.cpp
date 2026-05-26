// Fragment A
template <typename T> T podwoj(T x) { return x + x; }
podwoj(2, 3); // funkcja przyjmuje jeden argument a jest wywołana z dwoma

// Fragment B
template <typename T> T iloczyn(T a, T b);
// definicja w innym pliku .cpp - kod się nie linkuje

// Fragment C
template <typename T> T wiekszy(T a, T b) { return a > b ? a : b; }
wiekszy("abc", 5); // musi być dwa razy ten sam typ danych, a nie dwa różne
