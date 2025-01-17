#include <stdlib.h>
#include <signal.h> 
#include <unistd.h> 
#include <string.h> 

struct s_message
{
    unsigned char *str;
    int need_space;
    int msg_ready;
    size_t size;
};
