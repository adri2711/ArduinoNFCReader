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

void Setup() {
    nfc.begin();
}

CardData ReadCard() {
    if (!nfc.tagPresent()) return CardData();
    
    NfcTag tag = nfc.read();
    if (!tag.hasNdefMessage()) return CardData();

    CardData data;
    NdefMessage message = tag.getNdefMessage();
    for (int i = 0; i < message.getRecordCount(); i++) {
        NdefRecord record = message.getRecord(i);
        byte *payload;
        record.getPayload(payload);
        int numBytes = record.getPayloadLength();
        record.print();
        Serial.println(F("----------------------------"));
        
        

        Serial.println(F("----------------------------"));
    }
    
    return data;
}


#endif