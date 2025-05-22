#ifndef NFCREADER_H
#define NFCREADER_H

#include <Arduino.h>
#include "CardData.h"

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>

#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

int cardContactTimer = 0;
const int contactsNeeded = 15;

void Setup() {
    nfc.begin();
}

bool ReadCard(CardData* data) {
    if (!nfc.tagPresent()) {
      cardContactTimer = 0;
      return false;
    } 
    
    if (cardContactTimer < contactsNeeded) {
      cardContactTimer++;
      return false;
    }

    cardContactTimer = 0;

    NfcTag tag = nfc.read();
    if (!tag.hasNdefMessage()) return false;

    NdefMessage message = tag.getNdefMessage();
    for (int i = 0; i < message.getRecordCount(); i++) {
        NdefRecord record = message.getRecord(i);
        byte payload[256];
        std::string type = record.getType().c_str();
        record.getPayload(payload);
        int payloadLength = record.getPayloadLength();

        std::string payloadAsString = "";
        for (int c = 0; c < payloadLength; c++) {
            payloadAsString += (char)payload[c];
        }

        if (type == "playersetup:champion") {
          data->champion = std::stoi(payloadAsString, 0, 10);
        }
        else if (type == "playersetup:isB") {
          data->isB = std::stoi(payloadAsString, 0, 10);
        }
        else if (type == "playersetup:ip") {
          data->ipAddress = payloadAsString;
        }
        else if (type == "playersetup:porttolisten") {
          data->portToListen = std::stoi(payloadAsString, 0, 10);
        }
        else if (type == "playersetup:gameid") {
          data->gameId = std::stoi(payloadAsString, 0, 10);
        }
        else if (type == "playersetup:playerid") {
          data->playerId = std::stoi(payloadAsString, 0, 10);
        }
        else if (type == "playersetup:wifi") {
          data->wifi = payloadAsString;
        }
        else if (type == "playersetup:password") {
          data->password = payloadAsString;
        }
    }
    return true;
}




#endif