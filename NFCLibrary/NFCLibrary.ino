#include "NFCReader.h"

void setup(void) {
    Serial.begin(115200);
    Serial.println("NDEF Reader");
    Setup();
}

void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    CardData cardData = ReadCard();
    delay(5000);
}