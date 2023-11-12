#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <memory>
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

        cout << GREEN_TEXT << "Lion class constructor called" << endl
             << RESET_TEXT;
    }

    Lion::Lion(const Lion &otherAnimal)
    {
        this->name = new char[strlen(otherAnimal.name) + 1];
        strcpy(this->name, otherAnimal.name);

        this->region = new char[strlen(otherAnimal.region) + 1];
        strcpy(this->region, otherAnimal.region);

        this->specialTrick = new char[strlen(otherAnimal.specialTrick) + 1];
        strcpy(this->specialTrick, otherAnimal.specialTrick);

        cout << YELLOW_TEXT << "Lion class copy constructor called" << endl
             << RESET_TEXT;
    };

    Lion::~Lion()
    {
        delete[] name;
        delete[] region;
        delete[] specialTrick;

        cout << RED_TEXT << "Lion class destructor called" << endl
             << RESET_TEXT;
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
        cout << YELLOW_TEXT << "Lion class assignment operator called" << endl
             << RESET_TEXT;

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

        cout << YELLOW_TEXT << "Lion class move constructor called" << endl
             << RESET_TEXT;
    }

    void Lion::Perform()
    {
        cout << "The lion named " << name << " manages to " << specialTrick << "!" << endl;
    }

    template <typename T>
    Clown<T>::Clown(char *name, const T &age)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->age = age;

        cout << YELLOW_TEXT << "Clown class constructor called" << endl
             << RESET_TEXT;
    }

    template <typename T>
    Clown<T>::~Clown()
    {
        delete[] name;

        cout << RED_TEXT << "Clown class destructor called" << endl
             << RESET_TEXT;
    }

    template <typename T>
    void Clown<T>::Perform()
    {
        cout << name << " manages to make baloons! " << endl;
    }

    template <typename T1>
    template <typename T2>
    void Clown<T1>::MakeBaloons(list<T2> shapes)
    {
        cout << "The baloons that " << name << "makes are of various shapes: ";
        for (typename list<T2>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    Circus::Circus(const char* name)
    {
        this->name = std::make_unique<char[]>(strlen(name) + 1);
        strcpy(this->name.get(), name);

        cout << GREEN_TEXT << "Circus class object created" << endl
             << RESET_TEXT;
    }

    Circus::~Circus()
    {
        //delete[] name; -no longer needed, name is smart pointer

        cout << RED_TEXT << "Circus class destructor called" << endl
             << RESET_TEXT;
    }

    void Circus::Greetings()
    {
        cout << "Hello and welcome to the grand circus of " << name.get() << "!" << endl;
        cout << "Without further delay, let's see what our fabulous performers have prepared for you!" << endl;
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

    void Circus::Perform(std::shared_ptr<Lion> animal)
    {
        // shared pointer copy constructor will handle ownership
        std::shared_ptr<Lion> copy = std::make_shared<Lion>(*animal);

        std::cout << "Everybody, let's welcome " << copy->name << "! ";
        std::cout << "He comes to you straight from " << copy->region << "! " << std::endl;

        copy->Perform();

        std::cout << "Spectacular!" << std::endl;
        // shared pointer will automatically release memory when it goes out of scope
    }

    template <typename T>
    void Circus::Perform(Clown<T> *clown)
    {
        cout << "Everybody, let's welcome " << clown->name << "! ";
        cout << "He is " << clown->age << " years old!" << endl;
        clown->Perform();
        cout << "Spectacular!" << endl;
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

    // declaring the explicit instantiations of the templates
    template class Clown<int>;
    template void Clown<int>::MakeBaloons<char>(list<char>);
    template void Clown<int>::MakeBaloons<string>(list<string>);
    template void Circus::Perform<int>(Clown<int> *);
};