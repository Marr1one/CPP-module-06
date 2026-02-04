/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:48:24 by root              #+#    #+#             */
/*   Updated: 2026/02/04 16:33:30 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp" 
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	
	int r = std::rand()%3;
	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	std::cout << "In identify with pointer\n";
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "The pointer point to a A class!\n";
		return;
	}
	if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "The pointer point to a B class!\n";
		return;
	}
	if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "The pointer point to a C class!\n";
		return;
	}
}

void identify(Base& p)
{
	std::cout << "In identify with reference\n";
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "Type of base class : A\n";
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Type of base class : B\n";
		return;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Type of base class : C\n";
		return;
	}
	catch(const std::exception& e)
	{
	}
	
}

int main()
{
	std::srand(time(NULL));
	// Test avec adresse
	Base *a = generate();
	identify(a);
	delete a;

	// Test avec reference
	Base *b = generate();
	Base &ref = *b;
	identify(ref);
	delete b;
	
	return (0);
}

