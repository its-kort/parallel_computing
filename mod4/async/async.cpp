#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int sum(int x, int y) {
    for(int i = 0; i < 10; i++) {
        cout << "[Async]: " << i << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
    return x + y;
}

int main() {
    cout << "Getting the sum . . ." << endl;
    future<int> result = async(sum, 2, 1);

    for(int i = 0; i < 10; i++) {
        cout << "[Main]: " << i << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << "RESULT: " << result.get() << endl;

    return 0;
}
