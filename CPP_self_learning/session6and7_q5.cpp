#include <iostream>
using namespace std;
size_t my_strlen(const char *str)
{
    size_t length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
char *my_strcpy(char *dest, const char *src)
{
    char *ptr = dest;
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}
int main()
{
    const char *source = "Hello, World!";
    char destination[50]; 

    cout << "Length of source string: " << my_strlen(source) << endl;

    my_strcpy(destination, source);
    cout << "Copied string: " << destination << endl;

    return 0;
}
