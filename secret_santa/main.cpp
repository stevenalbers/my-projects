#include <iostream>
#include <string>
#include <random>
#include <fstream>

struct family
{
	std::string member[10];
	int size = 0;
	int id[10] = 0;
};

bool randomizeSecretSanta(int memberCount);

family findMember(int inputId);


int main()
{
	// initialize random number generator
	srand(time(NULL));

	
	// variables
	family Albers;
	family Lansang;
	family Fremont;
	std::fstream albersFile("albers.txt");
	std::fstream lansangFile("lansang.txt");
	std::fstream fremontFile("fremont.txt");
	

	std::string name;
	
	int i=0;
	int j=0;
	while(std::getline(albersFile, name))
	{
		Albers.member[i] = name;
		Albers.id[i] = j;

		i++;
		j++;
	}
	Albers.size = i;
	
	i=0;
	while(std::getline(lansangFile, name))
	{
		Lansang.member[i] = name;
		Lansang.id[i] = j;

		i++;
		j++;
	}
	Lansang.size = i;
	
	i=0;
	while(std::getline(fremontFile, name))
	{
		Fremont.member[i] = name;
		Fremont.id[i] = j;

		i++;
		j++;
	}
	Fremont.size = i;

	
		
	
return 0;
}

bool randomizeSecretSanta(int memberCount)
{
	// variables
	std::ofstream output("output.txt", std::ofstream::out);
	int randInt = 0;

	// loop through each id
	for(int i = 0; i < memberCount; i++)
	{
		// randomize a potential secret santee
		randInt = rand() % memberCount;

		// match id to member

		
		// if the member with that id is of the same family or already selected, try again
	}
		
	
	return false;
}

family findMember(int inputId)
{
	// loop through each family
	for(int i = 0; i < Albers.size; i++)
	{
		if( inputId == i)
		{
			return i;
		}
	}
}

