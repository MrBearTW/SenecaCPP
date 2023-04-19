# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# define FUZZ 0.00000001
# define CHILD 15
# define SENIOR 65

int main(void) {
	
	// Short cuts
	// pre-increment and post-increment
	int n = 42;
	printf("n=%d\n", n);
	printf("n++ = %d\n", n++);
	printf("++n = %d\n", ++n);
	printf("After all that n = %d\n", n);
	/*
	n = 42
	n++ = 42
	++n = 44
	After all that n = 44
	*/

	printf("n + 5 = %d\n", n += 5); // Same as n = n + 5
	// n = 49
	printf("n *= 2 =%d\n", n *= 2);
	// n = 98

	// relational operators compare values
	// ==, !=, <, >, >=
	// 0 = False, other = True
	printf("dose 2 == 2? %d\n", 2 == 2);
	printf("dose 2 < 2? %d\n", 2 < 2);
	printf("dose 2 <= 2? %d\n", 2 <= 2);
	printf("dose 2 != 2? %d\n", 2 != 2);

	printf("is a < b? %d\n", 'a'<'b');
	printf("is a < B? %d\n", 'a'<'B');

	printf("is 3.14 < 2.28? %d\n", 3.14 < 2.28);

	double oneThird = 1.0 / 3.0;
	double one1 = oneThird + oneThird + oneThird;
	double one2 = oneThird * 3;
	printf("one1 == 1.00 --> %d\n", one1 == 1.0);
	printf("one2 == 1.00 --> %d\n", one2 == 1.0);

	double oneTenth = 1.0 / 10.0;
	double one3 = (oneTenth + oneTenth) * 5;
	printf("one3 == 1.00 --> %d\n", (oneTenth + oneTenth) * 5 == 1.0);


	// Use fuzz to compare floating point values
	printf("one3 == 1 --> %d\n", one3 - 1.0 < FUZZ);


	// Logical operators
	// &&, ||, !
	// precedence ! before && before ||
	printf("1 and 1 --> %d\n", 1 && 1);
	printf("1 and 0 --> %d\n", 1 && 0);
	printf("0 and 1 --> %d\n", 0 && 1);
	printf("0 and 0 --> %d\n", 0 && 0);

	printf("1 or 1 --> %d\n", 1 || 1);
	printf("1 or 0 --> %d\n", 1 || 0);
	printf("0 or 1 --> %d\n", 0 || 1);
	printf("0 or 0 --> %d\n", 0 || 0);

	printf("NOT 5 --> %d\n", !5);

	// now, let's put them together ...
	int age = 66;
	double wealth = 235000.0;
	double salary = 45000;

	printf("This person make over 25000 per year and has a wealth or over quarter millions -> %d\n", salary > 25000.0 && wealth > 250000.0);
	printf("Is this a senior with a 40,000 income or more worth at least 200,000 in saving -> %d\n", age >= 65 && (salary >= 40000 || wealth >= 200000));

	// Children get 50% off ticket price
	// Senior get 25% off ticket price
	double ticketPrice = 15.0;
	printf("Your ticket price is %.2lf\n", ticketPrice - ((age <= CHILD) * ticketPrice * 0.5) - ((age >= SENIOR) * ticketPrice * 0.25));
	
	return 0;
}