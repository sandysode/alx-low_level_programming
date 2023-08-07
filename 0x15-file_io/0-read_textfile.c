#include "main.h"

/**
 * read_textfile - Reads a text file n prints it to the POSIX stnd output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         If the file cannot be opened or read, return 0.
 *         If filename is NULL, return 0.
 *         If write fails or doesnt write the expected amount of bytes, ret 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
		return (0);

	char *buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	ssize_t read_chars = fread(buffer, sizeof(char), letters, file);
	if (read_chars == -1)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	ssize_t written_chars = write(STDOUT_FILENO, buffer, read_chars);
	if (written_chars == -1 || written_chars != read_chars)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	fclose(file);
	free(buffer);

	return (written_chars);
}
