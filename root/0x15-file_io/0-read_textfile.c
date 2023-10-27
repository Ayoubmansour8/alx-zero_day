#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: Text file being read.
 * @letters: Number of letters to be read.
 * Return: The actual number of bytes read and printed.
 *         0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    char *buffer = (char *)malloc(letters + 1);
    if (buffer == NULL) {
        fclose(file);
        perror("Memory allocation error");
        return 0;
    }

    ssize_t bytes_read = fread(buffer, 1, letters, file);
    buffer[bytes_read] = '\0';

    fclose(file);
    printf("%s", buffer); // Print the contents to STDOUT (optional)
    free(buffer);
    return bytes_read;
}

