char * strsepNoLeak(char *stringp, const char *delim, char **remain)
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;
    if ((s = stringp) == NULL)
        return (NULL);
    for (tok = s;;) {
        c = *s++;       //next char
        spanp = delim;  //initialize spanp
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *remain = s;

                return (tok);
            }
        } while (sc != 0);
    }

}


int main(){
    const char *gga = {"$GPGGA,150430.200,2412.1234,N,12042.5678,E,1,7,1.32,186.5,M,15.9,M,,*52\r\n"};
    char *token;
    char *delim = ",*";
    char *s = malloc(sizeof(char)*100), *c1, *c2;

    for(token = strsepNoLeak(s,delim,&c2); token!=NULL ; token = strsepNoLeak(c1, delim,&c2))
        {
            printf("%s\n",token);
            c1=c2;
        }


//test is memory leak?
    int i;
    for(i=0;i<100;i++)
        if(s[i]==0)
            printf(" ");
        else
            printf("%c",s[i]);

    printf("\n%s",gga);

    free(s);

    return 0;
}
