int Scalar::setStatus(std::string literal) {
	if (literal.size() == 1) {
		if (std::isalpha(literal.at(0)))
			return (type = CHAR);
		else
			return (type = INT);
	}
	long unsigned int i = 0;
	if (literal.at(0) == '+' || literal.at(0) == '-')
			i += 1;
	for (; i < literal.size(); i++) {
		if (literal.at(i) == '.') {
			if (literal.find_first_of('f') == literal.at(literal.size() - 1))
				return (type = FLOAT);
			else if (isdigit(literal.at(literal.size() - 1)))
				return (type = DOUBLE);
			else
				return (type = INVALID);
		} else if (!isdigit(literal.at(i)))
			return (type = INVALID);
	}
	return (type = INT);
}