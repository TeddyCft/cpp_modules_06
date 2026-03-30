#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string _name;
	int			_value;
}	Data;

class Serializer
{
	private:

	Serializer(void);
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &og);

	public:

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
	~Serializer(void);
}		;

#endif
