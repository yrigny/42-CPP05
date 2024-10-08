/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:47:56 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 16:16:36 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor is called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	std::cout << "Intern copy constructor is called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor is called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Intern copy assignment operator is called" << std::endl;
	return (*this);
}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	AForm*	form;
	switch (formType(name))
	{
		case SHRUBBERY_CREATION:
			form = new ShrubberyCreationForm(target);
			break;
		
		case ROBOTOMY_REQUEST:
			form = new RobotomyRequestForm(target);
			break;

		case PRESIDENTIAL_PARDON:
			form = new PresidentialPardonForm(target);
			break;

		default:
			std::cout << "Error: Form " << name << " doesn't exist" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}

t_form_type	formType(const std::string s)
{
	std::string	arr_forms[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (s == arr_forms[i])
			return (static_cast<t_form_type>(i));
	}
	return (NONE);
}