/*************************************************************************
	> File Name: 2017_15.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月15日 星期六 20时49分05秒
 ************************************************************************/

#include<stdio.h>
#ifdef __linux__
    int a=1;
#elif _WIN32
    int a=2;
#elif __APPLE__
    int a=3;
#else
    int a=4;
#endif
