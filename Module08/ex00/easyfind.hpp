/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:57:16 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:57:28 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>
# include <algorithm>

class EasyFind {

	public:
		class CannotFind : public std::exception {
			public:
				virtual const char* what() const throw() { return ("Cannot find wanted number"); }
		};
};

template <typename T>
void	easyfind( T container, int i );
