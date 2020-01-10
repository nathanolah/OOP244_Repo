// Robot.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 9, 2019 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // Includes istream and ostream
using namespace std;
#include "Robot.h" // Includes the class Robot, helper function box() and constant NICK_MAX_LEN
#include <cstring> // For strncpy(), strcpy() and strlen()
namespace sdds
{
   // Constructor used to set data members to safe empty state
   Robot::Robot(): durability(0), arms(nullptr), legs(nullptr) { 
      nickname[0] = '\0'; 
      durability = 0;
      arms = nullptr;
      legs = nullptr;
   }

   // Robot constructor with 4 parameters used to validate and set the data members of the robot object
   Robot::Robot(const char* newNickname, int armForce, int legSpeed, int tempDurability) {
      if (newNickname == nullptr || newNickname[0] == '\0' || tempDurability == 0) {
         Robot(); // set to safe empty state
      }
      else if (strlen(newNickname) > NICK_MAX_LEN) { // if character length is greater than NICK_MAX_LEN
         strncpy(nickname, newNickname, NICK_MAX_LEN + 1);  
      }
      else {
         strcpy(nickname, newNickname);
      }

      if (tempDurability < 1) { // if "tempDurability" is less than 1
         durability = 100; // sets durability to 100
      }
      else {
         durability = tempDurability;
      }

      // Sets the value of arms, allocation of "arms" and "legs"
      arms = new Arms(armForce);
      legs = new Legs(legSpeed);
   }

   // Destructor used for deallocation
   Robot::~Robot() {
      delete arms;
      delete legs;
      arms = nullptr;
      legs = nullptr;
   }

   // Check if the object is empty, else values are displayed 
   ostream& Robot::display()const {
      if (operator bool()) { 
         cout << "This Robot isn't operational" << endl;
      }
      else {
         cout << "***Robot Summary***" << endl;
         cout << "Nickname: " << nickname << endl;
         cout << "Arm Power: " << arms->getForce() << endl;
         cout << "Durability: " << durability << endl;
         cout << "Legs: " << legs->getSpeed() << endl;
      }

      return cout;
   }

   // Checks if nickname or durability is empty and returns a boolean
   Robot::operator bool()const {
      return nickname[0] == '\0' || durability == 0;
   } 

   // Returns a copy of the Arms current Robot object 
   Arms Robot::getArms()const {
     // Arms temp = this->arms->getForce();
     // return temp;
      //return *arms; 
      return *this->arms;
   }

   // Returns a copy of the Legs current Robot object 
   Legs Robot::getLegs()const {
     // Legs temp = this->legs->getSpeed();
     // return temp;
      //return *legs;
      return *this->legs;
   }

   // Operator overload that maps the notion of 
   // minus equals assignment.
   Robot& Robot::operator-=(int val) {
      durability -= val;

      if (durability < 1) {
         durability = 0; // sets the durability to 0 if less than 1 
      }

      return *this; // Returns the current object 
   }

   // 
   void box(Robot& robot1, Robot& robot2) {
      cout << "Attempting to begin a Robot boxing match" << endl;
      // Checks if either of the robot objects are in a empty state 
      if (robot1 || robot2) {
         cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
      }
      else {
         cout << "Both participants are operational... beginning the bout" << endl;
         // While both of the robot objects are not in a empty state condition is true
         while (!robot1 && !robot2) {
            if (robot1.getLegs() > robot2.getLegs()) {  // if robot1's speed is greater than robot2's speed 
               robot2-=(robot1.getArms().getForce()); // robot1's force value is passed as an argument to minus equals operator overload

               // Checks if robot2's durability is not 0 
               if (!robot2) {
                  robot1-=(robot2.getArms().getForce()); // robot2's force value is passed as an argument to minus equals operator overload
               }
            } 
            else if (robot2.getLegs() > robot1.getLegs()) { // if robot2's speed is greater than robot1's speed 
               robot1-=(robot2.getArms().getForce()); // robot2's force value is passed as an argument to minus equals operator overload 

               // Checks if robot1's durability is not 0
               if (!robot1) {
                  robot2-=(robot1.getArms().getForce()); 
               }
            }

         }
         cout << "The bout has concluded... the winner is: " << endl;
         // Checks for the not empty robot object to display results 
         if (!robot1) {
            robot1.display();
         }
         else if (!robot2) {
            robot2.display();
            }
      }
   }

}