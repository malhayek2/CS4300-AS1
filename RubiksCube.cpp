#include "Side.h"
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "RubiksCube.h"


/*
 *contructor
 */
RubiksCube::RubiksCube() {
    /*
     * a cube consists of 6 sides (w,g,r,b,o,y)
     * perfect/sloved state init
     */
	Side *s1 = new Side(0);
	Side *s2 = new Side(1);
	Side *s3 = new Side(2);
	Side *s4 = new Side(3);
	Side *s5 = new Side(4);
	Side *s6 = new Side(5);
    this->cube.resize(7);
	this->cube[5] =(*s6);
	this->cube[4]=(*s5);
	this->cube[3]=(*s4);
	this->cube[2]=(*s3);
	this->cube[1]=(*s2);
	this->cube[0]=(*s1);


}

Side RubiksCube::getSide(int index) const {
    return this->cube[index];
}

std::vector<Side> RubiksCube::getCube()
{
	return this->cube;
}

void RubiksCube::setSide(int index, std::istream &fin) {
    fin >> this->cube[index];

}

void RubiksCube::setSide(int index, Side side)
{
	this->cube[index] = side;
}

void RubiksCube::rotateCW(int index) {
	std::vector<std::string> side1;
	side1.resize(3);
    std::vector<std::string> side2;
	side2.resize(3);
	std::vector<std::string> side3;
	side3.resize(3);
	std::vector<std::string> side4;
	side4.resize(3);
    if (index == 1) {
        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(4).getSideColor(0, i );
            side2[i] = this->getSide(3).getSideColor(0, i );
            side3[i] = this->getSide(2).getSideColor(0, i );
            side4[i] = this->getSide(1).getSideColor(0, i );
			Side newSide1 = this->getSide(4);
			Side newSide2 = this->getSide(3);
			Side newSide3 = this->getSide(2);
			Side newSide4 = this->getSide(1);
			newSide1.setSideColor(0, i, side4[i]);
			newSide2.setSideColor(0, i, side1[i]);
			newSide3.setSideColor(0, i, side2[i]);
			newSide4.setSideColor(0, i, side3[i]);

			this->setSide(4, newSide1);
			this->setSide(3, newSide2);
			this->setSide(2, newSide3);
			this->setSide(1, newSide4);

        }

    } else if (index == 2) {


        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(0).getSideColor(i , 0);
            side2[i] = this->getSide(2).getSideColor(i , 0);
            side3[i] = this->getSide(5).getSideColor(i , 0);
            side4[i] = this->getSide(4).getSideColor(i , 2);
			Side newSide1 = this->getSide(0);
			Side newSide2 = this->getSide(2);
			Side newSide3 = this->getSide(5);
			Side newSide4 = this->getSide(4);
			newSide1.setSideColor(i, 0, side4[i]);
			newSide2.setSideColor(i, 0, side1[i]);
			newSide3.setSideColor(i, 0, side2[i]);
			newSide4.setSideColor(i, 2, side3[i]);

			this->setSide(0, newSide1);
			this->setSide(2, newSide2);
			this->setSide(5, newSide3);
			this->setSide(4, newSide4);

        }
    } else if (index == 3) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(0).getSideColor(2,i);
            side2[i] = this->getSide(3).getSideColor(i , 0);
            side3[i] = this->getSide(5).getSideColor(0, i );
            side4[i] = this->getSide(1).getSideColor(i , 2);
			Side newSide1 = this->getSide(0);
			Side newSide2 = this->getSide(3);
			Side newSide3 = this->getSide(5);
			Side newSide4 = this->getSide(1);
			newSide1.setSideColor(2, i, side4[i]);
			newSide2.setSideColor(i, 0, side1[i]);
			newSide3.setSideColor(0, i, side2[i]);
			newSide4.setSideColor(i, 2, side3[i]);

			this->setSide(0, newSide1);
			this->setSide(3, newSide2);
			this->setSide(5, newSide3);
			this->setSide(1, newSide4);
			
        }

    } else if (index == 4) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(2).getSideColor(i , 2);
            side2[i] = this->getSide(0).getSideColor(i , 2);
            side3[i] = this->getSide(4).getSideColor(i , 0);
            side4[i] = this->getSide(5).getSideColor(i , 2);

			Side newSide1 = this->getSide(2);
			Side newSide2 = this->getSide(0);
			Side newSide3 = this->getSide(4);
			Side newSide4 = this->getSide(5);
			newSide1.setSideColor(i, 2, side4[i]);
			newSide2.setSideColor(i, 2, side1[i]);
			newSide3.setSideColor(i, 0, side2[i]);
			newSide4.setSideColor(i, 2, side3[i]);

			this->setSide(2, newSide1);
			this->setSide(0, newSide2);
			this->setSide(4, newSide3);
			this->setSide(5, newSide4);

        }
    } else if (index == 5) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(3).getSideColor(i , 2);
            side2[i] = this->getSide(0).getSideColor(0,  i);
            side3[i] = this->getSide(1).getSideColor( i, 0);
            side4[i] = this->getSide(5).getSideColor(2, i);
			Side newSide1 = this->getSide(3);
			Side newSide2 = this->getSide(0);
			Side newSide3 = this->getSide(1);
			Side newSide4 = this->getSide(5);
			newSide1.setSideColor(i, 2, side4[i]);
			newSide2.setSideColor(0, i, side1[i]);
			newSide3.setSideColor(i, 0, side2[i]);
			newSide4.setSideColor(2, i, side3[i]);

			this->setSide(3, newSide1);
			this->setSide(0, newSide2);
			this->setSide(1, newSide3);
			this->setSide(5, newSide4);

        }
    } else if (index == 6) {
        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(3).getSideColor(2, i);
            side2[i] = this->getSide(4).getSideColor(2, i);
            side3[i] = this->getSide(1).getSideColor(2, i);
            side4[i] = this->getSide(2).getSideColor(2, i);
			Side newSide1 = this->getSide(3);
			Side newSide2 = this->getSide(4);
			Side newSide3 = this->getSide(1);
			Side newSide4 = this->getSide(2);
			newSide1.setSideColor(2, i, side4[i]);
			newSide2.setSideColor(2, i, side1[i]);
			newSide3.setSideColor(2, i, side2[i]);
			newSide4.setSideColor(2, i, side3[i]);

			this->setSide(3, newSide1);
			this->setSide(4, newSide2);
			this->setSide(1, newSide3);
			this->setSide(2, newSide4);

        }
    }
}

void RubiksCube::rotateCCW(int index) {
    this->rotateCW(index);
	this->rotateCW(index);
	this->rotateCW(index);

}

//std::ostream &operator<<(std::ostream &fout, Side &mySide); //operator to send object to std::ostream cout << PPMIns;
//std::istream &operator>>(std::istream &fin, Side &mySide); // operator to retrieve object from std::istream
//bool operator==(const RubiksCube& rhs) const;
//bool operator<(const RubiksCube& rhs) const;

std::istream &operator>>(std::istream &fin, RubiksCube &myRubiksCube) {
	Side s1;
	Side s2;
	Side s3;
	Side s4;
	Side s5;
	Side s6;
	fin >> s1;
	fin >> s2;
	fin >> s3;
	fin >> s4;
	fin >> s5;
	fin >> s6;
	myRubiksCube.setSide(0, s1);
	myRubiksCube.setSide(1, s2);
	myRubiksCube.setSide(2, s3);
	myRubiksCube.setSide(3, s4);
	myRubiksCube.setSide(4, s5);
	myRubiksCube.setSide(5, s6);    
	return fin;
}

std::ostream &operator<<(std::ostream &fout, RubiksCube &myRubiksCube) {
    for (int k = 0; k < 6; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				fout << myRubiksCube.getSide(k).getSideColor(i, j) + " ";
			}
			fout << std::endl;
		}
		fout << std::endl;
    }
    return fout;
}

bool RubiksCube::operator==(const RubiksCube & rhs){
    for (int i = 0; i < 7; i++) {
        for (int l = 0; l < 3; l++) {
            for (int k = 0; k < 3; k++) {
				//std::cout << "left Side " << this->getSide(i).getSideColor(l, k) << " Right Side " << rhs.getSide(i).getSideColor(l, k) << std::endl;
                if (!(this->getSide(i).getSideColor(l, k) == rhs.getSide(i).getSideColor(l, k))) {
                    return false;
                }
            }
        }

    }
    return true;
}
int RubiksCube::helper_color(std::string colorValue){
    if(colorValue == "white"){
     return 1;   
    }else if (colorValue == "green"){
        return 2;
    }else if (colorValue == "red"){
        return 3;
    }else if (colorValue == "blue"){
        return 4;
    }else if (colorValue == "orange"){
        return 5;
    }else if (colorValue == "yellow"){
        return 6;
    }
    return 0;
}
bool RubiksCube::operator<(const RubiksCube& rhs) {
    int thisCubeVar = 0;
    int rhsCubeVar = 0;
    for (int l = 0; l < 3; l++) {
        for (int k = 0; k < 3; k++) {
            if(this->getSide(1).getSideColor(l, k) != "white"){
                thisCubeVar += helper_color(this->getSide(1).getSideColor(l, k));
            } 
            if(this->getSide(2).getSideColor(l, k) != "green"){
                thisCubeVar += helper_color(this->getSide(2).getSideColor(l, k));
            }
            if(this->getSide(3).getSideColor(l, k) != "red"){
                thisCubeVar += helper_color(this->getSide(3).getSideColor(l, k));
            }
            if(this->getSide(4).getSideColor(l, k) != "blue"){
                thisCubeVar += helper_color(this->getSide(4).getSideColor(l, k));
            }
            if(this->getSide(5).getSideColor(l, k) != "orange"){
                thisCubeVar += helper_color(this->getSide(5).getSideColor(l, k));
            }
            if(this->getSide(6).getSideColor(l, k) != "yellow"){
                thisCubeVar += helper_color(this->getSide(6).getSideColor(l, k));
            }
            if(rhs.getSide(1).getSideColor(l, k) != "white"){
                thisCubeVar += helper_color(rhs.getSide(1).getSideColor(l, k));
            } 
            if(rhs.getSide(2).getSideColor(l, k) != "green"){
                thisCubeVar += helper_color(rhs.getSide(2).getSideColor(l, k));
            }
            if(rhs.getSide(3).getSideColor(l, k) != "red"){
                thisCubeVar += helper_color(rhs.getSide(3).getSideColor(l, k));
            }
            if(rhs.getSide(4).getSideColor(l, k) != "blue"){
                thisCubeVar += helper_color(rhs.getSide(4).getSideColor(l, k));
            }
            if(rhs.getSide(5).getSideColor(l, k) != "orange"){
                thisCubeVar += helper_color(rhs.getSide(5).getSideColor(l, k));
            }
            if(rhs.getSide(6).getSideColor(l, k) != "yellow"){
                thisCubeVar += helper_color(rhs.getSide(6).getSideColor(l, k));
            }
        }
    }
    return thisCubeVar < rhsCubeVar;
}
