/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:34:40 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 14:52:43 by yrigny           ###   ########.fr       */
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
	if (this != &src)
	{
		std::cout << "Bureaucrat " << this->name << " with grade " << this->grade
		<< " is assigned grade " << src.getGrade()
		<< " with copy assignment operator" << std::endl;
		this->grade = src.getGrade();
	}
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

void	Bureaucrat::signForm(AForm& form)
{
	if (form.getSignedStatus() == true)
		std::cout << "⛔ Bureaucrat " << this->getName() << " couldn't sign " << form.getName()
		<< " because the form is already signed" << std::endl;
	else if (this->grade > form.getGradeToSign())
		std::cout << "⛔ Bureaucrat " << this->getName() << " couldn't sign " << form.getName()
		<< " because the bureaucreat's grade is lower than the form's sign grade" << std::endl;
	else
		std::cout << "✅ Bureaucrat " << this->getName() << " signed " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(AForm& form)
{
	if (form.getSignedStatus() == false)
		std::cout << "⛔ Bureaucrat " << this->getName() << " could't execute " << form.getName()
		<< " because the form is not signed" << std::endl;
	else if (this->grade > form.getGradeToExec())
		std::cout << "⛔ Bureaucrat " << this->getName() << " couldn't execute " << form.getName()
		<< " because the bureaucreat's grade is lower than the form's execute grade" << std::endl;
	else
		std::cout << "✅ Bureaucrat " << this->getName() << " executed " << form.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high. Valid range for grade is [1,150]");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low. Valid range for grade is [1,150]");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
