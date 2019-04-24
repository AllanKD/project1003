#include <stdio.h>

char subcypher (char);  //function definition

int main(void)
{
    printf ("Enter Message: ");
    scanf("%s", message);
    
    for(i = 0; message[i] != '\0'; ++i)
    {
        message[i] = subcypher(message[i]);
    }
    printf("Encrypted Msg is: %s", message);
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
