#include "CrossPoint.h"


using namespace std;

//constructor and destructor
CrossPoint::CrossPoint(void){

}

CrossPoint::CrossPoint (int ID, int CellIndex1, int CellIndex2){
	setCellID(ID);
	setPath1CellIndex(CellIndex1);
	setPath2CellIndex(CellIndex2);
}

CrossPoint::~CrossPoint(void){

}

//Define Mutators
void CrossPoint::setCellID(int ID){
	cellID=ID;
}
void CrossPoint::setPath1CellIndex (int CellIndex){
	path1CellIndex=CellIndex;
}
void CrossPoint::setPath2CellIndex (int CellIndex){
	path2CellIndex=CellIndex;
}

//Define Accessors
int CrossPoint::getCellID(){
	return cellID;
}
int CrossPoint::getPath1CellIndex(){
	return path1CellIndex;
}
int CrossPoint::getPath2CellIndex(){
	return path2CellIndex;
}

vector <CrossPoint> CrossPoint::findCrossPoints(Path* path1, Path* path2 ){

	vector <CrossPoint> crossoverPoints;
	CrossPoint crossoverPoint;

	int id=0;

	unsigned int c; //counter, will contain the index foe common cell in path2
	for (unsigned int i = 1; i < path1->getPath().size() -1; i++) {
		c = 1;
		while (c < path2->getPath().size() -1 && path1->getPath()[i] != path2->getPath()[c]) {
			c++;
		}
		if (c != path2->getPath().size() - 1) {
			crossoverPoint.cellID=id;
			crossoverPoint.path1CellIndex = i;
			crossoverPoint.path2CellIndex = c;
			id++;

			crossoverPoints.push_back(crossoverPoint);
		}
	}
	return crossoverPoints;
}

/****************************************************/
// Function: chooseRandomlyTwoCrossPoints
// Input: size of crossoverPoints vector
// Output: return randomly two cross points
/****************************************************/
vector <int> CrossPoint::chooseRandomlyTwoCrossPoints(uint size){

	vector <int> randomPoints;
	int randomCrossPoint1;
	int randomCrossPoint2;

	do{
	randomCrossPoint1 = rand() % size;
	randomCrossPoint2 = rand() % size;
	} while (randomCrossPoint1 == randomCrossPoint2);

	if (randomCrossPoint1>randomCrossPoint2){
		int temp=randomCrossPoint1;
		randomCrossPoint1=randomCrossPoint2;
		randomCrossPoint2=temp;
		}

	randomPoints.push_back(randomCrossPoint1);
	randomPoints.push_back(randomCrossPoint2);

	return randomPoints;
}

void CrossPoint::swapCrossPoints(){

	int temp = getPath1CellIndex();
	setPath1CellIndex(getPath2CellIndex());
	setPath2CellIndex(temp);
}


