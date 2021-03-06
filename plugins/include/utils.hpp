#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <cstdio>
#include <cstdlib>

#include "data_type.hpp"

#ifdef DLL_VERSION
#include "utils_plugin.hpp"
#else
extern "C" {

uint	l_sizeof(char *src);
char*	l_malloc(uint size);
void	l_free(char *src);
char*	l_realloc(char *src, uint size);
char*	l_mem2mem(char *src);

char*	bytedump(const char *value);
char*	strdump(const char *value);
char*	strndump(const char *value, int len);
void	strupdate(char **src, const char *value);

char	dir_exist(const char *dirname);
char	file_exist(const char *filename);
size_t	file_size(const char *filename);
void	l_mkdir(const char* dirname);

float	atof2(char* val);
bool	atob(char* val);
short	is_atoi(char* val);

long	microsec();

char*	l_realpath(const char * src);

void	hexdump(const char* function, const char* title, const void *Vbuffer, unsigned long index);

void	DEBUG(const char*, ...);
void	DEBUG2(const char*, ...);

}
#endif // DLL_VERSION

#endif // _UTILS_HPP_
