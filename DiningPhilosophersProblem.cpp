#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>

/**
    Dining-Philosopher's Problem
    In this simulator, the user is prompt to input the total number of philosophers,
    the number of hungry philosophers, and the position of each philosopher on the table

    @author Charie Mae
**/


using namespace std;

class Philosopher {
public:
    int id;
    int position;
    bool isEating;
    bool isThinking;
    bool done;
    bool isHungry;

    Philosopher(){
        /* ids and positions are initialize as -1 because the indexes starts at 0*/
        id = -1;
        position = -1;
        isThinking = true;
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
                int adj = curr+1;   // will indicate the adjacent philosopher

                /* if the adjacent reaches the last position, then it subtracts the value by itself to be in the first
                position again since the position is in circular */
                if (adj >= hungry_philosophers){
                    adj -= adj;
                }

                /* iterates until the right position is found */
                if (philosopher.at(curr).position == i){
                   if (philosopher.at(curr).isHungry){
                        // implies that if the adjacent philosopher is still thinking, then it does not have any chopstick yet.
                        if(philosopher.at(curr).isThinking && philosopher.at(adj).isThinking && !(philosopher.at(curr).done)){
                            philosopher.at(curr).isThinking = false;
                            philosopher.at(curr).isEating = true;
                            philosopher.at(curr).done = true;
                            show_state();
                         }
                        // after eating, the philosopher starts to think again.
                        philosopher.at(curr).isThinking = true;
                        philosopher.at(curr).isEating = false;
                    }
                    adj++;
                }
            }
        }
    }
    // end of one_at_a_time

    /* this works the same as the one_at_a_time() but with extra loops inside*/

    void two_at_a_time(){
        for (int i = 0;i < philosopher.size(); i++){
           for (int curr = 0; curr < total_philosophers; curr++){
            int adj = curr+1, j;
            int next = curr + 2;    // indicate the position of the philosopher a seat apart from the current philosopher

                /* if the adjacent reaches the last position, then it subtracts the value by itself to be in the first
                position again since the position is in circular */
                if (adj >= hungry_philosophers){
                    adj -= adj;
                }

                if (next >= hungry_philosophers){
                    next -= next;
                }

                if (philosopher.at(curr).position == i){
                    if (philosopher.at(curr).isHungry){
                        if(philosopher.at(curr).isThinking && philosopher.at(adj).isThinking && !(philosopher.at(curr).done)){
                            philosopher.at(curr).isThinking = false;
                            philosopher.at(curr).isEating = true;
                            philosopher.at(curr).done = true;

                            for (j = next; j < total_philosophers; j++){
                                int before = j-1;
                                int after = j+1;

                                if (after >= hungry_philosophers){
                                    after -= after;
                                }
                                if (before < 0){
                                    before = before + hungry_philosophers;
                                }

                                if(philosopher.at(j).isHungry && philosopher.at(after).isThinking && philosopher.at(before).isThinking){
                                   philosopher.at(j).isThinking = false;
                                   philosopher.at(j).isEating = true;
                                   philosopher.at(j).done = true;
                                   break;
                                }
                            }
                            show_state();
                            philosopher.at(j).isThinking = true;
                            philosopher.at(j).isEating = false;
                            philosopher.at(curr).isThinking = true;
                            philosopher.at(curr).isEating = false;
                        }
                    }
                }
           }
        }
    }
    // end of two_at_a_time()

    void show_state(){
        for(int i = 0; i < philosopher.size(); i++){
        for(int j = 0; j <total_philosophers; j++){
            if (philosopher.at(j).position == i){
                philosopher.at(j).state();
            }
        }
        }
        cout << endl;
    }
    // end of show_state()

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
    // end of init()

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
            philosophers.two_at_a_time();
            philosophers.show_state();
            clr();
        }
        philosophers.philosopher.clear();
    } while (choice != 3);

return 0;
}
