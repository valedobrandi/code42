/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:02 by bde-albu          #+#    #+#             */
/*   Updated: 2025/07/21 15:24:12 by bde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <ostream>
#include <iostream>

int main(void)
{

	std::cout << "===== Base Test =====\n" << std::endl;
    IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
    delete src;
	delete me;

	std::cout << "===== Equip more than 4 Materias =====\n" << std::endl;

	ICharacter* hero = new Character("hero");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	hero->equip(new Ice());
	hero->equip(new Ice());
	hero->equip(new Ice());
	hero->equip(new Ice());
	hero->equip(ice);

	delete ice;
	delete cure;
	delete hero;

	std::cout << "===== Unequip and reuse =====\n" << std::endl;

	ICharacter* player = new Character("player");

	AMateria* mat1 = new Ice();
	AMateria* mat2 = new Cure();

	player->equip(mat1);
	player->equip(mat2);

	player->unequip(0);
	player->unequip(5);

	player->use(0, *player);
	player->use(1, *player);

	delete mat1;
	delete mat2;
	delete player;

	std::cout << "===== Invalid materia creation =====\n" << std::endl;

	IMateriaSource* t = new MateriaSource();
	t->learnMateria(new Ice());

	AMateria* wrong = t->createMateria("fire");
	if (!wrong) std::cout << "Invalid materia not created as expected\n";

	delete t;

	std::cout << "=====  Deep Copy - Constructor =====\n" << std::endl;

	Character original("Alice");
	original.equip(new Ice());
	original.equip(new Cure());

	Character copy(original);
	copy.use(0, original);
	copy.use(1, original);

	original.unequip(0);
	copy.use(0, original);

	std::cout << "=====  Deep Copy - Assignment Operator =====\n" << std::endl;

	/* Character a("A");
	a.equip(new Ice());

	Character b("B");
	b = a;

	a.unequip(0);

	b.use(0, a); */

	std::cout << "=====  MateriaSource copy =====\n" << std::endl;

	/* MateriaSource m1;
	m1.learnMateria(new Ice());
	m1.learnMateria(new Cure());

	MateriaSource m2 = m1;

	AMateria* test = m2.createMateria("ice");
	if (test) std::cout << "Clone from copied MateriaSource successful\n";
	delete test; */
    return 0;
}
