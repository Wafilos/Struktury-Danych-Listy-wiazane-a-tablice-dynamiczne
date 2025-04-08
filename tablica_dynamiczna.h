#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

// Klasa reprezentująca dynamiczną listę tablicową
class DynamicList {
public:
    // Konstruktor - inicjalizuje listę z domyślną pojemnością 4
    DynamicList(int capacity = 4) {
        size = 0;
        this->capacity = capacity;
        data = new int[capacity];
    }

    // Dodaje element na koniec listy
    void append(int value) {
        ensureCapacity();            // Zwiększ pojemność jeśli potrzebna
        data[size++] = value;       // Dodaj element na końcu i zwiększ rozmiar
    }

    // Dodaje element na początek listy
    void prepend(int value) {
        ensureCapacity();           // Upewnij się, że jest miejsce
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];  // Przesuń wszystkie elementy o jedno miejsce w prawo
        }
        data[0] = value;            // Dodaj nową wartość na początku
        size++;
    }

    // Dodaje element w dowolnym miejscu listy (na indeksie index)
    void add(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        ensureCapacity();           // Zwiększ pojemność jeśli potrzeba
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];  // Przesuwamy elementy w prawo od danego indeksu
        }
        data[index] = value;        // Wstawiamy nową wartość
        size++;
    }

    // Usuwa element o podanym indeksie
    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];  // Przesuwamy wszystkie kolejne elementy w lewo
        }
        size--;
    }

    // Wyszukuje wartość w liście i zwraca jej indeks (lub -1 jeśli nie znaleziono)
    int find(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                cout << "Wartosc (" << value << ") znajduje sie na indeksie: " << i << endl;
                return i;
            }
        }
        cout << "Wartosc (" << value << ") nie znajduje sie na liscie." << endl;
        return -1;
    }

    // Wyświetla wszystkie elementy listy
    void show() {
        cout << "Lista: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << ", ";
        }
        cout << "null" << endl;
    }

    // Destruktor - zwalnia pamięć zaalokowaną na tablicę
    ~DynamicList() {
        delete[] data;
    }

private:
    int* data;       // Wskaźnik na dynamicznie alokowaną tablicę
    int size;        // Aktualna liczba elementów w liście
    int capacity;    // Maksymalna pojemność tablicy

    // Funkcja pomocnicza do podwajania rozmiaru tablicy, gdy brakuje miejsca
    void ensureCapacity() {
        if (size >= capacity) {
            capacity *= 2;                    // Podwajamy pojemność
            int* newData = new int[capacity]; // Tworzymy nową większą tablicę
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];         // Kopiujemy stare dane
            }
            delete[] data;                    // Usuwamy starą tablicę
            data = newData;                   // Przypisujemy nową
        }
    }
};

#endif // LISTA_H
