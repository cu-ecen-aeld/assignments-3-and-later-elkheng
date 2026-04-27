#include <stdio.h>
#include <stdlib.h>
#include <sys/syslog.h>


int main(int argc, char *argv[]) {
    char* writefile = argv[1];
    char* writestr = argv[2];
    FILE*fp;

    // Open syslog with the program name and log level
    openlog(argv[0], LOG_PID | LOG_CONS, LOG_USER);
    
    if (argc <= 2) {
        syslog(LOG_ERR, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return EXIT_FAILURE;
    }
    if(writefile == NULL || writestr == NULL) {
        syslog(LOG_ERR, "Invalid arguments: writefile and writestr cannot be NULL\n");
        closelog();
        return EXIT_FAILURE;
    }

    fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file: %s\n", writefile);
        closelog();
        return EXIT_FAILURE;
    }
    
    fprintf(fp, "%s", writestr);
    // Log the message with the LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing %s to file %s", writestr, writefile);
    
    fclose(fp);
    // Close the syslog connection
    closelog();
    return 0;
}