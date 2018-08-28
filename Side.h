#ifndef _SIDE_H_
#define _SIDE_H_
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
class Side {
public:
	/*
	*the contructor
	*/
	Side();
	Side(int colorNumber);
	/*
	* Getters & Setters
	*/
	std::string getSideColor(int  row, int col)const  ;
	void setSideColor(int row, int col, std::string color);
	std::string getColor(int index)const ;
	std::vector<std::vector<std::string>> getSide2D() const;

	std::string colors[6] = { "white","green","red","blue","orange", "yellow" };

protected:

    std::vector<std::vector<std::string>> side2D;


};
/*
* input & output operators
*/
std::ostream &operator<<(std::ostream &fout, Side &mySide); //operator to send object to std::ostream cout << PPMIns;
std::istream &operator>>(std::istream &fin, Side &mySide); // operator to retrieve object from std::istream
#endif /* SIDE_H_ */
