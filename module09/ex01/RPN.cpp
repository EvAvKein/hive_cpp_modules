/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeinan <ekeinan@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:39:37 by ekeinan           #+#    #+#             */
/*   Updated: 2025/08/25 13:23:55 by ekeinan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

typedef struct s_RPN
{
	std::stack<char> ops;
	std::stack<int> nums;
} RPN;

static std::overflow_error RPNOverflowException(const int a, const int b, const char sign, const std::string_view &name)
{
	return std::overflow_error("RPN " + std::string(name) + " overflow: " + std::to_string(a) + " " + sign + " " + std::to_string(b));
}

static void addition(RPN &rpn)
{
	if (rpn.nums.size() < 2)
		throw std::runtime_error("RPN received '+' operator with less than 2 preceding operands");

	int b = rpn.nums.top();
	rpn.nums.pop();
	int a = rpn.nums.top();
	rpn.nums.pop();
	int result = a + b;

#if VERBOSE
	std::cout << "[RPN]: " << a << " + " << b << " = " << result << std::endl;
#endif

	if (result - a != b && result - b != a)
		throw RPNOverflowException(a, b, '+', "addition");
	rpn.nums.push(result);
}

static void subtraction(RPN &rpn)
{
	if (rpn.nums.size() < 2)
		throw std::runtime_error("RPN received '-' operator with less than 2 preceding operands");

	int b = rpn.nums.top();
	rpn.nums.pop();
	int a = rpn.nums.top();
	rpn.nums.pop();
	int result = a - b;

#if VERBOSE
	std::cout << "[RPN]: " << a << " - " << b << " = " << result << std::endl;
#endif

	if (result + a != b && result + b != a)
		throw RPNOverflowException(a, b, '-', "subtraction");
	rpn.nums.push(result);
}

static void division(RPN &rpn)
{
	if (rpn.nums.size() < 2)
		throw std::runtime_error("RPN received '/' operator with less than 2 preceding operands");

	int b = rpn.nums.top();
	rpn.nums.pop();
	int a = rpn.nums.top();
	rpn.nums.pop();

	if (b == 0)
		throw std::runtime_error("RPN reached division by zero - undefined behavior, aborting");
	if (a == std::numeric_limits<int>::min() && b == -1)
		throw std::runtime_error("RPN reached division of INT_MIN by -1 - undefined/unrepresentable behavior, aborting");

	int result = a / b;

#if VERBOSE
	std::cout << "[RPN]: " << a << " / " << b << " = " << result << std::endl;
#endif

	rpn.nums.push(result);
}

static void multiplication(RPN &rpn)
{
	if (rpn.nums.size() < 2)
		throw std::runtime_error("RPN received '*' operator with less than 2 preceding operands");

	int b = rpn.nums.top();
	rpn.nums.pop();
	int a = rpn.nums.top();
	rpn.nums.pop();
	int result = a * b;

#if VERBOSE
	std::cout << "[RPN]: " << a << " * " << b << " = " << result << std::endl;
#endif

	if (a != 0 && result / a != b)
		throw RPNOverflowException(a, b, '*', "multiplication");
	rpn.nums.push(result);
}

int reversePolishNotation(std::string str)
{
	RPN rpn;

	size_t pos;
	while (str.length() > 0)
	{
		pos = str.find(' ');
		if (pos == 0)
		{
			str.erase(0, 1);
			pos = str.find(' ');
			continue;
		}
		else if (pos > 1 && pos != std::string::npos)
			throw std::runtime_error("RPN received token longer than 1 character: \"" + str.substr(0, pos) + "\"");

		if (std::isdigit(str[0]))
		{
			rpn.nums.push(str[0] - '0');
			str.erase(0, 1);
			continue;
		}

		switch (str[0])
		{
		case '+':
		{
			addition(rpn);
			break;
		}
		case '-':
		{
			subtraction(rpn);
			break;
		}
		case '*':
		{
			multiplication(rpn);
			break;
		}
		case '/':
		{
			division(rpn);
			break;
		}
		default:
			throw std::runtime_error("RPN received invalid token: \"" + str.substr(0, pos) + "\"");
		}
		str.erase(0, 1);
	}

	if (rpn.ops.size() > 0)
		throw std::runtime_error("RPN calculation called with excess operators");

	if (rpn.nums.size() == 0)
		throw std::runtime_error("RPN calculation called with no operands");

	if (rpn.nums.size() > 1)
		throw std::runtime_error("RPN calculation ended with leftover operands");

	return rpn.nums.top();
}
