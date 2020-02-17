/*
** ETNA PROJECT, 13/02/2020 by zhou_p
** list.h
** File description:
**      Code is poetry..
*/

#ifndef LIST_H
#define LIST_H

#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef struct opt_s
{
    int neg;
    int l;
    int R;
    int r;
    int d;
    int t;
    int a;
    int A;
    int L;
} opt_t;

typedef struct file_s
{
    blkcnt_t blocks;
    ino_t i_node;
    dev_t nb_link;
    off_t size;
    char *name;
    char *surname;
    char *user;
    char *group;
    char stat[11];
    char *time;
    time_t mtime;
} file_t;

typedef struct content_s
{
    file_t *file;
    struct content_s *next;
} content_t;

typedef struct path_s
{
    content_t *content;
    char *path;
    char *name;
    struct path_s *next;
} path_t;

void read_av(int ac, char **av);
char *my_strupcase(char *str);

opt_t *newopt();
opt_t *verif_options(int ac, char **av);
void addopt(opt_t *opt, char c);
int nopt(opt_t *opt);
int cptopt(opt_t *opt);

path_t *newpath();
path_t *verif_path(int ac, char **av);
void addpath(path_t *path, char *str);
char *get_current_path(char *str);
int existing_file(char *str, opt_t *opt, path_t *paths);

void fills_file(file_t *file, struct dirent *dir,
                struct stat *file_stat, char *name);
file_t *create_file(struct dirent *dir, struct stat *file_stat);
void file_right(struct stat *file_stat, file_t *file);
char get_file_type(struct stat *file_stat);

void reverse_content(content_t **begin);
content_t *new_content();
void add_to_content(content_t *content, file_t *file);

char *get_path(char *str);
void display_name(file_t *file, opt_t *opt);
void displaynopt(path_t *path, opt_t *opt);
void displayfollow(path_t *path, opt_t *opt, int pass);
void display(path_t *path, opt_t *opt);

void sort_content(content_t **begin, int (*cmp)());
void sort_content_time(content_t **begin);
void verif_sort(opt_t *opt, path_t *path);

void swap(content_t *a, content_t *b);

void display_condition(path_t *path, opt_t *opt, int x);
void displayneg(path_t *path, opt_t *opt);
void displayl(path_t *path, opt_t *opt);
void displaya(path_t *path, opt_t *opt);
void displayt(path_t *path, opt_t *opt);

int count_nb_blocks(content_t *content, opt_t *opt);
int max_nbrlen(content_t *content, int i);
void display_info(content_t *content, file_t *file);
int display_link_reference(file_t *file);
void display_list(content_t *content, file_t *file, opt_t *opt);

int my_nbrlen(int n);
void display_time(char *str);

int condition_opta(opt_t *opt, char *s);
int condition_opt(opt_t *opt, char *s);
void condition_optd(opt_t *opt, path_t *path);

void free_content(content_t *content);

void print_errors(char **av, char *str);
void no_found_errors(char **argv, char *str);
void print_option_errors(char c);
#endif
