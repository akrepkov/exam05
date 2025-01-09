#pragma once
#include <iostream>
#include "ASpell.hpp"

class ATarget {
	private:
		std::string type;
	public:
		std::string getType() const{return type;};
		virtual ATarget& clone(const ATarget& ATarget) const = 0;
		void getHitbySpell(const ASpell& ASpell) const {std::cout << type << " has been " << ASpell.getEffects()  << std::endl;};

};

