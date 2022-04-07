#include "Population.h"

Population::Population(void) {
}

Population::~Population(void) {
}

void Population::setPopulation(vector <Path*> populationPaths){

	  for(uint i=0; i<populationPaths.size(); i++){
		  population.push_back(populationPaths[i]);
	  }
}

void Population::setPopulationSize(uint popSize){
	populationSize = popSize;
}


vector <Path*> Population::getPopulation(){
	return population;
}

uint Population::getPopulationSize(){
	return populationSize;
}

void Population::setPath(int pathIndex, Path* path){
	population[pathIndex]=path;
}

Path* Population::getPath(int pathIndex){
	Path* path = new Path();
	path->setPath(population[pathIndex]->getPath());
	return path;
}

void Population::insertPath( Path* path){
		  population.push_back(path);
}

void Population::printPopulation(){

    for (unsigned int j=0; j < population.size();j++){
    	cout<<endl<<endl;
    	cout<<population[j]->getName()<<" : ";
    	for(unsigned int i=0; i<population[j]->getPath().size();i++)
    		cout<<population[j]->getPath()[i]<<" ";
    	cout<<endl<<endl;
    }
}
