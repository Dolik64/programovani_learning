#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Globální mutex

void safe_print(const std::string& msg) {
    mtx.lock();   // Zamknutí mutexu
    std::cout << msg << std::endl;
    mtx.unlock(); // Odemknutí mutexu
}

int main() {
    //std::thread t1(funkce, parametry);
    std::thread t1(safe_print, "Hello from thread 1");
    std::thread t2(safe_print, "Hello from thread 2");
    
    t1.join();
    t2.join();
    
    return 0;
}