#ifndef __PERSONAL_DATA_H__
#define __PERSONAL_DATA_H__

#include <iostream>
#include <string>
#include <memory>

class Pessoa{
	private:
		std::string _name;
		unsigned _day, _month, _year;
	
	public:	
		Pessoa (const std::string & _name, unsigned _day, unsigned _month, unsigned _year): 
		_name(_name), _day(_day), _month(_month), _year(_year) {	}
		
		const std::string &getName(void) {	return _name;	}	
		const unsigned &getDay(void)     {	return _day;	}
		const unsigned &getMonth(void)   {	return _month;	}
		const unsigned &getYear(void)    {	return _year;	}

};

std::unique_ptr<Pessoa> create_human(void){
	std::string name;
	unsigned day, month, year;
	std::cin>>name;
	std::cin>>day>>month>>year;
	std::unique_ptr<Pessoa> new_human(new Pessoa(name, day, month, year));
	return new_human;
}

#endif // __PERSONAL_DATA_H__
