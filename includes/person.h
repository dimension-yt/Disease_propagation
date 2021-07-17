#ifndef PERSON_H
#define PERSON_H
#include <SFML/Graphics.hpp>

#define HEALTHY_COLOR		sf::Color(10, 255, 50)	// Couleur des gens en bonne santé
#define VACCINATED_COLOR	sf::Color(10, 50, 255)	// Couleur des gens vaccinés
#define SICK_COLOR			sf::Color(255, 50, 50)	// Couleur des gens malades
#define DEAD_COLOR			sf::Color(0, 0, 0)		// Couleur des gens morts



// Enum définissant l'état de santé d'une personne

enum Health { vaccinated, healthy, sick, dead };



// Classe définissant une personne

class Person
{

public:

	Health	health;			// Etat de santé
	bool	resistant;		// Résistant à la maladie (ne meurt pas)
	bool	new_sick;		// Malade depuis une seule itération
	int		nb_sick_days;	// Nombre de jours depuis la contamination

	Person();
	Person(const Person& person);
	Person(const double& vaccinated_percentage, const double& death_rate);

	void operator=(const Person& person);
};

bool rand_probability(const double& probability);

#endif