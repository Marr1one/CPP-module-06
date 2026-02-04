/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maissat <maissat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:32:27 by root              #+#    #+#             */
/*   Updated: 2026/02/04 16:07:00 by maissat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

e_type detect_type(std::string str)
{
	if (str == "nan" || str == "nanf")
		return (NANN);
	if (str == "-inff" || str == "-inf")
		return (INF_NEG);
	if (str == "+inff" || str == "+inf")
		return (INF_POS);
	if (isInt(str))
		return (INT);
	if (isFloat(str))
		return (FLOAT);
	if (isDouble(str))
		return (DOUBLE);
	if (isChar(str))
		return (CHAR);
	return (UNKNOWN);
}

void ScalarConverter::convert(std::string str)
{
	e_type type = detect_type(str);

	switch (type)
	{
		case CHAR:
			printChar(str);
			break;
		case INT:
			printInt(str);
			break;
		case FLOAT:
			printFloat(str);
			break;
		case DOUBLE:
			printDouble(str);
			break;
		case NANN:
			printNan(str);
			break;
		case INF_POS:
			printInfPos(str);
			break;
		case INF_NEG:
			printInfNeg(str);
			break;
		case UNKNOWN:
			std::cout << "Sorry, value type is unknown !\n";
	}
}

void printNan(std::string str)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : nanf" <<  std::endl;
	std::cout << "double : nan"<<  std::endl;
}

int isInt(std::string str)
{
	if (str.empty())
		return (0);
	int i = 0;
	int len = str.length();
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i >= len)
		return (0);
	while (i < len)
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int isChar(std::string str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

int isFloat(std::string str)
{
	int count_dot=0;
	if (str.empty())
		return (0);
	int len = str.length();
	int i = 0;
	bool has_dot = false;
	if (str[len - 1] != 'f')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < len - 1)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && !has_dot)
				has_dot = true;
			else 
				return (0);
		}
		i++;
	}
	return (has_dot);
}

int isDouble(std::string str)
{
	if (str.empty())
		return (0);
	int len = str.length();
	int i = 0;
	bool has_dot = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < len)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && !has_dot)
				has_dot = true;
			else
				return (0);
		}
		i++;
	}
	return (has_dot);
}

void printInfPos(std::string str)
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : +inff" << std::endl;
    std::cout << "double : +inf" << std::endl;
}

void printInfNeg(std::string str)
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : -inff" << std::endl;
    std::cout << "double : -inf" << std::endl;
}

void printChar(std::string str)
{	
	char c = str[0];
	std::cout << "char : " << "'" << c << "'\n";
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f"<< std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0"<<  std::endl;
}

	void printInt(std::string str)
	{
		double d = std::atof(str.c_str());
		if (d < 33 || d > 126)
			std::cout << "char : " << "Non displayable" << std::endl;
		else
			std::cout << "char : " << static_cast<char>(d) << std::endl;
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int : " << "impossible" << std::endl;
		else
			std::cout << "int : " << str << std::endl;
		if (d > FLT_MAX || d < -FLT_MAX)
			std::cout << "float : " << "impossible" << std::endl;
		else
			std::cout << "float : " << str << ".0f"<< std::endl; // ou static cast mais perte de precision!
		std::cout << "double : "  << str << ".0" << std::endl;// ou static cast mais perte de precision!
	}

void printFloat(std::string str)
{
	double d = std::atof(str.c_str());
	if (d < 33 || d > 126)
		std::cout << "char : " << "Non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(d) << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int : " << "impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(d) << std::endl;
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float : " << "impossible" << std::endl;
	else
		std::cout << "float : "  << str << std::endl;
	std::string newstr = str.substr(0, str.length() - 1);
	std::cout << "double : " << newstr <<  std::endl; // pour que 0.0f marche bien et pour ne pas perdre la precision! 
	//std::cout << "double : " << d << std::endl;
}

void printDouble(std::string str)
{
	double d = std::atof(str.c_str());
	if (d < 33 || d > 126)
		std::cout << "char : " << "Non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(d) << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int : " << "impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(d) << std::endl;
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float : " << "impossible" << std::endl;
	else
		std::cout << "float : " << str << "f"<<  std::endl;
	std::cout << "double : " << str <<  std::endl;
}