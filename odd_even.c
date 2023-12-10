/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int p, n, i, sum = 0;
    printf("Enter how many number you want to enter: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    p = fork();
    if (p < 0)
    {
        printf("failed to create child\n");
        exit(1);
    }
    else if (p == 0)
    {
        printf("\nchild process :: ");
        for (i = 0; i < n; i++)
            if (arr[i] % 2 != 0)
            {
                sum += arr[i];
            }
        printf("\nSum of odd number : %d\n", sum);
    }
    else if (p > 0)
    {
        wait(NULL);
        printf("\nParent process :: ");
        for (i = 0; i < n; i++)
            if (arr[i] % 2 == 0)
            {
                sum += arr[i];
            }
        printf("\nSum od Even number : %d\n", sum);
    }

    return 0;
}
*/
//odd even
#include <stdio.h>
 #include <unistd.h> 
 int main() 
 {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum_even = 0;
    int sum_odd = 0;
    int pid = fork();
    if (pid == 0)
    {	
        for (int i = 0; i < n; i++)
        {	if (arr[i] % 2 != 0)
            {
                sum_odd += arr[i];
            }
        }
        printf("Child Process: Sum of odd numbers = %d\n", sum_odd);
    
    }

    else if (pid > 0)
    {
        for (int i = 0; i < n; i++)
        {	if (arr[i] % 2 == 0)
            {
                sum_even += arr[i];
            }
        }
        printf("Parent Process: Sum of even numbers = %d\n", sum_even);
    }
    return 0;
}


