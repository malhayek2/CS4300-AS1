#include <cstdlib>
#include <iomanip>
#include <vector>
#include "RubiksCube.h"
#include "Side.h"

/*
 *contructor
 */
RubiksCube::RubiksCube() {
    /*
     * a cube consists of 6 sides (w,g,r,b,o,y)
     * perfect/sloved state init
     */
    this->cube.resize(6);
    this->cube[1] = new Side(1);
    this->cube[2] = new Side(2);
    this->cube[3] = new Side(3);
    this->cube[4] = new Side(4);
    this->cube[5] = new Side(5);
    this->cube[6] = new Side(6);

}

Side RubiksCube::getSide(int index) {
    return this->cube[index];
}

void RubiksCube::setSide(int index, std::istream &fin) {
    fin >> this->cube[index];

}

void RubiksCube::rotateCW(int index) {
    vector<std::string> side1;
    vector<std::string> side2;
    vector<std::string> side3;
    vector<std::string> side4;

    if (index == 1) {
        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(5).getSideColor(1, i + 1);
            side2[i] = this->getSide(4).getSideColor(1, i + 1);
            side3[i] = this->getSide(3).getSideColor(1, i + 1);
            side4[i] = this->getSide(2).getSideColor(1, i + 1);
            this->getSide(5).setSideColor(1, i + 1, side4[i]);
            this->getSide(4).setSideColor(1, i + 1, side1[i]);
            this->getSide(3).setSideColor(1, i + 1, side2[i]);
            this->getSide(2).setSideColor(1, i + 1, side3[i]);
        }

    } else if (index == 2) {


        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(1).getSideColor(i + 1, 1);
            side2[i] = this->getSide(3).getSideColor(i + 1, 1);
            side3[i] = this->getSide(6).getSideColor(i + 1, 1);
            side4[i] = this->getSide(5).getSideColor(i + 1, 3);


            this->getSide(1).setSideColor(i + 1, 1, side4[i]);
            this->getSide(3).setSideColor(i + 1, 1, side1[i]);
            this->getSide(6).setSideColor(i + 1, 1, side2[i]);
            this->getSide(5).setSideColor(i + 1, 3, side3[i]);
        }
    } else if (index == 3) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(1).getSideColor(3, i + 1);
            side2[i] = this->getSide(4).getSideColor(i + 1, 1);
            side3[i] = this->getSide(6).getSideColor(1, i + 1);
            side4[i] = this->getSide(2).getSideColor(i + 1, 3);
            this->getSide(1).setSideColor(3, i + 1, side4[i]);
            this->getSide(4).setSideColor(i + 1, 1, side1[i]);
            this->getSide(6).setSideColor(1, i + 1, side2[i]);
            this->getSide(2).setSideColor(i + 1, 3, side3[i]);
        }

    } else if (index == 4) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(3).getSideColor(i + 1, 3);
            side2[i] = this->getSide(1).getSideColor(i + 1, 3);
            side3[i] = this->getSide(5).getSideColor(i + 1, 1);
            side4[i] = this->getSide(6).getSideColor(i + 1, 3);
            this->getSide(3).setSideColor(i + 1, 3, side4[i]);
            this->getSide(1).setSideColor(i + 1, 3, side1[i]);
            this->getSide(5).setSideColor(i + 1, 1, side2[i]);
            this->getSide(6).setSideColor(i + 1, 3, side3[i]);
        }
    } else if (index == 5) {

        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(4).getSideColor(i + 1, 3);
            side2[i] = this->getSide(1).getSideColor(1, 1 + i);
            side3[i] = this->getSide(2).getSideColor(1 + i, 1);
            side4[i] = this->getSide(6).getSideColor(3, 1 + i);
            this->getSide(4).setSideColor(i + 1, 3, side4[i]);
            this->getSide(1).setSideColor(1, 1 + i, side1[i]);
            this->getSide(2).setSideColor(1 + i, 1, side2[i]);
            this->getSide(6).setSideColor(3, 1 + i, side3[i]);
        }
    } else if (index == 6) {
        for (int i = 0; i < 3; i++) {
            side1[i] = this->getSide(4).getSideColor(3, 1 + i);
            side2[i] = this->getSide(5).getSideColor(3, 1 + i);
            side3[i] = this->getSide(2).getSideColor(3, 1 + i);
            side4[i] = this->getSide(3).getSideColor(3, 1 + i);
            this->getSide(4).setSideColor(3, 1 + i, side4[i]);
            this->getSide(5).setSideColor(3, 1 + i, side1[i]);
            this->getSide(2).setSideColor(3, 1 + i, side2[i]);
            this->getSide(3).setSideColor(3, 1 + i, side3[i]);
        }
    }
}

void RubiksCube::rotateCCW(int index) {
    rotateCW(index);
    rotateCW(index);
    rotateCW(index);

}
//std::ostream &operator<<(std::ostream &fout, Side &mySide); //operator to send object to std::ostream cout << PPMIns;
//std::istream &operator>>(std::istream &fin, Side &mySide); // operator to retrieve object from std::istream
//bool operator==(const RubiksCube& rhs) const;
//bool operator<(const RubiksCube& rhs) const;

std::ostream &operator>>(std::istream &fin, RubiksCube &myRubiksCube) {
    for (int i = 1; i <= 7; i++) {
        fin >> myRubiksCube.cube[i];
    }
    return fin;
}

std::ostream &operator<<(std::ostream &fout, RubiksCube &myRubiksCube) {
    for (int i = 1; i <= 7; i++) {
        fout << myRubiksCube.cube[i];
    }
    return fout;
}

bool RubiksCube::operator==(const RubiksCube& rhs) const {
    for (int i = 1; i <= 7; i++) {
        for (int l = 0; l < 3; l++) {
            for (int k = 0; k < 3; k++) {
                if (!(this->getSide(i).getSideColor(l, k) == rhs.getSide(i).getSideColor(l, k))) {
                    return false;
                }
            }
        }

    }
    return true;
}
int helper_color(std::string colorValue){
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
bool RubiksCube::operator<(const RubiksCube& rhs) const {
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