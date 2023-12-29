#include "func_proto.h"
#include "shell.h"
#include "error.h"

/**
 * get_query - reads query using getline
 * @query: buffer for query
 * @buf_size: size of buf
 * @tty_ret: return value of isatty()
 * Return: 0 if error
 */
int get_query(
		char **query,
		size_t *buf_size,
		int *tty_ret
		)
{
	int query_ret = getline(query, buf_size, stdin);

	if (query_ret == -1)
	{
		if (errno != 0)
			perror(STD_READ_ERR);
		if (*tty_ret == 1)
			printf("\n");
		free(*query);
		return (0);
	}

	if (query_ret != (int)*buf_size)
	{
		*query = realloc(*query, query_ret);

		if (*query == NULL)
		return (0);
	}
	(*query)[query_ret - 1] = 0;

	return (1);
}
