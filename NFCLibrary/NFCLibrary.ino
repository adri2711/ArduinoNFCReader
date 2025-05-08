#include "NFCReader.h"

void setup(void) {
    Serial.begin(115200);
    Serial.println("NDEF Reader");
    Setup();
}

void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    CardData *cardData = new CardData();
    if (ReadCard(cardData)) {
      Serial.println(cardData->champion);
      Serial.println(cardData->gameId);
      Serial.println(cardData->playerId);
    }

    delay(5000);
}