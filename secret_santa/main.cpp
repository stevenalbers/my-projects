#include <iostream>
#include <string>
#include <random>
#include <fstream>

struct person
{
	std::string firstName;
	std::string lastName;
	int id = 0;
	bool picked = false;
};

bool randomizeSecretSanta(person list[], int memberCount);

bool matchSanta(person &lhs, person rhs);

int main()
{
	// initialize random number generator
	srand(time(NULL));

	
	// variables
	person santaList[80];
	std::fstream albersFile("albers.txt");
	std::fstream lansangFile("lansang.txt");
	std::fstream fremontFile("fremont.txt");
	
	int count = 0;
	
	bool successfulRandomize = false;

	std::string name;
	
	int i=0;
	while(std::getline(albersFile, name))
	{
		santaList[i].firstName = name;
		santaList[i].lastName = "Albers";

		i++;
	}
	
	while(std::getline(lansangFile, name))
	{
		santaList[i].firstName = name;
		santaList[i].lastName = "Lansang";

		i++;
	}
	
	while(std::getline(fremontFile, name))
	{
		santaList[i].firstName = name;
		santaList[i].lastName = "Fremont";

		i++;
	}

	count = i;
		
	successfulRandomize = randomizeSecretSanta(santaList, count);
	
return successfulRandomize;
}

bool randomizeSecretSanta(person list[], int memberCount)
{
	// variables
	std::ofstream output("output.txt", std::ofstream::out);
	int randInt = 0;

	// loop through each id
	for(int i = 0; i < memberCount; i++)
	{
		// randomize a potential secret santee
		randInt = rand() % memberCount;

		// loop until this person is matched
		while(list[randInt].picked == false)
		{
			if(!matchSanta(list[randInt], list[i]))
			{
				randInt = rand() % memberCount;

			}
			else
			{
				output << list[i].firstName << " has " << list[randInt].firstName << std::endl;

			}
		}
		// if the member with that id is of the same family or already selected, try again
		
	}
		
	
	return false;
}

bool matchSanta(person &lhs, person rhs)
{
	if(lhs.lastName != rhs.lastName && lhs.picked == false)
	{
		lhs.picked == true;
	}
	return lhs.picked;
}

