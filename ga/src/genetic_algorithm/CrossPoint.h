#ifndef CROSSPOINT_H
#define CROSSPOINT_H


#include "../path/Path.h"
#include <algorithm> 
#include<vector>
using namespace std;
/**
* @class CrossPoint
* @brief A class that represents a common cell between two paths. To be used with crossover operator in the genetic algorithm
*/
class CrossPoint{

public:
	//constructor and destructor
	/**
	* @brief Constructor
	*/
	CrossPoint (void);
	/**
	* @brief Constructor
	* @param ID
	* @param CellIndex1 The index of the common cell in the first path
	* @param CellIndex2 The index of the common cell in the second path
	*/
	CrossPoint (int ID, int CellIndex1, int CellIndex2);
	/**
	* @brief Destructor
	*/
	~CrossPoint (void);

	 //Define Mutators
	void setCellID(int ID);
	void setPath1CellIndex (int CellIndex);
	void setPath2CellIndex (int CellIndex);

	//Define Accessors
	int getCellID();
	int getPath1CellIndex();
	int getPath2CellIndex();

	/**
	* @brief it used to find all the cross (common) points between two paths.
	* @param path1
	* @param path2
	* @return vector of all cross points between the two paths
	*/
	static vector <CrossPoint> findCrossPoints(Path* path1, Path* path2 );
	/**
	* @brief it used to choose randomly two of the cross points to perform the crossover with them
	* @param size Represent the number of the cross points
	* @return Two cross points
	*/
	static vector <int> chooseRandomlyTwoCrossPoints(uint size);
	/**
	* @brief it used to swap between two cross points
	*/
	void swapCrossPoints();

private:
	int cellID;
	int path1CellIndex;
	int path2CellIndex;
};

#endif

