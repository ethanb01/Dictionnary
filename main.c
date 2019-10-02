#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_translate(char*,char*);

int main(int argc ,char ** argv){
	
	argv[1] ="text.txt";
	FILE *src = fopen(argv[1],"r");
	FILE *temp = fopen("temp.txt","w+");
	char buf[32];
	if(src==NULL){
		printf("Could not open FILE %s\n",argv[1]);
		return -2;
	}
	while(fscanf(src, "%s", buf) != EOF)
    {
        fprintf(temp,"%s ", get_translate(buf,argv[2]));
    }
    fclose(src);
    fclose(temp);

	src = fopen(argv[1],"w+");
	temp = fopen("temp.txt","r");
	int c;
 	while( ( c = fgetc(temp) ) != EOF )
    	fputc(c, src);
    fclose(src);
    fclose(temp);
    int status = remove("temp.txt");
    if (status == 0)
    	printf("%s file deleted successfully.\n", "temp.txt");
  	else
  	{
    	printf("Unable to delete the file\n");
	    perror("Following error occurred");
  	}

	return 0;

}

char* get_translate(char* word,char* argv2){

	argv2 ="dic.txt";
	FILE *dic = fopen(argv2,"r");
	char *buf  = (char*)malloc(sizeof(char)*32);
	if(dic==NULL){
		printf("Could not open FILE %s\n",argv2);
		exit(1);
	}
	while(fscanf(dic, "%s", buf) != EOF)
    {
        if(strcmp(word,buf)==0)
        	if(fscanf(dic ,"%s", buf))
        		return buf;
    }
    fclose(dic);
    return word;
}