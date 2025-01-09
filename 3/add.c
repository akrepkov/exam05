#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



int main (int argc, char **argv){
	if (argc == 3){
		int neg1 = 0, neg2 = 0;
		if (argv[1][0] == '-')
			neg1 = 1;
		if (argv[2][0] == '-')
			neg2 = 1;
				
		char *result = (char*)malloc(1024);
		if (neg1 == neg2)
		{
			int i = 0, j = 0, k = 0, carry = 0;
			while(argv[1][i]  !=  '\0') i++;
			while(argv[2][j]  !=  '\0') j++;
			i--;j--;
			while (i >= 0 || j >= 0 || carry){
				int digit1 = (i >= 0) ? argv[1][i--] - '0' : 0;
				int digit2 = (j >=0) ? argv[2][j--] - '0' : 0;
				int sum = digit1 +digit2 + carry;
				carry = sum/10;
				result[k++] = (sum % 10) + '0';
				printf("Carry: %d\n", carry);
			}
			result[k] = '\0';
			i = k - 1;
			char *final = (char *)malloc(k+1);
			for (int m = 0; m < k; m++){
				final[m] = result[i];
				printf("final[m]: %d\n", final[m]);
				i--;
			}
			final[k] = '\0';
			write(1, final, k);
			free(result);
			free(final);
		}
		else {
			char * pos = (neg1 = 1) ? argv[2] : argv[1];
			char * neg = (neg2 = 1) ? argv[1] : argv[2];
			printf("pos: %s\n", pos);
			printf("neg: %s\n", neg);
			int i = 0, j = 0, k = 0, carry = 0;
			while(pos[i] != '\0') i++;
			while(neg[j] != '\0') j++;
			i--;
			j--;
			while(i >= 0 || j >= 1 || carry){
				int digit1 = (i >= 0) ? pos[i] - '0' : 0;
				int digit2 = (j >= 1) ? neg[j] - '0' : 0;
				int sub = digit1 - digit2 - carry;
				carry = sub / 10;
				result[k++] =( sub % 10) + '0';
			}
			result[k] = '\0';
			i = k - 1;
			char *final = (char *)malloc(k+1);
			for (int m = 0; m < k; m++){
				final[m] = result[i];
				printf("final[m]: %d\n", final[m]);
				i--;
			}
			final[k] = '\0';
			write(1, final, k);
			free(result);
			free(final);
		}
	}
	return 0;
}


