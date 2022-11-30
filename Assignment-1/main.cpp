//Problem Statement::
/*
Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence 
of search key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
*/

#include<iostream>
#include<string.h>
using namespace std;

typedef struct student
{
    int roll_num;
    char name [15];
    float marks;
}s;

void bubble_sort(s student[15],int n)
{
    int i,j;
    s temp;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(student[j].roll_num>student[j+1].roll_num)
            {
                temp=student[j];
                student[j]=student[j+1];
                student[j+1]=temp;
            }
        }
    }
}

void insertionSort(s student[15], int n)  
{  
    int i,  j;  
    s  key;
    for (i = 1; i < n; i++) 
    {  
        key= student[i];  
        j = i - 1;  
        while (j >= 0 && strcmp(student[j].name, key.name) >0)
        {  
            student[j + 1]= student[j];  
            j = j - 1;  
        }  
        student[j + 1]= key;  
    }  
}  

int par(s student[15], int l,int u)
{
    int i,j;
	 s temp, v;
    
    v=student[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
            
        while(student[i].marks<v.marks&&i<=u);
        
        do
            j--;
        while(v.marks<student[j].marks);
        
        if(i<j)
        {
            temp=student[i];
            student[i]=student[j];
            student[j]=temp;
        }
    }while(i<j);
    
    student[l]=student[j];
    student[j]=v;
    
    return(j);
}


void quick_sort(s student[15], int l,int u)
{
    int j;
    if(l<u)
    {
        j=par(student,l,u);
        quick_sort(student,l,j-1);
        quick_sort(student,j+1,u);
    }
}
 

void search(s student[15],int n,int key)
{
    int i;
    cout<<"\n\tRoll No\tName\tMarks";
    for(i=0;i<n;i++)
    {
        if(key==student[i].marks)
        {
            cout<<"\n\t "<< student[i].roll_num<<"\t "<<student[i].name<<"\t "<<student[i].marks;
        }

    }

}

int bsearch(s student[15], char x[15],int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(strcmp(x,student[mid].name)==0)
        {
            return mid;
        }
        else if(strcmp(x,student[mid].name)<0)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return -1;
}



int main()
{
    s student[15];
    int choice,n;;
    do
    {
        cout<<"\nEnter your choice:"
              "\n1. Create database"
              "\n2. Display database"
              "\n3. Bubble sort(according to roll number)"
              "\n4. Insertion sort(name)"
              "\n5. Quick sort(marks)"
              "\n6. Linear Search"
              "\n7. Binary search"
              "\n8. Exit"
              "\n Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nEnter number of records:";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    cout<<"\nEnter roll number:";
                    cin>>student[i].roll_num;
                    cout<<"\nEnter name:";
                    cin>>student[i].name;
                    cout<<"\nEnter marks:";
                    cin>>student[i].marks;
                }
                break;
            }
            case 2:
            {
                cout<<"\n\tRoll number\tName\tMarks";
                for(int i=0;i<n;i++)
                {
                    cout<<"\n\t"<<student[i].roll_num<<"\t"<<student[i].name<<"\t"<<student[i].marks;
                }
                break;
            }
            case 3:
            {
                bubble_sort(student,n);
                break;
            }
            case 4:
            {
                insertionSort(student,n);
                break;
            }
            case 5:
            {
                quick_sort(student,0,n-1);
                break;
            }
            case 6:
            {
                int key;
                cout<<"\nEnter the element to be searched";
                cin>>key;
                search(student,n,key);
                break;
            }
            case 7:
            {
                char key[15];
                cout<<"\nEnter the name to be searched";
                cin>>key;
                insertionSort(student,n);
                int result=bsearch(student,key,0,(n-1));
                if(result==-1)
                {
                    cout<<"\nStudent data not in database";
                }
                else
                {
                    cout<<"Student is present";
                }
                
                break;
            }
            case 8:
            {
                break;
            }
        }        
    }while(choice!=8);
    return 0;
}
