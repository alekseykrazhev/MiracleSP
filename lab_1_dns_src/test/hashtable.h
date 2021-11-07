#include <malloc.h>
#include <stddef.h>
#include <memory.h>
#include <string.h>
#include <stdint.h>

#define HT_INITIAL_SIZE 100000
#define PENGUINS_ARE_CUTE TRUE

typedef struct Item
{
    char *key; //domain
    char *value; //ip
    uint32_t key_size;

    struct Item* next;
} Item;

typedef struct HashTable
{
    Item** array;
    uint32_t arraySize;
    uint32_t seed;
} HashTable;

uint32_t murmurhash(const char* key, uint32_t len, uint32_t seed);

HashTable* HashTableInit();

char* HashTableSearch(HashTable* hashTable, char* key);

void HashTableInsert(HashTable* hashTable, char* key, char* value);

void HashTableRemove(HashTable* hashTable);