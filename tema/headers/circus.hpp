#ifndef CIRCUS_HPP
#define CIRCUS_HPP

#include <string>
#include <list>
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

    class Circus
    {
    public:
        Circus(char* name);
        Circus(const Circus &otherCircus);
        ~Circus();
        Circus &operator=(const Circus &otherCircus);

    public:
        char* name;
        void Greetings();
        void Perform(Lion* animal);
        void AnnounceBest(Lion* animal);
        void End();
    };
}

#endif
