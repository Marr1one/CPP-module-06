/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwan <marwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:09:11 by root              #+#    #+#             */
/*   Updated: 2026/01/28 16:42:46 by marwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

struct Data
{
	std::string ex_string;
	int ex_age;
};


class Serializer 
{
	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		
	public :
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};