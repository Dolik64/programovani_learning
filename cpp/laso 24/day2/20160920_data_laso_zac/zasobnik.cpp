#include <iostream>
#include <stack>  // Pro použití std::stack

int main() {
    // Definice zásobníku, který bude obsahovat celočíselné hodnoty
    std::stack<int> zasobnik;

    // Vložení prvků do zásobníku
    zasobnik.push(10);    //zasobnik je kyblík, push je vložení do kyblíku // dole je 10
    zasobnik.push(20);
    zasobnik.push(30);

    // Výpis vrcholu zásobníku
    std::cout << "Vrchni prvek na zasobniku je: " << zasobnik.top() << std::endl;

    // Odebrání vrcholu zásobníku
    zasobnik.pop();

    // Výpis vrcholu zásobníku po odebrání
    std::cout << "Po odebrani vrchniho prvku je novy vrchni prvek: " << zasobnik.top() << std::endl;

    // Odebrání dalších prvků
    zasobnik.pop();
    zasobnik.pop();

    // Kontrola, zda je zásobník prázdný
    if (zasobnik.empty()) {
        std::cout << "Zasobnik je prazdny!" << std::endl;
    }

    return 0;
}
