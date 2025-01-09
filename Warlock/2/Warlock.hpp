#pragma once
#include <iostream>


class Warlock{
	private:
		std::string name;
		std::string title;

	public:
		Warlock(std::string newName, std::string newTitle){name = newName; title = newTitle; std::cout << name << ": This looks like another boring day." << std::endl; };
		~Warlock(){ std::cout << name << ": My job here is done!" << std::endl; };
		Warlock& operator=(const Warlock& copy);
		Warlock(const Warlock& copy);
		std::string getName() const{return name;};
		std::string getTitle() const{return title;};
		void setName(std::string newName){name = newName;};
		void setTitle(std::string newTitle){title = newTitle;};
		void introduce() const{std::cout << name << ": I am " << name  << ", "  << title  << "!"  << std::endl; };
		
};
