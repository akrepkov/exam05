/*Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int isprime(int factor){
	int i = 2;
	while (i < factor){
		if (factor % i == 0)
			return 0;
		i++;
	}
	return 1;
}

void prime(int a){
	int prime = 2;
	while(prime <= a){
		if (a%prime == 0 && isprime(prime)){
			printf ("%d ", prime);
			a = a / prime;
		}
		else
			prime++;
	}
	printf("\n");
}

int main(){
	int a = 8333325;
	prime(a);
	return 0;
}