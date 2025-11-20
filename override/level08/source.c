#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// -------------------------------------------------------------
// Helper: log_wrapper
// -------------------------------------------------------------
void log_wrapper(FILE *log, char *msg, char *filename)
{
    char buffer[264];

    strcpy(buffer, msg);
    size_t len = strlen(buffer);
    snprintf(buffer + len, 254 - len, "%s", filename);

    buffer[strcspn(buffer, "\n")] = '\0'; // remove newline
    fprintf(log, "LOG: %s\n", buffer);
}

// -------------------------------------------------------------
// Main
// -------------------------------------------------------------
int main(int argc, char **argv)
{
    FILE *log_file;
    FILE *input_file;
    int fd;
    char byte;
    char filename_buf[104]; // stack var for file path
    int ret;

    byte = 0xFF;
    fd = -1;

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
    }

    // open ./backups/.log for logging
    log_file = fopen("./backups/.log", "w");
    if (!log_file) {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }

    // log the filename
    log_wrapper(log_file, "Starting back up: ", argv[1]);

    // open source file (the one to copy)
    input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }

    // build destination path "./backups/<filename>"
    strcpy(filename_buf, "./backups/");
    strncat(filename_buf, argv[1], 99 - strlen(filename_buf));

    // open destination file with permissions 0641
    fd = open(filename_buf, O_WRONLY | O_CREAT | O_EXCL, 432);
    if (fd < 0) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    // copy file byte by byte
    while (1)
    {
        byte = fgetc(input_file);
        if (byte == -1) {
            break ;
        }
        write(fd, &byte, 1);
    }

    // log completion
    log_wrapper(log_file, "Finished back up: ", argv[1]);

    fclose(input_file);
    close(fd);
    return 0;
}
