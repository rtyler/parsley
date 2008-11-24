#ifndef DEXTER_H_INCLUDED
#define DEXTER_H_INCLUDED

#define DEX_BUF_SIZE 1024

#include <json/json.h>

char* dex_compile(char* dex, char* incl);
char* dex_set_debug_mode(int);
void dex_error(char*);

void __dex_recurse(struct json_object *, struct printbuf*, char*);
void __dex_recurse_object(struct json_object *, struct printbuf*, char*);
void __dex_recurse_array(struct json_object *, struct printbuf*, char*);
void __dex_recurse_string(struct json_object *, struct printbuf*, char*);

#endif