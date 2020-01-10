// Nathan Olah
// Student Number: 124723198
// Email: nolah@myseneca.ca
// October 3, 2019

// Bouquet.cpp implementation file containing the necessary function
// definitions and constructors and destructor definitions used in the Bouquet module.

#include <iostream> // Includes standard input and output stream
using namespace std;
#include "Bouquet.h" // Includes constant integers and the definition of class Bouquet
#include "Flower.h" // Includes the constant integers and the definition of class Flowers
#include "utils.h" // Includes read() function and copystr() function 
namespace sdds
{  
   // Bouquet Constructor, used to initialize private data memebers to an empty state
   Bouquet::Bouquet() {
      setEmpty();
   }

   // Bouquet constructor, containing 3 parameters of Flower object, numOfFlowers, and message
   Bouquet::Bouquet(const Flower* flowers, int numOfFlowers, const char* message) {  
      bool valid = true;  
      double sum(0);
      int i(0);

      // Initialize data members to empty state
      setEmpty();

      if (flowers == nullptr) {
         setEmpty();
         valid = false;
      }

      // Sets the flower count
      if (valid) {
         if (numOfFlowers < MAX_FLOWERS) {
            b_flowerCount = numOfFlowers;
         }
         else if (numOfFlowers >= MAX_FLOWERS) {
            b_flowerCount = MAX_FLOWERS;
         }

         // Allocate memory for b_flowers 
         b_flowers = new Flower[b_flowerCount]; 

         // Sets the details for the Bouquet object 
         for (i = 0; i < b_flowerCount; i++) {
            b_flowers[i].setName(flowers[i].name(), NAME_MAX_LEN);
            b_flowers[i].setColour(flowers[i].colour(), COL_MAX_LEN);
            b_flowers[i].setPrice(flowers[i].price());
            sum += flowers[i].price();
         }
         // Sum of the flowers stored in b_price 
         b_price = sum;
  
         // Use the copystr function because of allocation
         copystr(b_message, message, MESS_MAX_LEN);
      }

   }

   // Bouquet destructor, deallocates data memebers and sets to an empty state
   Bouquet::~Bouquet() {
      if (isEmpty()) {
         cout << "An unknown bouquet has departed..." << endl;
      }
      else if (!isEmpty()) {
         cout << "A bouquet has departed with the following flowers..." << endl;
      }
      
      // Deallocate memory
      delete[] b_flowers;
      delete[] b_message;
      setEmpty();
   }

   // Returns the message of Bouquet
   const char* Bouquet::message()const {
      return b_message;
   }

   // Returns the price of Bouquet
   double Bouquet::price()const {
      return b_price;
   }

   // Returns true if Bouquet object is empty
   bool Bouquet::isEmpty()const {
      return b_flowers == nullptr; 
   }

   // Sets the Bouquet object into a safe empty state
   void Bouquet::setEmpty() {
      b_flowers = nullptr;
      b_message = nullptr;
      b_price = -1;
      b_flowerCount = -1;
   }

   // Sets the message of the Bouquet object using data inputted by the user
   // tempMessage is validated, then used to get the length of the string 
   // to allocate memory for and copy into b_message
   void Bouquet::setMessage(const char* prompt) {
      char* tempMessage = new char[MESS_MAX_LEN + 1];
      cout << prompt;
   
      read(tempMessage, MESS_MAX_LEN, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
      
      // Allocate memory and copy "tempMessage" into "b_message"
      copystr(b_message, tempMessage, MESS_MAX_LEN);

      // Deallocate memory
      delete[] tempMessage;
      tempMessage = nullptr;

   }

   // This discards a Bouquet object by deallocating the data members
   // and setting the data members to a safe empty state
   void Bouquet::discardBouquet() {
      cout << "Discarding the current bouquet..." << endl;
      delete[] b_flowers;
      delete[] b_message;
      setEmpty();
   }

   // Arranges a Bouquet object through the use of user input
   // to define the flowers in the Bouquet object
   void Bouquet::arrangeBouquet() {
      char input(0);
      char newline(0); 
      bool done = true;
      int tempCount(-1);
      int i(0);
      double sum(0);

      cout << "Arranging a new bouquet..." << endl;

      // If the object is not empty user is prompted to discard the Bouquet object
      if (!isEmpty()) {
         cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
         do {
            cin >> input;
            newline = cin.get(); // Gets the newline after the "input"
            if (cin.fail() || newline == '\n') {
               if (input == 'n' || input == 'N') {
                  cout << "No new arrangement performed..." << endl;  
                  done = true;
               }
               else if (input == 'y' || input == 'Y') {
                  discardBouquet();
                  done = true;
               } 
            }
            else {
               cout << "The decision is either Y or N... Try again: ";
               done = false;
            }
         } while (!done);
      }

      if (isEmpty()) {
         // Gets the number of flowers from user, and stores the value into b_flowerCount
         cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
         read(tempCount, 1, MAX_FLOWERS, "The valid range is 1-3... Try again: ");
         b_flowerCount = tempCount;

         // Allocate memory for b_flowers
         b_flowers = new Flower[b_flowerCount];
         // Sets the flowers
         for (i = 0; i < b_flowerCount; i++) {
            b_flowers[i].setFlower(); // Set flower details 
            b_price += b_flowers[i].price();
            sum += b_flowers[i].price();
         }
         // Stores the sum of flowers price 
         b_price = sum;

         // Clears the input stream after setting each Flower instance
         cin.clear();
         cout << "A bouquet has been arranged..." << endl;

         // Sets the object message
         setMessage("Enter a message to send with the bouquet...: ");
      }
   
   }

   // Checks if the object is empty and prints the details of the Bouquet
   ostream& Bouquet::display()const {
      int i(0);

      if (isEmpty()) {
         cout << "This is an empty bouquet..." << endl;
      }
      else if (!isEmpty()) {
         cout.setf(ios::fixed); // set fixed
         cout.precision(2); // For 2 decimal places
         cout << "This bouquet worth " << b_price << " has the following flowers..." << endl;
         
         // Displays the flowers
         for (i = 0; i < b_flowerCount; i++) {
            b_flowers[i].display();
         }
         cout << "with a message of: " << (b_message != nullptr ? b_message : "Congratulations") << endl;
      }

      return cout;
   }

}