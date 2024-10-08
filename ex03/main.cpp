/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:44:18 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 15:37:12 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#define TITLE "\e[1;32m"
#define COMMENT "\e[33m"
#define NONE "\e[0m"

void	help_msg(std::string msg, std::string style)
{
	if (style == TITLE)
		std::cout << std::endl;
	std::cout << style << msg << NONE << std::endl;
}

int	main(void)
{
	help_msg("Create Bureaucrat for test use", TITLE);
	Bureaucrat	b1("Amber", 1);
	Bureaucrat	b2("Brian", 20);
	Bureaucrat	b3("Chris", 60);
	Bureaucrat	b4("David", 140);
	Bureaucrat	b5("Eddie", 150);

	{	// Shrubbery Creation Form
		help_msg("Test - Shrubbery - default constructor with no argument", TITLE);
		ShrubberyCreationForm	s_default;

		help_msg("Test - Shrubbery - default constructor with target given", TITLE);
		ShrubberyCreationForm	s1("Home");
		ShrubberyCreationForm	s2("School");

		help_msg("Test - Shrubbery - copy constructor", TITLE);
		ShrubberyCreationForm	s3(s1);

		help_msg("Test - Shrubbery - copy assignment operator", TITLE);
		s3 = s_default;

		help_msg("Test - Shrubbery - Grade Too Low Exception", TITLE);
		try
		{
			help_msg("Try to get form signed by a lower grade Bureaucrat", COMMENT);
			b5.signForm(s1);
			s1.beSigned(b5);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get form signed by a higher grade Bureaucrat", COMMENT);
			b4.signForm(s1);
			s1.beSigned(b4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a lower grade Bureaucrat", COMMENT);
			b4.executeForm(s1);
			s1.execute(b4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			b3.executeForm(s1);
			s1.execute(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Shrubbery - Not Signed Exception", TITLE);
		try
		{
			help_msg("Try to get an unsigned form executed by a higher grade Bureaucrat", COMMENT);
			b3.executeForm(s2);
			s2.execute(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			s_default = s1;
			b3.executeForm(s_default);
			s_default.execute(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		help_msg("Test - Shrubbery - Already Signed Exception", TITLE);
		try
		{
			help_msg("Try to get a signed form signed", COMMENT);
			b4.signForm(s1);
			s1.beSigned(b4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get an unsigned form signed", COMMENT);
			b4.signForm(s2);
			s2.beSigned(b4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Shrubbery - destructor", TITLE);
	}

	{	// Robotomy Request Form
		help_msg("Test - Robotomy - default constructor with no argument", TITLE);
		RobotomyRequestForm	r_default;

		help_msg("Test - Robotomy - default constructor with target given", TITLE);
		RobotomyRequestForm	r1("007");
		RobotomyRequestForm	r2("008");

		help_msg("Test - Robotomy - copy constructor", TITLE);
		RobotomyRequestForm	r3(r1);

		help_msg("Test - Robotomy - copy assignment operator", TITLE);
		r3 = r_default;

		help_msg("Test - Robotomy - Grade Too Low Exception", TITLE);
		try
		{
			help_msg("Try to get form signed by a lower grade Bureaucrat", COMMENT);
			b4.signForm(r1);
			r1.beSigned(b4);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get form signed by a higher grade Bureaucrat", COMMENT);
			b3.signForm(r1);
			r1.beSigned(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a lower grade Bureaucrat", COMMENT);
			b3.executeForm(r1);
			r1.execute(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			b1.executeForm(r1);
			r1.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Robotomy - Not Signed Exception", TITLE);
		try
		{
			help_msg("Try to get an unsigned form executed by a higher grade Bureaucrat", COMMENT);
			b1.executeForm(r2);
			r2.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			r_default = r1;
			b1.executeForm(r_default);
			r_default.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Robotomy - Already Signed Exception", TITLE);
		try
		{
			help_msg("Try to get a signed form signed", COMMENT);
			b3.signForm(r1);
			r1.beSigned(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get an unsigned form signed", COMMENT);
			b3.signForm(r2);
			r2.beSigned(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Robotomy - destructor", TITLE);
	}

	{	// Presidential Pardon Form
		help_msg("Test - Presidential - default constructor with no argument", TITLE);
		PresidentialPardonForm	p_default;

		help_msg("Test - Presidential - default constructor with target given", TITLE);
		PresidentialPardonForm	p1("Fred");
		PresidentialPardonForm	p2("Greg");

		help_msg("Test - Presidential - copy constructor", TITLE);
		PresidentialPardonForm	p3(p1);

		help_msg("Test - Presidential - copy assignment operator", TITLE);
		p3 = p_default;

		help_msg("Test - Presidential - Grade Too Low Exception", TITLE);
		try
		{
			help_msg("Try to get form signed by a lower grade Bureaucrat", COMMENT);
			b3.signForm(p1);
			p1.beSigned(b3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get form signed by a higher grade Bureaucrat", COMMENT);
			b2.signForm(p1);
			p1.beSigned(b2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a lower grade Bureaucrat", COMMENT);
			b2.executeForm(p1);
			p1.execute(b2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			b1.executeForm(p1);
			p1.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Presidential - Not Signed Exception", TITLE);
		try
		{
			help_msg("Try to get an unsigned form executed by a higher grade Bureaucrat", COMMENT);
			b1.executeForm(p2);
			p2.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get a signed form executed by a higher grade Bureaucrat", COMMENT);
			p_default = p1;
			b1.executeForm(p_default);
			p_default.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Presidential - Already Signed Exception", TITLE);
		try
		{
			help_msg("Try to get a signed form signed", COMMENT);
			b2.signForm(p1);
			p1.beSigned(b2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			help_msg("Try to get an unsigned form signed", COMMENT);
			b2.signForm(p2);
			p2.beSigned(b2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		help_msg("Test - Presidential - destructor", TITLE);
	}

	help_msg("Destruct Bureaucrats", TITLE);
	std::cout << std::endl;
	return (0);
}
