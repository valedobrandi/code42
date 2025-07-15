#include <string>

class Animal {
    private:
        int _numbersOfLegs;
    public:
        Animal( void );
        Animal( Animal const & );
        Animal & operaot=( Animal const & );
        ~Animal( void );

        void run( int distance );
};

class Cat : public Animal {
    public:
        Cat( void );
        Cat( Cat const & );
        Cat & operaot=( Cat const & );
        ~Cat( void );

        void scornSomeone( std::string const & target);
};