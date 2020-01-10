// Parts.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 9, 2019 

#ifndef SDDS_PARTS_H__ // Safeguard for header file 
#define SDDS_PARTS_H__
namespace sdds
{
   const int MIN_FORCE = 50;
   const int MIN_SPEED = 25;

   class Legs {
      int speed;
   public:
      // Constructors/Destructor 
      Legs();
      Legs(int legSpeed);
      //~Legs();
      // Member function prototype
      int getSpeed()const;
      // Member operator prototype
      Legs& operator-=(int);
      Legs& operator+=(int val);

   };

   class Arms {
      int force;
   public:
      // Constructors/Destructor
      Arms();
      Arms(int armsForce);
      //~Arms();
      // Member function prototype
      int getForce()const;
      // Member operator prototypes
      Arms& operator++();
      Arms operator++(int);
      Arms& operator+=(int);
   };

   // Global helper operators 
   bool operator>(const Legs&, const Legs&);
   bool operator<(const Legs&, const Legs&);
   bool operator>(const Arms&, const Arms&);
   bool operator<(const Arms&, const Arms&);

}
#endif // !SDDS_PARTS_H__
