#ifndef CARDDATA_H
#define CARDDATA_H

#include <string>

struct CardData {
    std::string ipAddress;
    int portToListen;
    int champion;
    int gameId;
    int playerId;
    int isB;
    std::string wifi;
    std::string password;
};

#endif