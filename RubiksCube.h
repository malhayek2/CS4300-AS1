#ifndef _RUBIKSCUBE_H_
#define _RUBIKSCUBE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Side.h>
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
	Side getSide(int index);
	void setSide(int index, std::istream &fin);
	void rotateCW(int index);
	void rotateCCW(int index);
        int helper_color(std::string colorValue); 

};

private:
    vector<Side> cube;

};
/*
* input & output operators
*/
std::ostream &operator<<(std::ostream &fout, Side &mySide); //operator to send object to std::ostream cout << PPMIns;
std::istream &operator>>(std::istream &fin, Side &mySide); // operator to retrieve object from std::istream
bool operator==(const RubiksCube& rhs) const;
bool operator<(const RubiksCube& rhs) const;
#endif /* RUBIKSCUBE_H_ */