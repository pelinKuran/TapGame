#pragma once
#include <iostream>
#include "SimpleGameTypes.h"
namespace Utilities 
{

	GameTypes::eCurrencyType convertStringToCurrency(const std::string& pString)
	{
		if (pString == "GOLD")
		{
			return GameTypes::eCurrencyType::GOLD;
		}
		else if (pString == "DIAMOND")
		{
			return GameTypes::eCurrencyType::DIAMOND;
		}
	}
}