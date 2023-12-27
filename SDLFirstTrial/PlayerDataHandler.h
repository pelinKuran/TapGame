#pragma once

#include "SimpleGameTypes.h"
#include <vector>
#include <unordered_map>
namespace Data
{
    class PlayerDataHandler
    {
        public:
        // Some other related code.
        PlayerDataHandler();
        // It is used for updating a dedicated hard currency owned by the player
        int getCurrency(GameTypes::eCurrencyType);
        void SetCurrency(const int amount, const GameTypes::eCurrencyType mType);
       void addCurrency(const int amount, const GameTypes::eCurrencyType mType);
        std::unordered_map<GameTypes::eCurrencyType, int>* getCurrency();
    private:
        std::unordered_map<GameTypes::eCurrencyType, int> walletMap;
        // Some other related code.
    };
}