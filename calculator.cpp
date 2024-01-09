#include <iostream>
#include <algorithm>

using namespace std;

// OOP Stack
//stack int array
class Stack{
public:
    Stack(int s=100)
    {
        if (s<=0)
        {
            maxsize=0;
            top=-1;
            st=NULL;
        }
        else{
            st=new int [s];
            if (!st)
            {
                maxsize=0;
                top=-1;
                return;
            }
            top=-1;
            maxsize=s;
        }
    }
    bool isempty()
    {
        if (top==-1)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if (top==maxsize-1)
            return true;
        else
            return false;
    }
    
    bool push( int x)
    {
        if(isfull())
            return false;
        else
        {
            top++;
            st[top]=x;
            return true;
        }
    }
    bool pop(int &x)
    {
        if(isempty())
            return false;
        else{
            x=st[top];
            top--;
            return true;
        }
    }
    int Top()
    {
        if(isempty())
            return NULL;
        else
            return st[top];
    }
    void display()
    {
        for ( int i=0; i<=top;i++)
        cout<<st[i]<<endl;
    }
    
private:
    int maxsize;
    int top;
    int * st;
};

//Recognition of operand and operator
void diagnosis(char & op, int number1, int number2) 
{
    switch (op) 
	{
        case '+':
            cout << "Result: " << number1 + number2 << endl;
            break;
        case '-':
            cout << "Result: " << number1 - number2 << endl;
            break;
        case '*':
            cout << "Result: " << number1 * number2 << endl;
            break;
        case '/':
            if (number2 != 0) {
                cout << "Result: " << number1 / number2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
    }
}
// Identifying the priority of operators
int getPrecedence(char op) 
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}
// Infix To Prefix
string infixToPrefix(string &infix, Stack &op) 
{
    string prefix;
    for (int i = infix.length() - 1; i >= 0; i--) 
	{
        char a = infix[i];
        if (a >= '0' && a <= '9')
            prefix += a;
        else if (a == ')')
            op.push(a);
        else if (a == '(') 
		{
            while (!op.isempty() && op.Top() != ')') 
			{
                prefix += op.Top();
                int x;
                op.pop(x);
            }
        }
		else if (a == '+' || a == '-' || a == '*' || a == '/') 
		{
            while (!op.isempty() && getPrecedence(op.Top()) > getPrecedence(a)) 
			{
                prefix += op.Top();
                int x;
                op.pop(x);
            }
            op.push(a);
        }
    }
    while (!op.isempty()) {
        prefix += op.Top();
        int x;
        op.pop(x);
    } 
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
// Assessment prefix
int assessment_prefix(string prefix)
{
    int result;
    Stack op;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char a = prefix[i];
        if (a >= '0' && a <= '9')
            op.push(a - '0');
        else if (a == '+' || a == '-' || a == '*' || a == '/')
        {
            int x, y;
            op.pop(x);
            op.pop(y);
            switch (a)
            {
            case '+':
                op.push(x + y);
                break;
            case '-':
                op.push(x - y);
                break;
            case '*':
                op.push(x * y);
                break;
            case '/':
                if (y != 0)
                {
                    op.push(x / y);
                }
                break;
            }
        }
    }
    if (!op.isempty())
    {
        op.pop(result);
        return result;
    }
    return 0;
}
// Infix To Postfix
string infixToPostfix(string &infix, Stack &op) 
{
    string postfix;
    for (int i = 0; i < infix.length(); i++) 
	{
        char a = infix[i];
        if (a >= '0' && a <= '9')
            postfix += a;
        else if (a == '(')
            op.push(a);
        else if (a == ')') 
		{
            while (!op.isempty() && op.Top() != '(') 
			{
                postfix += op.Top();
                int x;
                op.pop(x);
            }
        }
		else if (a == '+' || a == '-' || a == '*' || a == '/') 
		{
            while (!op.isempty() && getPrecedence(op.Top()) >= getPrecedence(a)) 
			{
                postfix += op.Top();
                int x;
                op.pop(x);
            }
            op.push(a);
        }
    }
    while (!op.isempty()) 
	{
        postfix += op.Top();
        int x;
        op.pop(x);
    }
    return postfix;
}
// Assessment postfix
int assessment_postfix(string postfix)
{
	int result;
    Stack op;
    for (int i = 0; i < postfix.length(); i++)
    {
        char a = postfix[i];
        if (a >= '0' && a <= '9')
            op.push(a - '0');
        else if (a == '+' || a == '-' || a == '*' || a == '/')
        {
            int x, y;
            op.pop(x);
            op.pop(y);
            switch (a)
            {
            case '+':
                op.push(y + x);
                break;
            case '-':
                op.push(y - x);
                break;
            case '*':
                op.push(y * x);
                break;
            case '/':
                if (x != 0)
                {
                    op.push(y / x);
                }
                break;
            }
        }
    }
    if (!op.isempty())
    {
        op.pop(result);
        return result;
    }
    return 0;
}

int main() 
{
    char operation;
    float number1, number2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter number 1: ";
    cin >> number1;
    cout << "Enter number 2: ";
    cin >> number2;
    diagnosis(operation, number1, number2);

    Stack op;
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    // Infix To Prefix :
    string prefix = infixToPrefix(infix, op);
    cout << "Prefix expression: " << prefix << endl;
    // Assessment prefix :
    int result_prefix = assessment_prefix(prefix);
    cout << "Assessment prefix: " << result_prefix << endl;
    // Infix To Postfix :
    string postfix = infixToPostfix(infix, op);
    cout << "Postfix expression: " << postfix << endl;
    // Assessment postfix :
    int result_postfix = assessment_postfix(postfix);
    cout << "Assessment postfix: " << result_postfix << endl;
    return 0;
}
