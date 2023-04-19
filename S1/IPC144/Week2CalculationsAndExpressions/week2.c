#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 1, b = 2, c;
	double d1 = 1, d2 = 3, d3, d4;

	c = a + b;
	//printf("c = %d\n",c);

	c = a / b;
	//printf("c = %d\n", c); // 0

	
	// floating point arithmetic
	d3 = d1 / d2;
	printf("d3 = %lf\n",d3); // 0.333333
	printf("d3(.16) = %.16lf\n", d3); // d3(.16) = 0.3333333333333333
	printf("d3(.18) = %.18lf\n", d3); // d3(.18) = 0.333333333333333315
	
	// integer arithmetic expression
		
	
	// mixed mode expression
	d4 = 1.0 + 3 / 4 - 6.0 / 3;
	printf("d4(.18) = %.18lf\n", d4); // d4(.18) = -1.000000000000000000
	d4 = 1.0 + 3.0 / 4 - 6.0 / 3;
	printf("d4(.18) = %.18lf\n", d4); // d4(.18) = -0.250000000000000000
	d4 = 1.0 + 3 / 4. - 6.0 / 3;
	printf("d4(.18) = %.18lf\n", d4); // d4(.18) = -0.250000000000000000

	// 37832 s = ? h ? m ? s
	

	int t0 = 38732, t1, t2, t3;
	//t1 = t0 / 3600;
	//t2 = (t0 - t1*3600) / 60;
	t3 = t0 % 60;
	//printf("t1 = %d\n", t1); // 
	//printf("t2 = %d\n", t2); // 
	printf("t3 = %d\n", t3);  
	printf("t3(.18) = %.18lf\n", t3); // t3(.18)

	return 0;
}