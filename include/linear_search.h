#ifndef _LINEAR_SEARCH_H_
#define _LINEAR_SEARCH_H_

#include <stddef.h>

/* Forward declarations. */
typedef struct item;

item *linear_search(item *items, size_t size, const char *key);

#endif  /* #ifdef _LINEAR_SEARCH_H_ */