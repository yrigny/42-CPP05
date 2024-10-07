/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:44:18 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 19:58:36 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define GREEN "\e[1;32m"
#define FADE "\e[2m"
#define NONE "\e[0m"

int	main(void)
{
	std::cout << std::endl << GREEN "Test default constructor with no argument" NONE << std::endl;
	ShrubberyCreationForm	no_name;

	std::cout << std::endl << GREEN "Test default constructor with target given" NONE << std::endl;
	ShrubberyCreationForm	a("home");

	std::cout << std::endl << GREEN "Test copy constructor" NONE << std::endl;
	ShrubberyCreationForm	b(a);

	std::cout << std::endl << GREEN "Test copy assignment operator" NONE << std::endl;
	b = no_name;
	std::cout << FADE "After: " NONE << no_name << std::endl;

	std::cout << std::endl << GREEN "Test GradeTooHighException" NONE << std::endl;
	std::cout << FADE "Try to create Form C with grade 0" NONE << std::endl;
	try
	{
		ShrubberyCreationForm	c("company");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN "Test GradeTooLowException" NONE << std::endl;
	std::cout << FADE "Try to create Form with grade 151" NONE << std::endl;
	try
	{
		ShrubberyCreationForm	d("garden");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "Try to make a Bureaucrat sign a Form beyond his grade" NONE << std::endl;
	Bureaucrat	amber("Amber", 100);
	try
	{
		amber.signForm(b);
		b.beSigned(amber);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "After: " NONE << b << std::endl;

	std::cout << std::endl << GREEN "Extra tests" NONE << std::endl;
	std::cout << FADE "Try to make a Bureaucrat sign a Form within his grade" NONE << std::endl;
	try
	{
		amber.signForm(a);
		a.beSigned(amber);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "After: " NONE << a << std::endl;
	
	std::cout << FADE "Try to make a Bureaucrat execute a signed Form within his grade" NONE << std::endl;
	try
	{
		amber.executeForm(a);
		a.execute(amber);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "After: " NONE << a << std::endl;

	std::cout << std::endl << GREEN "Test destructor" NONE << std::endl;

	return (0);
}
