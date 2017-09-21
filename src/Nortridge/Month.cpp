#include "stdafx.h"
#include <math.h>
#include "Month.h"

using namespace std;

 Month::Month(int mNum)
{
	 _monthNum = mNum;
}

Month::~Month()
{
}

void Month::Calculate()
{
	if (_monthNum % 2 == 0)
	{
		deposit = 500.00;
	}

	if ((_monthNum > 1) && (prev != NULL))
	{
		principle = prev->endBal;
	}
	else
	{
		principle = 10000.00;
	}

	double initBalance = principle + deposit;
	interest = Round(initBalance * (0.03 / 12), 2);
	endBal = initBalance + interest;

	date = GetDate(_monthNum);
}

string Month::GetDate(int monthNum)
{
	string date;

	int year = (monthNum - 1) / 12 + 2017;
	int month = ((monthNum - 1) % 12) + 1;

	date = std::to_string(month) + "/1/" + std::to_string(year);
	return date;
}

double Month::Round(double x, int decPoint)
{
	double power = 1.0;
	int i;

	if (decPoint > 0)
	{
		for (i = 0; i < decPoint; i++)
		{
			power *= 10.0;
		}
	}
	// else if ....
	// unnecessary for this particular project

	if (x > 0)
	{
		x = floor(x * power + 0.5) / power;
	}
	else if (x < 0)
	{
		x = ceil(x * power - 0.5) / power;
	}

	if (x == -0)
		x = 0;

	return x;
}