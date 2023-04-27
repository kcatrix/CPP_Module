/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:01:12 by acolin            #+#    #+#             */
/*   Updated: 2022/03/23 14:01:12 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base*	generate(void);
void	identify(Base *p);
void	identify(Base &p);
