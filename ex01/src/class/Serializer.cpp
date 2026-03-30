#include "Serializer.hpp"

//Copy constructor
Serializer::Serializer(const Serializer &copy)
{ *this = copy ; }

//Default constructor
Serializer::Serializer(void)// : args(0), ...
{}

//Destructor
Serializer::~Serializer(void)
{}

//= Operator overloader
Serializer	&Serializer::operator=(const Serializer &og)
{
	(void) og;
	return (*this);
}


uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data *ret = reinterpret_cast<Data *>(raw);
	return (ret);
}