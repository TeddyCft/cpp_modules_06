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

	public:

	void convert(std::string &str) const;

	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &og);
	~ScalarConverter(void);
}		;

#endif
