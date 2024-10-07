/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:54 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 16:51:44 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), grade_to_sign(150), grade_to_exec(150), is_signed(false)
{
	std::cout << "Form " << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< ", is created with default constructor" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_exec, bool is_signed):
name(name), 
grade_to_sign(grade_to_sign), 
grade_to_exec(grade_to_exec),
is_signed(is_signed)
{
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException("Error: Form grade too low. Valid range for form grade is [1,150].");
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	std::cout << "Form " << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< ", is created with default constructor" << std::endl;
}

Form::Form(const Form& src):
name(src.getName()), 
grade_to_sign(src.getGradeToSign()), 
grade_to_exec(src.getGradeToExec()), 
is_signed(src.getSignedStatus())
{
	std::cout << "Form " << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< " is created with copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< " is destructed" << std::endl;
}

Form&	Form::operator=(const Form& src)
{
	std::cout << "Form " << this->name
	<< " is assigned signed status " << src.getSignedStatus()
	<< " with copy assignment operator" << std::endl;
	this->is_signed = src.getSignedStatus();
	return (*this);
}

const std::string&	Form::getName() const
{
	return (this->name);
}

bool	Form::getSignedStatus() const
{
	return (this->is_signed);
}

int	Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	Form::getGradeToExec() const
{
	return (this->grade_to_exec);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw GradeTooLowException("Error: Bureaucrat's grade is too low to sign the form");
	else if (this->is_signed == true)
		throw AlreadySignedException();
	this->is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade too high. Valid range for form grade is [1,150].");
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message): std::invalid_argument(message)
{}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Error: Form is already signed.");
}

std::ostream&	operator<<(std::ostream& out, const Form& form)
{
	out << "Form " << form.getName() << ", sign grade " << form.getGradeToSign() << ", execute grade " << form.getGradeToExec();
	if (form.getSignedStatus() == true)
		out << ", is signed";
	else
		out << ", is not signed";
	return (out);
}
