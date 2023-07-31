// Final Project Milestone 1
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
namespace sdds
{
   // Add for MS3 testing purposes
   bool sdds_test = false;
   int sdds_year = 2023;
   int sdds_mon = 12;
   int sdds_day = 25;

   bool Date::validate()
   {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1)
      {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12)
      {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays())
      {
         errCode(DAY_ERROR);
      }
      return !bad();
   }
   int Date::mdays() const
   {
      int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }
   int Date::systemYear() const
   {
      // time_t t = time(NULL);
      // tm lt = *localtime(&t);
      // return lt.tm_year + 1900;
      int theYear = sdds_year;
      if (!sdds_test)
      {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         theYear = lt.tm_year + 1900;
      }
      return theYear;
   }
   void Date::setToToday()
   {
      // time_t t = time(NULL);
      // tm lt = *localtime(&t);
      // m_day = lt.tm_mday;
      // m_mon = lt.tm_mon + 1;
      // m_year = lt.tm_year + 1900;
      // errCode(NO_ERROR);
      if (sdds_test)
      {
         m_day = sdds_day;
         m_mon = sdds_mon;
         m_year = sdds_year;
      }
      else
      {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         m_day = lt.tm_mday;
         m_mon = lt.tm_mon + 1;
         m_year = lt.tm_year + 1900;
      }
      errCode(NO_ERROR);
   }
   int Date::daysSince0001_1_1() const
   { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3)
      {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }
   Date::Date() : m_CUR_YEAR(systemYear())
   {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear())
   {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }
   const char *Date::dateStatus() const
   {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear() const
   {
      return m_CUR_YEAR;
   }
   void Date::errCode(int readErrorCode)
   {
      m_ErrorCode = readErrorCode;
   }
   int Date::errCode() const
   {
      return m_ErrorCode;
   }
   bool Date::bad() const
   {
      return m_ErrorCode != 0;
   }

   ostream &operator<<(ostream &os, const Date &RO)
   {
      return RO.write(os);
   }
   istream &operator>>(istream &is, Date &RO)
   {
      return RO.read(is);
   }

   // ---------- to develop ----------

   //    This function reads a date from the console in the following format YYYY/MM/DD as follows:
   std::istream &Date::read(std::istream &is)
   {
      // Clears the error code by setting it NO_ERROR
      errCode(NO_ERROR);

      // Reads the year, the month and the day member variables using istream and ignores a single character after the year and the month values to bypass the Slashes.
      // Note that the separators do not have to be Slash characters “/” but any separator that is not an integer number.
      is >> m_year;
      is.ignore(1);
      is >> m_mon;
      is.ignore(1);
      is >> m_day;

      // Checks if istream has failed.
      // If it did fail, it will set the error code to CIN_FAILED and clears the istream.
      // If not, it will validate the values entered.
      if (is) // checks if stream is still good state
      {
         validate();
      }
      else // stream state has failed or is bad
      {
         errCode(CIN_FAILED);
         is.clear(); // reset the state to good, allow more ops

         // MS3 remove
         // Flushes the keyboard
         // while (is.get() != '\n') // clear the buffer of old characters
         // {
         // }
      }
      // Returns the istream object
      return is;
   }

   // The write method
   std::ostream &Date::write(std::ostream &os) const
   {
      // If the Date object is in a “bad” state (it is invalid) print the “dateStatus()”. Otherwise, the function should write the date in the following format using the ostream object:
      if (bad())
      {
         os << dateStatus();
      }
      else
      {
         // Prints the year
         os << m_year;
         // Prints a Slash “/”
         os << "/";
         // Prints the month in two spaces, padding the left digit with zero if the month is a single-digit number
         os << setw(2) << setfill('0') << right << m_mon;
         // Prints a Slash “/”
         os << "/";
         // Prints the day in two spaces, padding the left digit with zero if the day is a single-digit number
         os << setw(2) << setfill('0') << right << m_day;
         // Makes sure the padding is set back to spaces from zero
         os << setfill(' ');
      }
      // Returns the ostream object.
      return os;
   }

   // Comparison operator overload methods
   // Use the return value of the daysSince0001_1_1() method to compare the two dates:
   bool Date::operator==(const Date &date) const
   {
      return daysSince0001_1_1() == date.daysSince0001_1_1();
   }
   bool Date::operator!=(const Date &date) const
   {
      return daysSince0001_1_1() != date.daysSince0001_1_1();
   }
   bool Date::operator<(const Date &date) const
   {
      return daysSince0001_1_1() < date.daysSince0001_1_1();
   }
   bool Date::operator>(const Date &date) const
   {
      return daysSince0001_1_1() > date.daysSince0001_1_1();
   }
   bool Date::operator<=(const Date &date) const
   {
      return daysSince0001_1_1() <= date.daysSince0001_1_1();
   }
   bool Date::operator>=(const Date &date) const
   {
      return daysSince0001_1_1() >= date.daysSince0001_1_1();
   }

   // Operator- method
   // Returns the difference between two Dates in days.
   int Date::operator-(const Date &date) const
   {
      return daysSince0001_1_1() - date.daysSince0001_1_1();
   }

   // bool type conversion operator
   Date::operator bool() const
   {
      // It will return true if the date is valid and false if it is not.
      return !bad();
   }
}
