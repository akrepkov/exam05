#include "ATarget.hpp"
#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "Warlock.hpp"

int main()
{
	Warlock richard("Richard", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();
	richard.learnSpell(fwoosh);

	richard.introduce();
	richard.launchSpell("Fwoosh", bob);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", bob);
	std::cout << fwoosh->getEffects() << std::endl;
	std::cout << bob.getType() << std::endl;
}

/*
Repeat:
	vectors
	maps?
	stacks
	iteration by value : (for (std::string s : spells)), 
s is a copy of each element, you can't change the vector, that's why we use 
remove and erase from <alghorithm>
	const method can have only other const methods inside
	if you use the same attributes in base and derived class, don't write them
again in derived, ask Jan wtf
	forward declaration, when to use?
	override?
	pure virtual functions, you can't create an instance for this class
	virtual deconstructor
	for (std::string s : spells)
	auto it = std::remove(spells.begin(), spells.end(), spell);


	*/