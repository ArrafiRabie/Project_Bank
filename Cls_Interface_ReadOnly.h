#pragma once
#include<iostream>

using namespace std;

class Cls_Interface_ReadOnly
{
//private:
//protected:

public:

	virtual string GetCountry() = 0;
	virtual string GetCurrencyCoud() = 0;
	virtual string GetCurrencyName() = 0;
	virtual void SetRate(float Rate) = 0;
	virtual float GetRate() = 0;
};

