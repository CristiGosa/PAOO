#include <iostream>
#include <cstring>
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
    Lion::Lion(char *name, char *region, char *specialTrick)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->region = new char[strlen(region) + 1];
        strcpy(this->region, region);

        this->specialTrick = new char[strlen(specialTrick) + 1];
        strcpy(this->specialTrick, specialTrick);

        cout << GREEN_TEXT << "Lion class constructor called" << endl << RESET_TEXT;
    }

    Lion::Lion(const Lion &otherAnimal)
    {
        this->name = new char[strlen(otherAnimal.name) + 1];
        strcpy(this->name, otherAnimal.name);

        this->region = new char[strlen(otherAnimal.region) + 1];
        strcpy(this->region, otherAnimal.region);

        this->specialTrick = new char[strlen(otherAnimal.specialTrick) + 1];
        strcpy(this->specialTrick, otherAnimal.specialTrick);

        cout << YELLOW_TEXT << "Lion class copy constructor called" << endl << RESET_TEXT;
    };

    Lion::~Lion()
    {
        delete[] name;
        delete[] region;
        delete[] specialTrick;

        cout << RED_TEXT << "Lion class destructor called" << endl << RESET_TEXT;
    }

    Lion &Lion::operator=(const Lion &otherAnimal)
    {
        if (this != &otherAnimal)
        {
            delete[] name;
            delete[] region;
            delete[] specialTrick;

            this->name = new char[strlen(otherAnimal.name) + 1];
            strcpy(this->name, otherAnimal.name);

            this->region = new char[strlen(otherAnimal.region) + 1];
            strcpy(this->region, otherAnimal.region);

            this->specialTrick = new char[strlen(otherAnimal.specialTrick) + 1];
            strcpy(this->specialTrick, otherAnimal.specialTrick);
        }
        cout << YELLOW_TEXT << "Lion class assignment operator called" << endl << RESET_TEXT;

        return *this;
    }

    Lion::Lion(Lion &&other)
    {
        swap(this->name, other.name);
        swap(this->region, other.region);
        swap(this->specialTrick, other.specialTrick);

        other.name = nullptr;
        other.region = nullptr;
        other.specialTrick = nullptr;

        cout << YELLOW_TEXT << "Lion class move constructor called" << endl << RESET_TEXT;
    }

    void Lion::Perform()
    {
        cout << "The lion named " << name << " manages to " << specialTrick << "!" << endl;
    }

    Circus::Circus(char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        cout << GREEN_TEXT << "Circus class object created" << endl << RESET_TEXT;
    }

    Circus::~Circus()
    {
        delete[] name;

        cout << RED_TEXT << "Circus class destructor called" << endl << RESET_TEXT;
    }

    Circus::Circus(const Circus &otherCircus)
    {
        this->name = new char[strlen(otherCircus.name) + 1];
        strcpy(this->name, otherCircus.name);
        cout << YELLOW_TEXT << "Circus class copy constructor called" << endl
             << RESET_TEXT;
    }

    Circus &Circus::operator=(const Circus &otherCircus)
    {
        if (this != &otherCircus)
        {
            delete[] name;

            this->name = new char[strlen(otherCircus.name) + 1];
            strcpy(this->name, otherCircus.name);
        }
        return *this;
        cout << YELLOW_TEXT << "Circus class assignment operator called" << endl << RESET_TEXT;
    }

    void Circus::Greetings()
    {
        cout << "Hello and welcome to the grand circus of " << name << "!" << endl;
        cout << "Without further delay, let's see what our fabulous animals have prepared for you!" << endl;
    }

    void Circus::Perform(Lion *animal)
    {
        Lion *copy = new Lion(*animal); // the copy constructor is used here to create a copy of animal object to be used in method

        cout << "Everybody, let's welcome " << copy->name << "! ";
        cout << "He comes to you straight from " << copy->region << "! " << endl;
        copy->Perform();
        cout << "Spectacular!" << endl;

        delete copy;
    }

    void Circus::AnnounceBest(Lion *animal)
    {
        Lion *winner = new Lion("default", "default", "default");

        if (animal != NULL)
        {
            *winner = *animal; // assignment operator is used to assign the values of the animal given as parameter is it is not null
        }
        cout << "And the best performance was by far the one of " << winner->name << endl;
        cout << "A round of applause for him!" << endl;

        delete winner;
    }

    void Circus::End()
    {
        cout << "That was our performance for the night, thank you!" << endl;
    }
};