#ifndef CIRCUS_HPP
#define CIRCUS_HPP

#include <string>
#include <list>
#include <memory>
using namespace std;
namespace circus
{
    class IPerformer {
        public:
            virtual ~IPerformer() {};
            virtual void Perform() = 0;
    };

    class Animal : public IPerformer{
        public: 
            char* name;
            char* region;
        protected:
            char* specialTrick;
        public:
            virtual ~Animal() {};
            virtual void Perform() = 0;
    };

    class Lion : public Animal
    {
        public:
            Lion(char* name, char* region, char* specialTrick);
            Lion(const Lion &otherAnimal);
            ~Lion();
            Lion &operator=(const Lion &other);
            Lion(Lion&& other);

        public:
            void Perform() override;
            void ChangeName(const char* name);
    };

    template<typename T1>
    class Clown: public IPerformer
    {
        public:
            Clown(char* name, const T1& age);
            ~Clown();
        public:
            char* name;
            T1 age;
            void Perform() override;
            template<typename T2>
            void MakeBaloons(list<T2> shapes);
    };

    class Circus
    {
    public:
        Circus(const char* name);
        Circus(const Circus &otherCircus);
        ~Circus();
        Circus &operator=(const Circus &otherCircus);

    public:
        unique_ptr<char[]> name;
        void Greetings();
        void Perform(Lion* animal);
        void Perform(shared_ptr<Lion> animal);
        template<typename T>
        void Perform(Clown<T>* clown);
        void AnnounceBest(Lion* animal);
        void End();
    };

    //declaring the explicit instantiations of the templates
    extern template class Clown<int>;
    extern template void Clown<int>::MakeBaloons<char>(list<char>);
    extern template void Clown<int>::MakeBaloons<string>(list<string>);
    extern template void Circus::Perform<int>(Clown<int>*);
}

#endif
