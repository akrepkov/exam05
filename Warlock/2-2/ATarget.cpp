#include "ATarget.hpp"


ATarget& ATarget::operator=(const	ATarget &a){
	if (this != &a){
		this->_type = a._type;
	}
	return *this;
}
std::string ATarget::getType() const{
	return (this->_type);
}
// const ATarget& ATarget::clone() {
// 	return *this;
// }
void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << this->_type << " has been " << spell.getEffects() << std::endl;
}