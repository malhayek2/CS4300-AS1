#include <cstdlib>
#include <iomanip>
#include "Side.h"

/*
* Empty Contructor. ?
*/
Side::Side() {
    this->side2D.resize (3);
   	for (int i = 0; i < side2D.size (); i++){
   	    this->side2D[i].resize (3);
   	}

}
/*
* this contructor creates a side with one given color.
*/
Side::Side(int colorNumber) {
    // n*m array where n =3 & m =3
   this->side2D.resize (3);
   	for (int i = 0; i < side2D.size (); i++)
    this->side2D[i].resize (3);
    
     for (int i = 0; i < side2D.size (); i++)
    {
      for (int j = 0; j < side2D[i].size (); j++)
	{
		this->side2D[i][j] = getColor(colorNumber);
	}
    }    
      
}
/*
* returns a color 1-white, 2-green 3-red, 4-blue, 5-orange 6-yellow
* based on the sides given in this order
*/
std::string Side::getColor(int index)const{
    return colors[index];
}
std::vector<std::vector<std::string>> Side::getSide2D() const
{
	return this->side2D;
}
/*
*	std::string getSideColor(const int& row, const int& col);
	void setSideColor(const int& row, const int& col);
	Side getSide();
*/

std::string Side::getSideColor(int row,int col)const{

    return this->side2D[row][col];
}
void Side::setSideColor(int row, int col, std::string color){

    this->side2D[row][col] = color;

     
}

/*
*overloading operator, maybe user ur setters?
*/

std::istream &operator>>(std::istream &fin, Side &mySide){
	std::string newValue;
    for (int i = 0; i < 3; i++){
         for (int j = 0; j < 3; j++){
			 fin >> newValue;
			 mySide.setSideColor(i,j, newValue);
			// std::cout << mySide.getSideColor(i, j) << std::endl;
         }
    }
    return fin;     
}
std::ostream &operator<<(std::ostream &fout, Side &mySide){
    for (int i = 0; i < 3; i++){
         for (int j = 0; j < 3; j++){
            fout << mySide.getSideColor(i,j) + " ";
         }
    }
    return fout; 
}
