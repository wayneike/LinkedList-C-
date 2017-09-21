// Nortridge.cpp : Defines the entry point for the console application.
//
/*
Create a linked list that represents the amortization schedule of a deposit account w/ an interest rate of 3% for 10 years starting at 1/1/2017.
Assume that initial deposit in 10,000 and a deposit of $500 will be added every 1st day of even numbered month.
Use class to represent each month in the link list.

Month		Beg Bal		Deposit		Interest	End Bal
1/1/2017	10,000.00				25.00		10,025.00
2/1/2017	10,025.00	500.00		26.31		10,551.31
3/1/2017	10,551.31				26.38		10,577.69
4/1/2017	10,577.69	500.00		27.69		11,105.39
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Month.h"

using namespace std;

Month* currentMonth;

void init()
{
	currentMonth = NULL;
}

void add(int mNum)
{
	Month* m = new Month(mNum);
	if (currentMonth != NULL)
	{
		m->prev = currentMonth;
		currentMonth->next = m;
	}
	currentMonth = m;
	currentMonth->Calculate();
}

void remove(int mNum)
{
	if (currentMonth->prev == NULL)
	{
		delete currentMonth;
	}
	else
	{
		currentMonth = currentMonth->prev;
		delete currentMonth->next;
	}
	
}

void main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	init();

	cout << "Date\t\tBeg Balance\tDeposit\t\tInterest\tEnd Balance\n";

	int i;
	for (i = 1; i <= n; i++)
	{
		add(i);
		cout << currentMonth->date << "\t" << 
			fixed << std::setprecision(2) << currentMonth->principle << "\t" << currentMonth->deposit << "\t\t" << currentMonth->interest << "\t\t" << currentMonth->endBal << "\n";
	}

	//cleanup
	for (i = n; i >= 1; i--)
	{
		remove(n);
	}

#ifdef _DEBUG

	// force it to pause
	int x;
	cin >> x;

#endif // DEBUG
}