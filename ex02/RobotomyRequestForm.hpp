/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:51:47 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 10:59:46 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:

		const std::string	target;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		
		const std::string&	getTarget() const;
		void				execute(Bureaucrat const& executor) const;
};

#endif