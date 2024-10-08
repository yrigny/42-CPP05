/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:15:30 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 10:56:11 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM
# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:

		const std::string	target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);

		const std::string&	getTarget() const;
		void				execute(Bureaucrat const& executor) const;
};

#endif
