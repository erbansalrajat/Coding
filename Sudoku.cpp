#include<vector>
int filloptions(int board[][9],vector<int>& options, int m, int n)
{
    int k=1;
	for(;k<10;k++)
    {
        bool flag=true;
		for(int i=0;i<9;i++)
        {
             if(board[m][i]==k)
             {	
                 flag=false;
                 break;
             }
        }
        if(flag==false)
            continue;
        for(int i=0;i<9;i++)
        {
            if(board[i][n]==k)
            {	
                flag=false;
                break;
            }
        }
        if(flag==false)
            continue;
        int row=(m/3);
        row*=3;
        int col=n/3;
        col*=3;
        for(int i=0;i<3;i++)
        {
            if(flag==false)
                break;
        		for(int j=0;j<3;j++)
        		{
                	if(board[row+i][col+j]==k)
                    {	
                    	flag=false;
                        break;
                    }  
        		} 	  
        }
        if(flag==true)
        {
            // cout<<k<<endl;
        	options.push_back(k);
        }
    }
    return options.size();
}
void printkardenabhai(int board[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
bool helperSolver(int board[][9], int x, int y)
{
    if(x==8 && y==8)
    {
        
        if(board[x][y]!=0)
        {
            // printkardenabhai(board);
        	return true;
        }
        else
        {
            // cout<<"it came here"<<endl;
            vector<int>options;
        	if(filloptions(board,options,8,8)==1)
            {
                // printkardenabhai(board);
                return true;
            }
            else
                return false;
        }
    }
	// cout<<x<<" "<<y<<endl;
    if(board[x][y]==0)
    {
        vector<int>options;
        int size=filloptions(board,options,x,y);
        if(size==0)
        {
            return false;
        }
        else
        {
            int m=0;
            // cout<<size<<endl;
            while(m<size)
            {
                
                board[x][y]=options[m];
                if(y==8)
                {
                    if(helperSolver(board,x+1,0)==true)
                        return true;
                }
                else
                {
                    if(helperSolver(board,x,y+1)==true)
                    	return true;
                }
                m++;
            }
            board[x][y]=0;
            // cout<<"it came here";
            return false;
        }
    }
    else
    {
        if(y==8)
            helperSolver(board,x+1,0);
        else
            helperSolver(board,x,y+1);
    }
}

bool sudokuSolver(int board[][9])
{
	return helperSolver(board,0,0);  
}
