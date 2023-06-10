#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"
#define PI 3.14159265

using namespace std;
namespace sdds
{
    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    void Canister::setName(const char *Cstr)
    {
        // Check the Cstr is not null && usable
        if (Cstr != nullptr && Cstr[0] != '\0' && m_usable)
        {
            // delete the current content name
            if (m_contentName)
            {
                delete[] m_contentName;
                m_contentName = nullptr;
            }

            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr); // copy the Cstr to newly allocated memory of m_contentName
        }
    }

    bool Canister::isEmpty() const
    {
        return m_contentVolume < 0.00001;
    }

    bool Canister::hasSameContent(const Canister &C) const
    {
        bool result = false;

        // it returns true if both content names are not null and are identical
        if (this->m_contentName != nullptr && C.m_contentName != nullptr)
        {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)
                result = true;
        }

        return result;
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char *contentName)
    {
        setToDefault();

        // Sets the Name to the incoming contentName argument
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char *contentName)
    {
        setToDefault();

        // The smallest Canister can have a height and diameter of 10.0 by 10.0 centimetres and the largest one can be 40 by 30 respectively.
        if (height >= 10.0 && diameter >= 10 && height <= 40 && diameter <= 30)
        {
            m_height = height;
            m_diameter = diameter;
            m_usable = true;
            setName(contentName);
        }
        else
            m_usable = false;
    }

    // Destructor  // Not Necessary for this workshop
    Canister::~Canister()
    {
        // Deallocates the dynamic memory pointed by the content name attribute.
        if (m_contentName)
        {
            delete[] m_contentName;
            m_contentName = nullptr;
        }
    }

    void Canister::clear()
    {
        if (m_usable == false)
        {
            delete[] m_contentName;  // deallocating the memory pointed by the content name attribute
            m_contentName = nullptr; // sets the content name attribute to nullptr
            m_contentVolume = 0.0;
            m_usable = true;
        }
    }

    double Canister::capacity() const
    {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }

    double Canister::volume() const
    {
        return m_contentVolume;
    }

    Canister &Canister::setContent(const char *contentName)
    {
        if (contentName == nullptr || contentName[0] == '\0') // If the contentName argument is null "this" Canister will be unusable
        {
            m_usable = false;
        }
        else if (this->isEmpty()) // else if the Canister is empty it will set the Name to the value pointed by the argument
        {
            setName(contentName);
        }
        else if (!(this->hasSameContent(contentName))) // else if the name of the Canister is not the same as the contentName argument it will render the Canister unusable.
        {
            m_usable = false;
        }

        return *this;
    }

    // If the Canister is usable and the quantity is more than zero and if the sum of the quantity and the volume() is less than or equal to the capacity(),
    // add the quantity to the content volume, otherwise set usable flag attribute to false.
    Canister &Canister::pour(double quantity)
    {
        if (m_usable && quantity > 0.0 && capacity() >= (quantity + this->volume()))
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }

        return *this;
    }

    Canister &Canister::pour(Canister &C) // "C" is source, "this" is target
    {
        // Set the content name to the Canister argument using setContent().
        setContent(C.m_contentName);

        // if the volume() of the argument is greater than the capacity() minus the volume()

        if (C.volume() > (this->capacity() - this->volume()))
        {
            // Reduce the content volume of the argument by capacity() minus volume() and then set the content volume to capacity()
            C.m_contentVolume -= (this->capacity() - this->volume());
            this->m_contentVolume = capacity();
        }
        else
        {
            // else pour the content volume of the argument using pour() method and set the content volume of the argument to 0.0.
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }

        // return the reference of the current object at the end.
        return *this;
    }

    std::ostream &Canister::display() const
    {
        cout.setf(ios::fixed);
        cout.precision(1); // Prints all the number values with one digit after the decimal point
        cout.width(7);     // In 7 spaces prints the capacity
        cout << capacity();
        cout << "cc (" << m_height << "x" << m_diameter << ") Canister";

        if (!m_usable)
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr)
        {
            cout << " of ";
            cout.width(7);
            cout << volume() << "cc   " << m_contentName;
        }

        cout.unsetf(ios::fixed);

        return cout;
    }

}