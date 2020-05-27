#include "general.h"

#define BUF_SIZE 1024
#define OPSZ 4
#define RLT_SIZE 4

int main(int argc, char *argv[])
{
    int sock;
    char opmsg[BUF_SIZE];
    int result, opnd_cnt, i;
    struct sockaddr_in serv_adr;
    if(argc != 3){
        cout << "Usage port: " << argv[0] << endl;
        return 0;
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        cout << "socket() error" << endl;
        return 0;
    }

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1){
        cout << "connect error" << endl;
        return 0;
    }
    else
        cout << "connected" << endl;

    fputs("Operand count: ", stdout);
    scanf("%d", &opnd_cnt);
    opmsg[0] = (char)opnd_cnt;

    for(i = 0; i < opnd_cnt; ++i){
        cout << "operated " << i + 1 << ": ";
        scanf("%d", (int*)&opmsg[i * OPSZ + 1]);
    }

    fgetc(stdin);
    fputs("Operator: ", stdout);
    scanf("%c", &opmsg[opnd_cnt * OPSZ + 1]);
    write(sock, opmsg, opnd_cnt * OPSZ + 2);
    read(sock, &result, RLT_SIZE);

    cout << "result: " << result;
    close(sock);
    return 0;
}