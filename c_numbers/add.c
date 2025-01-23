#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// int ft_itoa(int num){
// 	int len = 0;
// 	if (num <= 0)
// 		len += 1;
// 	while(num > 10){
// 		num = num / 10;
// 		len ++;
// 	}
// 	printf("Len %d\n", len);
// 	return (len);
// }

// int ft_atoi(char *str){
// 	int i = 0;
// 	int num = 0;
// 	int sign = 1;

// 	if (str[i] == '-')
// 		sign = -1;
// 	while(str[i] >='0' && str[i] <= '9' && str[i]){
// 		num = num * 10 + str[i] - '0';
// 		i++;
// 	}
// 	char *new = itoa(num);
// 	write(1, new, ft_itoa(num));
// 	return (num * sign);
// }

char* adding(char* s1, char* s2){
	int len1 = strlen(s1) - 1;
	int len2 = strlen(s2) - 1;
	int len = strlen(s1) > strlen(s2) ? len1 : len2;
	char* res = (char*)malloc(sizeof(char) * (len + 2));
	len += 2;
	int i = 0, carry = 0;
	while (i < len){
		res[i] = '0';
		i++;
	}
	res[len] = '\0';
	i--;
	while(len1 >= 0 && len2 >= 0){
		int num = s1[len1] - '0' + s2[len2] - '0'+ carry;
		if (num > 9)
			carry = 1;
		else
			carry = 0;
		int dig = num % 10;
		res[i] = dig + '0';
		printf("NUM %s \n", res);
		i--; len1--; len2--;
	}
	return res;
}

char* subsubtract(char* s1, char* s2) {
	int len1 = strlen(s1) - 1;
	int len2 = strlen(s2) - 1;
	char* res = (char*)malloc(strlen(s1) + 2);
    memset(res, '0', strlen(s1) + 1);
	int k = len1;
    res[len1 + 1] = '\0';
    int borrow = 0, i = len1, j = len2;
    while (i >= 0) {
        int num1 = s1[i] - '0';
        int num2 = (j >= 0) ? s2[j] - '0' : 0;
        int sub = num1 - num2 - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res[k--] = sub + '0';

        i--;
        j--;
	}

    return res; // Adjust pointer to skip leading zeros
}

char* subtract(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int negative = 0;
    if (len1 < len2 || (len1 == len2 && strcmp(s1, s2) < 0)) {
        subsubtract(s2, s1);
    }
	else
		subsubtract(s1, s2);
    
}

int main(int argc, char **argv){
	char* s1 = "123";
	char* s2 = "4569";
	//printf("Res %s \n", adding(s1, s2));
	printf("Res %s \n", subtract(s1, s2));

	return 0;

}