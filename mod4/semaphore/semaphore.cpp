#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>
using namespace std;

binary_semaphore bsp(0);

void doingSomething() {
    bsp.acquire();
    cout << "[Thread] Signal received." << endl;

    this_thread::sleep_for(chrono::seconds(3));

    cout << "[Thread] Signal sent." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    bsp.release();
}

int main() {
    thread t1(doingSomething);

    cout << "[Main] Signal sent." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    bsp.release(); 
    
    this_thread::sleep_for(chrono::seconds(3));

    bsp.acquire();
    cout << "[Main] Signal received." << endl;

    t1.join();

    return 0;
}
