#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int src_fd, dest_fd;
    char buffer[1024];
    ssize_t bytesRead;

    src_fd = open("source.txt", O_RDONLY);
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((bytesRead = read(src_fd, buffer, sizeof(buffer))) > 0)
    {
        write(dest_fd, buffer, bytesRead);
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
    return 0;
}
