#include "hash_tables.h"

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @len_str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *len_str)
{
    unsigned long int len_hash;
    int len_c;

    len_hash = 5381;
    while ((len_c = *len_str++))
    {
        len_hash = ((len_hash << 5) + len_hash) + len_c; /* len_hash * 33 + len_c */
    }
    return (len_hash);
}
