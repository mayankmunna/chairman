#include<stdio.h>
void create_board(int [][8]);
void get_details();
void draw_board(int [][8]);

int which_turn;  // 0 for white 1 for black

int tot_white_mov;
int tot_black_mov;



char player_black[11];
char *player_white[11];

void update_move_white(int [][8]);
void update_move_black(int [][8]);
int main ()
{
  	int board[8][8]={0};
 	get_details();
 	create_board(board); 
	 draw_board(board);
	update_move_white(board);
return 0;

}
void create_board(int arr[][8])
{
	int i,j;
	char soldiers[]={'r','n','b','k','q','b','n','r'};
	char psuine = 'p';

	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			arr[i][j]=' ';
		
	for(i=0;i<2;i++)
	{
		for(j=0;j<8;j++)
		{
		if(i==0)
		  arr[i][j]=(int)soldiers[j];
		if(i==1)
		  arr[i][j]=(int)psuine;
		 }
	}
	for(i=6;i<8;i++)
	{
	   for(j=0;j<8;j++)
	    {
		if(i==7)
		  arr[i][j]=(int)(soldiers[j]-32);
		if(i==6)
		  arr[i][j]=(int)(psuine-32);
	    }
	}
}
void draw_board(int arr[][8])
{
	int i,j;
	printf("\n\t\t\tBLACK:%s\n",player_black);
	printf("1\t2\t3\t4\t5\t6\t7\t8\n");
	printf("___________________________________________________________\n");
	for(i=0;i<8;i++)
	{
	   for(j=0;j<8;j++)
	    {
		 printf("%c |\t",(char)arr[i][j]);
	    }
		printf("\n");
		printf("___________________________________________________________\n");
	}
	printf("1\t2\t3\t4\t5\t6\t7\t8\n");
	printf("\n\t\t\tWHITE:%s\n",player_white);

}

void update_move_white(int arr[][8])
{


	char turn;
	static int first_move_white=0;
	static	int psuine_index[8]={0};
	int index=0;
	int steps=0;
	int i,j;
	if(which_turn==1)
		{
			update_move_black(arr);
			return;
		}
	printf("\n\t\"%s's\"Turn:\n",player_white);
		if(first_move_white==0 )
		{
			printf("\nSelect the correct index of psuine to move:");
			scanf("%d",&index);
				if((index<1) && (index>8))
				{
				  	printf("ARE YOU NOT PLAYING ON BOARD,board has limits.");
					update_move_white(arr);
					return;
				}
				index--;
			printf("\nNo. of steps:");
			scanf("%d",&steps);
			if(psuine_index[index]==0 && steps==2) 
			{
				if(arr[5][index]==(int)' ' && arr[4][index]==(int)' ')
					{
						arr[4][index]=(char)arr[6][index];
						arr[6][index]= (int)' ';
						first_move_white=1;
						psuine_index[index]=1;
					}
			}
			else if(steps==1)
			{
				if(arr[5][index]==(int)' ' )
					{
						arr[5][index]=arr[6][index];
						arr[6][index]= (int)' ';
						first_move_white=1;
						psuine_index[index]=1;
					}
			}
	
		else
		{
			printf("\nCannot move\n");
			update_move_white(arr);
			return;
		}	
		draw_board(arr);
		tot_white_mov++;
		which_turn=1;
	}       //end of main if
else	
{

	printf("Enter the name of soldier you want to send to the battle field:");
	fflush(stdin);
	scanf("%c",&turn);
	fflush(stdin);	
		
	if(!(turn == 'P' || turn == 'R'|| turn == 'N' || turn == 'B' || turn== 'Q'|| turn== 'K'))
		{
			printf("\t\nORDER ONLY YOUR SOLDIER TO MOVE:");
			update_move_white(arr);
			return;	
		}
	else 
	{	
		printf("\nEnter the column number of your soldier:");
		scanf("%d",&index);
		if((index<1) && (index>8))
		{
	  	printf("ARE YOU NOT PLAYING ON BOARD,Board has limits..");
		update_move_white(arr);
		return;
		}
		index--;
		

		for(i=0,j=index;i<8;i++)
		{
				
		  if( arr[i][j]==(int)turn )
		  	break;
		}

		if ( arr[i][j]!= (int)turn )
		{
			printf("\nNOT AVAILABLE in this column,try again");
			update_move_white(arr);
			return;
		}	
	
		if(turn == 'P')
		{
			if(arr[--i][index]< 97 && arr[i][index]>=65)
			{
				printf("\nCannot move/kill your own BRAVO");
				update_move_white(arr);
				return;
			}
			else if(arr[i][index] == (int)' '|| arr[i][index]>= 97 )
			{
				
				printf("\n\nYou killed \"%c\" of your opponent",arr[i][index]);
				arr[i][index] = arr[++i][index]; // kill opponent.
				
				arr[i][index]=(int)' ' ; // fill vacant value with ' '..
				tot_white_mov++;
				draw_board(arr);
				which_turn =1;   // black's turn now....
			
			}	
		}	
	
	}//else closed
	}
	update_move_black(arr);
}	
void update_move_black(int arr[][8])
{
	which_turn =0;
	
		update_move_white(arr);
	
	
}	
void get_details()
{
	printf("\nEnter the Player BLACK:");
	scanf("%s",player_black);
	printf("\nEnter the Player WHITE:");
	scanf("%s",player_white);
}
