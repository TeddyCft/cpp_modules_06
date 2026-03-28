#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

//Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{ *this = copy ; }

//Default constructor
ScalarConverter::ScalarConverter(void)
{}

//Destructor
ScalarConverter::~ScalarConverter(void)
{}

//= Operator overloader
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &og)
{
	(void) og;
	return (*this);
}

static bool isNum(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return(false);
}

static t_valtype	checkInf(std::string &val)
{
	std::string tmp = val.substr(1);
	if (tmp == "inf" || tmp == "inff")
	{
		if (val[0] == '-')
			return (VT_INF_NEG);
		else if (val[0] == '+')
			return (VT_INF_POS);
	}
	return (VT_OTHER);
}

static bool checkDots(std::string &val, size_t start)
{
	size_t dot = val.find('.', start); // checking for multiple dots
	if (dot != std::string::npos)
	{
		if (val.find('.', dot + 1) != std::string::npos)
			return (false);
	}
	return (true);
}

static bool checkExp(std::string &val, size_t start)
{
	size_t nextExp = val.find_first_of("eE", start); // checking if multiple exposant
	if (nextExp != std::string::npos)
	{
		if (nextExp == val.size() - 1)
			return (false);
		nextExp = val.find_first_of("eE", nextExp + 1);
		if (nextExp != std::string::npos)
			return (false);
	}
	return (true);
}

static bool checkSigns(std::string &val, size_t start)
{
	size_t nextSign = val.find_first_of("+-", start);
	if (nextSign != std::string::npos)
	{
		if (val[nextSign - 1] == 'e' || val[nextSign - 1] == 'E')
		{
			nextSign = val.find_first_of("+-", nextSign + 1);
			if (nextSign != std::string::npos)
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

static bool checkDigits(std::string &val)
{
	std::string set = "+-0123456789.eE";
	for (size_t i = 0; i < val.size(); i++)
	{
		for (size_t j = 0; j < 16; j++)
		{
			if (val[i] == set[j])
				break ;
			if (j == 15)
				return (false);
		}
	}
	return (true);
}

static bool checkVal(std::string &val)
{
	size_t start = 0;

	if (val[0] == '+' || val[0] == '-') // checking if multiple + or - signs
		start = 1;
	if (!checkSigns(val, start) || !checkExp(val, start) || !checkDots(val, start) || !checkDigits(val))
		return (false);
	return (true);
}

static t_valtype	checkFloat(std::string &val)
{
	std::string tmp = val.substr(0, val.size() - 1);
	if (!checkVal(tmp))
		return (VT_OTHER);
	return (VT_FLOAT);
}

static bool isNumeric(std::string &val)
{
	size_t	start = 0;
	size_t	exp = 0;
	if (val[0] == '+' || val[0] == '-')
		start++;
	for (size_t i = start; i < val.size(); i++)
	{
		if (val[i] == 'e' || val[i] == 'E')
		{
			if (exp)
				return (false);
			exp++;
		}
		else if (val[i] < '0' || val[i] > '9')
			return (false);
	}
	return (true);
}

static t_valtype	getType(std::string &val)
{
	if (val.size() == 1 && !(isNum(static_cast<char>(val[0]))))
		return (VT_CHAR);
	if (val == "nan" || val == "nanf")
		return (VT_NAN);
	if (val.find("inf", 1) == 1) // if the value contains "inf"
		return (checkInf(val));
	if (val[val.size() - 1] == 'f') // if the end of the value is f
		return (checkFloat(val));	
	if (val.find(".") != std::string::npos)
	{
		if (!checkVal(val))
			return (VT_OTHER);
		return (VT_DOUBLE);
	}
	if (isNumeric(val))
		return (VT_INT);
	return (VT_OTHER);
}

void displayDouble(std::string &val, t_valtype type)
{
	std::cout << "double :[";
	if (type == VT_INF_NEG)
		std::cout << "-inf";
	if (type == VT_INF_POS)
		std::cout << "+inf";
	if (type == VT_NAN)
		std::cout << "nan";
	if (type == VT_CHAR)
		std::cout << static_cast<double>(val[0]);
	if (type == VT_INT || type == VT_DOUBLE || type == VT_FLOAT)
	{
		std::cout << std::fixed << std::setprecision(15) << static_cast<double>(strtod(val.c_str(), NULL));
		// std::cout << std::setprecision(6);
	}
	if (type == VT_OTHER)
		std::cout << "input error";
	std::cout << "]" << std::endl;
}

void displayFloat(std::string &val, t_valtype type)
{
	std::cout << "float :[";
	if (type == VT_INF_NEG)
		std::cout << "-inff";
	if (type == VT_INF_POS)
		std::cout << "+inff";
	if (type == VT_NAN)
		std::cout << "nanf";
	if (type == VT_CHAR)
		std::cout << static_cast<float>(val[0]);
	if (type == VT_INT || type == VT_DOUBLE || type == VT_FLOAT)
	{
		std::cout << std::fixed << std::setprecision(7) << static_cast<float>(strtof(val.c_str(), NULL));
		// std::cout << std::setprecision(6);
	}
	if (type == VT_OTHER)
		std::cout << "input error";
	std::cout << "]" << std::endl;
}

void displayInt(std::string &val, t_valtype type)
{
	std::cout << "int :[";
	if (type == VT_INF_NEG)
		std::cout << "-inf";
	if (type == VT_INF_POS)
		std::cout << "+inf";
	if (type == VT_NAN)
		std::cout << "nan";
	if (type == VT_CHAR)
		std::cout << static_cast<int>(val[0]);
	if (type == VT_INT || type == VT_DOUBLE || type == VT_FLOAT)
		std::cout << static_cast<int>(strtol(val.c_str(), NULL, 10));
	if (type == VT_OTHER)
		std::cout << "input error";
	std::cout << "]" << std::endl;
}

void displayChar(std::string &val, t_valtype type)
{
	std::cout << "char :[";
	if (type == VT_INF_NEG || type == VT_INF_POS || type == VT_NAN)
		std::cout << "impossible";
	if (type == VT_CHAR)
		std::cout << static_cast<char>(val[0]);
	if (type == VT_INT || type == VT_FLOAT || type == VT_DOUBLE)
	{
		char			*end;
		int	c = static_cast<int>(strtol(val.c_str(), &end, 10));
		if (c >= 32 && c <= 126)
			std::cout << static_cast<char>(c);
		else
			std::cout << "Non displayable";
	}
	if (type == VT_OTHER)
		std::cout << "input error";
	std::cout << "]" << std::endl;
}

void	ScalarConverter::convert(std::string &val) const
{
	t_valtype type = getType(val);
	displayChar(val, type);
	displayInt(val, type);
	displayFloat(val, type);
	displayDouble(val, type);
}
