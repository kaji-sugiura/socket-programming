#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    struct sockaddr_in server, client;
    char buffer[256], sndbuffer[256];

    memset(sndbuffer, 0, sizeof(sndbuffer));
    snprintf(sndbuffer, sizeof(sndbuffer),
    "HTTP/1.1 200 OK\r\n"
    "Date: Mon, 12 Mar 2023 15:00:00 GMT\r\n"
    "Server: Apache/2.2\r\n"
    "Content-Length: 12\r\n"
    "\r\n"
    "HELLO WORLD\r\n");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 1);

    while(1) {
        socklen_t len = sizeof(client);
        int sock2 = accept(sock, (struct sockaddr *)&client, &len);
        recv(sock2, buffer, sizeof(buffer), 0);
        send(sock2, sndbuffer, sizeof(sndbuffer), 0);
        close(sock2);
    }

    close(sock);

    return 0;
}