OOP Stack and Expression Evaluation Program Documentation
Introduction
This C++ program implements an Object-Oriented Programming (OOP) stack and provides functionalities for evaluating arithmetic expressions. The program includes a stack class that supports basic stack operations, as well as functions for diagnosing arithmetic operations, converting infix expressions to prefix and postfix notations, and evaluating those expressions.

Stack Class
Public Members:
Constructor: Initializes the stack with a specified size (default is 100).
bool isempty(): Checks if the stack is empty.
bool isfull(): Checks if the stack is full.
bool push(int x): Pushes an integer onto the stack.
bool pop(int &x): Pops an integer from the stack.
int Top(): Returns the top element of the stack.
void display(): Displays the elements of the stack.

Private Members:
int maxsize: Maximum size of the stack.
int top: Index of the top element.
int *st: Pointer to the stack array.

Expression Evaluation Functions
void diagnosis(char &op, int number1, int number2)
Diagnoses and prints the result of arithmetic operations based on user input.
int getPrecedence(char op)
Returns the precedence of an operator for determining the order of operations.
string infixToPrefix(string &infix, Stack &op)
Converts an infix expression to a prefix expression using the stack.
Returns the resulting prefix expression.
int assessment_prefix(string prefix)
Evaluates a given prefix expression and returns the result.
string infixToPostfix(string &infix, Stack &op)
Converts an infix expression to a postfix expression using the stack.
Returns the resulting postfix expression.
int assessment_postfix(string postfix)
Evaluates a given postfix expression and returns the result.

Main Program
Takes user input for arithmetic operations.
Implements the stack for converting and evaluating infix, prefix, and postfix expressions.
Displays the results of diagnosis, infix to prefix conversion, infix to postfix conversion, and expression evaluation.

Usage
Enter an operator (+, -, *, /), number1, and number2 for arithmetic operation diagnosis.
Enter an infix expression for infix to prefix and infix to postfix conversions.
View the results of the diagnosis, infix to prefix conversion, infix to postfix conversion, and expression evaluations.
