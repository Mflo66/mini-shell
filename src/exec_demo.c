#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char *args[] = {"ls", "-l", NULL};

	pid_t pid = fork();

	if (pid == 0) {
		execvp(args[0], args);
		perror("execvp failed"); // only runs if execvp fails
		return 1;
	} else if (pid > 0) {
		int status;
		waitpid(pid, &status, 0);
		printf("Child finished.\n");
	} else {
		perror("fork failed");
		return 1;
	}

	return 0;
}
