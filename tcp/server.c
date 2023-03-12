#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    struct sockaddr_in server, client;
    char buffer[256];

    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 1);

    while(1) {
        socklen_t len = sizeof(client);
        int sock2 = accept(sock, (struct sockaddr *)&client, &len);
        recv(sock2, buffer, sizeof(buffer), 0);
        printf("%s\n", buffer);
        close(sock2);
    }

    close(sock);

    return 0;
}