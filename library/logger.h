#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

struct Logger {
    FILE *file;
    int print_to_console;
};

struct Logger GLOBAL_LOGGER;

void init_logger(const char *file_name, int print_to_console)
{
    GLOBAL_LOGGER.file = fopen(file_name, "w+");
    if (GLOBAL_LOGGER.file == NULL)
    {
        perror("Failed to open file for writing logs");
        abort();
    }
    GLOBAL_LOGGER.print_to_console = print_to_console;
}

void init_dummy_logger()
{
    init_logger("log.txt", 0);
}

void log_message(const char *message, ...)
{
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    char* time_str = asctime(tm_now);
    time_str[strlen(time_str) - 1] = '\0'; // удаляем перевод на новую строку
    
    va_list args;
    va_start(args, message);
    if (GLOBAL_LOGGER.print_to_console)
    {
        printf("[%s] ", time_str);
        vprintf(message, args);
        printf("\n");
    }
    fprintf(GLOBAL_LOGGER.file, "[%s] ", time_str);
    vfprintf(GLOBAL_LOGGER.file, message, args);
    fprintf(GLOBAL_LOGGER.file, "\n");
    va_end(args);
}