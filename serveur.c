#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>

main(){

int id1,len,desc;
char buffer[20];
struct sockaddr_in addr1,addr2;

id1=socket(AF_INET,SOCK_STREAM,0);

addr1.sin_family=AF_INET;
addr1.sin_port=htons(2000);
addr1.sin_addr.s_addr=INADDR_ANY;

bind(id1,(struct sockaddr *)(&addr1),sizeof(addr1));

listen(id1,6);

printf("\nattente de connexion.....\n");


len=sizeof(addr2);

desc=accept(id1,(struct sockaddr *)(&addr2),&len);
printf("\n*********  connexion établie **********\n");


read(desc,buffer,sizeof(buffer));

printf("reçu = %s",buffer);


close(id1);

}
