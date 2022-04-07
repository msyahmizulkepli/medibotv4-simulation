#ifndef OCCUPANCYGRIDMAP_H
#define OCCUPANCYGRIDMAP_H

#include"Map.h"
#include<limits.h>

/**
* @class OccupancyGridMap
* @brief A class that represents an occupancy grid map 
*/
class OccupancyGridMap : public Map {
 
public:
  //define constants
  static const int FREE     = 0;  //!< for free cell
  static const int OBSTACLE = 100; //!< for obstacles
  static const int UNKNOWN  = -1; //!< for unknown cell
  
  static constexpr float MOVE_COST = 1.0; //!< horizental or vertical move
  static constexpr float DIAGONAL_MOVE_COST = 1.4; //!< Diagonal move
  
   static constexpr float INFINIT_COST = INT_MAX; //!< cost of non connected nodes

   /**
   * @brief default constructor to initialize map
   */
  OccupancyGridMap(int w=0, int h=0, float res=0.0);
  /**
  * @brief four-argument constructor to initialize map
  */
  OccupancyGridMap(int w, int h, float res, int** mapMatrix, int obsSize, float obsRatio);
  /**
  * @brief constructor that loads a map from a file
  */
  OccupancyGridMap(ifstream mpgMapFile); 
  /**
  * @brief Copy constructor for the OccupancyGridMapGridMap
  */
  OccupancyGridMap (OccupancyGridMap* map);
  
  void setObstacle (int i, int j);
  void setFree (int i, int j);
  void setUnknown (int i, int j);
  void setCell (int i, int j, int occupancy); //give the cell(i,j) the value of occupancy 

  /**
  * @brief it is used to get the move cost between 2 cells
  * @param i1
  * @param j1
  * @param i2
  * @param j2
  * @return move cost
  */
  float getMoveCost(int i1, int j1, int i2, int j2);
  /**
  * @brief it is used to get the move cost between 2 cells
  * @param CellID1
  * @param CellID2
  * @return move cost 
  */
  float getMoveCost(int CellID1, int CellID2);

  /**
  * @brief it is used to check if the cell is an obstacle cell
  * @param i
  * @param j
  * @return true if the cell is an Obstacle
  */
  bool isObstacle(int i, int j); 
  /**
  * @brief it is used to check if the cell is a free cell
  * @param i
  * @param j
  * @return true if the cell is Free
  */
  bool isFree(int i, int j); 
  /**
  * @brief it is used to check if the cell is unknown cell
  * @param i
  * @param j 
  * @return true if the cell is Unknown
  */
  bool isUnknown(int i, int j); 
  
  /**
  * @brief it is used to check if the cell is a free cell
  * @param CellID
  * @return true if the cell is Free
  */
  bool isFree(int CellID); //returns true if the cell is Free
  /**
  * @brief it is used to check if the cell is an obstacle cell
  * @param CellID
  * @return true if the cell is an Obstacle
  */
  bool isObstacle(int CellID); //return true if the cell is an Obstacle
  /**
  * @brief it is used to check if the cell is unknown cell
  * @param CellID
  * @return true if the cell is Unknown
  */
  bool isUnknown(int CellID); //returns true if the cell is Unknown
  
  /*override the method defined in Map.h by adding ratio of obstacle*/
  /**
  * @brief it is used to write the MapLayout in a file; override the method defined in Map.h by adding ratio of obstacle
  * @param file_name
  * @param mapMatrix 
  */
  void exportMapLayout(const char* file_name, int** mapMatrix); 

};

#endif
