# Projekt zaliczeniowy Algorytmy i Struktury Danych I
--------------------------------------------------------

## Temat projektu
Implementacja wielomianów na bazie tablic. Działania na wielomianach: dodawanie, odejmowanie, mnożenie, obliczanie wartości wielomianu (algorytm Hornera).

## Jak uruchomić program
Aby uruchomić program należy wpisać w terminal komendę: 
  make
  
## Jak działa program
Wielomiany w programie reprezentowane są za pomocą tablic dynamicznych. Wielomiany możemy stworzyć na 3 sposoby:
-	Stworzenie pustego.
-	Stworzenie wielomianu podając jego stopień (zostaje utworzony wielomian o podanym stopniu z współczynnikami o wartości T()).
-	Stworzenie wielomianu podając tablicę współczynników (indeks tablicy odpowiada potędze x dla danego współczynnika) i stopnia wielomianu.

Program pozwala nam też na wykonywanie operacji na wielomianach takich jak:
-	Przypisanie wartości
-	Wyświetlanie
- Dodawanie
- Odejmowanie
- Mnożenie
- Porównanie
- Obliczanie wartości dla danego x
- Sprawdzenie czy dany wielomian jest wielomianem zerowym

## Złożoność obliczeniowa
Stworzenie wielomianu zajmuje O(n) czasu i O(n) miejsca. Przy obliczaniu wartości wielomianu wykorzystywany jest algorytm Hornera. 
Jest on dużo bardziej wydajniejszy czasowo niż zwykła metoda podstawiania wartości pod każdy x po kolei. 
Jego złożoność wynosi O(n) dla mnożenia i dodawania, a nie O(n^2) dla mnożenia i O(n) dla dodawania jak przy zwykłym podstawianiu.
