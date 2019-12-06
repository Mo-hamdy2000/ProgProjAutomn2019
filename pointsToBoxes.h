#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int x;
    int y;
}point;

point readpoint()
{
    point p;
    scanf("%d %d",&p.x,&p.y);
    return p;
}

void printPoint(point p)
{
    printf("%d",p.x);
    printf(" %d",p.y);
    printf("\n");
}
///this function check the Validity Of Points
///it returns 0 if the points are not valid
///it return -1 if the points are the same point
///it return -2 if one of the points is out of range
///sizeOfBoard is the number of boxes in each rows or columns
int checkValidityOfPoints(point a,point p,int sizeOfBoard)
{
    if(a.x<0||a.x>sizeOfBoard||a.y<0||a.y>sizeOfBoard||p.x<0||p.x>sizeOfBoard||p.y<0||p.y>sizeOfBoard)
    {
        return -2;
    }
    else if(a.x==p.x&&a.y==p.y)
    {
        return -1;
    }
    else if(a.x==p.x)
    {
        if(abs(a.y-p.y)==1)
        {
            return 1;
        }
        else
            return 0;
    }
    else if(a.y==p.y)
    {
        if(abs(a.x-p.x)==1)
        {
            return 1;
        }
        else
            return 0;
    }
}
///this function print the index of the boxes contain of the line
///as that line consists of that two points
///sizeOfBoard is the number of boxes in each rows or columns
void boxOffThatPoints(point a,point p,int sizeOfBoard)
{
    ///correct the wrong points by taking other from the user
    while(checkValidityOfPoints(a,p,sizeOfBoard)!=1)
    {
        if(checkValidityOfPoints(a,p,sizeOfBoard)==0)
        {
            printf("not valid points\n");
            printf("please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
        }
        else if(checkValidityOfPoints(a,p,sizeOfBoard)==-1)
        {
            printf("it is the same point\n");
            printf("please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
        }
        else if(checkValidityOfPoints(a,p,sizeOfBoard)==-2)
        {
            printf("one of the points is out of range\n");
            printf("please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
        }
    }
    ///find the boxes indexes :
    ///it deal with box1Index and box2Index as points
    ///x of the index is the row of the array of boxes where the box exist
    ///y of the index is the column of the array of boxes where the box exist
    point box1Index,box2Index;
    ///initialize the box index equal to -1
    ///to know if it has changed or no
    ///to be easier to print
    box1Index.x=-1;
    box2Index.x=-1;
    box1Index.y=-1;
    box2Index.y=-1;
    ///when x is constant then the box are around it
    ///the row of the two boxes is constant equal to min y
    ///the column is not constant as it take values: x , x-1  
    if(a.x==p.x)
    {
        if(a.y<=p.y)
        {
            box1Index.x=a.y;
            box2Index.x=a.y;
        }
        if(p.y<a.y)
        {
            box1Index.x=p.y;
            box2Index.x=p.y;
        }
        if(a.x!=0)
        {
            box1Index.y=a.x-1;
            box2Index.y=a.x;
        }
        else
        {
            box1Index.y=a.x;
        }
    }
    ///when y is constant then the box are around it
    ///the column of the two boxes is constant equal to min x
    ///the row is not constant as it take values: y , y-1
    else if(a.y==p.y)
    {
        if(a.x<=p.x)
        {
            box1Index.y=a.x;
            box2Index.y=a.x;
        }
        if(p.y<a.y)
        {
            box1Index.y=p.x;
            box2Index.y=p.x;
        }
        if(a.y!=0)
        {
            box1Index.x=a.y-1;
            box2Index.x=a.y;
        }
        else
        {
            box1Index.x=a.y;
        }
    }
    ///print first box if it exist
    if(box1Index.x!=-1&&box1Index.y!=-1)
    {
        printPoint(box1Index);
    }
    ///print second box if it exist
    if(box2Index.x!=-1&&box2Index.y!=-1)
    {
        printPoint(box2Index);
    }
}
