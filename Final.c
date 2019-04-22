#include <stdio.h>

char caesercypher (char ch, int r);
char subcypher (char ch);
char dubcypher (char ch);

int main()
{
char message[100];
int i = 0;
int cs = 0;
int ed = 0;
int r = 0;
    
printf("Choose Cypher Style\n1 - Caeser\nor\n2 - Substitution?");

scanf("%d", &cs);

printf("Do you wish to:\n1 - Encrypt\nor\n2 - Decrypt?\n");

scanf("%d", &ed);
    
if(cs == 1)
{
    printf ("Enter Rotation Variable: \n");
    scanf ("%d", &r);
};
    
printf ("Enter Message:");
fgets (message, 100, stdin);
    
if (cs == 1)
{
    if (ed == 1)
    {   
        for (i = 0; message[i] != '\0'; ++i)
        {
            message[i] = caesercypher (message[i], r);
        }
        printf ("Encrypted Msg is: %s", message);
    }
    else
    {
        for (i = 0; message[i] != '\0'; ++i)
        {
            message[i] = caesercypher (message[i], -r);
        }
        printf ("Decrypted Msg is: %s", message);
    }
}
else
{
    if (ed == 1)
    {
        for(i = 0; message[i] != '\0'; ++i)
        {
            message[i] = subcypher(message[i]);
        }
        printf("Encrypted Msg is: %s", message);
    }
    else
    {
        for(i = 0; message[i] != '\0'; ++i)
        {
            message[i] = dubcypher(message[i]);
        }
        printf("Decrypted Msg is: %s", message);
    }
}
}

char caesercypher (char ch, int r)
{
    if (ch >= 'A' && ch <= 'z')
    {
        if (ch >= 'a' && ch <= 'z')
	    {
	        ch = ch - 32;
	    }
	    if (ch >= '[' && ch <= '`')
	    {
	        return ch;
	    }
	    
        ch += r;

        if (ch > 'Z')
	    {
	        ch = ch - 'Z' + 'A' - 1;
	    }
	    if (ch < 'A')
	    {
	        ch = ch + 'Z' - 'A' + 1;
	    }  
    }
    return ch;
}

char subcypher (char ch)
{
    int c;

    char key [2][27] =
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "QWERTYUIOPASDFGHJKLZXCVBNM"    
    };
    
    for(c = 0; key[0][c] != '\0'; ++c)
    {   
        if (ch >= 'a' && ch <= 'z')
	    {
	        ch = ch - 32;
	    };
	    
        if (ch == key[0][c])
        {
            return key[1][c];
            break;
        };
    }
    return ch;
    
}

char dubcypher (char ch)
{
    int c;
    char key [2][27] =
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "QWERTYUIOPASDFGHJKLZXCVBNM"    
    };
    
    for(c = 0; key[1][c] != '\0'; ++c)
    {   
        if (ch >= 'a' && ch <= 'z')
	    {
	        ch = ch - 32;
	    };
        if (ch == key[1][c])
        {
            return key[0][c];
            break;
        };
    }
    return ch;
}