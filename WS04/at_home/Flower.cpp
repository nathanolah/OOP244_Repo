// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 1, 2019

// Flower.cpp implementation file containing the necessary function
// definitions used in the Flower module.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // Include the standard input and output stream
using namespace std;
#include <cstring> // For strcpy() and strlen()
#include "Flower.h" // Includes the constant integers and class Flowers, data members and methods 
#include "utils.h" // Includes read() function prototypes
namespace sdds
{
   // Constructor initializing data members to an empty state
   Flower::Flower() {
      setEmpty();
   }

   // Constructor with 3 parameters used to initialize a new flower object
   // Parameter variables are validated, if invalid they're set to an empty state
   // Otherwise memory is allocated for the strings and the price is set
   Flower::Flower(const char* name, const char* colour, double price) {
      bool valid = true;

      setEmpty();

      if (name == nullptr || name[0] == '\0') { // Checks if name is empty
         valid = false;
      }
      else if (colour == nullptr || colour[0] == '\0') { // Checks if colour is empty
         valid = false;
      }
      else if (price < 0) { // Checks if price is a negative number 
         valid = false;
      }

      // If valid memory is allocated and the strings are copied into
      // the assigned member.
      if (valid) {
         copystr(f_name, name, NAME_MAX_LEN);
         copystr(f_colour, colour, COL_MAX_LEN);
         f_price = price;
      }
   }

   // Destructor, used for when the Flower object goes out of scope
   // Allocated memory is then deallocated and data members are set
   // to an empty state.
   Flower::~Flower() {
      if (isEmpty()) {
         cout << "An unknown flower has departed..." << endl;
      }
      else {
         cout << f_colour << " " << f_name << " " << "has departed..." << endl;
      }

      // Deallocate memory and set to an empty state
      delete[] f_name;
      delete[] f_colour;
      setEmpty();
   }

   // Returns flower name
   const char* Flower::name()const {
      return f_name;
   }

   // Returns flower colour
   const char* Flower::colour()const {
      return f_colour;
   }

   // Returns flower price
   double Flower::price()const {
      return f_price;
   }

   // Returns true if the Flower object is empty, false otherwise
   bool Flower::isEmpty()const {
      bool ok = false;

      if (f_name == nullptr || f_name[0] == '\0' || strlen(f_name) == 0) {
         ok = true;
      }
      else if (f_colour == nullptr || f_colour[0] == '\0' || strlen(f_colour) == 0) {
         ok = true;
      }
      else if (f_price == -1) {
         ok = true;
      }

      return ok;

   }

   // Sets the Flower object to an empty state
   void Flower::setEmpty() {
      f_name = nullptr;
      f_colour = nullptr;
      f_price = -1;
   }

   // Set the name of the flower, using read() to validate the user inputted string
   // and maintain the correct string length otherwise an error messaged is displayed.
   // Memory is then allocated for the flower name, and copied into f_name.
   void Flower::setName(const char* prompt) {
      char* tempName = new char[NAME_MAX_LEN + 1]; // Plus one for null terminator

      cout << prompt;
      read(tempName, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");

      // Allocate memory and copy string into f_name
      copystr(f_name, tempName, NAME_MAX_LEN);

      // Deallocate
      delete[] tempName;
      tempName = nullptr;
   }

   // Set the colour of the flower, using read() to validate the user inputted string
   // and maintain the correct string length otherwise an error messaged is displayed.
   // Memory is then allocated for the colour name, and copied into f_colour.
   void Flower::setColour(const char* prompt) {
      char* tempColour = new char[COL_MAX_LEN + 1];

      cout << prompt;
      read(tempColour, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");

      // Allocate memory and copy string into f_colour
      copystr(f_colour, tempColour, COL_MAX_LEN);

      // Deallocate
      delete[] tempColour;
      tempColour = nullptr;
   }

   // Sets the price of the flower
   // Checks if the value is an invalid input using cin.fail()
   // If value is invalid an error message is displayed
   void Flower::setPrice(const char* prompt) {
      bool ok;
      char newline;

      cout << prompt;
      do {
         cin >> f_price;
         newline = cin.get();
         if (cin.fail() || newline != '\n') { // cin.fail() checks for a double type 
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n'); // Discard 1000 characters or up until '\n'
         }
         else {
            ok = f_price > 0; // Checks if f_price is a negative value
         }
      } while (!ok && cout << "A flower's price is a non-negative number... Try again: ");
   }

   // Sets the data members of Flower, by calling each set function for the
   // required data members. After setting the data members the details are 
   // displayed calling the display() function.
   void Flower::setFlower() {
      cout << "Beginning the birth of a new flower..." << endl;
      // Set name
      setName("Enter the flower's name... : ");

      // Set colour
      setColour("Enter the flower's colour... : ");

      // Set price 
      setPrice("Enter the flower's price... : ");

      // Display values 
      cout << "The flower's current details..." << endl;
      display();
   }

   // Used to display the objects details if the object isn't empty.
   // If the object is empty a message is displayed.
   ostream& Flower::display()const {
      if (isEmpty()) {
         cout << "This is an empty flower..." << endl;
      }
      else if (!isEmpty()) {
         cout << "Flower: " << f_colour << " " << f_name << " Price: ";
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << f_price << endl;
      }

      return cout;
   }

   // Copies the "name" string parameter into f_name 
   void Flower::setName(const char* name, int len) {
      copystr(f_name, name, len);
   }

   // Copies the "colour" string parameter into f_colour
   void Flower::setColour(const char* colour, int len) {
      copystr(f_colour, colour, len);
   }

   // Stores the double price parameter into f_price 
   void Flower::setPrice(double price) {
      if (price < 0) {
         price = 1;
      }
      f_price = price;
   }
}