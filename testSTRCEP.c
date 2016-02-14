#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strsep(char **stringp, const char *delim)
{
   char *s;
   const char *spanp;
   int c, sc;
     char *tok;
     if ((s = *stringp) == NULL)
         return (NULL);
     for (tok = s;;) {
         c = *s++;
         spanp = delim;
         do {
             if ((sc = *spanp++) == c) {
                 if (c == 0)
                     s = NULL;
                 else
                     s[-1] = 0;
                 *stringp = s;
                 return (tok);
             }
         } while (sc != 0);
     }
  /* NOTREACHED */
 }



 int main(){
     const char *gga = {"$GPGGA,150430.200,2412.1234,N,12042.5678,E,1,7,1.32,186.5,M,15.9,M,,*52\r\n"};
     char *token;
     char *delim = ",*";
     char *s = malloc(sizeof(char)*100), *c=s;

     strcpy(s,gga);
     for(token = strsep(&s,delim); token!=NULL ; token = strsep(&s, delim))
         {
             printf("%s\n",token);
         }

 //test is memory leak?
     int i;
     for(i=0;i<100;i++)
         if(c[i]==0)
             printf(" ");
         else
             printf("%c",c[i]);
     printf("\n%s",gga);

     free(c);
     return 0;
}
