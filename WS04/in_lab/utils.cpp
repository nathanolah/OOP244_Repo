/***********************************************************************
// OOP244 Workshop 4: read functions for foolproof integer and C string
//                    data entry
// File	utils.cpp
// Version 1.1
// Date	2019/09/26
// Author	Fardad Soleimanloo, Hong Zhan (Michael) Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
// Michael         Sept 26 2019    Added a copystr function for Cstring DMA
//                                 Updated cstring read to account for empty strings
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "utils.h"
using namespace std;

namespace sdds {
	/*
	A set function that generically works with cstring pointer copying w/ dynamic memory
	A src and dest are given as parameters where the latter is a pointer reference. Where
  the dynamic allocation would take place.
	If the src isn't nullptr, normal processing occurs otherwise dest is set to nullptr.
	Assumes dest is allocated or has been set to a safe empty state / nullptr.
  The max_len dicates how much memory is to be allocated to the dest at maximum
  for the copying / the max number of characters to copy. It is nullbyte non inclusive.
	*/

	void copystr(char*& dest, const char* src, unsigned int max_len) {
      bool valid = true;

      if (dest != nullptr) { 
         delete[] dest;
      } 
      else if (src[0] == '\0' || src == nullptr || strlen(src) > max_len) {
         dest = nullptr;
         valid = false;
      } 
      else if (valid) {
         // Allocate memory for "dest"
         dest = new char[strlen(src) + 1]; 
         strcpy(dest, src); // Copies "src" into "dest"
      }
	}

	// reads an integer from console the integer referenced by "val"
	// argument.
	// if the user enters an invalid integer or values outside of the 
	// boundries set by "min" or "max" , this function flushes the 
	//keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable integer
	void read(int& val, int min, int max, const char* ErrorMess) {
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}
	// reads a C style string from console up to "len" characters into the
	// the string pointed by the "str" pointer
	// if the user enters more than "len" characters, this function
	// flushes the keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable string
	void read(char* str, int len, const char* errorMessage) {
		bool ok;
		do {
			ok = true;
			cin.getline(str, len + 1, '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				ok = false;
			}
			else if (strlen(str) == 0)
				ok = false;
		} while (!ok && cout << errorMessage);
	}
}