/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:32:27 by root              #+#    #+#             */
/*   Updated: 2025/10/22 19:38:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string var)
{
	double d = std::atof(var.c_str());
	
	//char
		if (d < 32 || d > 126)
			std::cout << "char : not printable\n";
		else 
			std::cout << "char : " << static_cast<char>(d) << std::endl;
	//int 
		if (d <= -2147483647 || d >= 2147483647)
			std::cout << "int : impossible\n";
		else
			std::cout << "int : " << static_cast<int>(d) << std::endl;
	//float 
		std::cout << "float : " << static_cast<float>(d) << "f" <<  std::endl;
	//double
		std::cout << "double : " << d << std::endl;
}