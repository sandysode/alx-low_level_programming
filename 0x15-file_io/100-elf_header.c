#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	Elf64_Ehdr header;
	ssize_t r = read(fd, &header, sizeof(Elf64_Ehdr));
	if (r != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close_elf(fd);
		return (EXIT_FAILURE);
	}

	check_elf(header.e_ident);
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close_elf(fd);
	return (EXIT_SUCCESS);
}
