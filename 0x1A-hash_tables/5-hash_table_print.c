#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Function that prints a hash tab
 *
 * @ht: Hash tab to print
 **/
void hash_table_print(const hash_table_t *ht)
{
	unsigned int printed_entries = 0;
	unsigned int idx;

	if (ht == NULL)
		return;

	printf("{");

