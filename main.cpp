#include <iostream>
#include <chrono>
#include <fstream>
#include "tablica_dynamiczna.h"
#include "list.h"

using namespace std;
using namespace std::chrono;

int main()
{
    List lista;
    DynamicList dynamiclist;

    ofstream lista_wiazana("lista_wiazana.txt");
    ofstream lista_dynamiczna("lista_dynamiczna.txt");

    for (int i = 0; i < 10000; i++)
    {
        lista.append(i);
    }

    auto start = high_resolution_clock::now();
    lista.prepend(20000);
    auto end = high_resolution_clock::now();
    auto czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na poczatek wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas dodania elementu na poczatek wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.append(15000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na koniec wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas dodania elementu na koniec wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.add(5000, 40000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na srodek wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas dodania elementu na srodek wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.remove(0);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia poczatkowego elementu wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas usuniecia poczatkowego elementu wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.remove(10001);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia ostatniego elementu wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas usuniecia ostatniego elementu wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.remove(5000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia elementu ze srodka wyniosl: " << czas.count() << " ns\n";
    lista_wiazana << "Czas usuniecia elementu ze srodka wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    lista.find(5000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas wyszukania srodkowego elementu: " << czas.count() << " ns\n";
    lista_wiazana << "Czas wyszukania srodkowego elementu;" << czas.count() << ";ns\n";

    for (int i = 0; i < 10000; i++)
    {
        dynamiclist.append(i);
    }

    start = high_resolution_clock::now();
    dynamiclist.prepend(20000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na poczatek w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas dodania elementu na poczatek wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.append(15000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na koniec w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas dodania elementu na koniec wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.add(5000, 40000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas dodania elementu na srodek w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas dodania elementu na srodek wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.remove(0);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia poczatkowego elementu w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas usuniecia poczatkowego elementu wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.remove(10001);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia ostatniego elementu w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas usuniecia ostatniego elementu wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.remove(5000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas usuniecia elementu ze srodka w DynamicList wyniosl: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas usuniecia elementu ze srodka wyniosl;" << czas.count() << ";ns\n";

    start = high_resolution_clock::now();
    dynamiclist.find(5000);
    end = high_resolution_clock::now();
    czas = duration_cast<nanoseconds>(end - start);
    cout << "Czas wyszukania srodkowego elementu w DynamicList: " << czas.count() << " ns\n";
    lista_dynamiczna << "Czas wyszukania srodkowego elementu;" << czas.count() << ";ns\n";

    lista_wiazana.close();
    lista_dynamiczna.close();

    return 0;
}





