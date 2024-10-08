/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:24 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/08 11:00:37 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
# define A_FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	name;
		const int			grade_to_sign;
		const int			grade_to_exec;
		bool				is_signed;

	public:
		AForm();
		AForm(const std::string name, const int grade_to_sign, const int grade_to_exec, bool is_signed = false);
		AForm(const AForm& src);
		virtual	~AForm();
		AForm&	operator=(const AForm& src);

		const std::string&	getName() const;
		bool				getSignedStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual	void		execute(Bureaucrat const& executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& form);

#endif