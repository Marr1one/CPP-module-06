/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:27:12 by root              #+#    #+#             */
/*   Updated: 2026/02/04 15:19:10 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <cmath>

enum e_type
{
	CHAR,
	FLOAT,
	INT,
	DOUBLE,
	UNKNOWN,
	NANN,
	INF_POS,
	INF_NEG
};

class ScalarConverter 
{
	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
	public:
		void static convert(std::string str);	
};

int isInt(std::string str);
int isFloat(std::string str);
int isDouble(std::string str);
int isChar(std::string str);
e_type detect_type(std::string str);
void printChar(std::string str);
void printInt(std::string str);
void printFloat(std::string str);
void printDouble(std::string str);
void printNan(std::string str);
void printInfNeg(std::string str);
void printInfPos(std::string str);


#endif