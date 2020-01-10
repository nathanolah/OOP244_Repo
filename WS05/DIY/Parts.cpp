// Parts.cpp
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 9, 2019 

#include "Parts.h" // Include Parts.h MIN_FORCE and class Arms
namespace sdds
{
   // Constructor to set Arms object to an empty state 
   Arms::Arms(): force(0) { // initialize before setting force
      force = 0;
   }

   // One argument constructor to set the value of "force" 
   Arms::Arms(int armForce) {
      force = (armForce < 1) ? MIN_FORCE : armForce;
   }

   // Returns the force of the Arms object 
   int Arms::getForce()const {
      return force;
   }

   // Prefix increment for force, and returns the current object 
   Arms& Arms::operator++() {
      force += 10;
      return *this; // return the current object
   }

   // Postfix increment for force, a copy of the original is returned 
   Arms Arms::operator++(int) {
      Arms copy = *this; // saves the original 
      force += 10;
      return copy;
   }

   // Postfix increment for force, returns the current object 
   Arms& Arms::operator+=(int val) {
      force += val;
      if (force < 1) {
         force = 0;
      }

      return *this; // Returns the current object
   }

   // Sets the Legs object to a safe empty state
   Legs::Legs() : speed(0) { // initialize before setting speed
      speed = 0;
   }

   // Legs constructor with one parameter used to set the 
   // object legs data member "speed".
   Legs::Legs(int legSpeed) {
      speed = (legSpeed < 1) ? MIN_SPEED : legSpeed;
   }

   // Query function used to return "speed"
   int Legs::getSpeed()const {
      return speed;
   }

   // Postfix increment for force, returns the current object 
   Legs& Legs::operator+=(int val) {
      speed += val;
      if (speed < 1) {
         speed = 0;
      }

      return *this; // Returns the current object
   }

   // Operator overload that maps the notion of minus 
   // equals assignment.
   Legs& Legs::operator-=(int val) {
      speed -= val;
      if (speed < 1) {
         speed = 0; // sets "speed" to 0 if less than 1 
      }

      return *this; // returns the current object 
   }

   // Overloads the notion of greater than operator used for Legs 
   bool operator>(const Legs& legs1, const Legs& legs2) {
      return legs1.getSpeed() > legs2.getSpeed();
   }

   // Overloads the notion of less than operator used for Legs
   bool operator<(const Legs& legs1, const Legs& legs2) {
      return legs1.getSpeed() < legs2.getSpeed();
   }

   // Overloads the notion of greater than operator used for Arms
   bool operator>(const Arms& arms1, const Arms& arms2) {
      return arms1.getForce() > arms2.getForce();
   }

   // Overloads the notion of less than operator used for Arms
   bool operator<(const Arms& arms1, const Arms& arms2) {
      return arms1.getForce() < arms2.getForce();
   }
}