#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Philosophers{
public:
    int *philosopher;
    bool *done;
    bool *chopsticks;
    int numberOfPhilosophers;
    int numberOfHungryPhil;

    /* "chopsticks" variable is an array of boolean that indicates the state of the philosophers' chopsticks.
    The left chopstick will be stored in the index 0 and the right chopstick will be stored in the index 1.
    */

    Philosophers(){
        numberOfPhilosophers = 0;
        numberOfHungryPhil = 0;
        philosopher = new int[numberOfPhilosophers];
        done = new bool[numberOfPhilosophers];
        chopsticks = (bool *)malloc(numberOfPhilosophers * 2 * sizeof(bool));
    }

    void init(){
        bool valid_h;

        cout << endl << "--DINING-PHILOSOPHERS PROBLEM WITH ONE PHILOSOPHER EATING AT A TIME" << endl;
        cout << "Total number of Philosophers (min. of 5):";
        cin >> numberOfPhilosophers;
        cout << "Number of hungry Philosophers: ";

        do{
            cin >> numberOfHungryPhil;
            if(numberOfHungryPhil > numberOfPhilosophers){
                cout << endl << "The hungry philosophers should be less than the total number of philosophers" << endl;
            } else {
                valid_h = true;
            }
        } while(!valid_h);


        philosopher = new int[numberOfPhilosophers];
        done = new bool[numberOfPhilosophers];
        chopsticks = (bool *)malloc(numberOfPhilosophers * 2 * sizeof(bool));

        cout << endl;

        for (int i = 0; i < numberOfHungryPhil; i++){
            cout << "Position for Hungry Philosopher " << i+1 << ": ";
            cin >> philosopher[i]; // the value is the position and the index is the philosopher id
        }

    }


    void run(){
        for(int i = 0; i < numberOfPhilosophers; i++){
            if(!*(chopsticks + i*2 + 0) && *(chopsticks + (i+1)*2 + 0)){
               // philosopher eats when the right chopstick is vacant
            }
        }
    }

};

class Philosopher {
public:
    int id;
    int position;
    bool isEating;
    bool isThinking;
    bool done;
    bool hasLeftChopstick;
    bool hasRightChopstick;

    Philosopher(){
        id = 0;
        isEating = false;
        isThinking = true;
        hasLeftChopstick = false;
        hasRightChopstick = false;
        done = false;
    }

    void state(){
        if (isEating){
            cout << endl << "Philosopher " << id << " is eating" << endl;
        } else if (isThinking){
           cout << endl << "Philosopher " << id << " is thinking" << endl;
        }
    }


};

class Philosophers_{
public:
    vector<Philosopher> philosopher;
    int total_philosophers;
    int hungry_philosophers;

    Philosophers_(){
        philosopher.clear();
        total_philosophers = 0;
        hungry_philosophers = 0;
    }

    void one_at_a_time(Philosopher p){
        int adj = 1;
        for (int curr = 0; curr < philosopher.size(); curr++, adj++){
            if (curr+1 >= hungry_philosophers){
                adj -= adj;
            }
             if(philosopher.at(curr).isThinking && philosopher.at(adj).isThinking && !(philosopher.at(curr).done)){
                philosopher.at(curr).isThinking = false;
                philosopher.at(curr).isEating = true;
                philosopher.at(curr).done = true;
                show_state(p);
                cout << endl;
             }
            philosopher.at(curr).isThinking = true;
            philosopher.at(curr).isEating = false;
        }
    }

    void two_at_a_time(){

    }

    void show_state(Philosopher p){
        for(int i = 0; i < philosopher.size(); i++){
            philosopher.at(i).state();
        }
    }

    void init(Philosopher p){
        bool valid, valid_position;


        cout << endl << "--DINING-PHILOSOPHERS PROBLEM WITH ONE PHILOSOPHER EATING AT A TIME" << endl;
        cout << "Total number of Philosophers (min. of 5): ";
        cin >> total_philosophers;
        cout << "Number of hungry Philosophers: ";

        do{
            cin >> hungry_philosophers;
            if(hungry_philosophers > total_philosophers){
                cout << endl << "The hungry philosophers should be less than the total number of philosophers" << endl;
            } else {
                valid = true;
            }
        } while(!valid);

        cout << endl;

        for (int i = 0; i < hungry_philosophers; i++){
            do{
                cout << "Position for Hungry Philosopher " << i << ": ";
                cin >> p.position;
                p.id = i;

                if (p.position >= hungry_philosophers){
                    cout << "NOTE:\nThe position should be less than number of hungry philosophers." << endl;
                    cout << "Range of 0-" << hungry_philosophers-1 << endl << endl;
                } else {
                    valid_position = true;
                }
            } while (!valid_position);
            philosopher.push_back(p);
            valid_position = false;
        }
    }
};

int menu (){
    int choice;

    cout << endl << "-----DINING-PHILOSOPHERS PROBLEM SIMULATOR-----" << endl;
    cout << "Choose a scenario to simulate:" << endl;
    cout << "[1] One can eat at a time" << endl << "[2] Two can eat at a time" << endl;
    cout << "[3] EXIT" << endl;
    cout << endl << "CHOICE: ";
    cin >> choice;

return choice;
}


int main(){
    Philosophers_ philosophers;
    Philosopher p;

    int hungry_p, total_p, choice = 0;

    do{
        choice = menu();

        if (choice == 1){
            philosophers.init(p);
            philosophers.show_state(p);
            philosophers.one_at_a_time(p);

        } else if (choice == 2){
            philosophers.init(p);
            philosophers.show_state(p);

        }
    } while (choice != 3);

return 0;
}
