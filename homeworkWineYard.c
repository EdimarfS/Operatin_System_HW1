#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fcntl.h> //open,creat
#include <errno.h> //perror, errno
#include <sys/types.h> //open

/*

Spring is coming in vineyard called "Fine Wine Good Health". 

As you know grape likes care, work but much more busy workers which is grated by an excellent produce. 

The vineyard needs a lot of workers therefore we have to implement an application for it.

The vineyard waits for the registration of those who can enter employment in the spring period. 

During the registration they have to give some personal data: their names, addresses and the weekdays when they can work. 

(Give the days separated by spaces e.g. Monday Wendsday Friday!) The vineyard knows how many workers they need on given days.

(e.g. Monday 12 Thuesday 18 etc.) If there is enough worker for a given day the application has to reject further applicants for that day. 

The data of the applicants are stored in file. 

The program has to be able to modify, to delete the data and make a daily and full list of them. 

Implement a program in C programming language which solves the pregiven tasks - the result must run on opsys.inf.elte.hu server or a similar system.

The solution must be presented to the laboratory teacher close to the deadline (within 1 week). 

Upload the program code(s) as a zip file to laboratory canvas!

Deadline 29th March 2020 

*/

//This is our structure : -> The important data for each registration 
struct CostumerData
{
	char 	names[50]; 
	char 	address[50];
    char    weekDays[50];
};


int order;
//Add -> This function will  add new data in our system 


void add_()
{

	int f,g;

	f = open("dataInfo.txt",O_RDONLY);

	if(f < 0)
	{
		perror("Error at opening the file\n");
		exit(1);
	}

	g = open("dataInfo.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);

	if(g<0) 
	{

		perror("Error at opening the file\n");
		exit(1);
	}

	struct CostumerData registration[100];









	//The main  goal here is to  read from file and each data to specific place. This is the thing that is missing here for 
	//a while...
	if(order < 100)
	{   

		printf("add data funtion working ->FUNCTION() \n");

		order +=1;

	}

}

//Modify -> Will modify the existent data 
void modify_()
{

		printf("Modify working");

}

//Delete -> Will delete a data 
void  delete_()
{

		printf("Delete working");
}







//This is the main function -> All the functions above will be called here
int main()
{
	int choice;




	do{
		printf("\nFine Wine Good Health:\n");
		printf("\nInput the number of registration \n");
		printf("\n1. Add new registration\n");
    	printf("\n2. Edit registration\n");
    	printf("\n3. Delete registration\n");
    	printf("\n4. List all the data\n");
    	printf("\n5. Exit\n");
    	scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				add_(); //This place must be replaced by the  functions above.
			break; 

			case 2:
				printf("case 2 \n");
			break;

			case 3:
				printf("case 3 \n");
			break;

			case 4:
				printf("case 4 \n");
			break;

			case 5:
				printf("case 5 \n");
				exit(0);
			break;

			default:
				printf("Wrong data information \n");
			break;
		}



	}while(choice!=6);




	return 0;
}