#include "NFCReader.h"

void setup(void) {
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    delay(1000);
    digitalWrite(7, HIGH);
    delay(1000);
    Serial.begin(115200);
    Serial.println("NDEF Reader");
    Setup();
}

void loop(void) {
    //Serial.println("\nScan a NFC tag\n");
    CardData *cardData = new CardData();
    if (ReadCard(cardData)) {
      Serial.print("Champion: ");
      Serial.println(cardData->champion);
      Serial.print("Game id: ");
      Serial.println(cardData->gameId);
      Serial.print("Player id: ");
      Serial.println(cardData->playerId);
      Serial.print("Is team B?: ");
      Serial.println(cardData->isB);
      Serial.print("Ip Address: ");
      Serial.println(cardData->ipAddress.c_str());
      Serial.print("Port to listen: ");
      Serial.println(cardData->portToListen);
      Serial.print("Wifi SSID: ");
      Serial.println(cardData->wifi.c_str());
      Serial.print("Wifi Password: ");
      Serial.println(cardData->password.c_str());
    }

    //delay(5000);
}