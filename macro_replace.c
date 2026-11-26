#include "header.h"

int str_str(char *m,char *s)
{
        while(*s)
        {
                if(*s!=*m)
                        return 0;
                s++,m++;
        }
        return 1;
}
void replace(char *m,char *o,char *n)
{
        char temp[1024];
        int i=0,j=0,k,ol,nl;
        int in_string=0;

        for(ol=0;o[ol];ol++);
        for(nl=0;n[nl];nl++);

        while(m[i])
        {
                if(m[i]=='"')
                {
                        temp[j++]=m[i++];
                        in_string=!in_string;
                }
                else if(!in_string && str_str(&m[i],o))
                {
                        for(k=0;k<nl;k++)
                                temp[j++]=n[k];
                        i+=ol;
                }
                else
                {
                        temp[j++]=m[i++];
                }
        }

        temp[j]='\0';
        strcpy(m,temp);
}
void macro(char *file)
{
        FILE *fp=fopen(file,"r"),*dp,*sf;
        int c=large_line(fp),pl,i,j,k,sl;
        char *s=malloc(c+1),p[10]="#define",ol[20],nl[20],*t=malloc(c+1);

        for(pl=0;p[pl];pl++);

        while(fgets(s,c+1,fp))
        {
                for(sl=0;s[sl];sl++);

                for(i=0;i<=sl;i++)
                {
                        if(s[i]==p[0])
                        {
                                if(str_str(&s[i],p))
                                {
                                        dp=fopen("temp","w");
                                        sf=fopen("data","r");

                                        for(j=i+pl+1,k=0;s[j]!=' ';j++,k++)
                                                ol[k]=s[j];
                                        ol[k]='\0';

                                        for(j=j+1,k=0;s[j]!='\n';j++,k++)
                                                nl[k]=s[j];
                                        nl[k]='\0';

                                        while(fgets(t,c+1,sf))
                                        {
                                                if(str_str(t,p))
                                                        fputs("\n",dp);
                                                else if(strstr(t,ol))
                                                {
                                                        replace(t,ol,nl);
                                                        fputs(t,dp);
                                                }
                                                else
                                                        fputs(t,dp);
                                        }

                                        fclose(sf);
                                        fclose(dp);

                                        remove("data");
                                        rename("temp","data");
                                }
                        }
                }
        }

        fclose(fp);

        char ch;
        int fl;

        for(fl=0;file[fl];fl++);
        file[fl-1]='i';

        fp=fopen(file,"w");
        dp=fopen("data","r");

        while((ch=fgetc(dp))!=EOF)
                fputc(ch,fp);

        fclose(fp);
        fclose(dp);

        free(s);
        free(t);
}





