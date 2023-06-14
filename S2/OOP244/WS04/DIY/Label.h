/*/////////////////////////////////////////////////////////////////////////
                            Workshop 4 Part 2
Full Name  :CHI-WEI PERNG
Email      :cperng@myseneca.ca
Student ID#:121967228
Section    :NGG
Date       :2023/06/13

/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
namespace sdds
{
    class Label
    {
    private:
        char frameSymbol[9];
        char *oneLineText;

    public:
        // Creates an empty label and defaults the frame to "+-+|+-+|"
        Label();

        // Creates an empty label and sets the frame to the frameArg argument.
        Label(const char *frameArg);

        // Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument. Note that you must keep the content dynamically even though it should never be more than 70 characters.
        Label(const char *frameArg, const char *content);

        // destructor
        // Makes sure there is no memory leak when the label goes out of scope.
        ~Label();

        // Reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample
        void readLabel();

        // Prints the label by drawing the frame around the content ad shown in the Execution sample. Note that no newline is printed after the last line and cout is returned at the end.
        std::ostream &printLabel() const;
    };

}
#endif // !SDDS_LABEL_H