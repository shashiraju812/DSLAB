#include<stdio.h>
#include<string.h>
union Student {
	int roll_no;
	char name[50];
	int marks[5];
	int total;
};
int main()
{
	union Student s;
	int temp_marks[5],total=0;
	int i;
	printf("enter roll number:");
	scanf("%d",&s.roll_no);
    printf("roll number:%d\n",s.roll_no);
    
    printf("enter name: ");
    scanf(" %[^\n]",s.name);
    printf("name: %s\n",s.name);
    
    printf("enter marks:\n");
    for(i=0;i<5;i++){
    	printf("Subject %d:",i+1);
    	
    	scanf("%d",&temp_marks[i]);
    	total+=temp_marks[i];
    }
    printf("marks:");
    for(i=0;i<5;i++){
    	printf("%d",temp_marks[i]);
	}
     s.total=total;
     printf("\ntotal:%d\n",s.total);
     return 0;
     
     

	}



   
	



