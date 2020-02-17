/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** file.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

void fills_file(file_t *file, struct dirent *dir,
                struct stat *file_stat, char *name)
{
    uid_t uid;
    struct stat test = *file_stat;

    file->blocks = file_stat->st_blocks;
    file->i_node = dir->d_ino;
    file->nb_link = file_stat->st_nlink;
    file->size = file_stat->st_size;
    file->name = my_strdup(name);
    file->surname = my_strdup(my_strupcase(name));
    uid = file_stat->st_uid;
    file->user = getpwuid(uid)->pw_name;
    file->group = getgrgid(uid)->gr_name;
    file_right(file_stat, file);
    file->mtime = file_stat->st_mtime;
    file->time = my_strdup(ctime(&test.st_mtime));
}

file_t *create_file(struct dirent *dir, struct stat *file_stat)
{
    file_t *file;
    char *name = my_strdup(dir->d_name);

    file = malloc(sizeof(*file));
    if (file == NULL)
        return NULL;
    fills_file(file, dir, file_stat, name);
    free(name);
    return file;
}

void file_right(struct stat *file_stat, file_t *file)
{
    file->stat[0] = get_file_type(file_stat);
    file->stat[1] = (file_stat->st_mode & S_IRUSR) ? 'r' : '-';
    file->stat[2] = (file_stat->st_mode & S_IWUSR) ? 'w' : '-';
    file->stat[3] = (file_stat->st_mode & S_IXUSR) ? 'x' : '-';
    file->stat[4] = (file_stat->st_mode & S_IRGRP) ? 'r' : '-';
    file->stat[5] = (file_stat->st_mode & S_IWGRP) ? 'w' : '-';
    file->stat[6] = (file_stat->st_mode & S_IXGRP) ? 'x' : '-';
    file->stat[7] = (file_stat->st_mode & S_IROTH) ? 'r' : '-';
    file->stat[8] = (file_stat->st_mode & S_IWOTH) ? 'w' : '-';
    file->stat[9] = (file_stat->st_mode & S_IXOTH) ? 'x' : '-';
    file->stat[10] = '\0';
}

char get_file_type(struct stat *file_stat)
{
    switch (file_stat->st_mode & S_IFMT) {
    case S_IFBLK:
        return 'b';
    case S_IFCHR:
        return 'c';
    case S_IFDIR:
        return 'd';
    case S_IFIFO:
        return 'p';
    case S_IFLNK:
        return 'l';
    case S_IFREG:
        return '-';
    case S_IFSOCK:
        return 's';
    }
    return '-';
}
