/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <ydemange@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:06 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void) : root_part(0){ }
Object::Object(const Object &src) { *this = src; }
Object::~Object(void) { }

Object	&Object::operator=(const Object &rhs)
{
	this->model = rhs.model;
	this->root_part = rhs.root_part;

	// this->position = rhs.position;
	// this->velocity = rhs.velocity;
	// this->mass = rhs.mass;
	// this->angular_position = rhs.angular_position;
	// this->angular_velocity = rhs.angular_velocity;
	// this->dimension = rhs.dimension;
	// this->diameter = rhs.diameter;
	return (*this);
}

Matrix Object::GetModel() const
{
	if (this->root_part)
	{
		return (this->root_part->GetModel() * this->model);

	}
	else
	{
		return (this->model);

	}
	
	
}