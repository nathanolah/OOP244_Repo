// Robot.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 8, 2019 

#ifndef SDDS_ROBOT_H__ // Safeguard for header file 
#define SDDS_ROBOT_H__
#include "Parts.h" // Include Arms class for m_arms object
namespace sdds
{
   const int NICK_MAX_LEN = 10;

   class Robot {
      char m_nickname[NICK_MAX_LEN + 1]; // Plus one for null terminator
      int m_durability;
      Arms* m_arms;
   public:
      // Constructors/Destructor
      Robot();
      Robot(const char* nickname, int force, int durability);
      ~Robot();
      // Function prototype
      std::ostream& display()const;
      // Member operator prototype 
      operator bool()const;
   };
}
#endif // !SDDS_ROBOT_H__
