// Nguyễn Thanh Hà - 20210298
/*
Bài tập 1.10. Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, 
trong đó n nhập từ bàn phím. Sau đó tính tổng và tích của hai ma trận đó và 
đưa kết quả ra màn hình.Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
*/
#include <stdio.h>

void allocate_mem(int ***mt, int n){
    //#Allocate memory for the matrix
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    *mt = new int *[n]; //Tạo biến con trỏ mt và 
                             //cấp phát bộ nhớ gồm m biến con trỏ kiểu int 
    for(int i = 0 ; i < n; i++) 
    {
        (*mt)[i] = new int[n]; // Tại mỗi hàng cấp phát bộ nhớ cho n phần tử số nguyên
    }
    //*****************
}

void input(int **mt, int n){
    //#Input elements of the matrix
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298*/
    for(int i = 0; i<n;i++)
        for(int j = 0;j<n;j++){
            scanf("%d", &mt[i][j]); //Đọc ma trận từ bàn phím
        }
    //*****************
}

void free_mem(int **mt, int n){
    //# Free memory
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298*/
    for(int i = 0; i< n;i++)
        delete [] mt[i];    //Giải phóng bộ nhớ từng hàng 
    delete [] mt;
    //*****************
}

int main()
{
    printf("\n");
    printf("Nguyễn Thanh Hà - 20210298 \n");
    int n,**mt1,**mt2;
    scanf("%d",&n);
    
    allocate_mem(&mt1,n);
    allocate_mem(&mt2,n);

    input(mt1,n);
    input(mt2,n);
    printf("\n");

    // Tính tổng 2 ma trận
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            temp = mt1[i][j] + mt2[i][j];
            printf("%d ",temp);
        }
        printf("\n");
    }

    //Tính tích 2 ma trận
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp += mt1[i][k]*mt2[k][j];
            }  
            printf("%d ",temp);
        }
        printf("\n");
    }
    
    //Giải phóng ma trận
    free_mem(mt1,n);
    free_mem(mt2,n);

    return 0;
}
//Nguyễn Thanh Hà - 20210298
