#include <iostream>
#include <string>
#include <list>
#include "circus.hpp"

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"

using namespace std;

namespace circus
{
    Animal::Animal(string species, string name, string specialTrick)
    {
        this->name = name;
        this->specialTrick = specialTrick;
        this->species = species;
        cout << GREEN_TEXT << "Animal class object created" << endl << RESET_TEXT;
    };

    Animal::Animal(const Animal &otherAnimal)
    {
        this->name = otherAnimal.name;
        this->specialTrick = otherAnimal.specialTrick;
        this->species = otherAnimal.species;
    }

    Animal::~Animal(){
        cout << RED_TEXT << "Animal class destructor called" << endl << RESET_TEXT;
    }

    Animal &Animal::operator=(const Animal &otherAnimal)
    {
        if (this != &otherAnimal)
        {
            this->name = otherAnimal.name;
            this->specialTrick = otherAnimal.specialTrick;
            this->species = otherAnimal.species;
        }
        return *this;
    }

    void Animal::Perform()
    {
        cout << "The " + species + " named " + name + " manages to " + specialTrick + "! ";
    };

    Circus::Circus(string name)
    {
        this->name = name;
        cout << GREEN_TEXT << "Circus class object created" << RESET_TEXT << endl;
    }

    Circus::~Circus(){
        cout << RED_TEXT << "Circus class destructor called" << endl << RESET_TEXT;
    }

    Circus::Circus(const Circus &otherCircus)
    {
        this->name = otherCircus.name;
    }

    Circus &Circus::operator=(const Circus &otherCircus)
    {
        if (this != &otherCircus)
        {
            this->name = otherCircus.name;
        }
        return *this;
    }

    void Circus::Greetings()
    {
        cout << "Hello and welcome to the grand circus of " + name + "!" << endl;
        cout << "Without further delay, let's see what our fabulous animals have prepared for you!" << endl;
    }

    void Circus::Perform(Animal animal)
    {
        cout << "Everybody, let's welcome " + animal.name + "! ";
        cout << "He is a " + animal.species + "!" << endl;
        animal.Perform();
        cout << "Spectacular!" << endl;
    }

    void Circus::AnnounceBest(Animal animal)
    {
        cout << "And the best performance was by far the one of " + animal.name + " the " + animal.species << endl;
        cout << "A round of applause for him!" << endl;
    }

    void Circus::End()
    {
        cout << "That was our performance for the night, thank you!" << endl;
    }
};