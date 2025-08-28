#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int val)
 {
    if (top == MAX - 1)
	{
        printf("Stack Overflow\n");  
    }
    stack[++top] = val;
 }


  int pop() 
  {
     if (top == -1)
	  {
        printf("Stack Underflow\n");
    
      }
    return stack[top--];
  }

int evaluatePostfix(char exp[])
{
    int i, op1, op2;

    for (i = 0; exp[i] != '\0'; i++) 
	{
        if (exp[i] == ' ' || exp[i] == '\n')
		{
		
          if (isdigit(exp[i])) 
		{
            push(exp[i] - '0');  
        }
        else
		 {
            op2 = pop();
            op1 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    exit(1);
            }
        }
      }
    }
    return pop(); 
   }

int main() {
    char exp[MAX];
    printf("Enter a postfix expression: ");
    fgets(exp, MAX, stdin);

    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}
