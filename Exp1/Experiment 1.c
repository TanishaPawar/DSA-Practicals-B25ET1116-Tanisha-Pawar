// Experiment No: 01 
// Title: Perform following String operations: a. substring b. palindrome c. compare d. copy e. reverse.
// Aim: Perform following String operations with and without pointers to arrays (without using the library functions): a. substring, b. palindrome c. compare d. copy e. Reverse.

#include <stdio.h>

int main() {
    int opt;
    // 1
    char str[50], sub[50];
    int start, len1, i1;
    // 2
    char word[20];
    int len2=0, i2, flag;
    // 3
    char str1[50], str2[50];
    int i3=0, n3;
    // 4
    char s1[50], s2[50];
    int i4, n4;
    // 5
    char st1[50];
    int len5=0, i5;
    
    printf("Enter Operation: \n1. Substring \n2. Palindrome \n3. Compare \n4. Copy \n5. Reverse\n");
    printf("Operation: ");
    scanf("%d", &opt);
    
    switch(opt){
        case 1: // SUBSTRING
        // Pneumonoultramicroscopicsilicovolcanoconiosis
        
            printf("Enter string: ");
            scanf("%s", str);
            printf("Enter starting index: ");
            scanf("%d", &start);
            printf("Enter length: ");
            scanf("%d", &len1);
        
            for(i1 = 0; i1 < len1 && str[start + i1] != '\0'; i1++)
            {
                sub[i1] = str[start + i1];
            }
            sub[i1] = '\0';
            printf("Substring = %s\n", sub);
            
        break;
        
        case 2: // PALINDROME
        // level, radar, racecar
            int flag = 1;
            printf("Enter Word: ");
            scanf("%s", &word);
            printf("Your Word: %s\n", word);
           
            while(word[len2] != '\0'){
                len2++;
            }
           
            for(i2=0; i2<(len2/2); i2++){
                if(word[i2]!=word[len2-i2-1]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                printf("Palindrome.");
            }
            else{
                printf("Not Palindrome.");
            }
            
        break;
        
        case 3: // COMPARE
        
            printf("Enter String 1: ");
            scanf("%s", &str1);
            printf("Enter String 2: ");
            scanf("%s", &str2);
           
            while(str1[i3] != '\0' && str2[i3] != '\0'){
                if(str1[i3] != str2[i3]){
                    break;
                }
                i3++;
            }
           
            if(str1[i3] == '\0' && str2[i3] == '\0'){
                printf("Strings are Equal");
            }
            else{
                printf("Strings are not Equal");
            }
            
        break;
        
        case 4: // COPY
        
            printf("Enter String 1: ");
            scanf("%s", &s1);
            printf("Enter String 2: ");
            scanf("%s", &s2);
           
            for(i4=0; s2[i4] != '\0'; i4++){
                s1[i4] = s2[i4];
            }
            printf("Copied String: %s", s1);
            
        break;
        
        case 5: // REVERSE
        
            printf("Enter string: ");
            scanf("%s", st1);
        
            while(st1[len5] != '\0')
                len5++;
        
            printf("Reversed string = ");
        
            for(i5=len5-1; i5>=0; i5--){
                printf("%c", st1[i5]);
            }
            printf("\n");
            
        break;
        
        default:
        printf("Invalid Input!\n");
    }
    
    return 0;
}