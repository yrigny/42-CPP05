/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:47:56 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/09 16:45:41 by yrigny           ###   ########.fr       */
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
	AForm*			form;
	t_form_type		form_type = formType(name);
	t_form_creator	creator_arr[] =
	{
		&createShrubberyCreation,
		&createRobotomyRequest,
		&createPresidentialPardon
	};
	if (form_type == NONE)
	{
		std::cout << "Intern couldn't create nonexisting form "
		<< form->getName() << std::endl;
		return NULL;
	}
	form = creator_arr[form_type](target);
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
	std::string	s_lower = "";
	for (unsigned long i = 0; i < s.length(); i++)
		s_lower += std::tolower(s[i]);
	for (int i = 0; i < 3; i++)
	{
		if (s_lower == arr_forms[i])
			return (static_cast<t_form_type>(i));
	}
	return (NONE);
}

AForm*	createShrubberyCreation(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	createRobotomyRequest(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	createPresidentialPardon(const std::string target)
{
	return new PresidentialPardonForm(target);
}
