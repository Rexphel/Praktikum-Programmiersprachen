//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 1;
    int currentFib = 1;
    if(n == 0)										// Für Fehlerabdeckung könnte man hier n<=0 einstellen.
    {
        return 0;
    }
    if(n == 1 || n == 2) 							// f(2)=f(1)=1
    {
        return 1;
    }
    for (int i = 3; i <= n; i++) 					// Startwert muss angepasst werden. (0->2 sind ja abgedeckt.
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;					//prev == current und nicht prev=new.
        currentFib = newFib ;
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 47:" << std::endl ;
    for (int i = 1; i <= 47 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;
}
