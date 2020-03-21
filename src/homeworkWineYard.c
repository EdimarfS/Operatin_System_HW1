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
struct CostumerData data[100];
//Add -> This function will  add new data in our system 


void add_()
{

struct CostumerData tmp;

	if(order < 100)
	{
		printf("\nName: ");
		scanf("%s",tmp.names);
		printf("\nAdress: ");
		scanf("%s", tmp.address);
		printf("\nWeek Days:");
        scanf("%s", tmp.weekDays);


	}
	data[order] = tmp;
	order +=1;
	printf("\nAdd new data\n");


	//The main  goal here is to  read from file and each data to specific place. This is the thing that is missing here for 
	//a while...


}


//Modify -> Will modify the existent data 
void modify_()
{

int choice;
    int i = 0;
    int item = 0;
    struct CostumerData tmp;

    if(order > 0 && item < order && item > -1)
       {
        printf ("\nWhich record do you wish to edit? (Enter a number)\n");
        scanf ("%d", &i);

        printf("\n1.Names: ");
        printf("\n2.Address: ");
        printf("\n3.weekdays:");
        printf("\n");

        scanf("%d", &choice);

        switch(choice)
        {

        case 1:
            scanf("%s",data[i-1].names);
            break;
        case 2:
            scanf("%s",data[i-1].address);
            break;
        case 3:
            scanf("%s",data[i-1].weekDays);
            break;
        case 5:
            scanf("\n Exiting...\n");
            break;
        default: 
            printf("\nWrong input data, try again\n");
        break;
        }


       } else {
            printf("\nError\n");
            printf("No data founded in database...\n");
       }


	printf("\n edit the order\n");
		printf("Modify working");

}

//Delete -> Will delete a data 
void  delete_()
{
    int i =0;
    int item =0;
    char deleteNames[10];
    char deleteAddres[10];
    char nullStr[20] = {"\0"};
    struct CostumerData x;


    if(order > 0 && item < order && item > -1)
    {
          printf ("\nWhat is the name that you would like to delete ?\n");
          scanf("%s",deleteNames);
          printf ("\nWhat is their Adress ?\n");
          scanf("%s",deleteAddres);

                for(i = 0;i < order; i++)
                {
                    if(strcmp(deleteNames, data[i].names) == 0)
                    {   
                        for(i = 0; i < order; i++)
                        {
                            if(strcmp(deleteAddres, data[i].address) == 0)
                            {
                                strcpy(data[i].names, data[i+1].names);
                                strcpy(data[i].address, data[i+1].address);

                                strcpy(data[i].weekDays, data[i+1].weekDays);
                                order--;
                                printf("\nRegistration removed from the record.\n");
                                break;


                            }
                        }


                    }else {
                     printf("ERROR. Try again\n");
                    }
                }


    }else{
        printf("\nError\n");
        printf("No item found\n");
    }

		printf("Delete working");
}


//Printing all data 
void printall()
{
    int n;
    printf("\nData:\n");
    for(n = 0; n < order; n++)
    {
        printf("\n%d.\n", n+1);
        printf("%s\n",data[n].names);
        printf("%s\n",data[n].address);
        printf("%s\n",data[n].weekDays);
    }
}


//This is the main function -> All the functions above will be called here
int main()
{
	int choice;

	do{
		printf("\nFine Wine Good Health:\n");
		printf("\nInput the number of registration \n");
		printf("\n1. Add new registration\n");
    	printf("\n2. Modify registration\n");
    	printf("\n3. Delete registration\n");
    	printf("\n4. List all the data\n");
    	printf("\n5. Exit\n");
    	printf("////////////////////////\n");
    	scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				add_(); //This place must be replaced by the  functions above.
			break; 

			case 2:
				modify_();
			break;

			case 3:
				printf("case 3 \n");
			break;

			case 4:
				printall();
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