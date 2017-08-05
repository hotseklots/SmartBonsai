/*
 * WifiOperations.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */
#include "ESP8266WiFi.h"
#include "WifiOperations.h"

CWifiOperations::CWifiOperations() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
}

void CWifiOperations::waitForUserResponse(char* buffer, uint8_t length) {
    char inByte;
    int bufferPointer = 0;

    while (true) {
        if (Serial.available()) {
            inByte = Serial.read();
            Serial.write(inByte);
            if (inByte == '\r') {
                // 'newline' character
                buffer[bufferPointer++] = '\0';
                bufferPointer = 0;
                return;
            } else {
                // not a 'newline' character
                if (bufferPointer < length - 1) // Leave room for a null terminator
                    buffer[bufferPointer++] = inByte;
            }
        }
    }
}

void CWifiOperations::getSSID(char* ssid, uint8_t length) {
    uint8_t wifiIndex = 0;

    waitForUserResponse(ssid, length);
    wifiIndex = atoi(ssid);
    String ssidString = WiFi.SSID(wifiIndex);
    ssidString.toCharArray(ssid, length, 0);
}

void CWifiOperations::getPassword(char* password, uint8_t length) {
    waitForUserResponse(password, length);
}

bool CWifiOperations::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

String CWifiOperations::getSSID() {
    return String(m_ssid);
}

bool CWifiOperations::selectWifi() {
    Serial.println("scan start");
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0)
        Serial.println("no networks found");
    else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println(
                    (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
        }
    }
    Serial.println("");

    Serial.println("Select network:");
    getSSID(m_ssid, BUFFERSIZE);
    Serial.println();

    Serial.println("enter password:");
    getPassword(m_password, BUFFERSIZE);
    Serial.println();

    return this->reconnect();
}

bool CWifiOperations::reconnect() {
    WiFi.begin(m_ssid, m_password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        if (WiFi.status() == WL_CONNECT_FAILED) {
            Serial.println("Invalid Password");
            return false;
        }
    }

    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());

    return false;
}
