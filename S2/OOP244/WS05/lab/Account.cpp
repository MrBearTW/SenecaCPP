/*/////////////////////////////////////////////////////////////////////////
                            Workshop 5 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/15

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty()
   {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account()
   {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance)
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream &Account::display() const
   {
      if (*this)
      {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   // -------------------- type conversion operators --------------------

   // operator bool
   Account::operator bool() const
   {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
   }

   // operator int
   Account::operator int() const
   {
      return m_number;
   }

   // operator double
   Account::operator double() const
   {
      return m_balance;
   }

   // -------------------- Unary member operator --------------------

   bool Account::operator~() const
   {
      return m_number == 0;
   }

   //  -------------------- Binary member operator --------------------

   // assignment operators
   Account &Account::operator=(int number)
   {
      // If the integer value is an invalid account number, the object should be set to an invalid empty state instead.
      if (number < 10000 || number > 99999)
      {
         setEmpty();
      }

      // If the account is not new, then this operator should not perform any action.
      if (~*this)
      {
         m_number = number;
      }

      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   // overload the assignment operator
   Account &Account::operator=(Account &left)
   {
      // This action should move the balance and the account number from one account to another; therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands;
      // the balance of the left account will be set to the balance of the right account and then the balance of the right account will be set to zero.
      // The same will happen to the account number If the left Account operand is not new or the right account operand is not valid, no action should be taken.
      if (~*this && left)
      {
         m_balance = left.m_balance;
         left.m_balance = 0.0;
         m_number = left.m_number;
         left.m_number = 0;
      }

      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   // overload the += operator
   Account &Account::operator+=(double deposit)
   {
      // This should act like depositing money into an account. (i.e. the value of the double should be added to the balance)
      // if the account is in an invalid state or the double value is negative, no action should be taken.
      if (*this && deposit > 0)
      {
         m_balance += deposit;
      }
      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   // overload the -= operator
   Account &Account::operator-=(double withdraw)
   {
      // This should act like withdrawing money from an account. (i.e. the value of the balance should be reduced by the double value)
      // if the account is in an invalid state, the double value is negative or there is not enough money in the account no action should be taken.
      if (*this && withdraw > 0 && m_balance >= withdraw)
      {
         m_balance -= withdraw;
      }

      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   // overload the << operator (left shift operator)
   Account &Account::operator<<(Account &moveToLeft)
   {
      // After this operation, the balance of the left account will be the sum of both and the balance of the right account will be zero.
      // Funds of an account should not be able to be moved to itself and this operation does not affect the account.
      if (*this && moveToLeft && this != &moveToLeft)
      {
         this->m_balance += moveToLeft.m_balance;
         moveToLeft.m_balance = 0.0;
      }

      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   // overload the >> operator (right shift operator)
   Account &Account::operator>>(Account &moveToRight)
   {
      // After this operation, the balance of the right account will be the sum of both and the balance of the left account will be zero.
      // Funds of an account should not be able to be moved to itself and this operation does not affect the account.
      if (*this && moveToRight && this != &moveToRight)
      {
         moveToRight.m_balance += this->m_balance;
         this->m_balance = 0.0;
      }

      // In any case, a reference of the current object (account) should be returned.
      return *this;
   }

   //  -------------------- Binary helper operators --------------------

   // The double value should be the sum of the balances of the two accounts.
   // If any of the two accounts is invalid, then zero is returned.
   double operator+(const Account &left, const Account &right)
   {
      double sum = 0.0;
      if (left && right)
      {
         sum = left.m_balance + right.m_balance;
      }
      return sum;
   }

   // The value of the balance of the right operand (account reference) should be added to the left operand (double reference)
   double operator+=(double &left, const Account &right)
   {
      if (right)
      {
         left += right.m_balance;
      }
      return left;
   }
}