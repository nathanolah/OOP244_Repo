// Final Project Milestone 1 
// Menu Module
// File	menuTester.cpp
// Version 2.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/13		       Preliminary release
// Fardad             2019/11/14           Added operator[] usage
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
using namespace sdds;

void showOrder(const unsigned int* cnt, const Menu& M);
int main() {
   unsigned int selections[3] = { 0 };
   unsigned int s;
   Menu m1("Lunch Menu"), m2;
   if (!m2) { 
      cout << "The " << m2 << " menu is empty" << endl;
   }
   else {
      cout << "Wrong output, your bool cast is done incorrenctly!";
   }
   m1 << "Omelet" << "Tuna Sandwich" << "California Roll";
   m2 << "Order more";
   if (m1) {
      cout << "The " << m1 << " is not empty and has " << (unsigned int)(m1) << " menu items." << endl;
   }
   do {
      s = m1.getSelection();
      if (s) {
         selections[s - 1]++;
         cout << "you chose " << m1[s - 1] << endl;
      }
   } while (s != 0 || ~m2 != 0);
   showOrder(selections, m1);
   return 0;
}
void showOrder(const unsigned int* cnt, const Menu& M) {
   bool orderedSomthing = false;
   cout << "Your orders: " << endl;
   for (int i = 0; i < 3; i++) {
      if (cnt[i]) {
         orderedSomthing = true;
         cout << cnt[i] << " " << M[i] << (cnt[i] > 1 ? "s" : "") << endl;
      }
   }
   if (!orderedSomthing) cout << "You didn't order anything!" << endl;
}