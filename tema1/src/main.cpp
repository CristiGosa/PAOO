#include "circus.hpp"
using namespace circus;

int main()
{
    Circus* mainCircus = new Circus("ZooMumba");

    mainCircus->Greetings();

    Animal *firstAnimal = new Animal("lion", "Alex", "jump through a fiery circle");

    mainCircus->Perform(firstAnimal);
    // here the copy constructor is used

    Animal* secondAnimal = new Animal("turtle", "Fred", "do nothing, but with style");

    mainCircus->Perform(secondAnimal);

    mainCircus->AnnounceBest(secondAnimal);
    //here the assignment operator is used

    mainCircus->End();

    delete firstAnimal;
    delete secondAnimal;
    delete mainCircus;

    return 0;
}