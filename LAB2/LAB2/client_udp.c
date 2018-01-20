#include <stdio.h>     //UDP PROGRAMMING
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0,n;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5001);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    // if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    // {
    //     printf("\nInvalid address/ Address not supported \n");
    //     return -1;
    // }

    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
    
    char s[256];
    scanf("%s",s);
    sendto(sock , s, strlen(s) , 0,(struct sockaddr * )&serv_addr,sizeof(serv_addr));
    
    return 0;
}
