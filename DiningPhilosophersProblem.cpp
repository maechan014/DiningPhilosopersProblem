#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Philosophers{
public:
    int *philosopher;
    bool *done;
    bool *chopsticks;
    int numberOfPhilosophers;
    int numberOfHungryPhil;

    Philosophers(){
        numberOfPhilosophers = 0;
        numberOfHungryPhil = 0;
        philosopher = new int[numberOfPhilosophers];
        done = new int[numberOfPhilosophers];
        chopsticks = (bool *)malloc(numberOfPhilosophers * 2 * sizeof(bool));
    }

    void init(){
        cout << endl << "--DINING-PHILOSOPHERS PROBLEM WITH ONE PHILOSOPHER EATING AT A TIME" << endl;
        cout << "Enter total number of Philosophers: ";
        cin >> numberOfPhilosophers;
        cout << "Enter number of hungry philosophers: ";
        cin >> numberOfHungryPhil;

        philosopher = new int[numberOfPhilosophers];
        done = new int[numberOfPhilosophers];
        chopsticks = (bool *)malloc(numberOfPhilosophers * 2 * sizeof(bool));

        cout << endl;

        for (int i = 0; i < numberOfHungryPhil; i++){
            cout << "Position for Hungry Philosopher " << i+1 << ": ";
            cin >> philosopher[i];
        }


    }

    /* "chopsticks" variable is an array of boolean that indicates the state of the philosophers' chopsticks.
    By default, each philosopher owns the left chopstick. The left chopsticks are stored in the zero (0)
    index of each philosopher. The right chopstick will be stored in the index 1.
    The 'setChopstickState' function sets all left chopsticks to true and right chopsticks to false.
    */

    void setChopstickState(){
        for (int i = 0; i < numberOfPhilosophers; i++){
            *(chopsticks + i*2 + 0) = true;    // set all left chopstick to true (philosophers owns the left chopstick by default).
            *(chopsticks + i*2 + 1) = false;   // set all right chopstick to false.
        }
    }


    void eating(){
    }

    void run(){
        for(int i = 0; i < numberOfPhilosophers; i++){
            if(!(chopsticks[i][0] && chopsticks[i+1][0])){
               // philosopher eats when the right chopstick is vacant

            }
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
    Philosophers p;

    int hungry_p, total_p, choice = 0;

    do{
        choice = menu();
        p.init();

        if (choice == 1){

        } else if (choice == 2){

        }




    } while (choice != 3);

return 0;
}
