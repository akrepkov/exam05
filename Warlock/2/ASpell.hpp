#pragma once
#include <iostream>
#include "ATarget.hpp"

class ASpell {
	private:
		std::string name;
		std::string effects;
	public:
		ASpell(){};
		ASpell(std::string newName, std::string newEffects){name = newName; effects = newEffects;};
		std::string getName() const{return name;};
		std::string getEffects() const{return effects;};
		virtual ASpell& clone(const ASpell& ASpell) const = 0;
		void launch(const ATarget& ATarget) const {ATarget.getHitbySpell(*this);};

};

