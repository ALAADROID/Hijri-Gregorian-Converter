#include <stdio.h>
#include <stdbool.h>

// ANSI escape sequences
#define BOLD "\033[1m"
#define LIGHT "\033[2m"
#define RESET "\033[0m"

// }onversion math 
void conversionOpertaion(int mode, int oldDate){
    int newDate;
    
    switch(mode){
        case 1: // Gregorian to Hijri
            newDate = (int)((oldDate - 622) / 0.97);
            printf("The Hijri date for that: %d", newDate);
        break;
        
        case 2: // Hijri to Gregorian (+0.5 rounding)
            newDate = (int) ((oldDate * 0.97) + 622 + 0.5);
            printf("The Gregorian date for that: %d", newDate);
        break;
        
        default:
            printf("Enter valid date please.");
        break;
    }
}

int main(){
    
    char newConversion = 'y';
    int mode, dateInput;
    
    puts("\n┌───────────────────────────┐\n│ Hijri Gregorian converter │\n└───────────────────────────┘");  

    // Main app loop
    while (newConversion == 'y' || newConversion == 'Y'){
        
        char check = 0;
        printf("\nSelect the mode:\n"LIGHT"1-Gregorian to Hijri.\n2-Hijri to Gregorian.\n"RESET"Please select 1 or 2: ");
        
        // Accepts 1 or 2 followed directly by newline
        if(scanf("%d%c", &mode, &check) == 2 && check == '\n' && (mode == 1 || mode == 2)){
            switch(mode){
                case 1:
                    printf("Enter the Gregorian date: ");
                    // Ensures valid numeric entry and flushes trailing bad characters
                    while(scanf("%d%c", &dateInput, &check) != 2 || check != '\n'){
                        while(getchar() != '\n'); // Clear input buffer
                        printf("\n\033[31mError: Please don't enter characters: \033[0m");
                    }
                    conversionOpertaion(1, dateInput);
                    break;
                case 2:
                    printf("Enter the Hijri date: ");
                    while(scanf("%d%c", &dateInput, &check) != 2 || check != '\n'){
                        while(getchar() != '\n'); 
                        printf("\n\033[31mError: Please don't enter characters: \033[0m");
                    }
                    conversionOpertaion(2, dateInput);
                    break;
            }
            
            // Ask for another conversion round
            printf("\nIf you want to convert a new date enter 'y' if no 'n': ");
            scanf(" %c", &newConversion);
        
            // Validate continuation input choice
            while (newConversion != 'y' && newConversion != 'Y' && newConversion != 'N' && newConversion != 'n'){
                while(getchar() != '\n'); 
                printf("\n\033[31mError: Please enter 'y' for more conversion or 'n' to exit: \033[0m");
                scanf(" %c", &newConversion);
            }
            
            if (newConversion == 'n' || newConversion == 'N'){ break; }
            
        } else {
            // Flush buffer only if remaining invalid input is still pending
            if(check != '\n'){
                while(getchar() != '\n');
            }
            printf("\033[31mError: Please enter 1 for mode one or 2 for mode two: \033[0m");
        }
    
    }
  
    return 0;
}