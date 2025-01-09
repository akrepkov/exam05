#pragma once
#include <iostream>

class ASpell {
	private:
		std::string name;
		std::string effects;
	public:
		ASpell(std::string newName, std::string newEffects){name = newName; effects = newEffects;};
		std::string getName() const{return name;};
		std::string getEffects() const{return effects;};
		virtual ASpell& cloning(const ASpell& ASpell) const = 0;

};
open .
