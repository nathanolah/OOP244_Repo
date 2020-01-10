// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 30, 2019

#include <iostream>
using namespace std;
#include <iomanip>
#include "Book.h"
#include "Utils.h"
namespace sdds
{
   // Default constructor
   Book::Book() {
      setEmpty();
   }

   // Copy constructor
   Book::Book(const Book& ro): PubRecord(ro) {
      setEmpty();
      m_ISBNno = ro.m_ISBNno;
      m_memberID = 0; 
   }

   // Copy assignment operator
   Book& Book::operator=(const Book& RO) {
      if (this != &RO) {
         PubRecord::operator=(RO);
         m_ISBNno = RO.m_ISBNno;
         m_memberID = 0; 
      }
      return *this;
   }

   // Destructor
   Book::~Book() {}

   // Set empty state 
   void Book::setEmpty() {
      m_ISBNno = 0;
      m_memberID = 0;
   }

   // Return recID
   char Book::recID()const {
      return 'B';
   }

   // Return member ship ID
   int Book::memberID()const {
      return m_memberID;
   }

   // Sets member id to 0
   void Book::checkIn() {
      m_memberID = 0;
      write() << " checked in!" << endl;
   }

   // Validate and set return date 
   void Book::checkOut() {
      bool ok = true;
      Date currentDate;

      // Set member id
      cout << "Enter Member id: ";
      readMemberID();
      // Set current date
      currentDate.setToToday();
      // Set return date
      do {
         cout << "Enter return date: ";
         m_date.read(); 
         if (m_date.errCode() != 0) { // Check date status
            cout << m_date.dateStatus() << "." << endl;
            ok = false;
         } 
         else if (m_date <= currentDate) { // Check if set for future date
            cout << "Please enter a future date." << endl;
            ok = false;
         } 
         else if ((m_date - currentDate) > 30) { // Check if date is earlier than 30 days 
            cout << "The return date must be eariler than 30 days away from today." << endl;
            ok = false;
         } 
         else if ((m_date - currentDate) < 30 && (m_date - currentDate) > 1) { // Check if date is within a month
            ok = true;
         }
      } while (!ok); 
   }

   // Reads valid member ship ID
   void Book::readMemberID() {
      int tempMember = 0;
      readValue(tempMember, 10000, 99999, "Invalid Member ID, Enter again: ");
      m_memberID = tempMember;
   }

   // Book istream read function
   std::istream& Book::read(std::istream& is) {
      char tempName[41] = "";
      int tempShelf = 0;

      if (mediaType() == SDDS_CONSOLE) { // read to console 
         m_memberID = 0; 
         cout << "Book Name: ";
         readBookName();
         cout << "ISBN: ";
         readISBNno();
         cout << "Shelf Number: ";
         readShelfNo();
      }
      else if (mediaType() == SDDS_FILE) { // read to file 
         is.getline(tempName, 40, '\t');
         name(tempName);
         is >> m_ISBNno;
         is.ignore();
         is >> tempShelf;
         shelfNo(tempShelf);
         is >> m_memberID;
         if (m_memberID != 0) {
            is.ignore();
            is >> m_date;
         }
      }
      return is;
   }

   // Book ostream write function 
   ostream& Book::write(ostream& os)const {
      if (mediaType() == SDDS_CONSOLE) { // write to console 
         os << setw(41)
            << left
            << setfill(' ')
            << name()
            << m_ISBNno << "  " << shelfNo();
         if (memberID() != 0) {
            os << " "
               << m_memberID
               << "   "
               << m_date;
         }
      }
      else if (mediaType() == SDDS_FILE) { // write to file 
         os << recID()
            << name() << '\t'
            << m_ISBNno << '\t'
            << shelfNo() << '\t'
            << m_memberID;
         if (m_memberID != 0) {
            os << '\t'
               << m_date;
         }
         os << endl;
      }
      return os;
   }

   // Validates and sets ISBN number
   void Book::readISBNno() {
      long long tempISBNno = 0;
      readValue(tempISBNno, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: "); 
      m_ISBNno = tempISBNno;
   }                        

   // Validates and set Book name
   void Book::readBookName() {
      char tempName[41] = "";
      readString(tempName, 40, "Book name too long, Enter again: ");
      name(tempName);
   }
}  