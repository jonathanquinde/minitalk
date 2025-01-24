#include <signal.h> 
#include "libft.h"

struct s_message
{
    unsigned char *str;
    int need_space;
    size_t size;
};
