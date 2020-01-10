// Parts.h
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 8, 2019 

#ifndef SDDS_PARTS_H__ // Safeguard for header file 
#define SDDS_PARTS_H__
namespace sdds
{
   const int MIN_FORCE = 50;

   class Arms {
      int m_force;
   public:
      // Constructors/Destructor
      Arms();
      Arms(int armsForce);
      ~Arms();
      // Member function prototype
      int getForce()const;
      // Member operator prototypes
      Arms& operator++();
      Arms operator++(int);
      Arms& operator+=(int);
   };
}
#endif // !SDDS_PARTS_H__