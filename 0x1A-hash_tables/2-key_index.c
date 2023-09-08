#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: key to get index for
 * @len: size of the hash table
 *
 * Return: index for the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int len)
{
    return (hash_djb2(key) % len);
}
