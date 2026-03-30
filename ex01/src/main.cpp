#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

int main ()
{
	Data data = {"Michel", 42};
	std::cout << "---- before serialize ----" << std::endl;
	std::cout << "data ptr = " <<  &data << " // data name = " << data._name << " // data value = " << data._value << std::endl; 
	
	uintptr_t raw = Serializer::serialize(&data);	
	std::cout << std::endl << "---- after serialize ----" << std::endl;
	std::cout << "raw = 0x" << std::hex << raw << std::endl;
	
	Data *ptr = Serializer::deserialize(raw);
	std::cout << std::endl << "---- after deserialize ----" << std::endl;
	std::cout << "data ptr = " << ptr << " // data name = " << ptr->_name << " // data value = " << ptr->_value << std::endl; 

	return (0);
}
