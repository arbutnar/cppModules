/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:04:12 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/09 16:04:12 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

template <typename T>
void	display( T element );

template <typename T1, typename T2, typename Func>
void	iter( T1 *array, T2 len, Func display );
