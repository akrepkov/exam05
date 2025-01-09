#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s){
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}


void mult(char *s1, char* s2){
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int max_len = len1 + len2;
    char* result = (char*) malloc(max_len + 1);
    int pos = 0;
    for (int m = 0; m <= max_len; m++){
        result[m] = '0';
    }
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        int dig1 = s1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--) {
            int dig2 = s2[j] - '0';
            pos = i + j + 1;
            int sum = (result[pos] - '0') + (dig1 * dig2) + carry;
            result[pos] = (sum % 10) + '0';
            carry = sum / 10;
        }
		result[pos -1] = (result[i] - '0') + carry + '0';
	}
    size_t start_pos = 0;
    while (start_pos <= max_len - 1 && result[start_pos] == '0')
        start_pos++;
	while (start_pos <= max_len - 1){
    	write(1, &result[start_pos],1);
		start_pos++;
	}
    write(1, "\n", 1);
}



int main(){
	char * s1 = "123";
	char* s2 = "456";
	mult(s1,s2);
	return 0;
}


/*
strlen s1
strlen s2
max len = len1 + len2 + 1;
fill it with 0s
while (int i >= 0){
	carry = 0;
	s1 to dig1;
	while (int j >= 0)
	{
		s2 to dig2;
		pos = i + j + 1;
		sum = char to dig + dig1 * dig2 + carrt
		res = sum%10 to char
		carry = sum/10
		j--
	}
	res[pos - 1] = to dig + carry to char
}

*/