#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

// Function to determine the precedence of operators
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack); // Pop the '('
                i++;
            }
        } else {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    return pop(&stack);
}

int main() {
    char infix[] = "3+5*(6-2)/8";
    char postfix[MAX_SIZE];

    infixToPostfix(infix, postfix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}