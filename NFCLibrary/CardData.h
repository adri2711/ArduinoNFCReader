#ifndef CARDDATA_H
#define CARDDATA_H

#include <string>

struct CardData {
    std::string ipAdress;
    int champion;
    int gameId;
    int playerId;
    std::string hexColor;
    std::string wifi;
    std::string password;
};

#endif