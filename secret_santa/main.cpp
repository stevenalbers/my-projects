#include <iostream>
#include <string>
#include <random>
#include <fstream>

struct person
{
	std::string firstName;
	std::string lastName;
	int id = 0;
	bool isSanta = false;
	bool hasSanta = false;
};

bool randomizeSecretSanta(person list[], int memberCount);

bool matchSanta(person &lhs, person rhs);

void populateSantaList(person list[], std::string inputFile, std::string surname, int& iterator);

int main()
{
	// initialize random number generator
	srand(time(NULL));

	
	// variables
	person santaList[80];
	
	int count = 0;
	
	bool successfulRandomize = false;

	
	int i=0;

	populateSantaList(santaList, "albers.txt", "Albers", i);
	populateSantaList(santaList, "lansang.txt", "Lansang", i);
	populateSantaList(santaList, "fremont.txt", "Fremont", i);
	populateSantaList(santaList, "dipierro.txt", "DiPierro", i);
	populateSantaList(santaList, "novato.txt", "Novato", i);
	populateSantaList(santaList, "pacifica.txt", "Pacifica", i);

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
		while(!list[i].isSanta)
		{
			if(!matchSanta(list[randInt], list[i]))
			{
				randInt = rand() % memberCount;

			}
			else
			{
				output << list[i].firstName << " has " << list[randInt].firstName << std::endl;
				list[i].isSanta = true;
			}
		}
		// if the member with that id is of the same family or already selected, try again
		
	}
		
	
	return false;
}

bool matchSanta(person &lhs, person rhs)
{
	if(lhs.lastName != rhs.lastName && lhs.hasSanta == false)
	{
		lhs.hasSanta = true;
		return true;
	}
	
	return false;
}

void populateSantaList(person list[], std::string inputFile, std::string surname, int& iterator)
{
	std::fstream famFile(inputFile);
	std::string tempName;
	while(std::getline(famFile, tempName))
	{
		list[iterator].firstName = tempName;
		list[iterator].lastName = surname;

		iterator++;
	}
}
