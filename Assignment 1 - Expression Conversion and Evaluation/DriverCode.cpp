//============================================================================
// Name        : ExpressionConversion.cpp
// Author      : Saarth Deshpande 23150
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
#include "StackADT.h"		// Stack ADT used for conversion of expressions
#include "EvaluationStack.h"		// Stack ADT used for evaluation of expressions
using namespace std;

int priority(char x)
{
	switch(x)
	{
		case '+': return 5;
		case '-': return 5;
		case '*': return 10;
		case '/': return 10;
		case '^': return 10;
		default: return 0;
	}
}

class Expression
{
	string inputExpression,convertedExpression;
public:
	void input();
	void inFixToPostFix();
	void inFixToPreFix();
	double evaluatePreFix();
	double evaluatePostFix();
	void output();
	void clear();
};

void Expression::clear()		// Makes strings empty at beginning of every new operation
{
	convertedExpression.clear();
	inputExpression.clear();
}

void Expression::input()
{
		cin.ignore();		// Used to clear input buffer
		cout << "\nEnter Input Expression: ";
		getline(cin,inputExpression);
}

void Expression::inFixToPostFix()
{
	StackADT s;
	s.push(';');		// Dummy character to push at base of stack, easier to operate on
	for(int i = 0;i < inputExpression.length();i++)
	{
		char x = inputExpression[i];
		if((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z'))	// Adding operands in resultant string
			convertedExpression += x;
		else if(x == '(')	// Push brackets to stack
			s.push(x);
		else if(x == ')')
		{
			while((s.peep() != ';') && (s.peep() != '('))	// Pop from stack until opposite bracket obtained
				convertedExpression += s.pop();
			if(s.peep() == '(')		// Loop only iterates TILL inner bracket obtained, hence pop it separately
				char dummy = s.pop();
		}
		else
		{
			while((s.peep() != ';')&&(priority(s.peep()) >= priority(x))) // Pop from stack till precedence of character scanned is lesser than that of operator at top of stack
				convertedExpression += s.pop();
			s.push(x);
		}
	}
	while(s.peep() != ';')		// Pop remaining elements from stack
		convertedExpression += s.pop();
}

void Expression::inFixToPreFix()
{
	StackADT s;
	reverse(inputExpression.begin(),inputExpression.end());	// Infix expression is reversed
	for(int i = 0; i < inputExpression.size(); i++)		// Parentheses in string are reversed
	{
		if (inputExpression[i] == '(') {
			inputExpression[i] = ')';
			i++;
		}
		else if(inputExpression[i] == ')')
		{
			inputExpression[i] = '(';
			i++;
		}
	}
	inFixToPostFix();		// New in-fix expression converted to post-fix expression
	reverse(convertedExpression.begin(),convertedExpression.end());		// Post-fix expression reversed

}

double Expression::evaluatePreFix()
{
	EvaluationStack s;
	for(int i = inputExpression.size() - 1;i >= 0;i--)
	{
		char x = inputExpression[i];
		if(isdigit(x))
			s.push(x - '0');		// If scanned character is operand, push to stack
		// '0' is subtracted because ASCII value of 0 is 0x30 and for e.g. that of 9 is 0x39
		// hence we are pushing the digit '9'

		else		// Pop two elements from stack and apply the operation on them
		{
			double op1 = s.pop();
			double op2 = s.pop();
			switch(x)
			{
				case '+': s.push(op1 + op2) ;
						  break;
				case '-': s.push(op1 - op2);
						  break;
				case '*': s.push(op1 * op2);
						  break;
				case '/': s.push(op1 / op2);
						  break;
			}
		}
	}
	return s.peep();
}

double Expression::evaluatePostFix()
{
	EvaluationStack s;
	for(int i = 0; inputExpression[i] != '\0'; ++i)
	{
		char x = inputExpression[i];
		if (isdigit(x))
			s.push(x - '0');		// If scanned character is operand, push to stack
		// '0' is subtracted because ASCII value of 0 is 0x30 and for e.g. that of 9 is 0x39
		// hence we are pushing the digit '9'

		else		// Pop two elements from stack and apply the operation on them
		{
			double val1 = s.pop();
			double val2 = s.pop();
			switch (x)
			{
				case '+': s.push(val2 + val1);
						  break;
				case '-': s.push(val2 - val1);
						  break;
				case '*': s.push(val2 * val1);
						  break;
				case '/': s.push(val2/val1);
						  break;
			}
		}
	}
	return s.peep();
}

void Expression::output()
{
		cout << "\nResultant Expression: ";
		for(int i = 0;convertedExpression[i] != '\0';i++)
			cout << convertedExpression[i];
		cout << "\n\n";
}

int main() {
	Expression E;
	int userResponse;
	do
	{
		cout << "\nExpression Conversion\n\n1. Convert In-Fix to Post-Fix\n2. Convert In-Fix to Pre-Fix\n3. Evaluate Post-Fix Expression\n4. Evaluate Pre-Fix Expression\n5. Exit\nYour Choice: ";
		cin >> userResponse;
		switch(userResponse)
		{
			case 1: E.clear();
					E.input();
					E.inFixToPostFix();
					E.output();
					break;
			case 2: E.clear();
					E.input();
					E.inFixToPreFix();
					E.output();
					break;
			case 3: E.clear();
					E.input();
					cout << "Post-Fix Evaluation = " << E.evaluatePostFix();
					break;
			case 4: E.clear();
					E.input();
					cout << "Pre-Fix Evaluation = " <<  E.evaluatePreFix();
					break;
			case 5: return 1;
		}
	}while(userResponse != 5);
	return 0;
}
