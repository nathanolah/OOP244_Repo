// Robot.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 8, 2019 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring> // For strlen() and strcpy()
#include "Robot.h" // Includes constant NICK_MAX_LEN and the class Robot
namespace sdds
{  
   // Constructor used to set data members to safe empty state
   Robot::Robot() {
      m_nickname[0] = '\0';
      m_durability = 0;
      m_arms = nullptr; 
   }

   // 3 parameter constructor 
   Robot::Robot(const char* nickname, int force, int durability) {
      if (nickname == nullptr || nickname[0] == '\0') { 
         Robot(); //set to safe empty state
      }
      else if (strlen(nickname) > NICK_MAX_LEN) { 
         //m_nickname[NICK_MAX_LEN + 1];
         strcpy(m_nickname, nickname); 
      }
      else {
         strcpy(m_nickname, nickname);
      }

      // Checks if durability is less than 1 
      if (durability < 1) {
         m_durability = 100;
      }
      else {
         m_durability = durability;
      }

      // Sets the value of m_arms 
      m_arms = new Arms(force);
   }

   // Destructor used for deallocation
   Robot::~Robot() {
      delete m_arms;
      m_arms = nullptr;
   }

   // Check if the m_arm is empty, else values are displayed 
   ostream& Robot::display()const {
      if (m_arms == nullptr) {
         cout << "This Robot isn't operational" << endl;
      }
      else {
         cout << "***Robot Summary***" << endl;
         cout << "Nickname: " << m_nickname << endl;
         cout << "Arm Power: " << m_arms->getForce() << endl; 
         cout << "Durability: " << m_durability << endl;
      }

      return cout;
   }

   // Checks if nickname or durability is empty and returns a boolean
   Robot::operator bool()const {
      bool valid = false;
      if (m_nickname[0] == '\0' || m_durability == 0) {
         valid = true;
      }

      return valid;
   }
}