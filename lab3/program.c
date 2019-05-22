#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    int fd[2], nbytes;
    pid_t childpid;
    char string[] = "This is a test string…\n";
    char readbuffer[80];
    pipe(fd);
    if ((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    if (childpid == 0)
    {                 /* Народжений процес закриває вхід до каналу */
        close(fd[0]); /* Введений рядок */
        write(fd[1], string, strlen(string));
        exit(0);
    }
    else
    {                 /* Первісний процес закриває вхід до каналу */
        close(fd[1]); /* Читання рядка через канал */
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
        printf("Received string: %s", readbuffer);
    }
    return (0);
}