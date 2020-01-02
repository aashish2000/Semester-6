#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>


int main(){
	FILE *fp=fopen("sample.c","r");

	if (fp!=NULL)
	{
		char line[128];
		int i,j=0;
		char tokens[128];
		int quote=0;
		int comment=0;
		char sample[128];
		int flag=0;
		for(i=0;i<128;i++)
		{
			line[i]=NULL;
			sample[i]=NULL;
		}
		while (fgets(line,sizeof line,fp))
		{
			
			/*if(line[0]=='/' && line[1]=='/')
			{
				printf("// - comment\n");
				continue;
			}*/

			for(i=0;i<127;i++)
			{

				if(line[i]=="/" && line[i+1]=="/")
				{
					printf("// - comment");
					break;
				}
				if(line[i]=="/" && line[i+1]=="*")
				{
					printf("/* - multi line comment");
					comment=1;
					continue;
				}
				if(line[i]=="*" && line[i+1]=="/")
				{
					printf("*/ - multi line comment end");
					comment=0;
				}

				if((line[i]=="\"" || line[i]=="\'") && quote==1)
				{
					quote--;
				}
				else if(line[i]=="\"" || line[i]=="\'")
				{
					quote++;
				}

				if((i>0 && line[i]==' ' && isalpha(line[i-1])) && comment==0 && quote==0)
				{
					printf("%s - keyword\n",sample);
				}
				
				sample[i]=line[i];
				//j++;
			}

			//fprintf(stdout,"%s",line);
			
			



			for(i=0;i<128;i++)
			{
				line[i]=NULL;
				sample[i]=NULL;
			}
		}
	}
	else
	{
		perror ("sample.c");
	}
	return 0;
}