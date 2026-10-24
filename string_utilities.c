#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//number 1
char* print_any_base(unsigned long num, unsigned int base){
    char* out = malloc(num);
    char* out2 = malloc(num);
    int i = 0;
    if(base < 2 || base > 36){
    	out = "Illegal base";
    	return out;
    }
    if(num == 0){
    	*out = '0';
    	return out;
    }
    char symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    while(num > 0){
    	long whole = num / base;
    	long remainder = num % base;
    	*out2 = symbols[remainder];
    	out2++;
    	i++;
    	num = whole;
    }
    out2 = out2 - 1;
    int j = i;
    while(i >= 0){
    	*out = *out2;
    	out = out + 1;
    	out2 = out2 - 1;
    	i--;
    }
    *out = '\0';
    out = out - j-1;
    return out;
    
}

//number 2
unsigned int count_vowels(char *str){
    int count = 0;
    while (*str != '\0'){
        if(*str == 'a' || *str == 'A' 
        || *str == 'e' || *str == 'E' 
        || *str == 'i' || *str == 'I'
        || *str == 'o' || *str == 'O'
        || *str == 'u' || *str == 'U'){
            count++;
        }
        str++;
    }

    return count;
}

//number 3
char *reverse_words(char *str){
    char *reverse = malloc(strlen(str + 1));
    int start = strlen(str) - 1;
    int end = strlen(str) - 1;
    int index = 0;
    int pointer;
    
    while(start >= 0){
        if(str[start] == ' '){
            pointer = start + 1;
            while(pointer <= end){
                reverse[index] = str[pointer];
                index++;
                pointer++;
            }
            reverse[index] = ' ';
            index++;
            end = start - 1;
        }
        start = start - 1;
    }
    pointer = 0;
    while(pointer <= end){
        reverse[index] = str[pointer];
        pointer++;
        index++;
    }
    reverse[index] = '\n';
    return reverse;  
}

//number 4
void *rotate_string_in_place(char *str, unsigned int disp){
    int remainder = disp % 26;
    while(*str != '\0'){
    	if(*str >= 'A' && *str <= 'Z'){
    		int total = *str + remainder;
    		if(total > 'Z'){
    			total = total - 'Z';
    			total = total + 'A' - 1;
    		}
    		printf("%c", total);
    	}
    	else if(*str >= 'a' && *str <= 'z'){
    		int total = *str + remainder;
    		if(total > 'z'){
    			total = total - 'z';
    			total = total + 'a' - 1;
    		}
    		printf("%c", total);
    	}
    	else if(*str == ' '){
    		printf("%s", " ");
    	}
    	else{
    		printf("%c", *str);
    	}
    str++;
    }
    printf("\n");
}

int main(){
    
    printf("%s\n", "Number 1");
    printf("%s\n", print_any_base(1234, 2));
    printf("%s\n", print_any_base(1234, 3));
    printf("%s\n", print_any_base(1234, 16));
    printf("%s\n", print_any_base(1234, 36));
    printf("%s\n", print_any_base(12345678, 23));
    printf("%s\n", print_any_base(0, 25));
    printf("%s\n", print_any_base(100, 44));
    
    printf("\n%s\n", "Number 2");
    printf("%d\n", count_vowels("Hello World"));
    printf("%d\n", count_vowels(""));
    printf("%d\n", count_vowels("qwertyuiopasdfghjklzxcvbnm"));
    printf("%d\n", count_vowels("EduCAtion"));
    printf("%d\n", count_vowels("The quick brown fox jumped over the lazy dog"));
    
    printf("\n%s\n", "Number 3");
    printf("%s", reverse_words("Hello World"));
    printf("%s", reverse_words(""));
    printf("%s", reverse_words("HeyYou"));
    printf("%s", reverse_words("What is the question?"));
    printf("%s", reverse_words("It is what it is."));
    
    printf("\n%s\n", "Number 4");
    rotate_string_in_place("Hello World", 5);
    rotate_string_in_place("", 100);
    rotate_string_in_place("Hey You!", 11);
    rotate_string_in_place("gcc -c hw.c -o hw", 2413);
    rotate_string_in_place("Hello", 0);
    rotate_string_in_place("Hello", 26);
    
}

