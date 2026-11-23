#include <iostream>
#include <queue>  // Pro použití std::queue

int main() {
    // Vytvoření fronty
    std::queue<int> myQueue;

    // Přidání prvků do fronty (enqueue)
    myQueue.push(10);  // První prvek
    myQueue.push(20);  // Druhý prvek
    myQueue.push(30);  // Třetí prvek

    std::cout << "Fronta byla naplněna." << std::endl;
    std::cout << "Velikost fronty: " << myQueue.size() << std::endl;

    // Zobrazení prvního prvku ve frontě (front)
    if (!myQueue.empty()) {
        std::cout << "První prvek fronty: " << myQueue.front() << std::endl;
    }

    // Odebrání prvků z fronty (dequeue)
    std::cout << "Odstranění prvku z fronty: " << myQueue.front() << std::endl;
    myQueue.pop();  // Odebere první prvek

    std::cout << "Nyní je první prvek fronty: " << myQueue.front() << std::endl;
    std::cout << "Velikost fronty po odebrání: " << myQueue.size() << std::endl;

    // Vyprázdnění fronty
    while (!myQueue.empty()) {
        std::cout << "Odebírání: " << myQueue.front() << std::endl;
        myQueue.pop();
    }

    std::cout << "Fronta je prázdná? " << (myQueue.empty() ? "Ano" : "Ne") << std::endl;

    return 0;
}
