#ifndef FUNC_PROTO
#define FUNC_PROTO
#include "shell.h"

int command_execution(
		char **query
		);

int get_query(
		char **query,
		size_t *buf_size,
		int *tty_ret
		);

char **token_str(
		char *query,
		const char *delim
		);

#endif /* FUNC_PROTO */
