// Nathan Olah 
// Student Number: 124723198
// September 11, 2019

#ifndef SDDS_TOOLS_H__
#define SDDS_TOOLS_H__

namespace sdds
{
   // displays the user interface menu
   int menu(int noOfSamples);
   // moves the cursor backwards
   void goBack(int n);
   // Draws a line and adds a label if provided
   void line(int n, const char* label = nullptr);
   // Performs a fool-proof integer entry
   int getInt(int min, int max);
}

#endif