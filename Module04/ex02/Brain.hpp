/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:08:14 by arbutnar          #+#    #+#             */
/*   Updated: 2023/08/09 16:08:16 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Brain {

	private:
		std::string ideas[100];
	public:

		Brain();
		Brain(const Brain &src);
		~Brain( void );

		Brain &operator=(const Brain &src);
};