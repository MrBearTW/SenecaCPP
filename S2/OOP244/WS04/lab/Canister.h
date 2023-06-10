#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds
{
   class Canister
   {
      char *m_contentName;    // points to a dynamically allocated Cstring.
      double m_diameter;      // in centimeters
      double m_height;        // in centimeters
      double m_contentVolume; // in CCs
      bool m_usable;          // a flag to identify if the Canister is usable or unusable

      // This function sets the attributes to their default values. It sets the content name pointer to null, height to 13.0, diameter to 10.0, content volume to 0.0 and usable flag to true.
      void setToDefault();

      // Returns true is the content volume is less than 0.00001 CCs.
      bool isEmpty() const;

      // Compares the content name of this Canister with the one received from the argument C. Using strCmp in cstring.h, it returns true if both content names are not null and are identical. Otherwise, it returns false;
      bool hasSameContent(const Canister &C) const;

      // Sets the content name of the current Canister.
      // If the incoming Cstr is not null and the Canister is usable, it will delete the current content name, allocate memory to the length of Cstr (+1 for null) and copies the Cstr into the newly allocated memory. Otherwise, it will silently do nothing.
      void setName(const char *Cstr);

   public:
      // Constructor & Destructor
      Canister();
      Canister(const char *contentName); // Sets the attributes to their default values (note: reuse code). Sets the Name to the incoming contentName argument.
      Canister(double height, double diameter, const char *contentName = nullptr);
      ~Canister();

      // Public Methods (member variables)

      // It will set the Content name of the canister using the following rule and then returns the reference of the current object (i.e. *this)
      Canister &setContent(const char *contentName);

      // Adds the quantity argument to the content volume of the Canister if the quantity fits in the Canister. Otherwise, it will render the Canister unusable and then returns the reference of the current object.
      Canister &pour(double quantity);

      // Pours the content of the Canister argument into the current Canister following the Specs stated at the top
      Canister &pour(Canister &C);

      // returns the content volume attribute
      double volume() const;

      // Prints the Canister
      std::ostream &display() const;

      // returns the capacity as stated in Calculating the capacity
      double capacity() const;

      // Clears an unusable Canister back to an empty Canister by:
      void clear();
   };
}

#endif // !SDDS_BOX_H
