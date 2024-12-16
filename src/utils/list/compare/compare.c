#include "ArrayList.h"

static int cmp_void(void *a, void *b)
{
    return (a == b);
}

static int cmp_int(void *a, void *b)
{
    return (*(int *)a == *(int *)b);
}

static int cmp_str(void *a, void *b)
{
    char *c;
    char *d;

    c = a;
    d = b;
    if (!c || !d)
        return (!c && !d);
    while (*c && *d)
    {
        if (*c != *d)
            return (0);
        c++;
        d++;
    }
    return (1);
}
t_cmp get_cmp(t_type_node type)
{
    if (type == OBJECT)
        return (cmp_void);
    if (type == INT)
        return (cmp_int);
    if (type == STR)
        return (cmp_str);
    return (NULL);
}