#include "ScalarConverter.hpp"
#include <iostream>

bool arg_check(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "error : wrong argument count" << std::endl;
	else if (static_cast<std::string>(argv[1]).empty())
		std::cerr << "error : empty arg" << std::endl;
	else
		return (true);
	return (false);
}

int main (int argc, char **argv)
{
	if (!arg_check(argc, argv))
		return (1);
	std::string val = static_cast<std::string>(argv[1]);
	ScalarConverter::convert(val);
	return (0);
}
