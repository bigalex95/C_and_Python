// demolib.c
#include <stdio.h>
#include "demolib.h"

unsigned long cfactorial_sum(char num_chars[]) {
	unsigned long fact_num;
	unsigned long sum = 0;

	for (int i = 0; num_chars[i]; i++) {
		int ith_num = num_chars[i] - '0';
		fact_num = factorial(ith_num);
		sum = sum + fact_num;
	}
	return sum;
}

unsigned long ifactorial_sum(long nums[], int size) {
	unsigned long fact_num;
	unsigned long sum = 0;
	for (int i = 0; i < size; i++) {
		fact_num = factorial(nums[i]);
		sum += fact_num;
	}
	return sum;
}

unsigned long factorial(long n) {
	if (n == 0)
		return 1;
	return (unsigned)n * factorial(n - 1);
}

typedef unsigned int Color32;

inline Color32 Color32Reverse(Color32 x)
{

	return
		// Source is in format: 0xAARRGGBB
		((x & 0xFF000000) >> 24) | //______AA
		((x & 0x00FF0000) >> 8) | //____RR__
		((x & 0x0000FF00) << 8) | //__GG____
		((x & 0x000000FF) << 24);  //BB______
								   // Return value is in format:  0xBBGGRRAA
}