/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhuang <yzhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:21:39 by yzhuang           #+#    #+#             */
/*   Updated: 2024/12/09 11:21:41 by yzhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &copy) {

	*this = copy;
}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &other) {

	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){

	return (reinterpret_cast<uintptr_t>(ptr));
 }

Data* Serializer::deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data*>(raw));
}
