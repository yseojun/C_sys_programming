#ifdef COMPILETIME
#include <malloc.h>
#include <stdio.h>

/* malloc wrapper function */
void *mymalloc(size_t size) {
  void *ptr = malloc(size);
  printf("malloc(%d)=%p\n", (int)size, ptr);
  return ptr;
}

/* free wrapper function */
void myfree(void *ptr) {
  free(ptr);
  printf("free(%p)\n", ptr);
}
#endif

#ifdef LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

/* malloc wrapper function */
void *__wrap_malloc(size_t size) {
  void *ptr = __real_malloc(size); /* Call libc malloc */
  printf("malloc(%d) = %p\n", (int)size, ptr);
  return ptr;
}

/* free wrapper function */
void __wrap_free(void *ptr) {
  __real_free(ptr); /* Call libc free */
  printf("free(%p)\n", ptr);
}
#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // write 함수를 위해 추가
#include <dlfcn.h>

static void *(*mallocp)(size_t size) = NULL;
static void *(*freep)(size_t size) = NULL;

static unsigned long n_malloc = 0;
static unsigned long n_free = 0;

__attribute__((constructor))
void __init(void)
{
  fprintf(stderr, "%s", "library interpositioning loaded\n");
}

__attribute((destructor))
void fini(void)
{
  fprintf(stderr, "%s", "library interpositioning unloded\n");
  fprintf(stderr, "%s %ld\n", "malloc called\n", n_malloc);
  fprintf(stderr, "%s %ld\n", "free called\n", n_free);
}

/* malloc wrapper function */
void *malloc(size_t size) {
  // void *(*mallocp)(size_t size);
  char *error;

  mallocp = dlsym(RTLD_NEXT, "malloc"); /* Get addr of libc malloc */
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  char *ptr = mallocp(size); /* Call libc malloc */
  // printf("malloc(%d) = %p\n", (int)size, ptr);
  char buf[80];
  int len = snprintf(buf, sizeof(buf), "malloc(%d) = %p\n", (int)size, ptr);
  write(1, buf, len);

  n_malloc++;

  return ptr;
}

/* free wrapper function */
void free(void *ptr) {
  void (*freep)(void *) = NULL;
  char *error;

  if (!ptr)
    return;

  freep = dlsym(RTLD_NEXT, "free"); /* Get address of libc free */
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  freep(ptr); /* Call libc free */
  // printf("free(%p)\n", ptr);
  char buf[80];
  int len = snprintf(buf, sizeof(buf), "free(%p)\n", ptr);
  write(1, buf, len);
}
#endif
