/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 07:32:27 by root              #+#    #+#             */
/*   Updated: 2025/10/23 19:19:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_type detect_type(std::string var)
{
	if (isInt(var))
		return (INT);
	if (isFloat(var))
		return (FLOAT);
	if (isDouble(var))
		return (DOUBLE);
	if (isChar(var))
		return (CHAR);
	return (UNKNOWN);
}

void ScalarConverter::convert(std::string var)
{
	e_type type = detect_type(var);

	switch (type)
	{
		case CHAR:
			printChar(var);
			break;
		case INT:
			//printInt();
		case FLOAT:
			//printFloat();
		case DOUBLE:
			//printDouble();
		case UNKNOWN:
			std::cout << "Sorry, value type is unknown !\n";
	}
}

int isInt(std::string var)
{
	if (var.empty())
		return (0);
	int i = 0;
	int len = var.length();
	if (var[i] == '+' || var[i] == '-')
		i++;
	if (i >= var.length())
		return (0);
	while (i < len)
	{
		if (!std::isdigit(var[i]))
			return (0);
		i++;
	}
	return (1);
}

int isChar(std::string var)
{
	return (var.length() == 1);
}

int isFloat(std::string var)
{
	if (var.empty())
		return (0);
	int len = var.length();
	int i = 0;
	bool has_dot = false;
	if (var.length() - 1 != 'f')
		return (0);
	if (var[i] == '+' || var[i] == '-')
		i++;
	while (i < len)
	{
		if (!std::isdigit(var[i]))
		{
			if (var[i] == '.')
			{
				has_dot = true;
			}
			else 
				return (0);
		}
		i++;
	}
	return (has_dot);
}

int isDouble(std::string var)
{
	if (var.empty())
		return (0);
	int len = var.length();
	int i = 0;
	bool has_dot = false;
	if (var[i] == '+' || var[i] == '-')
		i++;
	while (i < len)
	{
		if (!std::isdigit(var[i]))
		{
			if (var[i] == '.')
			{
				has_dot = true;
			}
			else 
				return (0);
		}
		i++;
	}
	return (has_dot);
}

void printChar(std::string var)
{
	int i;
	if  (var.length() == 1)
		i = 0;
	else
		i = 1;
	char c = var[i];
	std::cout << "char : " << "'" << c << "'\n";
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f"<< std::endl;
	std::cout << "double : " << static_cast<double>(c) << ".0"<<  std::endl;
}