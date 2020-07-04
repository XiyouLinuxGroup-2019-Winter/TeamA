/*************************************************************************
	> File Name: debug.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 00时37分36秒
 ************************************************************************/

#ifndef _DEBUG_H
#define _DEBUG_H

#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif
#ifdef
#define check_exit(A, M, ...) if(!(A)) { log_err(M "\n", ##__VA_ARGS__); exit(1);}
#define check_debug(A, M, ...) if(!(A)) { debug(M "\n", ##__VA_ARGS__); /* exit(1); */}
#endif
