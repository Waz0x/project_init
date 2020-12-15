#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

void print_help(void)
{
    printf("USAGE:\n");
    printf("\tproject [name]\n");
    printf("You need to have a init foled with all your files in your home\n");
    printf("project -c to create it");
}

int main(int av, char **ac)
{
    char cwd[PATH_MAX];
    char *include = strdup("include/");

    if (av == 2 && ac[1][0] == '-' && ac[1][1] == 'h') {
        print_help();
        return (0);
    }
    if (av == 2 && ac[1][0] == '-' && ac[1][1] == 'c') {
        system("mkdir ~/init");
        return (0);
    }
    if (av == 2) {
        setreuid(geteuid(), geteuid());
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            system("cp -rf ~/init/* ./");
            strcat(include, ac[1]);
            strcat(include, ".h");
            rename("include/project.h", include);
            printf("Done");
            printf("Don't forget to modify headers !");
        } else {
            printf("Error");
            return (84);
        }
        return 0;
    } else {
        printf("Error please check help. project -h");
        return (84);
    }
}