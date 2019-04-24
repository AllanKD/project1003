#include <stdio.h>

char dubcypher (char);

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