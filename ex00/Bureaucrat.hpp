/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:14:01 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/04 18:45:31 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:

		const std::string	name;
		int					grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string name, int grade = 150);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& src);

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
#endif
