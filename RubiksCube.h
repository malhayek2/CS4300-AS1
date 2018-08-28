#ifndef _RUBIKSCUBE_H_
#define _RUBIKSCUBE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Side.h"
#include <string>
class RubiksCube {
public:
	/*
	*the contructor
	*/
	RubiksCube();
    /*
	* Getters & Setters
	*/

	void setSide(int index, std::istream &fin);
	void setSide(int index, Side side);
	void rotateCW(int index);
	void rotateCCW(int index);
    int helper_color(std::string colorValue);
	bool operator==(const RubiksCube& rhs) ;
	bool operator<(const RubiksCube& rhs) ;
	Side getSide(int index) const;
	std::vector<Side> getCube();

	std::vector<Side> cube;

protected:
    

};
/*
* input & output operators
*/
std::ostream &operator<<(std::ostream &fout, RubiksCube &RubiksCube); //operator to send object to std::ostream cout << ;
std::istream &operator>>(std::istream &fin, RubiksCube &RubiksCube); // operator to retrieve object from std::istream

#endif /* RUBIKSCUBE_H_ */
