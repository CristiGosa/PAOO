#include "circus.hpp"

int main()
{
    circus::Circus mainCircus = circus::Circus("ZooMumba");

    mainCircus.Greetings();

    circus::Animal firstAnimal = circus::Animal("lion", "Alex", "jump through a fiery circle");

    mainCircus.Perform(firstAnimal);

    circus::Animal secondAnimal = circus::Animal("turtle", "Fred", "do nothing, but with style");

    mainCircus.Perform(secondAnimal);
    // the copy constructor is used when passing the object animal by value inside the Perform function

    circus::Animal winner = firstAnimal;
    // the assignment operator is used by assigning the winner without creating a new animal

    mainCircus.AnnounceBest(winner);

    mainCircus.End();
} // after the execution of the program, the destructor should be called 3 times