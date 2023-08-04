// Nguyễn Thanh Hà - 20210298
/*
Bài tập 1.9. Viết chương trình in ra tất cả các dãy con của một dãy cho trước.
*/
#include <stdio.h>
int main()
{
    int n;
    printf("\n");
    printf("Nguyễn Thanh Hà - 20210298 \n");
    scanf("%d",&n); // Nhập số lượng phần tử của dãy
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]); // Nhập vào dãy 
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
           for (int k = i; k <= j; k++)
           {
            printf("%d ",a[k]);
           }
           printf("\n");
        }
    return 0;  
}
// Nguyễn Thanh Hà - 20210298