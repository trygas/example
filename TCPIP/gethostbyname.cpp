#include "general.h"

int main(int argc, char* argv[])
{
    int i;
    struct hostent *host;

    host = gethostbyname(argv[1]);
    if(!host){
        cout << "gethost... error" << endl;
        return 0;
    }

    cout << "Official name: " << host->h_name << endl;

    for(i = 0; host->h_aliases[i]; ++i){
        cout << "Aliases " << i + 1 << ": " << host->h_aliases[i] << endl;
    }

    cout << "Address type: " << (host->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6") << endl;

    for(i = 0; host->h_addr_list[i]; ++i){
        cout << "IP addr " << i + 1
             << ": " << inet_ntoa(*(struct in_addr*)host->h_addr_list[i]) << endl;
    }

    return 0;
}