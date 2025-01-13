#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// int ftAtoi(char* s){
//     int i = 0;
//     int res;
//     if (s[i] == '-'){
//         i++;
//     }
//     while(s[i] >= '0' && s[i] <= '9'){
//         res = res * 10 + s[i] - '0';
//         i++;
//     }
//     return res;
// }

void addNum(char* s1, char* s2){
    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    char* res = (char*)malloc(100);
    int i = 0;
    int num = 0;
    int extra = 0;
    while(len1 >= 0 && len2 >= 0){
        num = s1[len1] - '0' + s2[len2] - '0' + extra;
        if (num > 9){
            extra = 1;
            num -= 10;
        }
        else
            extra = 0;
        res[i] = num + '0';
        i++;
        len1--;
        len2--;
    }
    while(len1 >= 0){
        res[i] == s1[len1];
        i++;
        len1--;
    }
    while(len2>= 0){
        res[i] == s1[len2];
        i++;
        len2--;
    }
    if (extra == 1)
         res[i] = 1 + '0';

    // printf("ReS %s\n", res);
    int len = strlen(res) - 1;
    while(res[len] >= '0'&& res[len] <='9'){
        write(1, res + len, 1);
        len--;
    }
}


int main(){
    char str1[] = "-456";
    char str2[] = "-789";
    if (str1[0] == '-' && str2[0] == '-'){
        write(1, "-", 1);
        addNum(str1 + 1, str2 + 1);
    }
    if (str1[0] == '-' && str2[0] != '-'){
        subtractNum(str2 + 1, str2);
    }
    if (str1[0] != '-' && str2[0] == '-'){
        subtractNum(str1, str2 + 1);
    }
    if (str1[0] != '-' && str2[0] != '-'){
        addNum(str1, str2);
    }
    printf("\nCORRECT: %d\n", atoi(str1) + atoi(str2));
}