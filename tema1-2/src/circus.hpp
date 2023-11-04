#ifndef CIRCUS_HPP
#define CIRCUS_HPP

#include <string>
#include <list>
using namespace std;
namespace circus
{
    class IPerformer {
        public:
            virtual void Perform() = 0;
    };

    class Animal : public IPerformer{
        public: 
            string name;
            string region;
        protected:
            string specialTrick;
        public:
            virtual void Perform() = 0;
    };

    class Lion : public Animal
    {
        public:
            Lion(string name, string region, string specialTrick);
            Lion(const Lion &otherAnimal);
            ~Lion();
            Lion &operator=(const Lion &other);
            Lion(Lion&& other);

        public:
            void Perform() override;
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
        void Perform(Lion* animal);
        void AnnounceBest(Lion* animal);
        void End();
    };
}

#endif
