//
//  main.c
//  keyword
//
//  Created by 张木林 on 3/2/24.
//

#include <stdio.h>

//排电梯的问题
//小乐乐学校教学楼的电梯前排了很多人，他的前面有n个人在等电梯。电梯每次可以乘坐12人，每次上下需要的时间为4分钟（上需要2分钟，下需要2分钟）。请帮助小乐乐计算还需要多少分钟才能乘电梯到达楼上。（假设最初电梯在1层）

//
//int main()
//{
//    int a;
//    scanf("%d",&a);
//    printf("%d\n",a/12*4+2);
//}






//找最大数的问题。
//比如 3 4 1 2，如何找出四个数字的最大数
//int main()
//{
//    int arr[4] = {0};
//    int i = 0;
//    for(i=0; i<=3; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    //假设
//    int max = arr[0];
//    for(i=1; i<=3; i++)
//    {
//        if(arr[i]> max)
//        {
//            max = arr[i];
//        }
//    }
//    printf("%d\n", max);
//    return 0;
//}




//ASCII值
//int main()
//{
//    //int a = 0;
//    char arr[] = {73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33};
//    int length = sizeof(arr)/sizeof(arr[0]);
//    for(int i = 0;i<length;i++)
//    {
//        printf("%c",arr[i]);
//    }
//    
//    return 0;
//}






//统计数据正负个数
int main()
{
    //int a = 0;
    int positive = 0;
    int negative = 0;
    int tmp = 0;
    for(int i = 0;i<10;i++)
    {
        scanf("%d",&tmp);
        if(tmp>=0)
        {
            positive++;
        }
        else
        {
            negative++;
        }
        
    }
    printf("%d\n",positive);
    printf("%d\n",negative);
    return 0;
}
