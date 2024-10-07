/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:09:10 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 16:30:41 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#define GREEN "\e[1;32m"
#define FADE "\e[2m"
#define NONE "\e[0m"

int	main()
{
	std::cout << std::endl << GREEN "Test default constructor" NONE << std::endl;
	Bureaucrat	no_name;

	std::cout << std::endl << GREEN "Test default constructor with name given" NONE << std::endl;
	Bureaucrat	amber("Amber");

	std::cout << std::endl << GREEN "Test default constructor with name and grade given" NONE << std::endl;
	Bureaucrat	bob("Bob", 1);

	std::cout << std::endl << GREEN "Test copy constructor" NONE << std::endl;
	Bureaucrat	chris(bob); // chris has name copied from bob

	std::cout << std::endl << GREEN "Test copy assignment operator" NONE << std::endl;
	std::cout << FADE "Let " NONE << no_name << " = " << bob << std::endl;
	no_name = bob;
	std::cout << FADE "After: " NONE << no_name << std::endl;

	std::cout << std::endl << GREEN "Test GradeTooHighException" NONE << std::endl;
	std::cout << FADE "Try to create David with grade 0" NONE << std::endl;
	try
	{
		Bureaucrat	david("David", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "Try to promote " NONE << bob << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "After: " NONE << bob << std::endl;

	std::cout << std::endl << GREEN "Test GradeTooLowException" NONE << std::endl;
	std::cout << FADE "Try to create Edward with grade 151" NONE << std::endl;
	try
	{
		Bureaucrat	edward("Edward", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "Try to demote " NONE << amber << std::endl;
	try
	{
		amber.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << FADE "After: " NONE << amber << std::endl;

	std::cout << std::endl << GREEN "Test destructor" NONE << std::endl;
	return (0);
}