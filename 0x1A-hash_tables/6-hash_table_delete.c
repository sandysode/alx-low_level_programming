#include "hash_tables.h"

/**
 * hash_table_delete - Function that deletes a hash tab
 * @ht: Hash tab
 **/
void hash_table_delete(hash_table_t *ht)
{
	unsigned int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
