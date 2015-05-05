//	Lab01.c	2014/06/16
#include <msp430.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab01.h"

int main(void)
{
  	// TERMINAL1("Signed int: 21000 + 200 = %d", 21000 + 200);
	// TERMINAL3("Largest Q4.4 = %f (0x%2x)", (((long)biggest_char)/16.0), biggest_char);

	/** CHAR-------------------------------------------------------------------
	 */

	TERMINAL("\n\r-----------------------------------\n\n\r*** CHAR ***\n");

  signed char biggest_char, next_char; // POSITIVE S CHAR
	signed char neg_char, next_neg_char; // NEGATIVE CHAR
	unsigned char biggest_uchar, next_uchar; // POSITIVE U CHAR

  next_char = 1;						// Positive S char
  biggest_char = 1;
  while((next_char <<= 1) > 0)
  {
    biggest_char = (biggest_char << 1) + 1;;
  }

	TERMINAL2("Largest signed char = %d (0x%2x)", biggest_char);

  next_uchar = 1;						// Positive U char
  biggest_uchar = 1;
  while((next_uchar <<= 1) > 0)
  {
    biggest_uchar = (biggest_uchar << 1) + 1;;
  }

  TERMINAL2("Largest unsigned char = %u (0x%2x)", biggest_uchar);

	next_neg_char = 1;					// Negative char
	neg_char = 1;
	while((next_neg_char <<= 1) > 0)
	{
		neg_char = (neg_char << 1) + 1;;
	}

	TERMINAL2("Most negative signed char = %d (0x%2x)", next_neg_char);

	biggest_char = biggest_char + 1;

	TERMINAL1("Signed char overflow: 127 + 1 should = 128 but we got %d", biggest_char); // Char overflow

	/**INT-------------------------------------------------------------------
	 */

	signed int biggest_int, next_int; // POSITIVE S INT
	unsigned int biggest_uint, next_uint; // POSITIVE U INT
	signed int neg_int, next_neg_int; // NEGATIVE INT

	TERMINAL("\n\n\r*** INT ***\n");

    next_int = 1;						// Positive S int
    biggest_int = 1;
    while((next_int <<= 2) > 0)
    {
    	biggest_int = (biggest_int << 1) + 1;;
    }
	TERMINAL2("Largest signed int = %d (0x%2x)", biggest_int);

	next_uint = 1;						// Positive U int
	biggest_uint = 1;
	while((next_uint <<= 1) > 0)
	{
		biggest_uint = (biggest_uint << 1) + 1;;
	}
	TERMINAL2("Largest unsigned int = %u (0x%2x)", biggest_uint);

	next_neg_int = 1;					// Negative int
	neg_int = 1;
	while((next_neg_int <<= 1) > 0)
	{
		neg_int = (neg_int << 1) + 1;;
	}

	TERMINAL2("Most negative signed int = %d (0x%2x)", next_neg_int);

	TERMINAL1("Signed int overflow: 32,000 + 1,000 should = 33,000 but we got %d", 32000 + 1000); // Int overflow

	/*LONG-------------------------------------------------------------------
	 */

	signed long int biggest_lint, next_lint; // POSITIVE S LONG INT
	unsigned long int biggest_ulint, next_ulint; // POSITIVE U LONG INT
	signed long int neg_lint, next_neg_lint; // NEGATIVE LONG INT
	TERMINAL("\n\n\r*** LONG ***\n");

	next_lint = 1;						// Positive S long int
	biggest_lint = 1;
	while((next_lint <<= 1) > 0)
	{
		biggest_lint = (biggest_lint << 1) + 1;;
	}
	TERMINAL2("Largest signed long int = %ld (0x%2x)", biggest_lint);

	next_ulint = 1;						// Positive U long int
	biggest_ulint = 1;
	while((next_ulint <<= 1) > 0)
	{
		biggest_ulint = (biggest_ulint << 1) + 1;;
	}
	TERMINAL2("Largest unsigned long int = %lu (0x%2x)", biggest_ulint);

	next_neg_lint = 1;					// Negative long int
	neg_lint = 1;
	while((next_neg_lint <<= 1) > 0)
	{
		neg_lint = (neg_lint << 1) + 1;;
	}

	TERMINAL2("Most negative signed long int = %ld (0x%2x)", next_neg_lint);

	TERMINAL1("Signed long int overflow: 2,000,000,000 + 1,000,000,000 should = 3,000,000,000 but we got %ld", 2000000000 + 1000000000); // Long overflow

	/*Fixed Point-------------------------------------------------------------------
	 */

	TERMINAL("\n\n\r*** FIXED POINT ***\n");

	TERMINAL3("Largest singed Q16.16 = %f (0x%2x)", (((long)biggest_lint)/65536.0), biggest_lint);
	TERMINAL3("Most negative singed Q16.16 = %f (0x%2x)", (((long)next_neg_lint)/65536.0), next_neg_lint);

	/*Floating Point-------------------------------------------------------------------
	 */

	TERMINAL("\n\n\r*** FLOATING POINT ***\n");

	float f = 0.02f;
	float sum = 0.0;
	int i;
	for (i = 0; i < 100; ++i) sum += f;

	TERMINAL2("Rounding: If we take 0.02 and add it up 100 times we should get 2, however we get %f (0x%08lx)", sum);
	TERMINAL2("Rounding: However if we multiply 100 x 0.02 we do get %f (0x%08lx)", f * 100);

	float g = 0.03f;
	float sum0 = 0.0;
	int h;
	for (h = 0; h < 100; ++h) sum0 += g;

	TERMINAL2("Rounding: Similarly, if we add up 0.03 100 times we should get 3, but we get %f (0x%08lx)", sum0)
	TERMINAL2("Rounding: And if we instead multiply 100 x 0.03 we do get %f (0x%08lx)", g * 100);

	float sum1 = (0.000000001 + 2) - 2;
	float sum2 = 0.000000002 + (2 - 2);
	TERMINAL2("Operations: If we do (0.000000001 + 2) - 2 we should and do get %f (0x%08lx) ", sum1);
	TERMINAL2("Operations: However if we do 0.000000001 + (2 - 2) we should also get zero, however we get %f (0x%08lx)", sum2);
	float sum3 = (0.000000009 + 3) - 3;
	float sum4 = 0.000000009 + (3 - 3);
	TERMINAL2("Operations: Similarly, (0.000000009 + 3) - 3 and 0.000000009 + (3 - 3) should both equal 3, however the first is %f (0x%08lx)", sum3);
	TERMINAL2("Operations: And the second gives us (notice the hex values) %f (0x%08lx)", sum4);

/* SALAMI CUT PROGRESS

	float ff = 0.01f;
	float sumx = 0.0;
	float fraction = 0.0;
	float penny = 0.0;
	float dollar = 1.0;
	int countx = 0;

	for (i = 0; i < 100; i++) sumx += ff;

	fraction = dollar - sumx;

	while (penny > 0.01);
	{
		penny += fraction;
		countx++;
	}
	TERMINAL1("Salami count = %u", countx);
*/
	return 0;
}
