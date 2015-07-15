//Horse Race Program
//CS240
//Cory Stephens

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

//begin with the prototype
class Horse{
    private:
        int position;
    public:
        Horse();
        void advance();
        int getPosition();

}; //end class Horse()

//still need a constructor

Horse::Horse(){
    Horse::position = 0;
    //I don't know where this will go, but I'll need a random seed for each different run through
    srand(time(NULL));
} //end Horse::Horse()

//for advance, random number to move. 0 for nothing happens, 1 for moves. We'll use modulus to get either a 1 or 0.
void Horse::advance(){
    int moveChance = rand()%2; //random number of either 0 or 1 gives a 50 / 50 chance of the horse moving

    if(moveChance == 1){
        position++;
    } //end if

} //end advance

int Horse::getPosition(){
    return position;
} //end getPosition

class Race{
    private:
        Horse h[5]; //array of horses in the race
    public:
        int length;
        Race();
        Race(int length);
        void printLane(int horseNum);
        void start();
}; //end class Race()

Race::Race(){
    length = 25;
} //end Race

Race::Race(int length){
    Race::length = length;
} //end Race(int length)

void Race::printLane(int horseNum){
//to print the lane, need to get the position of each horse
//if the the horse is in that position, draw the horse's number
//if the horse isn't in that position, draw a '.'
//so for loops with if's nested

    for (int i = 0; i < length; i++){
        int location = h[horseNum].getPosition();
        if (i == location){
            cout << horseNum +1; //+1 for numbering purposes. Normal counting starts at 1, not 0
        } //end if
        else{
            cout << ".";
        } //end else
    } //end for
        cout << endl;
} //end printLane()

void Race::start(){
    bool keepGoing = true;


    for(int n = 0; n < 5; n++){
        printLane(n); //initial print statement for the start of the array
    } //end for

    cout << "\nReady, set, go!\n" << endl;
    cin.ignore();

    while(keepGoing){
        for(int number = 0;  number < 5; number++){
            h[number].advance();
            printLane(number);
            if(h[number].getPosition() == (length)){ //win condition
                keepGoing = false;
                cout << "Horse " << number+1 << " wins!" << endl; // the +1 is because of numbering purposes
            } //end if
        } //end for

        cout << "\nPress enter to continue: " << endl; // Editing these two lines out allows you
        cin.ignore(); //to run the program from start to finish by pressing enter once.

        cout << "\n" << endl;

    } //end while
} //0end void start

main(){

    cout << "Welcome to the racetrack! Press Enter to begin the race." << endl;
    cin.ignore();

    Race race;
    race.start();
    cout << "Good race" << endl;
    cin.ignore();
} //end main

