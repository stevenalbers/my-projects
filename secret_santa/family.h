#include <string>

// family class
class family
{
	public:
family(int size)
{
	familySize = size;
	std::string member[familySize];
}
~family()
{
	
}
	std::string setMember(std::string newMember, int pos);
	std::string member[];
	int familySize;

	private:
	
};
