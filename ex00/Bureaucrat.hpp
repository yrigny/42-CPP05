/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrigny <yrigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:14:01 by yrigny            #+#    #+#             */
/*   Updated: 2024/10/03 12:56:17 by yrigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:

		const std::string	name;
		unsigned char		grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string name, unsigned char grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& src);

		const std::string&	getName() const;
		unsigned char		getGrade() const;
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

#endif
