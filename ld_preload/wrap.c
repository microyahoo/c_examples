// http://www.tecyle.com/2017/03/03/dlsym%E5%8F%82%E6%95%B0-rtld_next%E8%AF%A6%E8%A7%A3/
//
# define RTLD_NEXT      ((void *) -1l)

#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>

void(*f)();

void load_func() __attribute__((constructor));

void load_func()
{
    f = (void(*)())dlsym(RTLD_NEXT, "print_message");
    char *error_str;
    error_str = dlerror();
    if (error_str != NULL) {
        printf("%s\n", error_str);
    }
    printf("load func first f=%p\n",f);

}

void print_message()
{
    printf("the wrap lib~~\n");
    f();
}
