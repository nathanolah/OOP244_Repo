// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 18, 2019

#ifndef SDDS_MENU_H__ // Safeguard for Menu.h 
#define SDDS_MENU_H__
namespace sdds
{
   const unsigned int MAX_MENU_ITEMS = 20;

   // Forward declaration 
   class Menu;

   // MenuItem
   class MenuItem {
      char* m_description;
      friend class Menu;
      // Constructors/Destructor
      MenuItem();
      MenuItem(const char* description);
      virtual ~MenuItem();
      //
      void setEmpty();
      bool isEmpty()const;
      //
      operator bool()const;
      operator const char* ()const;
      const char* description()const;
      std::ostream& display(std::ostream & = std::cout)const;

      MenuItem(const MenuItem& RO) = delete; // prevent copy constructor
      MenuItem& operator=(const MenuItem& RO) = delete; //prevent copy assignment operator
   };

   // Menu  
   class Menu {
      MenuItem m_title;
      MenuItem* m_pMenuItems[MAX_MENU_ITEMS];
      unsigned int m_menuSize;
   public:
      // Constructor/Destructor
      Menu(const char* cString = "");
      virtual ~Menu();
      // Member Operators 
      Menu& operator<<(const char* cString);
      unsigned int operator~()const;
      bool operator!()const;
      operator unsigned int()const;
      const char* operator[](unsigned int index)const;
      // Member functions
      void setEmpty();
      unsigned int getSelection()const;
      //const char* getTitle()const;
      unsigned int menuSize()const;
      std::ostream& display(std::ostream & = std::cout)const;
      std::ostream& displayTitle(std::ostream & = std::cout)const;

      Menu(const Menu& RO) = delete; // Prevents copy constructor
      Menu& operator=(const Menu& RO) = delete; // Prevents copy assignment operator
   };
   // Helper functions 
   std::ostream& operator<<(std::ostream& os, const Menu& RO);
}
#endif


