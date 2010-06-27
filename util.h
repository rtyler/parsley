#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <ctype.h>
#include <errno.h>
#include <json/json.h>
#include <json/printbuf.h>
#include <libexslt/exslt.h>
#include <libxml/xmlIO.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parsed_xpath.h"
#include "parsley.h"
#include "parser.h"
#include "regexp.h"
#include "functions.h"

FILE* parsley_fopen(char*, char*);
xmlNodePtr new_stylesheet_skeleton(char *incl);
void registerEXSLT();
void printbuf_file_read(FILE *f, struct printbuf *buf);

int parsley_key_flags(char*);
char* parsley_key_tag(char*);
pxpathPtr parsley_key_filter(char*);
int parsley_io_get_mode();
void parsley_io_set_mode(int mode);
void _parsley_set_user_agent(char *agent);

xmlDocPtr parsley_apply_span_wrap(xmlDocPtr ptr);

#endif
