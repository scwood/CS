/*
 * ExpressionManager.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Spencer
 */

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>
#include "ExpressionManager.h"

using namespace std;

ExpressionManager::ExpressionManager(){}
ExpressionManager::~ExpressionManager(){}

// Clears the stack
//-----------------------------------------------------------------
void ExpressionManager::clearStack(stack<string> theStack) {
	while (!theStack.empty()) {
		theStack.pop();
	}
}

// Evaluates two numbers and an operator
//-----------------------------------------------------------------
int ExpressionManager::evaluateExpression(int left, int right, string op) {
	int result;
	if (op == "*") {
		result = left * right;
	}
	else if (op == "/" && right != 0) {
		result = left / right;
	}
	else if (op == "+") {
		result = left + right;
	}
	else if (op == "-") {
		result = left - right;
	}
	else if (op == "%" && right != 0) {
		result = left % right;
	}
	return result;
}

bool ExpressionManager::hasParenthesis(string value) {
	stringstream stream(value);
	string parse;
	string item;
	while (stream >> parse) {
		item = parse;
		if (isOpenParenthesis(item) || isClosedParenthesis(item)) {
			return true;
		}
	}
	return false;
}

// Checks if value is an open parenthesis
//-----------------------------------------------------------------
bool ExpressionManager::isOpenParenthesis(string value) {
	if (value == "(" || value == "{" || value == "["){
		return true;
	}
	else {
		return false;
	}
}


// Checks if value is a closed parenthesis
//-----------------------------------------------------------------
bool ExpressionManager::isClosedParenthesis(string value) {
	if (value == ")" || value == "}" || value == "]"){
		return true;
	}
	else {
		return false;
	}
}

// Checks if value is an integer
//-----------------------------------------------------------------
bool ExpressionManager::isNumber(string value) {
	for (unsigned int i = 0; i < value.size(); i++) {
		if(!isdigit(value[i])) {
			return false;
		}
	}
	return true;
}

// Checks if value is an operator
//-----------------------------------------------------------------
bool ExpressionManager::isOperator(string value) {
	if (value == "*" || value == "/" || value == "%" || value == "+" || value == "-") {
		return true;
	}
	else {
		return false;
	}
}

// Checks values precedence on stack
//-----------------------------------------------------------------
int ExpressionManager::checkOrder(string value) {
	int order = 0;
	if (value == "*" || value == "/" || value == "%") {
		order = 2;
	}
	else if (value == "+" || value == "-") {
		order = 1;
	}
	return order;
}


// Checks if a function is valid infix
//-----------------------------------------------------------------
bool ExpressionManager::isValidInfix(string expression) {
	int number_count = 0;
	int operator_count = 0;
	stringstream stream(expression);
	string parse;
	string item;

	while (stream >> parse) {
		item = parse;

		if (!isNumber(item) && !isOperator(item) && !isOpenParenthesis(item) && !isClosedParenthesis(item)) {
			return false;
		}

		else if (isNumber(item)) {
			number_count++;
		}

		else if (isOperator(item)) {
			operator_count++;
		}

		if (operator_count > number_count) {
			return false;
		}
	}
	return true;
}

// Checks if a function is valid postfix
//-----------------------------------------------------------------
bool ExpressionManager::isValidPostfix(string expression) {
	int number_count = 0;
	int operator_count = 0;
	stringstream stream(expression);
	string parse;
	string item;

	while (stream >> parse) {
		item = parse;

		if (!isNumber(item) && !isOperator(item) && !isOpenParenthesis(item) && !isClosedParenthesis(item)) {
			return false;
		}

		else if (isNumber(item)) {
			number_count++;
		}

		else if (isOperator(item)) {
			operator_count++;
		}

		if ((operator_count == 1 && number_count == 0) || (operator_count == 1 && number_count == 1) || (operator_count == number_count)) {
			return false;
		}
	}

	if (number_count - operator_count != 1) {
		return false;
	}

	else {
		return true;
	}
}

/*
 * Checks whether an expression is balanced on its parentheses
 *
 * - The given expression will have a space between every number or operator
 *
 * @return true if expression is balanced
 * @return false otherwise
 */
bool ExpressionManager::isBalanced(string expression) {
	stack<string> parenthesisStack;
	stringstream stream(expression);
	string parse;

	if (expression == "") {
		return false;
	}

	while(stream >> parse) {
		string item = parse;

		if (isOpenParenthesis(item)) {
			parenthesisStack.push(item);
		}

		else if (isClosedParenthesis(item)) {

			if (item == ")" && !parenthesisStack.empty()) {
				string check = parenthesisStack.top();
				if (check != "(") {
					return false;
				}
				else {
					parenthesisStack.pop();
				}
			}

			else if (item == "}" && !parenthesisStack.empty()) {
				string check = parenthesisStack.top();
				if (check != "{") {
					return false;
				}
				else {
					parenthesisStack.pop();
				}
			}

			else if (item == "]" && !parenthesisStack.empty()) {
				string check = parenthesisStack.top();
				if (check != "[") {
					return false;
				}
				else {
					parenthesisStack.pop();
				}
			}

			// stack must be empty
			else {
				return false;
			}
		}
	}

	if (parenthesisStack.size() > 0) {
		return false;
	}

	else {
		return true;
	}
}

/**
 * Converts a postfix expression into an infix expression
 * and returns the infix expression.
 *
 * - The given postfix expression will have a space between every number or operator.
 * - The returned infix expression must have a space between every number or operator.
 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if postfixExpression is not a valid postfix expression.
 * otherwise, return the correct infix expression as a string.
 */
string ExpressionManager::postfixToInfix(string postfixExpression) {
	stack<string> numberStack;
	stringstream stream(postfixExpression);
	string parse;
	string output;
	string item;
	string left_term;
	string right_term;
	string current_operator;

	if (postfixExpression == "") {
		return "invalid";
	}

	if (!isValidPostfix(postfixExpression)) {
		return "invalid";
	}

	if (hasParenthesis(postfixExpression)) {
		return "invalid";
	}

	while (stream >> parse) {
		item = parse;
		if (isNumber(item)) {
			numberStack.push(item);
		}

		else if (isOperator(item)) {
			right_term = numberStack.top();
			numberStack.pop();
			left_term = numberStack.top();
			numberStack.pop();
			output = "( " + left_term + " " + item + " " + right_term + " )";
			numberStack.push(output);
		}
	}

	return output;
}

/**
 * Converts an infix expression into a postfix expression
 * and returns the postfix expression
 *
 * - The given infix expression will have a space between every number or operator.
 * - The returned postfix expression must have a space between every number or operator.
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if infixExpression is not a valid infix expression.
 * otherwise, return the correct postfix expression as a string.
 */
string ExpressionManager::infixToPostfix(string infixExpression) {
	stack<string> operatorStack;
	stringstream stream(infixExpression);
	string parse;
	string output;
	string operator_string;

	if (infixExpression == "") {
		return "invalid";
	}

	if (!isValidInfix(infixExpression)) {
		return "invalid";
	}

	if (!isBalanced(infixExpression)) {
		return "invalid";
	}

	while(stream >> parse) {
		string item = parse;

		if (isNumber(item)) {
			output += item + " ";
		}

		else if (isOpenParenthesis(item)) {
			operatorStack.push(item);
		}

		else if (isOperator(item)) {

			if (operatorStack.empty() || isOpenParenthesis(operatorStack.top())){
				operatorStack.push(item);
			}

			else if (checkOrder(item) > checkOrder(operatorStack.top())) {
				operatorStack.push(item);
			}

			else if (checkOrder(item) <= checkOrder(operatorStack.top())) {

				while (!operatorStack.empty() && checkOrder(item) <= checkOrder(operatorStack.top()) && !isOpenParenthesis(operatorStack.top())) {
					operator_string = operatorStack.top();
					operatorStack.pop();
					output += operator_string + " ";
				}

				operatorStack.push(item);
			}
		}

		else if (isClosedParenthesis(item)) {

			while (!isOpenParenthesis(operatorStack.top())) {
				operator_string = operatorStack.top();
				operatorStack.pop();
				output += operator_string + " ";
			}

			operatorStack.pop();
		}

		else {
			return "invalid";
		}
	}

	while (!operatorStack.empty()) {
		operator_string = operatorStack.top();
		operatorStack.pop();
		output += operator_string + " ";
	}

	// Cut ending whitespace off
	output = output.substr(0, output.size() - 1);

	return output;
}

/**
 * Evaluates a postfix expression returns the result as a string
 *
 * - The given postfix expression will have a space between every number or operator.
 * - Check lab requirements for what will be considered invalid.
 *
 * return the string "invalid" if postfixExpression is not a valid postfix Expression
 * otherwise, return the correct evaluation as a string
 */
string ExpressionManager::postfixEvaluate(string postfixExpression) {
	stack<int> numberStack;
	int output = 0;
	int left_term;
	int right_term;
	stringstream stream(postfixExpression);
	string parse;
	string item;
	string current_operator;

	if (postfixExpression == "") {
		return "invalid";
	}

	if (!isValidPostfix(postfixExpression)) {
		return "invalid";
	}

	if (hasParenthesis(postfixExpression)) {
		return "invalid";
	}

	while (stream >> parse) {
		item = parse;
		if (isNumber(item)) {
			int value = atoi(item.c_str());
			numberStack.push(value);
		}

		else if (isOperator(item)) {
			right_term = numberStack.top();
			numberStack.pop();
			left_term = numberStack.top();
			numberStack.pop();
			if ((item == "%" && right_term == 0) || (item == "/" && right_term == 0)) {
				return "invalid";
			}
			output = evaluateExpression(left_term, right_term, item);
			numberStack.push(output);
		}
	}

	output = numberStack.top();

	stringstream convert;
	convert << output;
	string result = convert.str();

	return result;
}

