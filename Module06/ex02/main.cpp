/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbutnar <arbutnar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:28:17 by arbutnar          #+#    #+#             */
/*   Updated: 2023/09/08 17:28:10 by arbutnar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

class Base {
	public:
		virtual ~Base( void ) {};
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base *generate( void ) {
	srand(time(NULL));
	std::string letter[3] = {"a", "b", "c"};
	int i = rand() % 3;
	if (letter[i] == "a")
		return (new A);
	else if (letter[i] == "b")
		return (new B);
	else if (letter[i] == "c")
		return (new C);
	else
		return (NULL);
}

void identify( Base* p ) {
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer type: C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify( Base& p ) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference type: A" << std::endl;
		(void)a;
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "Reference type: B" << std::endl;
			(void)b;
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "Reference type: C" << std::endl;
				(void)c;
			} catch (std::exception &e) { std::cout << e.what() << std::endl; }
		}
	}
}

int main() {

	Base *base = generate();
	identify(base);

	Base *base2 = new A();
	identify(*base2);

	return 0;
}