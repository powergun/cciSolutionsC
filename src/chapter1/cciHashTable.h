//
// Created by wein on 3/3/18.
//

#ifndef CCISOLUTIONSC_CCIHASHTABLE_H
#define CCISOLUTIONSC_CCIHASHTABLE_H

#include "cciValue.h"

typedef struct cciHashTable cciHashTable_t;

cciHashTable_t *NewHashTable(size_t size);

void DeleteHashTable(cciHashTable_t *tb);

void SSet(cciHashTable_t *tb, const char *key, cciValue_t value);

cciValue_t SGet(cciHashTable_t *tb, const char *key);

#endif //CCISOLUTIONSC_CCIHASHTABLE_H
