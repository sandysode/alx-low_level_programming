#include "hash_tables.h"

hash_node_t *create_node(const char *key, const char *value);

/**
 * hash_table_set -  function that adds an element to the hash table
 *
 * @ht: Hash table
 * @key: d Key
 * @value: Val associated with d key
 *
 * Return: 1 if it succeeded, 0 otherwise
 **/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned int index;
	hash_node_t *current, *new_node;

	if (!ht || !key || !value || strlen(key) == 0 || !ht->array || ht->size == 0)
