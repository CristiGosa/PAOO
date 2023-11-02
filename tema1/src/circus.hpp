#ifndef CIRCUS_HPP
#define CIRCUS_HPP

#include <string>
#include <list>
using namespace std;
namespace circus
{
    class Animal
    {
    public:
        Animal(string species, string name, string specialTrick);
        Animal(const Animal &otherAnimal);
        ~Animal();
        Animal &operator=(const Animal &other);

    private:
        string specialTrick; // you are not allowed to know the animal's special trick until they perform

    public:
        string name;
        string species;
        void Perform();
    };

    class Circus
    {
    public:
        Circus(string name);
        Circus(const Circus &otherCircus);
        ~Circus();
        Circus &operator=(const Circus &otherCircus);

    public:
        string name;
        void Greetings();
        void Perform(Animal* animal);
        void AnnounceBest(Animal* animal);
        void End();
    };
}

#endif
