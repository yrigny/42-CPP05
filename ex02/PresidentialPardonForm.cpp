/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:27:31 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 15:36:17 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential Pardon Form", 25, 5), target("Default")
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
AForm("Presidential Pardon Form", 25, 5), target(target) 
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
AForm(src), target(src.getTarget())
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is destructed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
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

const std::string&	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedStatus() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("Error: Executor's grade is too low to execute this form");
	std::cout << "[ " << this->getTarget() << " ]"
	<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
