#include <cstdlib>
#include <iomanip>
/*
*contructor
*/
RubiksCube::RubiksCube(){
    /*
    * a cube consists of 6 sides (w,g,r,b,o,y)
    * perfect/sloved state init
    */
    this.cube.resize (6);
    this.cube[1] = new Side(1); 
    this.cube[2] = new Side(2);
    this.cube[3] = new Side(3);
    this.cube[4] = new Side(4);
    this.cube[5] = new Side(5);
    this.cube[6] = new Side(6);
    
}


Side RubiksCube::getSide(int index){
    return this.cube[index];	    
}

void RubiksCube::setSide(int index, std::istream &fin){
    fin >> this.cube[index];
	    
}
void RubiksCube::rotateCW(int index){
    
}
	void rotateCCW(int index);