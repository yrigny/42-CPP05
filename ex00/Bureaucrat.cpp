/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:34:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/04 19:00:40 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " is created with default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " is created with default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): name(src.getName()), grade(src.getGrade())
{
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " is created with copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " is destructed" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " is assigned grade " << src.getGrade() << " with copy assignment operator" << std::endl;
	this->grade = src.getGrade();
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade -= 1;
	std::cout << "Bureaucrat " << this->name << " is promoted to grade " << grade << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade += 1;
	std::cout << "Bureaucrat " << this->name << " is demoted to grade " << grade << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high. Valid range for grade is [1,150].");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low. Valid range for grade is [1,150].");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
