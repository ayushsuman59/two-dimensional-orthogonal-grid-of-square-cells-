#include<iostream>
#include<stdlib.h>
#define ROW 500                                                                 //max ROW in Gird
#define COL 500                                                                 //max COLumn in Grid
using namespace std;
 

int colPrint(int col){                                                           //used to print column lines
    cout<<endl;
    for(int i=0; i<col; i++)
    {
        cout<<" -----";
    }
    cout<<endl;
}
 
 
int countLiveNeighbourCell(int initialGrid[][COL], int row,int col,int r, int c)                       //used to count number of live cell i.e...which is equal to 1.
{
    int i, j, count=0;
    
    for(i=r-1; i<=r+1; i++)
    {
        for(j=c-1;j<=c+1;j++)
        {
            if((i==r && j==c) || (i<0 || j<0) || (i>=row || j>=col))
            {
                continue;
            }
            if(initialGrid[i][j]==1)
            {
                count++;
            }
        }
    }
    return count;
}



void getFinalGrid(int initialGrid[][COL] ,int finalGrid[][COL],int row,int col)                                          //to get the final gird .
{
    int neighbourLiveCell;
    
    for(int i=0; i<row; i++)
    {
        for(int j=0;j<col;j++)
        {
            neighbourLiveCell = countLiveNeighbourCell(initialGrid,row,col,i,j);
            
            if(initialGrid[i][j]==1 && (neighbourLiveCell==2 || neighbourLiveCell==3))
            {
                finalGrid[i][j]=1;
            }
 
            else if(initialGrid[i][j]==0 && neighbourLiveCell==3)
            {
                finalGrid[i][j]=1;
            }
 
            else
            {
                finalGrid[i][j]=0;
            }
        }
    }   
}



void printGrid(int grid[][COL],int row,int col)                                  //to print the final grid
{
    colPrint(col);
    
    for(int i=0; i<row; i++)
    {
        cout<<"|";
        
        for(int j=0;j<col;j++)
        {
            cout<<"  "<<grid[i][j]<<"  |";
        }
        
        colPrint(col);
    }   
}


void checkCell(int finalGrid[][COL],int newRow,int newCol,int row, int col){
	
    if(newRow<row && newCol<col)
	{
    	if(finalGrid[newRow][newCol]==1)
		{
    		cout<<"Cell at "<<newRow<<","<<newCol<<" is "<<"Live"<<endl;
    	}
		else
		{
    		cout<<"Cell at "<<newRow<<" "<<newCol<<" is "<<"Dead"<<endl;
    	}
    }
	else
	{
    	cout<<"Invalid input"<<endl;
    }
}




 
int main(){                                                                      //main function
  
    int row,col,newRow,newCol;
    cin>>row>>col;                                                               //user input of rows and columns
    
    int initialGrid[ROW][COL], finalGrid[ROW][COL];
 
 
    /*for(i=0; i<row; i++){                                                      //this take the user input .            
        for(j=0;j<col;j++){
           cin>>initialGrid[i][j];
        }
    }*/
    
    
    for(int i=0; i<row; i++){                                                    // this will take input from rand() function which generates random value .
        for(int j=0;j<col;j++){
            initialGrid[i][j] = rand() % 2;
        }
    }
     
   
    cout<<"Initial Grid:";
    printGrid(initialGrid,row,col);                                             //print the initial GRID
 
 
    getFinalGrid(initialGrid,finalGrid,row,col);                                //main logic to set the value for current column.
    
    cout<<endl;
    cout<<"Final Grid:";
    printGrid(finalGrid,row,col);                                               //print final GRID
    
    cout<<endl;
    
    cout<<"To know current state of cell ,Enter its Row and column :"<<endl;                                   
    cin>>newRow>>newCol;
    
    checkCell(finalGrid,newRow,newCol,row,col);
    
    
    return 0;
}
