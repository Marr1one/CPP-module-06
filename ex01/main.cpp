/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:07:45 by root              #+#    #+#             */
/*   Updated: 2025/12/09 18:03:46 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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
	dataContainer = Serializer::deserialize(adress_container);
	std::cout << "data container adress :" << dataContainer << std::endl;
	std::cout << "After serialize and deserialize ===\n";
	std::cout << dataContainer->ex_age << ", " << dataContainer->ex_string << std::endl;
}