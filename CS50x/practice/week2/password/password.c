// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool upper = false, lower = false, number = false, symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]) != 0)
        {
            upper = true;
        }
        else if (islower(password[i]) != 0)
        {
            lower = true;
        }
        else if (isdigit(password[i]) != 0)
        {
            number = true;
        }
        else if (!isalnum(password[i]))
        {
            symbol = true;
        }
    }

    if (upper == true && lower == true && number == true && symbol == true)
    {
        return true;
    }
    return false;
}
