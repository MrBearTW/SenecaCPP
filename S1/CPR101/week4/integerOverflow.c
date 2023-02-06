#include <stdio.h>		// compiled for x64, On the menu bar, choose Build > Configuration Manager.
#include <stdbool.h>	// need this for use of booleans under C99 
#include <limits.h>		// POSIX standard for data type limits on this system.
#include <stdint.h>		// integer types per http://en.cppreference.com/w/c/types/integer

// SCHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX(C99) – maximum possible value of signed integer types: signed char, signed short, signed int, signed long, signed long long. Similarly, _MIN.


int main(void)
{
	int_fast8_t gdxg;
	short mid, low = 10000, high = 20000; // test overflow bug
	short sum = 0;		// running total
	long amount = 0;	// user input
	char c;				// error handling
	int i, j;
	int scanfReturn = 0; // input return value

	//	mid = (high + low) / 2; // bug
	/* The intermediate value of two integers (high + low) is an int. The default width for int on our VS platform is 32-bits or 2.1+ billion.
	So if high + low are short data types (16-bit), they will not overflow the intermediate value (32-bit). Everything appears fine and there is no obvious bug.

	However, if mid/low/high are all int types and the sum of low+high > INT_MAX, overflow occurs.

	int mid;
	int       low=1000000000;
	int      high=2000000000;
	mid = (high + low) / 2; // bug
	mid should be 1500000000 It is -647483648
	mid = low + (high - low) / 2; // fix
	mid should be 1500000000 It is 1500000000

	// casting to unsigned works if high & low are signed integers
	mid = (unsigned int)(high + low) /2;

	but, if they are both unsigned, then we are back to the overflow problem when low+high > UINT_MAX
	*/

	/* Print limits of integers
	Note use of %u in format string to indicate "unsigned". */

	printf("On the VS menu bar, choose Build > Configuration Manager...\nEven selecting x64 instead of x86 still results in a 32-bit integer.\nSize of int is platform and compiler dependent.\n\n");
	printf("sizeof(int)  =  %d bytes X 8 bits per byte = %d-bit width\n", sizeof(int), (sizeof(int) * 8 ));
	printf("INT_MAX      =  %d\n", INT_MAX);
	printf("INT_MIN      = %d\n", INT_MIN);
	//printf("UINT_MAX     =  %u\n", UINT_MAX);
	printf("\n");

	/* Print limits of long integers, signed and unsigned.  LEFT SIDE
	Note use of %ld in format string to specify "long" decimal. */

	/* Print limits of short integers, signed and unsigned.  RIGHT SIDE
	Note use of %hd in format string to indicate "short" decimal. */

	printf("sizeof(long)  =  %d bytes", sizeof(long));
	printf("\t\tsizeof(short) = %d bytes\n", sizeof(short));
	printf("LONG_MAX      =  %ld", LONG_MAX);
	printf("\t\tSHRT_MAX      =  %hd\n", SHRT_MAX);
	printf("LONG_MIN      = %ld", LONG_MIN);
	printf("\t\tSHRT_MIN      = %hd\n", SHRT_MIN);
	printf("\n");
/*
	printf("short mid, low, high;\t// Demonstration of binary search bug.\n");

	mid = (short)(high + low) / 2;
	printf("mid = (low + high) / 2;\t// low=%d  high=%d\n\t\t\t\/\/ mid should be 15000  It is %d \n", low, high, mid);
	low = mid; // new low is previous mid
	printf("low = mid;\t\t// new low to simulate search in upper half\n");
	mid = (short)(high + low) / 2;
	printf("mid = (low + high) / 2;\t// low=%d  high=%d;\n\t\t\t\/\/ mid should be 17500 It is %d\n\t\t\t   (low + high) overflowed   %d \n", low, high, mid, (short)(high + low));
	printf("\n");
*/
	printf("Add positive or negative values to a short integer to cause overflow\n");
	printf("End program with Ctrl-C\n");
	printf("\t\t short\tbinary value\n");

	while (scanfReturn >= 0)  // prompt until user kills program with Ctrl-C or EOF
	{ 
		// print short and binary values in columns
		printf("\t\t% 06hd\t", sum);
		for (i = 15; i >= 0; i--)
		{
			j = sum >> i;
			if (j & 1)
				printf("1");
			else
				printf("0");
		}

		/*
		scanf() returns the number of arguments of data type(s) successfuly read 
		[ 0 = these are not the droids you're looking for] ;
		all whitespace is stripped including \n so empty input of Return key only
		causes buffer to continue waiting for non-whitespace input
		-- a user interface issue with scanf()
		*/

		printf("\nAdd +/- value  > "); // prompt for input to add +/- value to sum
		scanfReturn = scanf("%d", &amount);
		if (scanfReturn > 0)
		{ // if a number was entered
			sum += amount;
		}
		else if (scanfReturn == 0)
		{  // no numeric input returned from above scanf, empty buffer, give user diagnostic msg
			printf("%d ==> ", scanfReturn);
			while ((c = getchar()) != '\n') { printf("%c", c); };
			printf(" is not a number. Press Ctrl-C to end program.\n");
		}
		else // scanf returned -1 
		{	 // indicating EOF from redirected stdin (text file) 
			 // or keyboard (F6 Enter F6 Enter F6 Enter || Ctrl-Z Enter Ctrl-Z Enter Ctrl-Z Enter ) appears as ^Z\n^Z\n^Z\n 
			printf("EOF %d \n", scanfReturn);
		}
	}
	return 0;
}
