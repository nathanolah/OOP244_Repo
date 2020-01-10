// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
namespace sdds
{
   // Validate the formatted date, and display specified error string
   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }

   // 
   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }

   //
   int Date::curYear()const {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      return lt.tm_year + 1900;
   }

   //
   void Date::setToToday() {
      time_t t = time(NULL);
      tm lt = *localtime(&t);
      m_day = lt.tm_mday;
      m_mon = lt.tm_mon + 1;
      m_year = lt.tm_year + 1900;
      errCode(NO_ERROR);
   }

   //
   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01 
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }

   //
   Date::Date() :m_CUR_YEAR(curYear()) {
      setToToday();
   }

   //
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(curYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }

   //
   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }

   // Returns the current year
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }

   // Accepts error code to initialize "m_ErrorCode"
   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }

   // Returns the error code
   int Date::errCode()const {
      return m_ErrorCode;
   }

   // Returns true if error code is not equal to 0
   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   // Returns m-mon
   int Date::currentMonth()const {
      return m_mon;
   }

   // Returns m_day
   int Date::currentDay()const {
      return m_day;
   }

   // Inputs the values of Date 
   istream& Date::read(istream& is) {
      errCode(NO_ERROR);
      is >> m_year;
      //is.ignore();
      is.ignore(2, '/');
      is >> m_mon;
      is.ignore(2, '/');
      //is.ignore();
      is >> m_day;
      if (cin.fail()) {
         errCode(CIN_FAILED);
         is.clear();
      }
      else {
         validate();
      }
      flushKeyboard();

      return is;
   }

   // Outputs the values of Date 
   ostream& Date::write(ostream& os)const {
      if (bad()) {
         os << dateStatus();
      }
      else {
         os << currentYear() << '/';
         os.width(2); // set width of 2
         os.fill('0'); // padding of '0'
         os << currentMonth() << '/';
         os.width(2);
         os.fill('0');
         os << currentDay();
      }

      return os;
   }

   // Clear buffer
   void Date::flushKeyboard() {
      while (getchar() != '\n');
   }

   // Boolean operator equal to, comparing the current object to the explicit object
   bool Date::operator==(const Date& RO)const {
      return (this->daysSince0001_1_1() == RO.daysSince0001_1_1());
   }

   // Boolean operator not equal to, comparing the current object to the explicit object
   bool Date::operator!=(const Date& RO)const {
      return (this->daysSince0001_1_1() != RO.daysSince0001_1_1());
   }

   // Operator greater than or equal, comparing the current object from the explicit object
   bool Date::operator>=(const Date& RO)const {
      return (this->daysSince0001_1_1() >= RO.daysSince0001_1_1());
   }

   // Operator less than or equal, comparing the current object from the explicit object
   bool Date::operator<=(const Date& RO)const {
      return (this->daysSince0001_1_1() <= RO.daysSince0001_1_1());
   }

   // Operator less than, comparing the current object from the explicit object  
   bool Date::operator<(const Date& RO)const {
      return (this->daysSince0001_1_1() < RO.daysSince0001_1_1());
   }

   // Operator greater than, comparing the current object from the explicit object  
   bool Date::operator>(const Date& RO)const {
      return (this->daysSince0001_1_1() > RO.daysSince0001_1_1());
   }

   // Operator minus, of the current object, and explicit object 
   int Date::operator-(const Date& RO)const {
      return (this->daysSince0001_1_1() - RO.daysSince0001_1_1());
   }

   // Operator bool returning state 
   Date::operator bool() {
      return validate();
   }

   // Helper functions 
   // Extraction operator for inputting object's data members 
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }

   // Insertion operator for outputting object's data members
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }

}