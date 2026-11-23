#include <iostream>
#include <vector>
#include <algorithm> // pro funkce make_heap, push_heap, pop_heap

// Min-halda implementovaná pomocí std::vector
class MinHeap {
private:
    std::vector<int> heap; // Vector pro uložení haldy

public:
    // Přidání prvku do haldy
    void insert(int value) {
        heap.push_back(value);         // Přidání na konec
        std::push_heap(heap.begin(), heap.end(), std::greater<>());  // Uspořádání do min-haldu
    }

    // Získání a odstranění minimálního prvku (extract-min)
    int extractMin() {
        if (heap.empty()) {
            throw std::runtime_error("Halda je prázdná");
        }
        
        std::pop_heap(heap.begin(), heap.end(), std::greater<>()); // Minimální prvek na konci
        int minElement = heap.back();
        heap.pop_back(); // Odstranění minimálního prvku
        return minElement;
    }

    // Zobrazení haldy
    void printHeap() {
        std::cout << "Halda: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap minHeap;

    // Vkládání prvků do haldy
    minHeap.insert(10);
    minHeap.insert(4);
    minHeap.insert(15);
    minHeap.insert(8);
    minHeap.insert(2);
    minHeap.insert(19);
    minHeap.insert(3);


    minHeap.printHeap(); // Výpis haldy po vložení prvků

    // Odstranění a výpis minimálního prvku
    std::cout << "Minimální prvek: " << minHeap.extractMin() << std::endl;
    minHeap.printHeap(); // Výpis haldy po odstranění minimálního prvku

    return 0;
}
