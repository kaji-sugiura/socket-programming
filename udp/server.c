#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
    struct sockaddr_in server, client;
    char buffer[256];

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(9999);
    server.sin_family = AF_INET;

    bind(sock, (struct sockaddr *)&server, sizeof(server));

    memset(buffer, 0, sizeof(buffer));

    socklen_t len = sizeof(client);
    recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&client, &len);
    printf("%s\n", buffer);

    close(sock);

    return 0;
}