/* limits.c - print limits of integer types.

   You can use this program to find out if your system's int integers
   are same as or longer than its short integers.

   matrix compilation:
   alias gcc='/usr/local/gcc/10.2.0/bin/gcc'
   gcc -lm -Wextra -Wall sizeof_Data_Types.c -o sizeof_Data_Types
   gcc -lm <== switch needed for math library.
 */

/* limits.h is an include file defined by the POSIX standard which
   tells us about various limits on our system, including those of the
   integer types. */

#include <limits.h> // contains _MAX _MIN values
#include <float.h> // macros for floating - point types
#include <math.h>
#include <stdbool.h> // Boolean data type
#include <stdint.h>  // Standard Integer Types
#include <stdio.h>

int main()
{
	bool isNotZero;

	/* Print limits of boolean.  Note use of u
   character in format strings to indicate "unsigned". */

	printf("sizeof(bool)  = %11ld byte,   %ld bits\n", sizeof(bool), sizeof(bool) * 8);
	printf("sizeof(true)  = %11ld bytes,  %ld bits with value of %d\n", sizeof(true), sizeof(true) * 8, true);
	printf("sizeof(false) = %11ld bytes,  %ld bits with value of %d\n", sizeof(false), sizeof(false) * 8, false);
	isNotZero = 12345; // any non-zero integer assigned to a bool data type results in true. 
	printf("bool isNotZero;\nisNotZero = 12345; // assign non-zero value integer to bool data type\nif (isNotZero) is %d or %s\n", isNotZero, isNotZero ? "true" : "false");
	isNotZero = 0; // a zero integer assigned to a bool data type results in false. 
	printf("isNotZero = 0    ; // assign     zero value integer to bool data type\nif (isNotZero) is %d or %s\n", isNotZero, isNotZero ? "true" : "false");

	/* Print limits of characters, signed and unsigned. */

	printf("\nsizeof(char)  = %+11ld bytes,  %ld bits\n", sizeof(char), sizeof(char) * 8);
	printf("CHAR_MAX      = %+11d\n", CHAR_MAX);
	printf("CHAR_MIN      = %+11d\n", CHAR_MIN);
	printf("SCHAR_MAX     = %+11u\n", SCHAR_MAX);
	printf("UCHAR_MAX     = %+11u\n", UCHAR_MAX);

	/* Print limits of integers, signed and unsigned.  Note use of u
   character in format strings to indicate "unsigned". */

	printf("\nsizeof(int)   = %+11ld bytes,  %ld bits\n", sizeof(int), sizeof(int) * 8);
	printf("INT_MAX       = %+11d\n", INT_MAX);
	printf("INT_MAX + 1   = %+11d  overflow\n", INT_MAX + 1);
	printf("INT_MIN       = %+11d\n", INT_MIN);
	printf("INT_MIN - 1   = %+11d  overflow\n", INT_MIN - 1);

	printf("\nsizeof(unsigned int) = %4ld bytes,  %ld bits\n", sizeof(unsigned int), sizeof(unsigned int) * 8);
	printf("UINT_MAX      = %+11u\n", UINT_MAX);
	printf("UINT_MAX + 1  = %+11u  overflow\n", UINT_MAX + 1);
	// there is no unsigned int minimum constant; by definition, min is zero.
	//printf("INT_MIN       = %+11d\n", UINT_MIN);
	//printf("INT_MIN - 1   = %+11d  overflow\n", UINT_MIN - 1);

	/* Print limits of short integers, signed and unsigned.  Note use
	   of hd character in format strings to indicate "short". */

	printf("\nsizeof(short) = %+11ld bytes,  %ld bits\n", sizeof(short), sizeof(short) * 8);
	printf("SHRT_MAX      = %+11hd\n", SHRT_MAX);
	printf("SHRT_MIN      = %+11hd\n", SHRT_MIN);

	/* Print limits of long integers, signed and unsigned.  Note use
	   of l character in format strings to specify "long". */

	printf("\nsizeof(long)  = %+11ld bytes,  %ld bits\n", sizeof(long), sizeof(long) * 8);
	printf("LONG_MAX      = %+11li\n", LONG_MAX);
	printf("LONG_MIN      = %+11li\n", LONG_MIN);

	/* Print limits of long long integers, signed and unsigned.  Note use
		   of ll characters in format strings to specify "long long" type. */

	printf("\nsizeof(long long)  = %ld bytes, %ld bits\n", sizeof(long long), sizeof(long long) * 8);
	printf("LLONG_MAX          = %+11lld\n", LLONG_MAX);
	printf("LLONG_MIN          = %+11lld\n", LLONG_MIN);

	/* Print Minimum-width integer types.  Note use of u
character in format strings to indicate "unsigned". */
	printf("\nint is preferred when the maximum value the variable must hold\nwill ALWAYS fit within the range of a 2 byte, 16-bit \nsigned integer, a short, the minimum int size in C.\ne.g. counting from 1 to 30000, arrays with <16,000 elements.\nThis will cover the vast majority of use cases.\n\nC99 guarantees variables to be a particular size across platforms:\n~ in general use, declare int##_t where ## is bit width: 8, 16, 32, 64\n~ for performance, use int_FAST##_t where ## is bit width: 8, 16, 32, 64\n~ for memory conservation over performance, use int_LEAST##_t\n  when allocating a great many variables on a memory constrained system.\n");

	/* see https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/ */

	/* Print size of floating point types */
	float fltTest;
	printf("\nsizeof(float)  = %ld bytes, %d significant bits\n", sizeof(float), FLT_MANT_DIG);
	printf("significant digits accuracy = min. %u positions of whole + fractional parts. i.e. the number of base-10 digits that can be represented without change after rounding.\ne.g. 0.123456 or 123456.0 or 123.456\n", FLT_DIG);
	printf("maximum value    = %.0f\n", pow(FLT_RADIX, FLT_MANT_DIG) );
	
	fltTest = pow(2, FLT_MANT_DIG);
	printf(    "maximum          = %.12f  whole values added to max are rounded\n", fltTest);
	for (int i = 1; i <= 5; i++)
	{
		printf("plus 1.000000000 = %.12f\n", fltTest += 1.000000000);
	}
	for (int i = 1; i <= 5; i++)
	{
		printf("plus 1.111111111 = %.12f\n", fltTest += 1.111111111);
	}
	fltTest = pow(2, FLT_MANT_DIG) * .1;
	printf("maximum * .1     = %.12f  values vary by 0.125 or 1/8\n", fltTest);
	for (int i = 1; i <= 5; i++)
	{
		printf("sub  1.111111111 = %.12f\n", fltTest -= 1.111111111);
	}
	for (int i = 1; i <= 10; i++)
	{
		printf("plus 1.111111111 = %.12f\n", fltTest += 1.111111111);
	}

	double  dblTest;
	printf("\nsizeof(double) = %ld bytes, %d significant bits\n", sizeof(double), DBL_MANT_DIG);
	printf("maximum value  = 2^%d = %.0f\n", DBL_MANT_DIG, pow(2, DBL_MANT_DIG));
	printf("significant digits accuracy = %u regardless of decimal point's position (similar to float)\n", DBL_DIG);

	printf("\ndoubles with multiple calcs may result in some values drifting or becoming less accurate.\n");
	double oneThird;
	oneThird = 1.0 / 3.0;

	dblTest = 1.0;
	printf("\ndouble   1 is %.20f\n", dblTest);
	printf("              -.----+----1----+-????\n");
	for (int i = 1; i <= 10; i++)
	{
		dblTest = dblTest / 3;
		printf("double  /3 is %.20f\n", dblTest);
	}

	dblTest = 1.0;
	printf("\ndouble 1.0000 is %25.20f\n", dblTest);
	printf("                    -.----+----1----+-????\n");
	for (int i = 1; i <= 10; i++)
	{
		dblTest = dblTest * 2.0625;
		printf("double*2.0625 is %25.20f\n", dblTest);
	}

	dblTest = oneThird;
	printf("\ndouble .3 is %.20f\n", dblTest);
	printf("             -.----+----1----+-????\n");
	for (int i = 1; i <= 20; i++)
	{
		dblTest += oneThird; // cumulative addition of 1/3
		printf("double += is %.20f\n", dblTest);
	}

	dblTest = 0.12345678901234567890;
	printf("\ndouble         is %.20f after assignment of 0.12345678901234567890\n", dblTest);
	printf("                  -.----+----1----+-????\n");
	for (int i = 1; i <= 20; i++)
	{
		dblTest *= 10.0; // cumulative multiplication by ten
		printf("double *= 10.0 is %.20f\n", dblTest);
	}

	printf("\nrounding to 2 decimals is platform/compiler dependent\nSee https://www.exploringbinary.com/inconsistent-rounding-of-printed-floating-point-numbers/\nand https://floating-point-gui.de/\n");
	// see also https://stackoverflow.com/questions/25104883/round-positive-value-half-up-to-2-decimal-places-in-c
	printf("the following works because 0.375 can be represented exactly in binary\n");
	printf("Binary approx of decimal\t%%.2f\t+.0001\ttrunc((dblTest+.0051)*100)*.01\n");
	dblTest = 0.375;
	for (int i = 0; i <= 25; i++)
	{
		{
			printf("%.20f\t\t%.2f\t%.2f\t%.2f\t%.20f\n", dblTest, dblTest, dblTest + .0001, trunc((dblTest + .0051) * 100) * .01, dblTest + .0051);
		}
		dblTest += 0.375;
	}
	printf("\nprintf rounding does not always work because +0.251 is not always exact in binary\nwhen printing, nudge by +.0001 when rounding to 2 decimal (or -.0001 for negatives).\nThis prevents the problematic half-way value n.nn49999 which is a close as binary gets to n.nn5.\n");
	printf("Binary approx of decimal\t%%.2f\t+.0001\ttrunc((dblTest+.0051)*100)*.01\n");
	dblTest = 1.000;
	for (int i = 1; i <= 25; i++)
	{
		printf("%.20f\t\t%.2f\t%.2f\t%.2f\t%.20f\n", dblTest, dblTest, dblTest + .0001, trunc((dblTest + .0051) * 100) * .01, dblTest + .0051);
		dblTest += 0.251;
	}
	printf("\nadd 0.01 works, binary is close enough, rounding to .nn works in all cases\n");
	printf("Binary approx of decimal\t%%.2f\t+.0001\ttrunc((dblTest+.0051)*100)*.01\n");
	dblTest = 2.000;
	for (int i = 1; i <= 25; i++)
	{
		printf("%.20f\t\t%.2f\t%.2f\t%.2f\t%.20f\n", dblTest, dblTest, dblTest + .0001, trunc((dblTest + .0051) * 100) * .01, dblTest + .0051);
		dblTest += 0.01;
	}
	printf("\nadd 0.00n does not work as expected for the problematic half-way value n.nn49999\n");
	double increment = .000;
	for (int j = 0; j <= 10; j++)
	{
		increment += .001;
		printf("Binary of +=%.3f decimal\t%%.2f\t+.0001\ttrunc((dblTest+.0051)*100)*.01\n", increment);
		dblTest = 3.000;
		for (int i = 0; i <= 11; i++)
		{
			printf("%.20f\t\t%.2f\t%.2f\t%.2f\t%.20f\n", dblTest, dblTest, dblTest + .0001, trunc((dblTest + .0051) * 100) * .01, dblTest + .0051);
			dblTest += increment;
		}
	}
	printf("\nsimulate value of a half cent in binary.\n");
	printf("Binary approx of decimal\t%%.2f\t+.0001\ttrunc((dblTest+.0051)*100)*.01\n");
	dblTest = 8.995;
	for (int i = 0; i <= 10; i++)
	{
		{
			printf("%.20f\t\t%.2f\t%.2f\t%.2f\t%.20f\n", dblTest, dblTest, dblTest + .0001, trunc((dblTest + .0051) * 100) * .01, dblTest + .0051);
		}
		dblTest += 0.01; // simulating the adding of one cent.
	}

	printf("\n\n Use mouse to scroll and view from the top.\n A change to the window's Properties, Options, Buffer size may be required.\n");

	return 0;
}