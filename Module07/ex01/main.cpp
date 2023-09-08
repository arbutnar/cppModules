/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:40:19 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 18:40:19 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

# define N 5

template <typename T>
void	display( T element ) {
	std::cout << element << " ";
}

template <typename T1, typename T2, typename Func>
void	iter( T1 *array, T2 len, Func display ) {
	for (int i = 0; i < len; i++)
		display(array[i]);
}

int main() {

    int arr1[] = { 1, 2, 3, 4, 5 };

    std::cout << "Array 1: ";
    iter( arr1, N, display<int> );

    double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    std::cout << "\nArray 2: ";
    iter( arr2, N, display<float> );

    char arr3[] = { 'a', 'b', 'c', 'd', 'e' };

    std::cout << "\nArray 3: ";
    iter( arr3, N, display<char> );

    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\nArray 4: ";
    iter( arr4, N, display<std::string> );
	std::cout << std::endl;

    return 0;
}