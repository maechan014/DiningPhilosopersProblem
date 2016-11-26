#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Philosopher {
public:
    int id;
    int position;
    bool isEating;
    bool isThinking;
    bool done;
    bool isHungry;
    bool hasLeftChopstick;
    bool hasRightChopstick;

    Philosopher(){
        id = -1;
        position = -1;
        isThinking = true;
        isHungry = false;
    }

    void state(){
        if (isEating){
            cout << endl << "Philosopher " << id << " is eating";
        } else if (isThinking){
           cout << endl << "Philosopher " << id << " is thinking";
        }
        if (!isHungry){
            cout << " and is not hungry";
        } if (done && !isEating){
            cout << " and have eaten";
        }
        cout << endl;
    }


};

class DiningPhilosophers {
public:
    vector<Philosopher> philosopher;
    int total_philosophers;
    int hungry_philosophers;
    bool done;

    DiningPhilosophers(){
        philosopher.clear();
        total_philosophers = 0;
        hungry_philosophers = 0;
    }

    void one_at_a_time(){
        for (int i = 0; i < philosopher.size(); i++){
            for (int curr = 0; curr < total_philosophers; curr++){
                int adj = curr+1;

                /* if the adjacent reaches the last position, then it subtracts the value by itself to be in the first
                position again since the position is in circular */
                if (adj >= hungry_philosophers){
                    adj -= adj;
                }

                /* iterates until the right position is found */
                if (philosopher.at(curr).position == i){
                   if (philosopher.at(curr).isHungry){
                        if(philosopher.at(curr).isThinking && philosopher.at(curr).isThinking && !(philosopher.at(curr).done)){
                            philosopher.at(curr).isThinking = false;
                            philosopher.at(curr).isEating = true;
                            philosopher.at(curr).done = true;
                            show_state();
                         }
                        philosopher.at(curr).isThinking = true;
                        philosopher.at(curr).isEating = false;
                    }
                    adj++;
                }
            }



        }
    }

    void two_at_a_time(){
        for (int curr = 0; !done;){
           // if (hungry_philosophers)
        }

    }

    void show_state(){
        for(int i = 0; i < philosopher.size(); i++){
            philosopher.at(i).state();
        }
        cout << endl;
    }

    void init(Philosopher p){
        bool valid, valid_position;

        cout << endl << "--ONE PHILOSOPHER EATING AT A TIME" << endl;
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

        for (int i = 0; i <total_philosophers; i++){
            p.id = i;

            if (i < hungry_philosophers){
                do{
                    cout << "Position for Hungry Philosopher " << i << ": ";
                    cin >> p.position;

                    if (p.position >= total_philosophers){
                        cout << "NOTE:\nThe position should be less than number of total philosophers." << endl;
                        cout << "Range of 0-" << total_philosophers-1 << endl << endl;
                    } else {
                        valid_position = true;
                        p.isHungry = true;
                    }
                } while (!valid_position);
            } else {
                p.isHungry = false;
            }

            philosopher.push_back(p);
            valid_position = false;
        }
    }


   void print(){
       for (int i = 0; i < total_philosophers; i++){
        cout << "ID: " << philosopher.at(i).id << endl;
        cout << "Position: " << philosopher.at(i).position << endl;
        if (philosopher.at(i).isHungry)
            cout << "Status: Hungry" << endl;
        else
            cout << "Status: Not Hungry" << endl;
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

void clr(){
    int menu;

    cout << endl << "Press 1 then ENTER to return to Main Menu." << endl;
    cin >> menu;

    if (menu == 1){
        system("CLS");
    }
}

int main(){
    DiningPhilosophers philosophers;
    Philosopher p;

    int hungry_p, total_p, choice = 0;

    do{
        choice = menu();

        if (choice == 1){
            philosophers.init(p);
            philosophers.show_state();
            philosophers.one_at_a_time();
            philosophers.show_state();
            clr();

        } else if (choice == 2){
            philosophers.init(p);
            philosophers.show_state();

        }
        philosophers.philosopher.clear();

    } while (choice != 3);

return 0;
}
