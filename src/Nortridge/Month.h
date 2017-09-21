#pragma once

#ifndef MONTH_H_
#define MONTH_H_

#include <string>

class Month
{
public:
	Month(int mNum);
	~Month();

	//doubly linked list
	Month* prev = NULL;
	Month* next = NULL;

	double principle;
	double interest;
	double endBal;
	double deposit = 0.00;
	std::string date;

	void Calculate();

private:
	int _monthNum;

	static double Round(double x, int decPoint);
	static std::string GetDate(int monthNum);
};

#endif
