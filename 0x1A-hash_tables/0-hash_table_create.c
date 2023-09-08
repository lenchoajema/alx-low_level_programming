#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @len: size of the array
 *
 * Return: pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int len)
{
    hash_table_t *hash_table;
    unsigned long int i;

    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);
    hash_table->size = len;
    hash_table->array = malloc(len * sizeof(hash_node_t *));
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }
    for (i = 0; i < len; i++)
        hash_table->array[i] = NULL;
    return (hash_table);
}
