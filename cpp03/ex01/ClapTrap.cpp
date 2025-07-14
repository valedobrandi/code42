#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 )
{
    std::cout << "ClapTrap constructor called" << std::endl;

    return;
}

ClapTrap::ClapTrap( const ClapTrap &other )
    : _name( other._name ),
      _hitPoints( other._hitPoints ),
      _energyPoints( other._energyPoints ),
      _attackDamage( other._attackDamage )
{
    std::cout << "ClapTrap copy constructor called\n";
    return;
}

ClapTrap &ClapTrap::operator=( const ClapTrap & rhs )
{
    std::cout << "ClapTrap assignment operator called\n";

    if ( this != & rhs) 
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }

    return *this;
}


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10)
{
    std::cout << "Claptrap: " << this->_name << " was created" << std::endl;
    this->_attackDamage = 0;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Claptrap: " <<  this->_name << " was destroyed" << std::endl;
    return;
}

void ClapTrap::attack(const std::string &target)
{

    if (!this->status()) return;

    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
              << this->_attackDamage << " points of damage!" << std::endl;

    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{

    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!"
              << std::endl;

    this->_hitPoints -= amount;

    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{

    if (!this->status()) return;
    
    this->_hitPoints += amount;
    if (this->_hitPoints > 10)
        this->_hitPoints = 10;
        
    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " repair " << amount << " points of damage!"
              << std::endl;

    return;
}

bool ClapTrap::status(void)
{

    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return false;
    }

    if (this->_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is exhausted!" << std::endl;
        return false;
    }

    return true;
}