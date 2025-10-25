/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:09:11 by root              #+#    #+#             */
/*   Updated: 2025/10/25 13:33:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
		Serializer(Serializer &other);
		Serializer &operator=(Serializer &other);
		
	public :
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};