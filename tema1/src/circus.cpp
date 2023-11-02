#include <iostream>
#include <string>
#include <list>
#include "circus.hpp"

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"
#define YELLOW_TEXT "\x1b[33m"

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

    Animal::Animal(const Animal& otherAnimal)
    {
        this->name = otherAnimal.name;
        this->specialTrick = otherAnimal.specialTrick;
        this->species = otherAnimal.species;
        cout <<  YELLOW_TEXT << "Animal class copy constructor called" << endl <<  RESET_TEXT;
    }

    Animal::~Animal(){
        // std::string does not require manual memory management
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
        cout <<  YELLOW_TEXT << "Animal class assignment operator called"<< endl << RESET_TEXT;
        return *this;
    }

    void Animal::Perform()
    {
        cout << "The " + species + " named " + name + " manages to " + specialTrick + "! ";
    };

    Circus::Circus(string name)
    {
        this->name = name;
        cout << GREEN_TEXT << "Circus class object created" << endl << RESET_TEXT;
    }

    Circus::~Circus(){
        cout << RED_TEXT << "Circus class destructor called" << endl << RESET_TEXT;
    }

    Circus::Circus(const Circus &otherCircus)
    {
        this->name = otherCircus.name;
        cout <<  YELLOW_TEXT << "Circus class copy constructor called" << endl << RESET_TEXT;
    }

    Circus &Circus::operator=(const Circus &otherCircus)
    {
        if (this != &otherCircus)
        {
            this->name = otherCircus.name;
        }
        return *this;
        cout <<  YELLOW_TEXT << "Circus class assignment operator called" << endl << RESET_TEXT;
    }

    void Circus::Greetings()
    {
        cout << "Hello and welcome to the grand circus of " + name + "!" << endl;
        cout << "Without further delay, let's see what our fabulous animals have prepared for you!" << endl;
    }

    void Circus::Perform(Animal *animal)
    {
        Animal* copy = new Animal(*animal); //the copy constructor is used here to create a copy of animal object to be used in method

        cout << "Everybody, let's welcome " + copy->name + "! ";
        cout << "He is a " + copy->species + "!" << endl;
        copy->Perform();
        cout << "Spectacular!" << endl;

        delete copy;
    }

    void Circus::AnnounceBest(Animal* animal)
    {
        Animal* winner = new Animal("default", "default", "default");

        if(animal != NULL)
        {
            *winner = *animal; //assignment operator is used to assign the values of the animal given as parameter is it is not null
        }
        cout << "And the best performance was by far the one of " + winner->name + " the " + winner->species << endl;
        cout << "A round of applause for him!" << endl;

        delete winner;
    }

    void Circus::End()
    {
        cout << "That was our performance for the night, thank you!" << endl;
    }
};