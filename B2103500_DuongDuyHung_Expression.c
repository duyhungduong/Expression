#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//B2103500 Duong Duy Hung

const char *strInput;
int currentPos = 0;

//int checkExpression();
//int checkTerm(); 		
//int checkFactor();
//int getDigits();

int checkExpression() {
    int result = checkTerm();
    
    // Xu ly cac toan tu '+' va '-'
    while (strInput[currentPos] == '+' || strInput[currentPos] == '-') {
        char operator = strInput[currentPos];
        currentPos++;  // Bo qua toan tu da xu ly
        
        if (operator == '+') {
            result += checkTerm();
        } else if (operator == '-') {
            result -= checkTerm();
        }
    }
    return result;
}

int checkTerm() {
    int result = checkFactor();
    
    // Xu ly cac toan tu '*' va '/'
    while (strInput[currentPos] == '*' || strInput[currentPos] == '/') {
        char operator = strInput[currentPos];
        currentPos++;  // Bo qua toan tu da xu ly
        
        if (operator == '*') {
            result *= checkFactor();
        } else if (operator == '/') {
            int divisor = checkFactor();
            if (divisor == 0) {
                printf("Invalid Expression\n"); //Error: Loi chia cho '0'
                exit(1);
            }
            result /= divisor;
        }
    }
    return result;
}

int checkFactor() {
	//Xu ly cac so nguyen hoac bieu thuc trong dau ngoac don
    int result;
    if (strInput[currentPos] == '(') {
        currentPos++;  // Bo qua dau ngoac da xu ly '('
        result = checkExpression();
        if (strInput[currentPos] == ')') {
            currentPos++;  // Bo qua dau ngoac da xu l ')'
        } else {
            printf("Invalid Expression\n"); //Error: Thieu dau ngoac ')'
            exit(1);
        }
    } else {
        result = getDigits();
    }
    return result;
}

int getDigits() {
	//Doc va tra ve so nguyen 
    int start = currentPos;
    while (isdigit(strInput[currentPos])) {
        currentPos++;
    }
    return atoi(&strInput[start]); //Chuyen doi ky tu char thanh so nguyen 
}


int main() {
    
    const char *expression = "2-3+12/(2*2)";
    strInput = expression; // Gan bieu thuc vao strInput 
    currentPos = 0;        // Dat lai currentPos = 0

    // Goi ham E 
    int result = checkExpression();

    // Ket qua 
    printf("Ket qua : %d\n", result);  

    return 0;
}

