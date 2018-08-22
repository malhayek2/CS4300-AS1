#ifndef _SIDE_H_
#define _SIDE_H_
#include <iostream>
#include "Color.cpp"
#include <string>
#include <fstream>

class Side {
public:
	/*
	*the contructor
	*/
	Side();
	Side(Color color);
	/*
	* Getters & Setters
	*/
	std::string getValue(const int& row, const int& col);
	void setValue(const int& row, const int& col);
	Side getSide();	

};

private:

	std::string value[5][5];

};
/*
* input & output operators
*/
std::ostream &operator<<(std::ostream &fout, Side &mySide); //operator to send object to std::ostream cout << PPMIns;
std::istream &operator>>(std::istream &fin, Side &mySide); // operator to retrieve object from std::istream
// bool operator==(const RubiksCube& rhs) const;
// bool operator<(const RubiksCube& rhs) const;
#endif /* SIDE_H_ */