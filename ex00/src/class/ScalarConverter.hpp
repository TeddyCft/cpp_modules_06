#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

typedef enum e_valtype
{
	VT_CHAR,
	VT_FLOAT,
	VT_INT,
	VT_DOUBLE,
	VT_INF_POS,
	VT_INF_NEG,
	VT_NAN,
	VT_OTHER
}	t_valtype;

class ScalarConverter
{
	private:

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &og);

	public:

	static void convert(std::string &str);
	~ScalarConverter(void);
}		;

#endif
