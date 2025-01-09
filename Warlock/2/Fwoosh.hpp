#pragma once
#include <iostream>
#include "ASpell.hpp"

class FWoosh : public ASpell {
	private:
		std::string name;
		std::string effects;
	public:
		FWoosh(){name = "Fwoosh"; effects = "Fwooshed";};
		virtual ASpell& clone(const ASpell& ASpell) const {};


};

