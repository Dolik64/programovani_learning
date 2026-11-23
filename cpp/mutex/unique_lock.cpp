#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void worker() {
    // Simulace přípravy dat
    this_thread::sleep_for(chrono::seconds(2));
    {
        unique_lock<mutex> lock(mtx);
        ready = true;
        cout << "Worker: data jsou připravena.\n";
    }
    cv.notify_one();  // Probouzí čekající vlákno
}

void waiter() {
    unique_lock<mutex> lock(mtx);
    cout << "Waiter: čekám na data...\n";
    // Čeká, dokud 'ready' není true; operace odemykání/zamykání se ošetří automaticky
    cv.wait(lock, []{ return ready; });
    cout << "Waiter: data přijata, mohu pokračovat.\n";
}

int main() {
    thread t1(worker);
    thread t2(waiter);

    t1.join();
    t2.join();
    return 0;
}
