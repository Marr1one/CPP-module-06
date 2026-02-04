/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:07:45 by root              #+#    #+#             */
/*   Updated: 2026/02/04 16:25:36 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"

int main()
{
	// Serializer s;
	Data test;
	test.ex_age = 23;
	test.ex_string = "Marwan";
	uintptr_t adress_container;
	Data *dataContainer;
	
	std::cout << "test adress :" << &test << std::endl;
	adress_container = Serializer::serialize(&test);
	std::cout << "Number serialized = > " << adress_container << std::endl;
	dataContainer = Serializer::deserialize(adress_container);
	std::cout << "data container adress :" << dataContainer << std::endl;
	std::cout << "After serialize and deserialize === > ";
	std::cout  << "age = > " << dataContainer->ex_age << ", string == > " << dataContainer->ex_string << std::endl;
	return (0);
}