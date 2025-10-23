/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:27:12 by root              #+#    #+#             */
/*   Updated: 2025/10/24 01:35:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

enum e_type
{
	CHAR,
	FLO,AT,
	INT
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
void printInt(std::string var);
void printFloat(std::string var);
void printDouble(std::string var);


#endif