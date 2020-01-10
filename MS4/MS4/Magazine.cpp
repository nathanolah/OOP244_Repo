// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 30, 2019

#include <iostream>
using namespace std;
#include <iomanip>
#include "Magazine.h"
#include "Utils.h"
namespace sdds
{
   // Default constructor
   Magazine::Magazine() : m_volume(0), m_issueNo(0) {

   }

   // Copy constructor
   Magazine::Magazine(const Magazine& RO): PubRecord(RO) {
      m_volume = RO.m_volume;
      m_issueNo = RO.m_issueNo;
   }

   // Copy assignment operator
   Magazine& Magazine::operator=(const Magazine& RO) {
      if (this != &RO) {
         PubRecord::operator=(RO);
         m_volume = RO.m_volume;
         m_issueNo = RO.m_issueNo;
      }
      return *this;
   }

   // Destructor
   Magazine::~Magazine() {}

   // Returns RecID value 
   char Magazine::recID()const {
      return 'M';
   }

   // 
   void Magazine::checkIn() {
      cout << "Magazines cannot be checked in or out!" << endl; 
   }

   //
   void Magazine::checkOut() {
      cout << "Magazines cannot be checked in or out!" << endl; 
   }

   // Magazine istream read function 
   istream& Magazine::read(istream& is) {
      char tempName[41] = "";
      int tempShelf = 0;
      
      if (mediaType() == SDDS_CONSOLE) { // read into console
         cout << "Magazine Name: ";
         readName();
         cout << "Volume: ";
         readVolume();
         cout << "Issue: ";
         readIssueNo();
         cout << "Shelf Number: ";
         readShelfNo();
      }
      else if (mediaType() == SDDS_FILE) { // read into a file 
         is.getline(tempName, 40, '\t');
         name(tempName);
         is >> m_volume;
         is.ignore();
         is >> m_issueNo;
         is.ignore();
         is >> tempShelf;
         shelfNo(tempShelf);
         is.ignore();
      }

      return is;
   }

   // Magazine ostream write function 
   ostream& Magazine::write(ostream& os)const {
      if (mediaType() == SDDS_CONSOLE) { // write to console 
         os << setw(41) << left
            << name();
         os << "       " << right;
         os << setw(2) << setfill('0')
            << volume() << setfill(' ')
            << "("
            << setw(2) << setfill('0')
            << issue() << setfill(' ')
            << ")" << left
            << "  " << shelfNo();
      }
      else if (mediaType() == SDDS_FILE) { // write to file 
         os << recID()
            << name()
            << '\t'
            << volume()
            << '\t'
            << issue()
            << '\t'
            << shelfNo() << endl;
      }

      return os;
   }
   
   // Returns m_volume's value
   int Magazine::volume()const {
      return m_volume;
   }

   // Returns m_issueNo's value
   int Magazine::issue()const {
      return m_issueNo;
   }

   // Validates and sets name
   void Magazine::readName() {
      char tempName[41] = "";
      readString(tempName, 40, "Magazine name too long, Enter again: ");
      name(tempName); // inherit name() function call
   }

   // Validates volume number 
   void Magazine::readVolume() {
      int volume = 0;
      readValue(volume, 1, 99, "Invalid Volume number, Enter again: ");
      setVolume(volume);
   }

   // Sets m_volume
   void Magazine::setVolume(int volume) {
      m_volume = volume;
   }

   // Validates issue number
   void Magazine::readIssueNo() {
      int issueNo = 0;
      readValue(issueNo, 1, 99, "Invalid Issue Number, Enter again: ");
      setIssueNo(issueNo);
   }
   
   // Set m_issue
   void Magazine::setIssueNo(int issueNo) {
      m_issueNo = issueNo;
   }
}