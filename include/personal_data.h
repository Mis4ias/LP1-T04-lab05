#ifndef __PERSONAL_DATA_H__
#define __PERSONAL_DATA_H__

#include <iostream>
#include <string>
#include <memory>

class Person{
	private:
		std::string _name;
		unsigned _day, _month, _year;
	
	public:	
		Person (const std::string & _name, unsigned _day, unsigned _month, unsigned _year): 
		_name(_name), _day(_day), _month(_month), _year(_year) {	}
		
		const std::string &getName(void) {	return _name;	}	
		const unsigned &getDay(void)     {	return _day;	}
		const unsigned &getMonth(void)   {	return _month;	}
		const unsigned &getYear(void)    {	return _year;	}

};

std::unique_ptr<Person> create_human(void){
	std::string name;
	unsigned day, month, year;
	std::cin>>name;
	std::cin>>day>>month>>year;
	std::unique_ptr<Person> new_human(new Person(name, day, month, year));
	return new_human;
}

#endif // __PERSONAL_DATA_H__
