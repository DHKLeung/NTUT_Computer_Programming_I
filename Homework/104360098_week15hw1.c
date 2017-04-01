#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/*Computer Programming 2016 week 15 hw 1, Coded by Leung Ho Kwan 104360098*/
typedef struct _stackDT stackDT;
struct _stackDT {
    char bucket[513];
    int top;
};
void infixinput(char input[]) { //infix input
    fgets(input, 513, stdin);
    input[strlen(input) - 1] = '\0';
}
void spush(stackDT *stack, char element) {    //push element to stack
    stack->bucket[++(stack->top)] = element;
}
char spop(stackDT *stack) { //pop element from stack
    return stack->bucket[(stack->top)--];
}
char stop(stackDT stack) {  //return the toppest element of stack
    return stack.bucket[stack.top];
}
bool isEmpty(stackDT stack) {   //whether the stack is empty of not
    return (stack.top == -1) ? 1 : 0;
}
void processbracket(stackDT *stack) {   //perform action when meet ')'
    spop(stack);    //throw away the ')'
    while(stack->bucket[stack->top] != '(') {   //keep printing the arithmetic sign till '('
        printf("%c", spop(stack));
    }
    spop(stack);    //throw away the '('
}
void processplusminus(stackDT *stack) { //perform action when meet '+' or '-'
    stackDT temp = { .top = -1 };   //create a temp stack for temporarily storing the '+' or '-'
    spush(&temp, spop(stack));  //pop the '+' or '-' from stack to temp
    while (!(isEmpty(*stack) || stop(*stack) == '(')) {  //keep printing till isEmpty or meet '('
        printf("%c", spop(stack));
    }
    while(!isEmpty(temp)) { //keep pushing back the '+' or '-' to stack
        spush(stack, spop(&temp));
    }
}
int main(int argc, char **argv) {
    char input[513];
    int i = 0;
    bool multidivide = false;
    stackDT stack = { .top = -1 };
    infixinput(input);  //input the infix
    for (i = 0; i < strlen(input); i++) {
        if (ispunct(input[i])) {    //is punctuation
            if (input[i] == ')') {  //if it is ')', perform action for ')'
                spush(&stack, input[i]);
                processbracket(&stack);
            }else if (input[i] == '+' || input[i] == '-') { //if is '+' or '-', perform action for '+' or '-'
                spush(&stack, input[i]);
                processplusminus(&stack);
            }else { //if it is '*' or '/' or '^', just push it into stack
                spush(&stack, input[i]);
            }
        }else {
            printf("%c", input[i]); //print the alphabet
        }
    }
    while(!isEmpty(stack)) {    //print all the remaining arithmetic sign
        printf("%c", spop(&stack));
    }
    printf("\n");
    return 0;
}
