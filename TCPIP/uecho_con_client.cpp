#include "general.h"

#define BUF_SIZE 30
int main(int argc, char *argv[])
{
    int sock;
    char message[BUF_SIZE];
    int str_len;
    socklen_t adr_sz;
    struct sockaddr_in serv_adr, from_adr;

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1){
        cout << "socket error" << endl;
        return 0;
    }

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    while(1){
        fputs("Insert message (q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;

        write(sock, message, strlen(message));
        str_len = read(sock, message, sizeof(message) - 1);
        printf("message from server: %s", message);
    }
    close(sock);
    return 0;
}