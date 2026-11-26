#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    char source_name[1024], destination_name[1024];
    struct stat source_info, destination_info;
    FILE *source, *destination;
    int ch;

    printf("Enter source file name: ");
    if (!fgets(source_name, sizeof source_name, stdin) || !strchr(source_name, '\n')) {
        fprintf(stderr, "Invalid or too long source file name.\n");
        return 1;
    }
    source_name[strcspn(source_name, "\n")] = '\0';
    printf("Enter destination file name: ");
    if (!fgets(destination_name, sizeof destination_name, stdin) || !strchr(destination_name, '\n')) {
        fprintf(stderr, "Invalid or too long destination file name.\n");
        return 1;
    }
    destination_name[strcspn(destination_name, "\n")] = '\0';

    source = fopen(source_name, "rb");
    if (source == NULL) {
        perror("Cannot open source file");
        return 1;
    }
    if (stat(source_name, &source_info) == 0 && stat(destination_name, &destination_info) == 0 &&
        source_info.st_dev == destination_info.st_dev && source_info.st_ino == destination_info.st_ino) {
        fprintf(stderr, "Source and destination must be different files.\n");
        fclose(source);
        return 1;
    }
    destination = fopen(destination_name, "wb");
    if (destination == NULL) {
        perror("Cannot open destination file");
        fclose(source);
        return 1;
    }
    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) {
            perror("Error writing destination file");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }
    if (ferror(source)) {
        perror("Error reading source file");
        fclose(source);
        fclose(destination);
        return 1;
    }
    fclose(source);
    if (fclose(destination) == EOF) {
        perror("Error closing destination file");
        return 1;
    }
    printf("File copied successfully.\n");
    return 0;
}
