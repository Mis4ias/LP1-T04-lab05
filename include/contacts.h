#ifndef __CONTACTS_H__
#define __CONTACTS_H__

#include <iostream>
#include <string>
#include <memory>

class Contact{
	private:
		std::string _name;
		unsigned _day, _month, _year;
	
	public:	
		Contact (const std::string & _name, unsigned _day, unsigned _month, unsigned _year): 
		_name(_name), _day(_day), _month(_month), _year(_year) {	}
		
		const std::string &getName(void) {	return _name;	}	
		const unsigned &getDay(void)     {	return _day;	}
		const unsigned &getMonth(void)   {	return _month;	}
		const unsigned &getYear(void)    {	return _year;	}

};

std::unique_ptr<Contact> create_contact(void){
	std::string name;
	unsigned day, month, year;
	
	std::cout<<"Nome: ";
//	std::getline(std::cin, name);
	std::cin>>name;
	std::cin.sync();
	std::cin.get();
	
	
	std::cout<<"Dia Mes Ano: ";
	std::cin>>day>>month>>year;
	std::cin.sync();
	std::cin.get();
	std::unique_ptr<Contact> new_contact(new Contact(name, day, month, year));
	return new_contact;
}

#endif // __CONTACTS_H__
