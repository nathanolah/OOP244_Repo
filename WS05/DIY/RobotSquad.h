// RobotSquad.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 9, 2019 

#ifndef SDDS_ROBOTSQUAD_H__ // Safe guard for header file
#define SDDS_ROBOTSQUAD_H__
#include "Robot.h" // Used for Robot class 
namespace sdds
{  
   const int NAME_MAX_LEN = 10; 

   class RobotSquad { 
      char name[NAME_MAX_LEN + 1];
      int numOfRobots;
      Robot* robots;
   public:
      // Constructors/Destructor 
      RobotSquad(const char* newName = "No Name"); 
      ~RobotSquad();
      // Member functions
      const char* getName()const;
      int getNumOfRobots()const;
      Robot* getRoster()const;
      std::ostream& display()const;
      // Member operator functions 
      RobotSquad& operator+=(const Robot& src);
      operator bool()const;
      RobotSquad& operator --();
   };
}
#endif // !SDDS_ROBOTSQUAD_H__

