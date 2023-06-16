/*/////////////////////////////////////////////////////////////////////////
                            Workshop 5 Part 1
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/15

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
   class Account
   {
      int m_number;
      double m_balance;
      void setEmpty();

   public:
      Account();
      Account(int number, double balance);
      std::ostream &display() const;

      // -------------------- type conversion operators --------------------

      // operator bool
      // returns true if the account is valid and otherwise false. This operator can not modify the account object.
      operator bool() const;

      // operator int
      // returns the account number. This operator can not modify the account object.
      operator int() const;

      // operator double
      // returns the balance value. This operator can not modify the account object.
      operator double() const;

      // -------------------- Unary member operator --------------------

      // This operator returns true is the account is new or not set (i.e. if the account number is zero), otherwise it will return false. This operator can not modify the account object.
      bool operator~() const;

      //  -------------------- Binary member operator --------------------

      //  ssignment operators
      // overload the assignment operator so a NEW account can be set to an integer. Doing so should set the account number of the account to the integer value.
      Account &operator=(int number);

      // overload the assignment operator so a NEW account can be set to another Account object.
      Account &operator=(Account &left);

      // overload the += operator to add a double value to an account. This should act like depositing money into an account.
      Account &operator+=(double deposit);

      // overload the -= operator to reduce an account balance by a double value . This should act like withdrawing money from an account.
      Account &operator-=(double withdraw);

      // overload the << operator (left shift operator) to move funds from the right account to the left.
      Account &operator<<(Account &moveToLeft);

      // overload the >> operator (right shift operator) to move funds from the left account to the right.
      Account &operator>>(Account &moveToRight);

      //  -------------------- Binary helper operators --------------------

      // create a binary stand alone helper + operator that accepts a constant account reference at left and another constant account reference at right and returns a double value.
      friend double operator+(const Account &left, const Account &right);

      // create a binary stand alone helper += operator that accepts a double reference at left and a constant account reference at right and returns a double value.
      friend double operator+=(double &left, const Account &right);
   };

}
#endif // SDDS_ACCOUNT_H_