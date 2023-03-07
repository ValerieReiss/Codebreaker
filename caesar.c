#include <stdio.h>
#include <stdlib.h>
#define NL printf("\n")

FILE *f1;
FILE *f2;

char encrypt(char buchstabe,int key)
{
  if(isalpha(buchstabe))
   {
   buchstabe = toupper(buchstabe);               //grossbuchstaben 
   buchstabe = (buchstabe -'A' + key) %26+'A';     //variable verändern 
   if(buchstabe<'A') buchstabe=buchstabe+'A';
   }
   return buchstabe;
}
      
char decrypt(char buchstabe,int key)
{
  if(isalpha(buchstabe))
   {
   buchstabe = toupper(buchstabe);               //grossbuchstaben
   buchstabe = buchstabe -'A';                   //ermittelt abstand
   if (buchstabe<key)
    {
      buchstabe='Z'-key +buchstabe;              //geht von Z runter
    }
   else
    {
      buchstabe= (buchstabe + key) %26+'A';      //geht bei A hoch
    }
   }
   return buchstabe;
}

char Codeknacker(char buchstabe)
{
  struct ziffern {
  char feld[25];
  int vari;                    // hier gehts weiterrrr
  }ABC;
  char feld[]={'A','B','C','D','E','F','G','H','I',
               'J','K','L','M','N','O','P','Q','R',
	       'S','T','U','V','W','X','Y','Z'};			     
  if(isalpha(buchstabe))
  {
   int i;
   buchstabe = toupper(buchstabe);
    for(i=0;i<26;i++)
    {
     if(buchstabe == feld[i])
      {}
     else
      {}
    }
  }
}
      
int main(int argc, char *argv[])
{
 int key;
 if (argc == 4)
    {
     key = atoi(argv[3]);
        printf("%d",key);NL;
        char buchstabe;
        f1=fopen(argv[1],"r");                   //öffnet Datei 1
        if(f1==NULL) 
         {fprintf(stderr,"ERROR 1");NL;exit(1);}
        else 
        {
          f2=fopen(argv[2],"w");                //öffnet Datei 2
          if(f2==NULL)
           {fprintf(stderr,"ERROR 2");NL;exit(2);}
          else
           {
	      while(1)
	      {
               buchstabe = fgetc(f1);              //lesen zeichen
	       if(feof(f1))
	          {break;}
	       else
                  {if(key>=0)
		   {
		     buchstabe = encrypt(buchstabe,key);
		   }
		   else
		   {
		     buchstabe = decrypt(buchstabe,key);
		   }
                   fputc(buchstabe,f2);}           //schreiben zeichen
	      }
           }
        }
    }
 else if (argc == 3)
  {
   printf("Codeknacker");               // Code knacken!!!
   char buchstabe;
   f1=fopen(argv[1],"r");
   if(f1==NULL)
     {fprintf(stderr,"ERROR 3");NL;exit(3);}
   else
     {
      f2=fopen(arg[2],"w");
      if(f2==NULL)
      {fprintf(stderr,"ERROR 4");NL;exit(4);}
      else
      {
       while(1)
       {
        buchstabe = fgetc(f1);
	if(feof(f1))
	   {break;}
	else
	   {//blablababla}
       }
      }
     }
  }
 else
  {
   printf("Wrong entry");
  }
  fclose(f1);
  fclose(f2);
  return 0;
}
