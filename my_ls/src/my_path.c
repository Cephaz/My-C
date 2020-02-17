/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** my_path.c
** File description:
**      Code is poetry..
*/

#include "../include/list.h"
#include "../include/my.h"

char *get_current_path(char *str)
{
    char current_path[256];
    char *path;

    getcwd(current_path, sizeof(current_path));
    path = my_strdup(current_path);
    path = my_strcat(current_path, "/");
    path = my_strdup(str);
    path = my_strcat(path, "/");
    return path;
}

path_t *newpath()
{
    path_t *path = NULL;

    path = malloc(sizeof(*path));
    if (path == NULL)
        return NULL;
    path->name = NULL;
    path->path = NULL;
    path->content = new_content();
    path->next = NULL;
    return (path);
}

void addpath(path_t *path, char *str)
{
    path_t *nextpath;

    if ((path->next == NULL) && (path->name == NULL)) {
        path->name = str;
    } else {
        nextpath = newpath();
        nextpath->name = str;
        while (path->next != NULL)
            path = path->next;
        path->next = nextpath; 
    }
}

int existing_file(char *str, opt_t *opt, path_t *paths)
{
    DIR *directory;
    struct dirent *dir;
    struct stat file_stat;
    char *path;

    directory = opendir(str);
    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            path = get_current_path(str);
            if (opt->L == 1)
                stat(my_strcat(path, dir->d_name), &file_stat);
            else
                lstat(my_strcat(path, dir->d_name), &file_stat);
            add_to_content(paths->content, create_file(dir, &file_stat));
        }
        closedir(directory);
        return 1;
    }
    return 0;
}

path_t *verif_path(int ac, char **av){
    path_t *path = newpath();
    int i = 1;
    int lengthpath = 0;

    while (i < ac)
        if (av[i++][0] != '-')
            ++lengthpath;
    i = 1;
    if (lengthpath == 0) {
        path->name = ".";
    }
    while (i < ac) {
        if (av[i][0] != '-'){
            addpath(path, av[i]);
        }
        ++i;
    }
    return (path);
}