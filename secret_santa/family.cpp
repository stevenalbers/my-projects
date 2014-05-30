#include "family.h"

#include <string>

std::string family::setMember(std::string newMember, int pos)
{
	this->member[pos] = newMember;
}
