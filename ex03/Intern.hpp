/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:41:07 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 16:16:26 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

typedef enum
{
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	NONE,
}	t_form_type;

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:

		Intern();
		Intern(const Intern& src);
		~Intern();
		Intern&	operator=(const Intern& src);

		AForm*	makeForm(const std::string name, const std::string target);
};

t_form_type	formType(const std::string s);

#endif
