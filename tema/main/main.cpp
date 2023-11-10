#include "circus.hpp"
#include <cstring>
using namespace circus;

int main()
{
    Circus* mainCircus = new Circus("ZooMumba");
    
    mainCircus->Greetings();

    Lion *firstAnimal = new Lion("Alex", "Africa", "jump through a fiery circle");

    mainCircus->Perform(firstAnimal);
    // here the copy constructor is used

    Lion secondAnimal = move(*firstAnimal);
    //here the move constructor is used

    delete firstAnimal;

    delete[] secondAnimal.name;
    secondAnimal.name = new char[strlen("Melvin") + 1];
    strcpy(secondAnimal.name, "Melvin");

    mainCircus->Perform(&secondAnimal);

    mainCircus->AnnounceBest(&secondAnimal);
    //here the assignment operator is used

    mainCircus->End();

    delete mainCircus;

    return 0;
}