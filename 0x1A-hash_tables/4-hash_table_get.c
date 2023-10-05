#include "hash_tables.h"
/**
 * hash_table_get - function dat retrieves a val associated with a key
 *
 * @ht: Hash table
 * @key: Key
 *
 * Return: Val of d associated with d element
 **/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned int index = key_index((unsigned char *)key, ht->size);
	hash_node_t *current = ht->array[index];

	if (!ht || !key || strlen(key) == 0 || !ht->array || ht->size == 0)
		return (NULL);

	while (current)
	{
