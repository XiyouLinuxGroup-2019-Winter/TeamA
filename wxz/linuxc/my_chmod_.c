/*************************************************************************
	> File Name: my_chmod_.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月07日 星期六 02时13分20秒
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    struct stat buf;
    //检查参数个数
    if(argc!=2)
    {
        printf("Usage:my_stat<filename>\n");
        exit(0);
    }
    //获取文件属性
    if(stat(argv[1],&buf)==-1)
    {
        perror("stat:");
        exit(1);
    }

    printf("device is:%d\n",buf.st_dev);
    printf("inode is:%d\n",buf.st_ino);
    printf("mode is:%d\n",buf.st_mode);
    printf("number of hard linked is:%d\n",buf.st_nlink);
    printf("user ID of owner is :%d\n",buf.st_uid);
    printf("group ID of own is:%d\n",buf.st_gid);
    printf("total size,in bytes is:%d\n",buf.st_rdev);
    printf("blocksize for filesystem I/O is :%d\n",buf.st_blksize);
    printf("number of blocks allocated is:%d\n",buf.st_blocks);
    printf("time of last access is:%s",ctime(&buf.st_mtime));
    printf("time of last modification is:%s\n",ctime(&buf.st_mtime));
    printf("time of last change is:%s\n",ctime(&buf.st_ctime));

}
