/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:22:37 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 11:28:08 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:

		const std::string	target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		
		const std::string&	getTarget() const;
		void				execute(Bureaucrat const& executor) const;
};

#endif
