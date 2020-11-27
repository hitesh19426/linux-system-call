/* Name: Hitesh Garg
   Roll_Number: 2019426 */

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{  
    printf("Invoking 'sh_task_info' system call\n");
    int pidInput;
    printf("%s", "Enter pid: ");
    scanf("%d", &pidInput) ;

    long int ret_status = syscall(440, pidInput, "/home/hitesh/Desktop/FileOutput.txt", 256);
    // 440 is the syscall number
    printf("%d\n", pidInput);
    
    if(ret_status == 0) 
    	printf("System call 'sh_task_info' executed correctly.\n Use dmesg to check sh_task_info\n");
    else 
    	printf("System call 'sh_task_info' did not execute as expected\n");
    
    printf("Error Value for program is: %d\n", errno);
    printf("Error Message for program is: %s\n", strerror(errno));

    return 0;
}
