#include "PlayerDataHandler.h"

Data::PlayerDataHandler::PlayerDataHandler()
{
	walletMap[GameTypes::eCurrencyType::GOLD] = 0;
	walletMap[GameTypes::eCurrencyType::DIAMOND] = 0;
}

int Data::PlayerDataHandler::getCurrency(GameTypes::eCurrencyType mType)
{
	return walletMap[mType];
}

void Data::PlayerDataHandler::SetCurrency(const int amount, const GameTypes::eCurrencyType mType)
{
	walletMap[mType] = amount;
}
void Data::PlayerDataHandler::addCurrency(const int amount, const GameTypes::eCurrencyType mType)
{
	walletMap[mType] += amount;
}

std::unordered_map<GameTypes::eCurrencyType, int>* Data::PlayerDataHandler::getCurrency()
{
	return &walletMap;
}

