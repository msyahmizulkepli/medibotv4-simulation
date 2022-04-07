#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

/**
* @class Map
* @brief A class that represents a grid environment as a two dimensional matrix 
*/
class Map {
 
public:
  
	/**
	* @brief default constructor to initialize map
	*/
	Map(int w=0, int h=0, float res=0.0);
	/**
	* @brief four-argument constructor o initialize map
	*/
	Map(int w, int h, float res, int** mapMatrix, int obsSize, float obsRatio);
	//constructor that loads a map from a file
	// Map(ifstream mpgMapFile); 
	/**
	* @brief Copy constructor for the map
	*/
	Map (Map* map);
	
	 
	//Define Mutators
	void setWidth(int w);
	void setHeight(int h);
	void setResolution (float res);
	void setMapLayout(int** mapMatrix);
	void setObstacleSize (int obsSize);
	void setObstacleRatio(float obsRatio);  
	
	//Define Accessors
	int getWidth();
	int getHeight();
	float getResolution();
	int** getMapLayout();
	int getObstacleSize();
	float getObstacleRatio();
	
	/**
	* @brief it is used to get the index of the cell to be used in Path.
	* @param i
	* @param j
	* @return cell index
	*/
	int getCellIndex(int i,int j);
	/**
	* @brief get the row ID from cell index
	* @param index
	* @return cell row ID
	*/
	int getCellRowID(int index);
	/**
	* @brief get colunm ID from cell index
	* @param index
	* @return cell col ID
	*/
	int getCellColID(int index);
	
	/**
	* @brief it is used to read the MapLayout from a file
	* @param path_name
	* @param file_name
	*/
	void importMapLayout(string path_name, const char* file_name); 
	/**
	* @brief it is used to write the MapLayout in a file
	* @param file_name
	* @param mapMatrix
	*/
	void exportMapLayout(const char* file_name, int** mapMatrix); 

private:
  int width; //!<  Map width [cells]
  int height;//!<  Map height [cells]
  float resolution; //!< The map resolution [m/cell]
  int** mapLayout; //!<  the map data structure that contains all cells of the environment
  int obstacleSize; //!< The size of the obstacles
  float obstacleRatio; //!< The ratio of obstacles in the map
};

#endif
