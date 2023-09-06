#include "iter.hpp"

template <typename T>
void	display(T element) {
	std::cout << element << " ";
}

template <typename T1, typename T2, typename Func>
void	iter(T1 *array, T2 len, Func display) {
	for (int i = 0; i < len; i++)
		display(array[i]);
}

int main() {

	int array[] = { 1, 3, 5, 7, 9 };
	
	iter(array, 5, display<int>);
	std::cout << std::endl;

	return 0;
}