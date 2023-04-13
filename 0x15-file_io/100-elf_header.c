#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *headline);
void print_magic(unsigned char *headline);
void print_class(unsigned char *headline);
void print_data(unsigned char *headline);
void print_version(unsigned char *headline);
void print_abi(unsigned char *headline);
void print_osabi(unsigned char *headline);
void print_type(unsigned int typo, unsigned char *headline);
void print_entry(unsigned long int entrance, unsigned char *headline);
void close_elf(int elf);

/**
 * check_elf - This Checks if a file is an ELF file.
 * @headline: This is a pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *headline)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (headline[index] != 127 &&
		    headline[index] != 'E' &&
		    headline[index] != 'L' &&
		    headline[index] != 'F')
		{
			dprintf(STDERR_FILENO, "err: Not an ELF file\n");
			exit(98);
		}
	}
}


void print_magic(unsigned char *headline)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", headline[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


void print_class(unsigned char *headline)
{
	printf("  Class:                             ");

	switch (headline[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", headline[EI_CLASS]);
	}
}

void print_data(unsigned char *headline)
{
	printf("  Data:                              ");

	switch (headline[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", headline[EI_CLASS]);
	}
}


void print_version(unsigned char *headline)
{
	printf("  Version:                           %d",
	       headline[EI_VERSION]);

	switch (headline[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


void print_osabi(unsigned char *headline)
{
	printf("  OS/ABI:                            ");

	switch (headline[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", headline[EI_OSABI]);
	}
}

void print_abi(unsigned char *headline)
{
	printf("  ABI Version:                       %d\n",
	       headline[EI_ABIVERSION]);
}


void print_type(unsigned int typo, unsigned char *headline)
{
	if (headline[EI_DATA] == ELFDATA2MSB)
		typo >>= 8;

	printf("  Type:                              ");

	switch (typo)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", typo);
	}
}


void print_entry(unsigned long int entrance, unsigned char *headline)
{
	printf("  Entry point address:               ");

	if (headline[EI_DATA] == ELFDATA2MSB)
	{
		entrance = ((entrance << 8) & 0xFF00FF00) |
			  ((entrance >> 8) & 0xFF00FF);
		entrance = (entrance << 16) | (entrance >> 16);
	}

	if (headline[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entrance);

	else
		printf("%#lx\n", entrance);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"err: Can't close fd %d\n", elf);
		exit(98);
	}
}


int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "err: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "err: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "err: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->headline);
	printf("ELF Header:\n");
	print_magic(header->headline);
	print_class(header->headline);
	print_data(header->headline);
	print_version(header->headline);
	print_osabi(header->headline);
	print_abi(header->headline);
	print_type(header->typo, header->headline);
	print_entry(header->entrance, header->headline);

	free(header);
	close_elf(o);
	return (0);
}
