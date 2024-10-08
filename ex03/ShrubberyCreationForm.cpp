/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:11 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 14:36:30 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Shrubbery Creation Form", 145, 137), target("Default")
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
AForm("Shrubbery Creation Form", 145, 137), target(target) 
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
AForm(src), target(src.getTarget())
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is destructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		std::cout << this->getName()
		<< " with target [ " << this->getTarget() << " ]"
		<< " is assigned signed status " << src.getSignedStatus()
		<< " with copy assignment operator" << std::endl;
	}
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedStatus() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("Error: Executor's grade is too low to execute this form");
	std::string		tree;
	tree += "        *\n";
    tree += "       ***\n";
    tree += "      *****\n";
    tree += "     *******\n";
    tree += "    *********\n";
    tree += "   ***********\n";
    tree += "        |\n";
	std::string		filename = this->target + "_shrubbery";
	std::fstream	outfile(filename.c_str(), std::ios::out);
	if (outfile.is_open())
	{
		outfile << tree;
		outfile.close();
	}
}
