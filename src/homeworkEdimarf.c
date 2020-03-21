#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


/*
1. homework 
Deadline: 7/04/2019, Presentation deadline: 12/5/2019 (the end of the term)

Housing market is vivid. Never was such extra opportunities in it! Enchanting-Home Firm takes on total recovery for everybody (who can pay :))! 
The firm has an excellent team: painters, masons, electricians, plumbers, gas-men, heating fitters, joiners (for unique kitchen furnitures) and decorators. When a customer orders a recovery they register the following data: the address of the house, the size of it (m2), the list of tasks (e.g. painting, electrical installation, etc.) and the very last deadline to finish everything. 

The application should be able to list out the orders, to take on new ones and to modify or to delete the existing orders.*/

struct CostumerData
{
	char 	house_address[50]; 
	char 	house_size[50];
    char    tasks[50];
	char 	time[50];
};

int order = 0;
struct CostumerData data[100];

// Add new order 
void add_order() 
{
	struct CostumerData tmp;
	if(order < 100)
	{
		printf("\nAddress: ");
		scanf("%s",tmp.house_address);
		printf("\nHouse Size: ");
		scanf("%s", tmp.house_size);
		printf("\nTask:");
        scanf("%s", tmp.tasks);

      time_t rawtime;
      struct tm * timeinfo;
      time ( &rawtime );
      timeinfo = localtime ( &rawtime );
      printf ("\nCurrent local time and date: %s", asctime (timeinfo) );
      strftime(tmp.time,50,"%I:%M%p.",timeinfo);

	}
	data[order] = tmp;
	order +=1;
	printf("\nAdd new order\n");
}

// modify orders 
void modify_it() // used to edit datas
{
    int choice;
    int i = 0;
    int item = 0;
    struct CostumerData tmp;

    if(order > 0 && item < order && item > -1)
       {
        printf ("\nWhich record do you wish to edit? (Enter a number)\n");
        scanf ("%d", &i);

        printf("\n1.Address: ");
        printf("\n2.House Size: ");
        printf("\n3.Task:");
        printf("\n");

        scanf("%d", &choice);

        switch(choice)
        {

        case 1:
            scanf("%s",data[i-1].house_address);
            break;
        case 2:
            scanf("%s",data[i-1].house_size);
            break;
        case 3:
            scanf("%s",data[i-1].tasks);
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
}


// delete existent order 
void delete_order()
{
    int i =0;
    int item =0;
    char deleteAddress[10];
    char deleteHouse_SIZE[10];
    char nullStr[20] = {"\0"};
    struct CostumerData x;


    if(order > 0 && item < order && item > -1)
    {
          printf ("\nWhat is the address that you would like to delete ?\n");
          scanf("%s",deleteAddress);
          printf ("\nWhat is their House size?\n");
          scanf("%s",deleteHouse_SIZE);

                for(i = 0;i < order; i++)
                {
                    if(strcmp(deleteAddress, data[i].house_address) == 0)
                    {   
                        for(i = 0; i < order; i++)
                        {
                            if(strcmp(deleteHouse_SIZE, data[i].house_size) == 0)
                            {
                                strcpy(data[i].house_address, data[i+1].house_address);
                                strcpy(data[i].house_size, data[i+1].house_size);

                                strcpy(data[i].time, data[i+1].time);
                                order--;
                                printf("\nOrder removed from the record.\n");
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

}

// print all data 
void printall()
{
    int n;
    printf("\nData:\n");
    for(n = 0; n < order; n++)
    {
        printf("\n%d.\n", n+1);
        printf("%s\n",data[n].house_address);
        printf("%s\n",data[n].house_size);
        printf("%s\n\n",data[n].time);
    }
}





// Main 
int main()
{
int choice;

struct CostumerData x;

do{
	printf("\nEnchanting-Home Menu:\n");
	printf("\nInput the number of Order \n");
	printf("\n1. Add new order\n");
    printf("\n2. Edit order\n");
    printf("\n3. Delete order\n");
    printf("\n4. List all the data\n");
    printf("\n5. Exit\n");
    scanf("%d", &choice);

    int i = 0;

    switch(choice)
    {
    	case 1 : 
    	add_order();
    	break;

    	case 2 : 
    	modify_it();
    	break;

    	case 3 : 
    	delete_order();
    	break;

    	case 4 : 
    	printall();
    	break;
    	case 5 : 
    	printf("\nSzia!!\n");
        exit(0);
    	default : 
    		printf("\n Wrong input please try again.\n");
    	break;
    }
}
while(choice != 4);
	


	return 0;
}









