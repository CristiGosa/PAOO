#include "circus.hpp"
#include <cstring>
#include <memory>
using namespace circus;

int main()
{
    std::unique_ptr<Circus> mainCircus = std::make_unique<Circus>("ZooMumba");
    //mainCircus is the "bootstrapper" of the app, and should be used only in one instance, in main
    
    mainCircus->Greetings();

    std::shared_ptr<Lion> firstAnimal(new Lion("Alex", "Africa", "jump through a fiery circle"));
    //the animals are handled in multiple instances and can be copied/assigned to other locations

    mainCircus->Perform(firstAnimal);
    // here the copy constructor is used

    Lion secondAnimal = move(*firstAnimal);
    //here the move constructor is used

    //delete firstAnimal; - no longer needed, because is a smart pointer now

    delete[] secondAnimal.name;
    secondAnimal.name = new char[strlen("Melvin") + 1];
    strcpy(secondAnimal.name, "Melvin");

    mainCircus->Perform(&secondAnimal);

    mainCircus->AnnounceBest(&secondAnimal);
    //here the assignment operator is used

    Clown<int>* clown = new Clown("Bozo", 22);

    mainCircus->Perform(clown);

    list<char> letterShapes = {'A', 'B', 'S'}; 
    clown->MakeBaloons(letterShapes);
    list<string> complexShapes = {"Puppy", "Sword", "France"};
    clown->MakeBaloons(complexShapes);

    mainCircus->End();

    delete clown;
    //delete mainCircus; -no longer needed, now is a smart pointer

    return 0;
}