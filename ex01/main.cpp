/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:07:45 by root              #+#    #+#             */
/*   Updated: 2025/10/25 13:33:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// Serializer s;
	Data test;
	uintptr_t container;
	Data *dataContainer;
	
	std::cout << "test adress :" << &test << std::endl;
	container = Serializer::serialize(&test);
	dataContainer = Serializer::deserialize(container);
	std::cout << "test adress :" << dataContainer << std::endl;
	
}