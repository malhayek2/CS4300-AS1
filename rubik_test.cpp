#include "RubiksCube.h"
#include <fstream>
#include "Side.h"
#include <string>
RubiksCube myCube;
void menu() {
    std::string choice;
    while (std::cin >> choice) {
        if (choice == "initial") {
			std::cin >> myCube;
            
        }  if (choice == "show") {
			std::cout << myCube;

        }  if (choice == "isequal") {
            RubiksCube compare;
          std::cin >> compare;
		  if (compare == myCube) {
			  std::cout << "TRUE" << std::endl;
		  }
		  else {
			  std::cout << "FALSE" << std::endl;
		  }
        }  if (choice == "rotate") {
            std::string side;
            int sideIndex;
            std::string command; 
            std::cin >> side;
            sideIndex = myCube.helper_color(side);
            std::cin >> command;
            if(command == "cw"){
                myCube.rotateCW(sideIndex);
            }else if (command == "ccw"){
                 myCube.rotateCCW(sideIndex);
            }
		} if (choice == "less") {
			RubiksCube compare;
			std::cin >> compare;
			if (compare < myCube) {
				std::cout << "TRUE" << std::endl;
			}
			else {
				std::cout << "FALSE" << std::endl;
			}
		}
    }
}

int main() {
    menu();
    return 0;
}
