#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")

#define TARGET_IP   "127.0.0.1"
#define TARGET_PORT 5555
#define LOCAL_PORT  8888
#define BUFFER_LEN  1024

void InitWinsock() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

int main() {
    InitWinsock();

    SOCKET socketS = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addrDest;

    addrDest.sin_family = AF_INET;
    addrDest.sin_port = htons(TARGET_PORT);
    InetPton(AF_INET, _T(TARGET_IP), &addrDest.sin_addr.s_addr);

    std::ifstream file("path_to_your_file", std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        printf("Failed to open the file!\n");
        return 1;
    }

    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    char buffer[BUFFER_LEN];
    sprintf(buffer, "START %zu", fileSize);
    sendto(socketS, buffer, strlen(buffer), 0, (sockaddr*)&addrDest, sizeof(addrDest));

    size_t totalSent = 0;
    while (totalSent < fileSize) {
        file.read(buffer, BUFFER_LEN);
        int bytesRead = file.gcount();
        sendto(socketS, buffer, bytesRead, 0, (sockaddr*)&addrDest, sizeof(addrDest));
        totalSent += bytesRead;
    }

    sprintf(buffer, "END");
    sendto(socketS, buffer, strlen(buffer), 0, (sockaddr*)&addrDest, sizeof(addrDest));

    file.close();
    closesocket(socketS);
    WSACleanup();
    return 0;
}
s