#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget{
	protected:
		// std::string _type;
	public:
		Dummy();
		~Dummy(){};
		Dummy& operator=(const Dummy &a);
		std::string getType() const;
		Dummy& clone();
		void getHitBySpell(const ASpell& spell) const ;
};
