

#include "PPM.h"
#include <cstdlib>
#include <iomanip>
#include "Color.cpp"
/*
* Empty Contructor. 
*/
Side::Side() {
   side2D.resize (n);
   	for (int i = 0; i < side2D.size (); i++)
    side2D[i].resize (n);

}
/*
* this contructor creates a side with one given color.
*/
Side::Side(Color color) {
   side2D.resize (n);
   	for (int i = 0; i < side2D.size (); i++)
    side2D[i].resize (n);
     for (int i = 0; i < side2D.size (); i++)
    {
      for (int j = 0; j < side2D[i].size (); j++)
	{
		side2D[i][j] = 
	}
    }    
      
}

