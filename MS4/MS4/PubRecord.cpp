// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 20, 2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <cstring>
#include "PubRecord.h"
#include "Utils.h"
namespace sdds
{
   // Dynamically allocate and copy a character string
   void PubRecord::allocateAndCopy(const char* cString) {
      unsigned int length = 0;
      length = strlen(cString);
      m_name = new char[length + 1];
      strcpy(m_name, cString);
   }

   // Copies dynamically the paramater "name" into 
   void PubRecord::name(const char* name) {
      if (name) {
         delete[] m_name;
         allocateAndCopy(name);
      }
      else {
         setEmpty();
      }
   }

   // Returns m_name
   const char* PubRecord::name()const {
      return m_name;
   }

   // Defualt constructor 
   PubRecord::PubRecord() : m_name(nullptr) {
      setEmpty();
   }

   // Copy constructor
   PubRecord::PubRecord(const PubRecord& RO) {
      setEmpty();
      name(RO.m_name);
      m_shelfNumber = RO.m_shelfNumber;
      m_typeOfMedia = RO.m_typeOfMedia;
   }

   // Destructor
   PubRecord::~PubRecord() {
      delete[] m_name;
   }

   // Copy assignment operator
   PubRecord& PubRecord::operator=(const PubRecord& RO) {
      if (this != &RO) {
         //delete[] m_name;
         name(RO.m_name);
         m_shelfNumber = RO.m_shelfNumber;
         m_typeOfMedia = RO.m_typeOfMedia;
      }
      return *this;
   }

   // Sets the value of "m_typeOfMedia"
   void PubRecord::mediaType(int type) {
      m_typeOfMedia = type;
   }

   // Returns "m_typeOfMedia"
   int PubRecord::mediaType()const {
      return m_typeOfMedia;
   }

   // Returns "m_shelfNumber"
   int PubRecord::shelfNo()const {
      return m_shelfNumber;
   }

   // Validate and sets "m_shelfNumber"
   void PubRecord::readShelfNo() {
      int number = 0;
      readValue(number, 100, 1000, "Invalid Shelf Number, Enter again: ");
      m_shelfNumber = number;
   }

   // Return boolean value if "letter" is equal to return value of recID()
   bool PubRecord::operator==(const char letter)const {
      return (letter == recID());
   }

   // Returns boolean if "m_name" is a substring of "str"
   bool PubRecord::operator==(const char* str)const {
      return strstr(this->m_name, str);
   }

   // Returns boolean value if PubRecord is not in a empty state
   PubRecord::operator bool()const {
      return (!isEmpty());
   }

   // Returns boolean value if m_name is in empty state
   bool PubRecord::isEmpty()const {
      return (strcmp(m_name, "") == 0);
   }

   // Set to safe empty state
   void PubRecord::setEmpty() {
      //delete[] m_name;
      m_name = nullptr;
      m_name = new char[1];
      m_name[0] = 0;
      m_shelfNumber = 0;
      m_typeOfMedia = 0;
   }

   // Set the value of m_shelfNumber
   void PubRecord::shelfNo(int value) {
      m_shelfNumber = value;
   }
}