#include <stdio.h>


char caesercypher (char ch, int r);
char subcypher (char ch);
char dubcypher (char ch);

int main(void)

{
    
char message[100];  //  message storage
int i = 0;          //  counter for "for" loop used to pass individual letters for ecrypt/decrypt
int cs = 0;         //  flow control - caeser or sust
int ed = 0;         //  flow control - encrypt or decrypt
int r = 0;          //  rotation variable for caeser cypher
    
printf("Choose Cypher Style \n1 - Caeser\nor\n2 - Substitution? ");
scanf("%d", &cs);
printf("Do you wish to:\n1 - Encrypt\nor\n2 - Decrypt? ");
scanf("%d", &ed);
printf ("Enter Rotation Variable: ");
scanf ("%d", &r);
printf ("Enter Message: ");
scanf("%s", message);
    
if (cs == 1)
{
    if (ed == 1)
    {   
        for (i = 0; message[i] != '\0'; ++i)    // passes individual letters to cypher function
        {
            message[i] = caesercypher (message[i], r);
        }
        printf ("Encrypted Msg is: %s", message);
    }
    else
    {
        for (i = 0; message[i] != '\0'; ++i)
        {
            r = -1*r;           // neg value r used to roll cypher backwards
            message[i] = caesercypher (message[i], r);
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

char caesercypher (char ch, int r)      // caeser cypher function
{
    if (ch >= 'A' && ch <= 'z')
    {
        if (ch >= 'a' && ch <= 'z')
	    {
	        ch = ch - 32;              // converts to capitals
	    }
	    if (ch >= '[' && ch <= '`')    // returns non alpha characters between z and A
	    {
	        return ch;
	    }
	    
        ch += r;                        // impliments rotation

        if (ch > 'Z')                   // re wraps rotation were it falls of the end
	    {
	        ch = ch - 'Z' + 'A' - 1;
	    }
	    if (ch < 'A')                   // as previous comment
	    {
	        ch = ch + 'Z' - 'A' + 1;
	    }  
    }
    return ch;                          // returns any other non alpha chars
}

char subcypher (char ch)                // substitution cypher function
{
    int c;

    char key [2][27] =
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",   // substitution key
        "QWERTYUIOPASDFGHJKLZXCVBNM"    
    };
    
    for(c = 0; key[0][c] != '\0'; ++c)  // test letter provided against the key
    {   
        if (ch >= 'a' && ch <= 'z')     // converts to capitals
	    {
	        ch = ch - 32;
	    };
	    
        if (ch == key[0][c])             // if key test positve substitutes for same value is second string
        {
            return key[1][c];
            break;
        };
    }
    return ch;                          // returns non alpha chars
    
}

char dubcypher (char ch)                // see above function (just reverses the key)
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