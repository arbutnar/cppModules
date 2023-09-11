/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:39:21 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/10 17:59:33 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack( void ) {
}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const & src ) {
	*this = src;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=( MutantStack const & rhs ) {
	(void)rhs;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack( void ) {
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (this->c.end());
}