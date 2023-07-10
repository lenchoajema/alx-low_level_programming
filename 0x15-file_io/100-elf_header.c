#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* len_strncmp - compare two strings
* @len_s1: the first string
* @len_s2: the second string
* @len_n: the max number of bytes to compare
*
* Return: 0 if the first n bytes of s1 and s2 are equal, otherwise non-zero
*/
int len_strncmp(const char *len_s1, const char *len_s2, size_t len_n)
{
while (len_n && *len_s1 && *len_s2)
{
if (*len_s1 != *len_s2)
return (*len_s1 - *len_s2);
--len_n;
++len_s1;
++len_s2;
}
if (len_n == 0)
return (0);
if (*len_s1)
return (1);
if (*len_s2)
return (-1);
return (0);
}

/**
* len_close - close a file descriptor and print an error message if it fails
* @len_fd: the file descriptor to close
*/
void len_close(int len_fd)
{
if (close(len_fd) != -1)
return;
if (write(STDERR_FILENO, "Error: Can't close fd\n", 22) < 0)
exit(98);
exit(98);
}

/**
* len_read - read from a file and print an error message if it fails
* @len_fd: the file descriptor to read from
* @len_buf: the buffer to write to
* @len_count: the number of bytes to read
*/
void len_read(int len_fd, char *len_buf, size_t len_count)
{
if (read(len_fd, len_buf, len_count) != -1)
return;
if (write(STDERR_FILENO, "Error: Can't read from file\n", 28) < 0)
exit(98);
len_close(len_fd);
exit(98);
}

/**
* elf_magic - print the ELF magic bytes
* @len_buffer: the ELF header
*/
void elf_magic(const unsigned char *len_buffer)
{
unsigned int i;

if (len_strncmp((const char *)len_buffer, ELFMAG, 4) != 0)
{
if (write(STDERR_FILENO, "Error: Not an ELF file\n", 23) < 0)
exit(98);
exit(98);
}

printf("ELF Header:\n  Magic:   ");

for (i = 0; i < 16; ++i)
{
printf("%02x%c", len_buffer[i], i < 15 ? ' ' : '\n');
}
}

/**
* elf_class - print the ELF class (bit mode) of the given ELF header
* @len_buffer: the ELF header
* @return: The bit mode of the ELF (32 or 64)
*/
size_t elf_class(const unsigned char *len_buffer)
{
const unsigned char len_elf_class = len_buffer[EI_CLASS];

printf("  %-34s ", "Class:");

if (len_elf_class == ELFCLASS32)
{
printf("ELF32\n");
return (32);
}

if (len_elf_class == ELFCLASS64)
{
printf("ELF64\n");
return (64);
}

printf("<unknown: %x>\n", len_elf_class);
return (32);
}

/**
* elf_data - print the ELF data (endianess) of the given ELF header
* @len_buffer: the ELF header
* @return: 1 if big endian, otherwise 0
*/
int elf_data(const unsigned char *len_buffer)
{
const unsigned char len_elf_data = len_buffer[EI_DATA];

printf("  %-34s ", "Data:");

switch (len_elf_data)
{
case ELFDATA2LSB:
printf("2's complement, little endian\n");
return (0);
case ELFDATA2MSB:
printf("2's complement, big endian\n");
return (1);
default:
printf("Invalid data encoding\n");
return (0);
}
}

/**
* elf_version - print the ELF version of the given ELF header
* @len_buffer: the ELF header
*/
void elf_version(const unsigned char *len_buffer)
{
const unsigned char len_elf_version = len_buffer[EI_VERSION];

printf("  %-34s %u", "Version:", len_elf_version);

if (len_elf_version == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");
}

/**
* elf_osabi - print the ELF OS/ABI of the given ELF header
* @len_buffer: the ELF header
*/
void elf_osabi(const unsigned char *len_buffer)
{
const unsigned char len_elf_osabi = len_buffer[EI_OSABI];
const char *os_table[19] = {
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

if (len_elf_osabi < 19)
printf("%s\n", os_table[len_elf_osabi]);
else
printf("<unknown: %x>\n", len_elf_osabi);
}

/**
* elf_abivers - print ELF ABI version
* @len_buffer: the ELF header
*/
void elf_abivers(const unsigned char *len_buffer)
{
printf("  %-34s %u\n", "ABI Version:", len_buffer[EI_ABIVERSION]);
}
/**
* elf_type - print ELF type
* @len_buffer: the ELF header
* @len_big_endian: endianness (big endian if non-zero)
*/
void elf_type(const unsigned char *len_buffer, int len_big_endian) 
{
const char *len_type_table[5] = {
"NONE (No file type)",
"REL (Relocatable file)",
"EXEC (Executable file)",
"DYN (Shared object file)",
"CORE (Core file)"
};
unsigned int len_type;

printf("  %-34s ", "Type:");

if (len_big_endian) 

len_type = (0x100 * len_buffer[16]) + len_buffer[17];
else 

len_type = (0x100 * len_buffer[17]) + len_buffer[16];


if (len_type < 5) 

printf("%s\n", len_type_table[len_type]);

else if (len_type >= ET_LOOS && len_type <= ET_HIOS) 

printf("OS Specific: (%4x)\n", len_type);

else if (len_type >= ET_LOPROC && len_type <= ET_HIPROC) 

printf("Processor Specific: (%4x)\n", len_type);

else 

printf("<unknown: %x>\n", len_type);

}

/**
* elf_entry - print entry point address
* @len_buffer: string containing the entry point address
* @len_bit_mode: bit mode (32 or 64)
* @len_big_endian: endianness (big endian if non-zero)
*/
void elf_entry(const unsigned char *len_buffer, size_t len_bit_mode, int len_big_endian) {
int len_address_size = len_bit_mode / 8;

printf("  %-34s 0x", "Entry point address:");

if (len_big_endian) {
while (len_address_size && !(*len_buffer)) {
--len_address_size;
++len_buffer;
}

printf("%x", *len_buffer & 0xff);

while (--len_address_size > 0) 
printf("%02x", *(++len_buffer) & 0xff);

} 
else {
len_buffer += len_address_size;

while (len_address_size && !(*(--len_buffer)))
--len_address_size;


printf("%x", *len_buffer & 0xff);

while (--len_address_size > 0) {
printf("%02x", *(--len_buffer) & 0xff);
}
}

printf("\n");
}

/**
* main - copy the contents of a file to another file
* @len_argc: the number of arguments
* @len_argv: the argument values
*
* Return: Always 0
*/
int main(int len_argc, const char *len_argv[]) 
{
unsigned char len_buffer[18];
unsigned int len_bit_mode;
int len_big_endian;
int len_fd;

/* Verify the correct number of arguments */
if (len_argc != 2) {
write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
exit(98);
}

/* Open the input file for reading */
len_fd = open(len_argv[1], O_RDONLY);
if (len_fd == -1) {
write(STDERR_FILENO, "Error: Can't read from file\n", 28);
exit(98);
}

/* Read the first 18 bytes of the file */
len_read(len_fd, (char *)len_buffer, 18);

/* Extract ELF header information */
elf_magic(len_buffer);
len_bit_mode = elf_class(len_buffer);
len_big_endian = elf_data(len_buffer);
elf_version(len_buffer);
elf_osabi(len_buffer);
elf_abivers(len_buffer);
elf_type(len_buffer, len_big_endian);

/* Move the file pointer to the entry point address */
lseek(len_fd, 24, SEEK_SET);
len_read(len_fd, (char *)len_buffer, len_bit_mode / 8);

/* Display the entry point address */
elf_entry(len_buffer, len_bit_mode, len_big_endian);

/* Close the input file */
len_close(len_fd);

return (0);
}
