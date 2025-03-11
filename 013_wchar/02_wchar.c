#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>


#define BUFFER_LENGTH 255

int main()
{
    setlocale(LC_ALL, "C.utf8");
    wchar_t c;
    printf("sizeof(wchar): %ld byte\n", sizeof(wchar_t));

    wchar_t wstr[BUFFER_LENGTH];
    fgetws(wstr, BUFFER_LENGTH, stdin);
    printf("My string: %ls", wstr);

    size_t num_of_symbols = wcslen(wstr);
    printf("Length: %ld\n", num_of_symbols);

    return 0;
}