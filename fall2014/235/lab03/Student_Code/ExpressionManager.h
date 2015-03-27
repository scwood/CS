/*
 * ExpressionManager.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Spencer
 */

#ifndef EXPRESSIONMANAGER_H_
#define EXPRESSIONMANAGER_H_

#include <iostream>
#include <string>
#include <stack>
#include "ExpressionManagerInterface.h"

using namespace std;

class ExpressionManager : public ExpressionManagerInterface {
public:
	ExpressionManager();
	~ExpressionManager();
	bool isBalanced(string expression);
	bool isValidPostfix(string expression);
	bool isValidInfix(string expression);
	string postfixToInfix(string postfixExpression);
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);

	bool isOpenParenthesis(string value);
	bool isClosedParenthesis(string value);
	bool isNumber(string value);
	bool isOperator(string value);
	bool hasParenthesis(string value);
	void clearStack (stack<string> theStack);
	int checkOrder(string value);
	int evaluateExpression(int left, int right, string op);
};

#endif /* EXPRESSIONMANAGER_H_ */
