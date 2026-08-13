#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include "clsUtil.h"
class clsInputValidation
{
public:
	static bool IsNumberBetween(int Number, int From, int To) {

		return  (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(double Number, double From, double To) {

		return  (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(float Number, float From, float To) {

		return  (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(long  Number, long From, long  To) {

		return  (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(long long  Number, long long From, long long  To) {

		return  (Number >= From && Number <= To);
	}
	static bool IsNumberBetween(short  Number, short From, short  To) {

		return  (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate) {

		if (FromDate.IsDateAfterDate2(ToDate)) {

			clsUtil::Swap(FromDate, ToDate);
		}

		return !Date.IsDateBeforeDate2(FromDate) && !Date.IsDateAfterDate2(ToDate);


	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

};
//Eng .MaysJaber
////Don't Repeat Yourself - DRY