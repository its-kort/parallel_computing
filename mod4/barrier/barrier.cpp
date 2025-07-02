#include <iostream>
#include <thread>
#include <barrier>
#include <chrono>
using namespace std;

barrier start_game(3);

void character_select(string username, string character_name, int time_taken) {
    cout << "[" << username << "]" << " Selected: " << character_name << endl;
    cout << "Loading . . ." << endl;

    this_thread::sleep_for(chrono::seconds(time_taken));
    cout << "[" << username << "]" << " Connected. " << endl;

    start_game.arrive_and_wait();
    cout << "[" << username << "]" << " In Game. " << endl;
}

int main() {
    cout << "Character Selection Phase. . ." << endl;

    thread player1(character_select, "Kurt", "Jeff the Land Shark", 5);
    thread player2(character_select, "Shikkari", "The Punisher", 1);
    thread player3(character_select, "Bea", "Groot", 4);

    this_thread::sleep_for(chrono::seconds(10));

    cout << "Match started." << endl;

    player1.join();
    player2.join();
    player3.join();

    return 0;
}
