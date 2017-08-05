/*
 * WifiOperations.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef WIFIOPERATIONS_H_
#define WIFIOPERATIONS_H_

class CWifiOperations {
public:
    static const uint8_t BUFFERSIZE = 64; //!< buffersize is also maximum password and ssid length

    CWifiOperations();

    /**
     * select wifi through the terminal
     * @return true if connected false otherwise
     */
    bool selectWifi();

    /**
     * Reconnect to last selected Wifi
     * @return true if connected false otherwise
     */
    bool reconnect();

    /**
     * Disconnect and disable wifi
     * @return true if success false otherwise
     */
    bool disconnect();

    /**
     * Gets if currently connectd to a network
     * @return true if connected, false otherwise
     */
    bool isConnected();

    /**
     * Gets the SSID of the current network
     */
    String getSSID();

private:

    char m_ssid[BUFFERSIZE]; //!< ssid of connected network
    char m_password[BUFFERSIZE]; //!< password of the connected network

    /**
     * gets user response for the terminal
     *
     * @buffer buffer in which the data input by the user is written
     * @length buffer lenght
     */
    void waitForUserResponse(char* buffer, uint8_t length);

    /**
     * gets the SSD from the current SSID map based on user input
     *
     * @buffer buffer in which the data input by the user is written
     * @length buffer lenght
     */
    void getSSID(char* ssid, uint8_t length);

    /**
     * gets the password based on user input
     *
     * @buffer buffer in which the data input by the user is written
     * @length buffer lenght
     */
    void getPassword(char* password, uint8_t length);
};

#endif /* WIFIOPERATIONS_H_ */
