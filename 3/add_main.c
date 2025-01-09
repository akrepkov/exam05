#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s) {
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

void large_number_addition(char *num1, char *num2){
	int len1 = ft_strlen(num1);
	int len2 = ft_strlen(num2);
	// int max = len1 + len2 + 2;
	char* res = (char*)malloc(100);
	int i = len1 - 1;
	int j = len2 -1;
	int k = 0;
	int carry = 0;
	while(i >= 0 || j >= 0 || carry){
		int dig1 = (i >= 0) ? num1[i] - '0' : 0;
		int dig2 = (j >= 0) ? num2[j] - '0' : 0;
		res[k] = ((dig1 + dig2 + carry) % 10) + '0';
		carry = (dig1 + dig2  + carry)  / 10;
		k++;
		i--;
		j--;
	}
	res[k] = '\0';
	while (res[--k] != '\0'){
		write(1, &res[k], 1);
	}
	
	
}



void large_number_subtraction(char *num1, char *num2){
	int len1 = ft_strlen(num1);
	int len2 = ft_strlen(num2);
	int max = len1 + len2 + 1;
    int max_len = len1 > len2 ? len1 : len2;
    char *res = (char *) malloc(max_len + 1);
	int i = len1 - 1;
	int j = len2 -1;
	int k = 0;
	int borrow = 0;
    while (i >= 0 || j >= 0 || (borrow && (i >= 0 || j >= 0))) {
        // Read the digits or 0 if we run out of digits
        int dig1 = (i >= 0) ? num1[i] - '0' : 0;  // Decrement first to access the current digit
        int dig2 = (j >= 0) ? num2[j] - '0' : 0;
		int sub = dig1 - dig2 - borrow;
		printf("check dig1 %d dig2 %d sub %d \n",dig1, dig2, sub);
		if (sub < 0){
			sub +=10;
			borrow = 1;
		}
		else
			borrow = 0;
		res[k] = sub + '0';
		k++;
		i--;
		j--;
	}
	// if (borrow == 1)
	res[k] = '\0';
	i = 0;
	char* final = (char *) malloc(max_len + 1);
	// while (i < k && res[i] == '0')
	// 	i++;
	while (res[--k] != '\0'){
		final[i] = res[k];
		i++;
	}
	i = 0;
	while(final[i] != '\0' && final[i] == '0')
		*final++;
	write(1, final, max_len + 1);
}


int main(int argc, char **argv) {
	if (argc == 3) {
		char * first;
		char * second;
		int neg1 = 0, neg2 = 0;
		if (argv[1][0] == '-')
			neg1 = 1;
		if (argv[2][0] == '-')
			neg2 = 1;
		char *num1 = neg1 ? argv[1] + 1 : argv[1];
		char *num2 = neg2 ? argv[2] + 1 : argv[2];
		int len1 = ft_strlen(num1);
		int len2 = ft_strlen(num2);
		if (len1 == len2){
			int i = 0;
			while(i < len1){
				if (num1[i] - '0' > num2[i] - '0')
					{first = num1; second = num2;
					break;}
				else if (num2[i] - '0' > num1[i] - '0')
					{first = num2;second = num1;
					break;}
				else
				{write (1, "0", 1);
				return 0;}
				i++;
			}
		}
		else{
			first = (len1 > len2) ? num1 : num2;
			second = (len1 < len2) ? num1 : num2; }
		printf("FIRST AND SECOND %s %s\n", first, second);
		if (neg1 == neg2){
			large_number_addition(num1, num2);
		} else {
			large_number_subtraction(first, second);
		}
	}
	return 0;
}
