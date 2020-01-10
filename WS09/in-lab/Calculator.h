// Calculator.h
// WS09 in-lab
// Nathan Olah 
// Student Number: 124723198
// Email: nolah@myseneca.ca
// November 25, 2019

#ifndef SDDS_CALCULATOR_H__
#define SDDS_CALCULATOR_H__
#include <iostream>
namespace sdds
{  
   // Templated class
   template <typename T, unsigned int N> // Template parameters
   class Calculator {
      T* m_results;
   public:
      // Constructor/Destructor 
      Calculator();
      ~Calculator();
      // Member functions
      void add(const T*, const T*);
      void subtract(const T*, const T*);
      void multiply(const T*, const T*);
      void divide(const T*, const T*);
      std::ostream& display(std::ostream& os)const;
      // Member operator overloads
      Calculator& operator+=(const T*);
      Calculator& operator-=(const T*);
      Calculator& operator*=(const T*);
      Calculator& operator/=(const T*);
   };

   // Default constructor
   template <typename T, unsigned int N>
   Calculator<T, N>::Calculator() {
      m_results = new T[N];
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] = 0;
      }
   }

   // Destructor
   template <typename T, unsigned N>
   Calculator<T, N>::~Calculator() {
      delete[] m_results;
   }

   // Add
   template <typename T, unsigned int N>
   void Calculator<T, N>::add(const T* lo, const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] = lo[i] + ro[i];
      }
   }

   // Subtract
   template <typename T, unsigned int N>
   void Calculator<T, N>::subtract(const T* lo, const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] = lo[i] - ro[i];
      }
   }

   // Multiply
   template <typename T, unsigned int N>
   void Calculator<T, N>::multiply(const T* lo, const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] = lo[i] * ro[i];
      }
   }

   // Divide
   template <typename T, unsigned int N>
   void Calculator<T, N>::divide(const T* lo, const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] = lo[i] / ro[i];
      }
   }

   // Display
   template <typename T, unsigned int N>
   std::ostream& Calculator<T, N>::display(std::ostream& os)const {
      for (unsigned int i = 0; i < N; i++) {
         os << m_results[i];
         if (i < N - 1) {
            os << ",";
         }
         else {
            os << std::endl;
         } 
      }
      
      return os;
   }

   // Member Operator overloads

   // Plus equal operator
   template <typename T, unsigned int N>
   Calculator<T, N>& Calculator<T, N>::operator+=(const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] += ro[i];
      }
      return *this;
   }

   // Minus equal operator
   template <typename T, unsigned int N>
   Calculator<T, N>& Calculator<T, N>::operator-=(const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] -= ro[i];
      }
      return *this;
   }

   // Multiply equal operator 
   template <typename T, unsigned int N>
   Calculator<T, N>& Calculator<T, N>::operator*=(const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] *= ro[i];
      }
      return *this;
   }

   // Divide equal operator
   template <typename T, unsigned int N>
   Calculator<T, N>& Calculator<T, N>::operator/=(const T* ro) {
      for (unsigned int i = 0; i < N; i++) {
         m_results[i] /= ro[i];
      }
      return *this;
   }

}

#endif // !SDDS_CALCULATOR_H__
