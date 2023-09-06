#include "easyfind.hpp"

template <typename T>
void	easyfind(T v, int i) {
	std::vector<int>::iterator it;
	
	it = std::find(v.begin(), v.end(), i);
	if (it != v.end())
		std::cout << i << " found at position " << it - v.begin() << std::endl;
	else
		throw EasyFind::CannotFind();
}

int main() {

	try {
		int arr[] = { 4, 5, 100, 200, 90, 1 };
		std::vector<int> v(arr, arr + 7);
		easyfind(v, 1);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}