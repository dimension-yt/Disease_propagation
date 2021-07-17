#include "person.h"
#include <random>



// Contruit une personnne

Person::Person()
{
	health = healthy;
	resistant = false;
	new_sick = false;
	nb_sick_days = 0;
}



// Construit une personne à partir d'une autre personne

Person::Person(const Person& person)
{
	health = person.health;
	resistant = person.resistant;
	new_sick = person.new_sick;
	nb_sick_days = person.nb_sick_days;
}



// Construit une personne à partir de ces paramètres

Person::Person(const double& vaccinated_percentage, const double& death_rate)
{
	health = healthy;

	if (rand_probability(vaccinated_percentage))
		health = vaccinated;

	resistant = rand_probability(1. - death_rate);
	new_sick = false;
	nb_sick_days = 0;
}



// Assignation

void Person::operator=(const Person& person)
{
	health = person.health;
	resistant = person.resistant;
	new_sick = person.new_sick;
	nb_sick_days = person.nb_sick_days;
}



// Donne "vrai" avec une probabilité choisie

bool rand_probability(const double& probability)
{
	if (probability < 1.)
		return ((double)rand() / (double)RAND_MAX < probability);

	return true;
}