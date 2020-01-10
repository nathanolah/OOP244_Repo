// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 18, 2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include "Menu.h"
#include "Utils.h"
namespace sdds
{
   // Default Constructor
   MenuItem::MenuItem() : m_description(nullptr) {
      setEmpty();
   }

   // One Argument constructor 
   MenuItem::MenuItem(const char* description) : m_description(nullptr) {
      int length = 0;

      if (description) { // if "description" contains a string
         length = strlen(description); // Get string length
         m_description = new char[length + 1]; // Allocate memory for description
         strcpy(m_description, description); // Copy description into "m_description"
      }
      else {
         setEmpty(); // Set to safe empty state 
      }
   }

   // Destructor 
   MenuItem::~MenuItem() {
      // Deallocate "m_description"
      delete[] m_description;
   }

   // Return true if object is not empty 
   MenuItem::operator bool()const {
      return (!isEmpty());
   }

   // Return boolean if object is empty
   bool MenuItem::isEmpty()const {
      return (m_description == 0);
   }

   // Set empty object to empty state 
   void MenuItem::setEmpty() {
      delete[] m_description;
      m_description = new char[1];
      m_description[0] = 0;
   }

   // Returns the address of the description
   MenuItem::operator const char* ()const {
      return description();
   }

   // Query that returns "m_description"
   const char* MenuItem::description()const {
      return m_description;
   }

   // Display "m_description" value 
   ostream& MenuItem::display(ostream& os)const {
      return os << description();
   }

   // MENU

   // One argument Constructor 
   Menu::Menu(const char* cString) {
      int length = 0;

      setEmpty();
      if (cString == 0) {
         setEmpty();
      }
      else {
         //allocateAndCopy();
         // Allocate and copy "cString" into "m_title.m_description"
         length = strlen(cString);
         m_title.m_description = new char[length + 1];
         strcpy(m_title.m_description, cString);
      }
   }

   // Destructor 
   Menu::~Menu() {
      for (unsigned int i = 0; i < menuSize(); i++) {
         delete m_pMenuItems[i];
      }
   }

   // Set object to empty state 
   void Menu::setEmpty() {

      for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
         m_pMenuItems[i] = new MenuItem();
      }
      m_menuSize = 0;
      delete[] m_title.m_description;
      m_title.m_description = new char[1];
      m_title.m_description[0] = 0;
   }

   // Displays entire menu 
   ostream& Menu::display(ostream& os)const {
      if (!m_title.isEmpty()) {
         m_title.display(os);

         if (strcmp(m_title, "") != 0) {
            os << ":" << endl;
         }
         for (unsigned int i = 0; i < m_menuSize; i++) {
            os << " " << i + 1 << "- "
               << m_pMenuItems[i]->description() << endl;
         }
         os << " 0- Exit" << endl
            << "> ";
      }

      return os;
   }

   // Displays title of the object's menu
   ostream& Menu::displayTitle(ostream& os)const {
      if (!m_title.isEmpty()) {
         m_title.display(os);
      }
      return os;
   }

   // Insertion operator, of cString into Menu object
   Menu& Menu::operator<<(const char* cString) {
      unsigned int i = 0;

      m_menuSize++; // increment the menu size

      // Allocate and copy "cString" into each element of "m_pMenuItems" 
      for (i = m_menuSize - 1; i < m_menuSize; i++) {
         if (m_pMenuItems[i] != nullptr) {
            m_pMenuItems[i] = new MenuItem(cString);
         }
      }

      return *this;
   }

   // Gets menu selection number, validates and returns selection number
   unsigned int Menu::getSelection()const {
      unsigned int selection = 0;
      
      display(); // Display menu 
      readValue(selection, 0, menuSize(), "Invalid Selection, try again: "); // Validate selection
      return selection;
   }

   // Tilde operator, returns the value of selection
   unsigned int Menu::operator~()const {
      unsigned int selection = 0;

      if (this->m_title == nullptr) {
         selection = 0;
      }
      else {
         selection = this->getSelection();
      }
      return selection;
   }

   // Return boolean if object is in empty state 
   bool Menu::operator!()const {
      return (m_title.m_description != 0);
   }

   // Returns "m_menuSize"
   unsigned int Menu::menuSize()const {
      return m_menuSize;
   }

   // Return unsigned int of m_menuSize
   Menu::operator unsigned int()const {
      return menuSize();
   }

   // Returns a constant character string, at the index of specified "index" value 
   const char* Menu::operator[](unsigned int index)const {

      unsigned idx = (index > this->menuSize() ? 0 : index);

      return m_pMenuItems[idx]->m_description;
   }

   // Helper Function
   // Insertion operator receives reference of Menu and ostream object 
   std::ostream& operator<<(std::ostream& os, const Menu& RO) {
      return RO.displayTitle(os);
   }

}