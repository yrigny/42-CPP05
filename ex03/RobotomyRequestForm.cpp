/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:02:20 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 15:20:31 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy Request Form", 72, 45), target("Default")
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
AForm("Robotomy Request Form", 72, 45), target(target) 
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
AForm(src), target(src.getTarget())
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is created with copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << this->getName()
	<< " with target [ " << this->getTarget() << " ]"
	<< ", sign grade " << this->getGradeToSign()
	<< ", execution grade " << this->getGradeToExec()
	<< ", signed status: " << this->getSignedStatus()
	<< ", is destructed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
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

const std::string&	RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedStatus() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException("Error: Executor's grade is too low to execute this form");
	if (std::rand() % 2 == 0)
	{
		std::cout << "bzzzzz...bzzzzz... " << "[ " << this->getTarget() << " ]"
		<< " has been robotomized successfully" << std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
}
