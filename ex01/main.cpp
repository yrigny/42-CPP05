/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:59:17 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 16:55:52 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define GREEN "\e[1;32m"
#define FADE "\e[2m"
#define NONE "\e[0m"

int	main(void)
{
	std::cout << std::endl << GREEN "Test default constructor with no attributes given" NONE << std::endl;
	Form	no_name;

	std::cout << std::endl << GREEN "Test default constructor with name and grade attributes given" NONE << std::endl;
	Form	a("A", 100, 120);

	std::cout << std::endl << GREEN "Test default constructor with all attributes given" NONE << std::endl;
	Form	b("B", 60, 80, true);

	std::cout << std::endl << GREEN "Test copy constructor" NONE << std::endl;
	Form	b_copy(b);

	std::cout << std::endl << GREEN "Test copy assignment operator" NONE << std::endl;
	b = no_name;
	std::cout << FADE "After: " NONE << no_name << std::endl;

	std::cout << std::endl << GREEN "Test GradeTooHighException" NONE << std::endl;
	std::cout << FADE "Try to create Form C with grade 0" NONE << std::endl;
	try
	{
		Form	c("C", 0, 150, false);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << GREEN "Test GradeTooLowException" NONE << std::endl;
	std::cout << FADE "Try to create Form with grade 151" NONE << std::endl;
	try
	{
		Form	d("D", 0, 200, false);
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
	
	std::cout << FADE "Try to make a Bureaucrat sign a signed Form within his grade" NONE << std::endl;
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

	std::cout << std::endl << GREEN "Test destructor" NONE << std::endl;

	return (0);
}
