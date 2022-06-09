#pragma once
#include "Date.h"
//任务二：定义Gender枚举类型
//任务三：定义Employee类
#include <iostream>
#include <string>

enum class Gender {
	male,
	female,	//最后一个枚举成员后可加括号
};
class Employee {
private:
	std::string name;
	Gender gender;
	Date birthday;
public:
	void setName(std::string name) { this->name = name; }
	void setGender(Gender gender) { this->gender = gender; }
	void setBirthday(Date birthday) { this->birthday = birthday; }
	std::string getName() { return name; }
	Gender getGender() { return gender; }
	Date* getBirthday() { return &birthday; }
	std::string toString() {
		return (name + (gender == Gender::male ? std::string("male") : std::string("female")) + birthday.toString());
	}
	Employee(std::string name, Gender gender, Date birthday):name{name},gender{gender},birthday{birthday}{}
	Employee():Employee("Alan",Gender::male, Date(2000,4,1)){}
};