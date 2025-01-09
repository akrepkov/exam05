#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_itoa(int num){
	int len = 0;
	if (num <= 0)
		len += 1;
	while(num > 10){
		num = num / 10;
		len ++;
	}
	printf("Len %d\n", len);
	return (len);
}

int ft_atoi(char *str){
	int i = 0;
	int num = 0;
	int sign = 1;

	if (str[i] == '-')
		sign = -1;
	while(str[i] >='0' && str[i] <= '9' && str[i]){
		num = num * 10 + str[i] - '0';
		i++;
	}
	char *new = itoa(num);
	write(1, new, ft_itoa(num));
	return (num * sign);
}



int main(int argc, char **argv){
	(void)argc;
	if (argc == 3) {
		int n1 = ft_atoi(argv[1]);
		int n2 = ft_atoi(argv[2]);
		//printf(" Number %d and %d\n", n1, n2);
	}

	return 0;

}