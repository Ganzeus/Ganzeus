#include <iostream>

#include "Date.h"
#include "Employee.h"

//任务四：创建Employee对象，然后修改其生日

int main() {
	Employee e;

	//1:setter
	e.setBirthday(Date(1999, 1, 1));
	std::cout << e.toString() << std::endl;

	//2:getter
	e.getBirthday()->setYear(1998);
	std::cout << e.toString() << std::endl;
	return (0);
}