// Robot.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 9, 2019 

#ifndef SDDS_ROBOT_H__ // Safeguard for header file 
#define SDDS_ROBOT_H__
#include "Parts.h" // Include Arms class for m_arms object
namespace sdds
{
   const int NICK_MAX_LEN = 10;

   class Robot {
      char nickname[NICK_MAX_LEN + 1]; // Plus one for null terminator
      int durability;
      Arms* arms;
      Legs* legs;
   public:
      // Constructors/Destructor
      Robot();
      Robot(const char* tempNickname, int armForce, int legSpeed, int tempDurability);
      ~Robot();
      // Function prototype
      std::ostream& display()const;
      Arms getArms()const;
      Legs getLegs()const;
      // Member operator prototype 
      operator bool()const;
      Robot& operator-=(int);
   };

   // Global helper function 
   void box(Robot& robot1, Robot& robot2);
}
#endif // !SDDS_ROBOT_H__