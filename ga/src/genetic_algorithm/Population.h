#ifndef POPULATION_H
#define POPULATION_H

#include "../path/Path.h"
#include <algorithm> 
#include<vector>
using namespace std;
/**
* @class Population
* @brief A class that represents population (set of candidate solutions or paths) for the genetic algorithm
*/
class Population{

public:
	//constructor and destructor
	/**
	* @brief Constructor
	*/
	Population (void);
	/**
	* @brief Destructor
	*/
	~Population (void);
	/**
	* @brief it used to set [population] 
	* @param populationPaths population 
	*/
	void setPopulation(vector <Path*> populationPaths);
	/**
	* @brief it used to set population size [populationSize]
	* @param popSize population size
	*/
	void setPopulationSize(uint popSize);
	/**
	* @brief it used to get population
	* @return population
	*/
	vector <Path*> getPopulation();
	/**
	* @brief it used to get population size
	* @return populationSize
	*/
	uint getPopulationSize();
	/**
	* @brief it used to replace a path in the population
	* @param pathIndex The index of the path in current population
	* @param path The new path 
	*/
	void setPath(int pathIndex, Path* path);
	/**
	* @brief it used to get a path from the population
	* @param pathIndex The index of the path
	* @return A path
	*/
	Path* getPath(int pathIndex);
	/**
	* @brief it used to insert new path at the end of the population
	* @param path The path that will be inserted
	*/
	void insertPath(Path* path);
	/**
	* @brief it used to print all the paths in the population
	*/
	void printPopulation();

private:
	vector <Path*> population; //!< Contains a set of paths
	uint populationSize; //!< The number of paths in one population
};

#endif
