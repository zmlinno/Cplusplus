#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month = d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}


bool Date::operator<=(const Date& d)
{
	return *this < d || *this == d;
}


bool Date::operator>(const Date& d)
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

bool Date::operator==(const Date& d)
{
	return _year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMontDay(_year, _month))
	{
		_day -= GetMontDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}



Date Date::operator+(int day)
{
	//Date tmp(*this);
	Date tmp = *this; 
	tmp += day;

	return tmp;
}
