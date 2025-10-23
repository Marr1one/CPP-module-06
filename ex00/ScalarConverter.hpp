/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:27:12 by root              #+#    #+#             */
/*   Updated: 2025/10/23 19:17:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

enum e_type
{
	CHAR,
	FLOAT,
	INT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter 
{
	public:
		void static convert(std::string var);	
};

int isInt(std::string var);
int isFloat(std::string var);
int isDouble(std::string var);
int isChar(std::string var);
e_type detect_type(std::string var);
void printChar(std::string var);
//void printInt();
//void printFloat();
//void printDouble();


#endif