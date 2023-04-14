#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the max number of bytes to compare
 *
 * Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
 */
int _strncmp(const char *s1, const char *s2, size_t n) {
	while (n && *s1 && *s2) {
		if (*s1 != *s2) {
			return (*s1 - *s2);
	}
		--n;
		++s1;
		++s2;
	}
	if (n == 0)
	{
		return 0;
	}
	if (*s1)
	{
		return 1;
	}
	if (*s2)
	{
		return -1;
	}
       	return 0;
}
/**
 * _close - close a file descriptor and print an error message if it fails
 * @fd: the file descriptor to close
 */
void _close(int fd) {
    if (close(fd) != -1) {
        return;
    }
    if (write(STDERR_FILENO, "Error: Can't close fd\n", 22) < 0) {
        exit(98);
    }
    exit(98);
}

/**
 * _read - read from a file and print an error message if it fails
 * @fd: the file descriptor to read from
 * @buf: the buffer to write to
 * @count: the number of bytes to read
 */
void _read(int fd, char *buf, size_t count) {
    if (read(fd, buf, count) != -1) {
        return;
    }
    if (write(STDERR_FILENO, "Error: Can't read from file\n", 28) < 0) {
        exit(98);
    }
    _close(fd);
    exit(98);
}

/**
 * elf_magic - print the ELF magic bytes
 * @buffer: the ELF header
 */
void elf_magic(const unsigned char *buffer) {
    unsigned int i;

    if (_strncmp((const char *) buffer, ELFMAG, 4) != 0) {
        if (write(STDERR_FILENO, "Error: Not an ELF file\n", 23) < 0) {
            exit(98);
        }
        exit(98);
    }

    printf("ELF Header:\n  Magic:   ");

    for (i = 0; i < 16; ++i) {
        printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
    }
}
/**
 * Print the ELF class (bit mode) of the given ELF header.
 *
 * @param buffer - The ELF header.
 * @return The bit mode of the ELF (32 or 64).
 */
size_t elf_class(const unsigned char* buffer) {
    const unsigned char elf_class = buffer[EI_CLASS];

    printf("  %-34s ", "Class:");

    if (elf_class == ELFCLASS32) {
        printf("ELF32\n");
        return 32;
    }

    if (elf_class == ELFCLASS64) {
        printf("ELF64\n");
        return 64;
    }

    printf("<unknown: %x>\n", elf_class);
    return 32;
}

/**
 * Print the ELF data (endianess) of the given ELF header.
 *
 * @param buffer - The ELF header.
 * @return 1 if big endian, otherwise 0.
 */
int elf_data(const unsigned char* buffer) {
    const unsigned char elf_data = buffer[EI_DATA];

    printf("  %-34s ", "Data:");

    switch (elf_data) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            return 0;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            return 1;
        default:
            printf("Invalid data encoding\n");
            return 0;
    }
}

/**
 * Print the ELF version of the given ELF header.
 *
 * @param buffer - The ELF header.
 */
void elf_version(const unsigned char* buffer) {
    const unsigned char elf_version = buffer[EI_VERSION];

    printf("  %-34s %u", "Version:", elf_version);

    if (elf_version == EV_CURRENT) {
        printf(" (current)\n");
    } else {
        printf("\n");
    }
}

/**
 * Print the ELF OS/ABI of the given ELF header.
 *
 * @param buffer - The ELF header.
 */
void elf_osabi(const unsigned char* buffer) {
    const unsigned char elf_osabi = buffer[EI_OSABI];
    const char* os_table[19] = {
        "UNIX - System V",
        "UNIX - HP-UX",
        "UNIX - NetBSD",
        "UNIX - GNU",
        "<unknown: 4>",
        "<unknown: 5>",
        "UNIX - Solaris",
        "UNIX - AIX",
        "UNIX - IRIX",
        "UNIX - FreeBSD",
        "UNIX - Tru64",
        "Novell - Modesto",
        "UNIX - OpenBSD",
        "VMS - OpenVMS",
        "HP - Non-Stop Kernel",
        "AROS",
        "FenixOS",
        "Nuxi CloudABI",
        "Stratus Technologies OpenVOS"
    };

    printf("  %-34s ", "OS/ABI:");

    if (elf_osabi < 19) {
        printf("%s\n", os_table[elf_osabi]);
    } else {
        printf("<unknown: %x>\n", elf_osabi);
    }
}
/**
 * elf_abivers - print ELF ABI version
 * @buffer: the ELF header
 */
void elf_abivers(const unsigned char *buffer) {
    printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - print ELF type
 * @buffer: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *buffer, int big_endian) {
    const char *type_table[5] = {
        "NONE (No file type)",
        "REL (Relocatable file)",
        "EXEC (Executable file)",
        "DYN (Shared object file)",
        "CORE (Core file)"
    };
    unsigned int type;
    
    printf("  %-34s ", "Type:");
    
    if (big_endian) {
        type = (0x100 * buffer[16]) + buffer[17];
    } else {
        type = (0x100 * buffer[17]) + buffer[16];
    }
    
    if (type < 5) {
        printf("%s\n", type_table[type]);
    } else if (type >= ET_LOOS && type <= ET_HIOS) {
        printf("OS Specific: (%4x)\n", type);
    } else if (type >= ET_LOPROC && type <= ET_HIPROC) {
        printf("Processor Specific: (%4x)\n", type);
    } else {
        printf("<unknown: %x>\n", type);
    }
}

/**
 * elf_entry - print entry point address
 * @buffer: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian) {
    int address_size = bit_mode / 8;
    
    printf("  %-34s 0x", "Entry point address:");
    
    if (big_endian) {
        while (address_size && !(*buffer)) {
            --address_size;
            ++buffer;
        }
        
        printf("%x", *buffer & 0xff);
        
        while (--address_size > 0) {
            printf("%02x", *(++buffer) & 0xff);
        }
    } else {
        buffer += address_size;
        
        while (address_size && !(*(--buffer))) {
            --address_size;
        }
        
        printf("%x", *buffer & 0xff);
        
        while (--address_size > 0) {
            printf("%02x", *(--buffer) & 0xff);
        }
    }
    
    printf("\n");
}
/**

main - copy the contents of a file to another file

@argc: the number of arguments

@argv: the argument values

Return: Always 0
*/
int main(int argc, const char *argv[])
{
unsigned char buffer[18];
unsigned int bit_mode;
int big_endian;
int fd;

/* Verify the correct number of arguments */
if (argc != 2)
{
write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
exit(98);
}

/* Open the input file for reading */
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
exit(98);
}

/* Read the first 18 bytes of the file */
_read(fd, (char *) buffer, 18);

/* Extract ELF header information */
elf_magic(buffer);
bit_mode = elf_class(buffer);
big_endian = elf_data(buffer);
elf_version(buffer);
elf_osabi(buffer);
elf_abivers(buffer);
elf_type(buffer, big_endian);

/* Move the file pointer to the entry point address */
lseek(fd, 24, SEEK_SET);
_read(fd, (char *) buffer, bit_mode / 8);

/* Display the entry point address */
elf_entry(buffer, bit_mode, big_endian);

/* Close the input file */
_close(fd);

return (0);
}

