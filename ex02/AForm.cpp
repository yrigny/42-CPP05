/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:46:54 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 17:02:04 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default"), grade_to_sign(150), grade_to_exec(150), is_signed(false)
{
	std::cout << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< ", is created with default constructor" << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_exec, bool is_signed):
name(name), 
grade_to_sign(grade_to_sign), 
grade_to_exec(grade_to_exec),
is_signed(is_signed)
{
	if (grade_to_sign > 150 || grade_to_exec > 150)
		throw GradeTooLowException("Error: AForm grade too low. Valid range for AForm grade is [1,150]");
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw GradeTooHighException();
	std::cout << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< ", is created with default constructor" << std::endl;
}

AForm::AForm(const AForm& src):
name(src.getName()), 
grade_to_sign(src.getGradeToSign()), 
grade_to_exec(src.getGradeToExec()), 
is_signed(src.getSignedStatus())
{
	std::cout << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< " is created with copy constructor" << std::endl;
}

AForm::~AForm()
{
	std::cout << this->name
	<< ", sign grade " << this->grade_to_sign
	<< ", execution grade " << this->grade_to_exec 
	<< ", signed status: " << this->is_signed
	<< " is destructed" << std::endl;
}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
	{
		std::cout << this->name
		<< " is assigned signed status " << src.getSignedStatus()
		<< " with copy assignment operator" << std::endl;
		this->is_signed = src.getSignedStatus();
	}
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSignedStatus() const
{
	return (this->is_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	AForm::getGradeToExec() const
{
	return (this->grade_to_exec);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw GradeTooLowException("Error: Bureaucrat's grade is too low to sign the Form");
	else if (this->is_signed == true)
		throw AlreadySignedException();
	this->is_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade too high. Valid range for Form grade is [1,150]");
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message): std::invalid_argument(message)
{}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("Error: Form is already signed.");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("Error: Form is not signed yet.");
}

std::ostream&	operator<<(std::ostream& out, const AForm& AForm)
{
	out << AForm.getName() << ", sign grade " << AForm.getGradeToSign() << ", execute grade " << AForm.getGradeToExec();
	if (AForm.getSignedStatus() == true)
		out << ", is signed";
	else
		out << ", is not signed";
	return (out);
}
