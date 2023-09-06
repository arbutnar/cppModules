#pragma once

#include <iostream>
#include <string>

class Fixed {

	private:
		int	num;
		static const int bit = 8;
	public:
		Fixed();
		// the const prevents any modificatoin of the source object
		Fixed(const Fixed &source);
		Fixed &operator=(const Fixed &source);
		~Fixed();
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};
