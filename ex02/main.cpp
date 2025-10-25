/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:48:24 by root              #+#    #+#             */
/*   Updated: 2025/10/25 18:13:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp" 
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(time(NULL));
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
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "Type of base class : B\n";
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "Type of base class : C\n";
	}
	catch(const std::exception& e)
	{
	}
	
}

int main()
{
	Base *b = generate();
	identify(*b);
	return (0);
}

