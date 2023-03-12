#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(9999);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    char *message = "Hello Server";

    send(sock, message, strlen(message), 0);

    close(sock);
    return 0;
}