/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:11 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 19:55:15 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
AForm("Shrubbery Creation Form", 145, 137), target(target) 
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
AForm(src), target(src.getTarget())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
		AForm::operator=(src);//???
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
	if (this->getGradeToExec() < executor.getGrade())
		throw AForm::GradeTooLowException("Error: Executor's grade is too low to execute this form");
	std::string	filename = this->target + "_shrubbery";
	std::fstream		outfile(filename.c_str(), std::ios::out);
	std::string			tree;
	tree += "        *\n";
    tree += "       ***\n";
    tree += "      *****\n";
    tree += "     *******\n";
    tree += "    *********\n";
    tree += "   ***********\n";
    tree += "        |\n";
	if (outfile.is_open())
		outfile << tree;
	outfile.close();
}
