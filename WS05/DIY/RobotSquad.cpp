// RobotSquad.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 12, 2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring> // Used for strlen(), strncpy(), strcpy()
#include "RobotSquad.h" // Include class RobotSquad

namespace sdds
{ 
   // Default constructor
   RobotSquad::RobotSquad(const char* newName): numOfRobots(0), robots(nullptr) {
      numOfRobots = 0;
      robots = nullptr;

      // Copy "newName" into "name"
      if (strlen(newName) > NAME_MAX_LEN) {
         strncpy(name, newName, NAME_MAX_LEN + 1);
      }
      else {
         strcpy(name, newName);
      }
   }

   // Destructor, used to deallocate robots and set to nullptr 
   RobotSquad::~RobotSquad() {
      delete[] robots;
      robots = nullptr;
   }

   // Assignment operator+= used to add members to an empty squad 
   RobotSquad& RobotSquad::operator+=(const Robot& src) {

      numOfRobots++; // Count number of robots 
      Robot* temp = new Robot[numOfRobots]; // Allocate memory for temp object

      if (robots == nullptr) {
         robots = temp;
         Robot new_robot(src);
         robots[0] = new_robot;
      }
      else {
         for (int i = 0; i < numOfRobots - 1; i++) {
            Robot new_robot(robots[i]); // Copy constructor 
            temp[i] = new_robot; // Store into temp at the index
         }

         temp[numOfRobots - 1] = src;

         // Deallocate robots 
         delete[] robots;
         // Store temp into robots
         robots = temp;
      }

      return *this;
   }

   // Assignment operator-- used to subtract a robot, with deallocation 
   RobotSquad& RobotSquad::operator--() {
      if (robots == nullptr) {
         cout << "This squad **" << getName() << "** has no members" 
                  " or is uninitialized. Can't do --." << endl;
      }
      else {
         numOfRobots--;
         Robot* temp = new Robot[numOfRobots];

         for (int i = 0; i < numOfRobots; i++) {
            Robot new_robot(robots[i]); // Copy constructor 
            temp[i] = new_robot;
         }

         // Deallocate robots
         delete[] robots;
         // Store temp into robots 
         robots = temp;
         
      }

      return *this;
   }

   // Returns boolean if numOfRobots is equal to 0
   RobotSquad::operator bool()const {
      return numOfRobots == 0; 
   }

   // Returns the number of robots in the roster 
   int RobotSquad::getNumOfRobots()const {
      return numOfRobots;
   }

   // Returns robot name
   const char* RobotSquad::getName()const {
      return name;
   }
   
   // Returns robot roster
   Robot* RobotSquad::getRoster()const {
      return robots; 
   }

   // Display for Robot squad
   ostream& RobotSquad::display()const {
      if (operator bool()) {
         cout << "Squad **" << name << "** has no members" << endl; 
      }
      else {
         cout << "***Squad Summary***" << endl;
         cout << "Name: " << name << endl;
         cout << "Roster Count: " << numOfRobots << endl;
         cout << "Roster:" << endl;
         for (int i = 0; i < numOfRobots; i++) {
            robots[i].display();
         }
      }

      return cout;
   }
}