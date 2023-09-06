#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class EasyFind {

	public:
		class CannotFind : public std::exception {
			public:
				virtual const char* what() const throw() { return ("Cannot find wanted number"); }
		};
};

template <typename T>
void	easyfind(T container, int i);