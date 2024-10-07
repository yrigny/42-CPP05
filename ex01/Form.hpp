/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:24 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/07 20:00:18 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_exec;
		bool				is_signed;

	public:

		Form();
		Form(const std::string name, const int grade_to_sign, const int grade_to_exec, bool is_signed = false);
		Form(const Form& src);
		~Form();
		Form&	operator=(const Form& src);

		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::invalid_argument
		{
			public:
				GradeTooLowException(const std::string& message);
		};
		class AlreadySignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
