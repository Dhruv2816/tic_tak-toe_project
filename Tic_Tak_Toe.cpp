#include <iostream>

using namespace std;

void print(char arr[4][4])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << arr[i][j] << " ";
        }
       
        cout << endl;
       
    }
}

void define(char arr[4][4])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            arr[i][j] = '#';
        }
       
    }
   
   
}
bool condition(char arr[4][4])
{
    for(int i = 0 ; i < 3 ; i++)
        {
            if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]  )
            {
                if(arr[i][0] == 'X')
                {
                    cout << "Plyer 1 wins" << endl;
                    return false;
                }
                if(arr[i][0] == 'O')
                {
                    cout << "Plyer 2 wins" << endl;
                    return false;
                }
            }
           
        }
       
    for(int j = 0 ; j < 3 ; j++)
    {
        if(arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]  )
        {
            if(arr[0][j] == 'X')
            {
                cout << "Plyer 1 wins" << endl;
                return false;
               
            }
            if(arr[0][j] == 'O')
            {
                cout << "Plyer 2 wins" << endl;
                return false;
            }
        }
       
    }
   
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]  )
    {
        if(arr[0][0] == 'X')
        {
            cout << "Plyer 1 wins" << endl;
            return false;
        }
        if(arr[0][0] == 'O')
        {
            cout << "Plyer 2 wins" << endl;
            return false;
        }
    }
   
    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]  )
    {
        if(arr[0][2] == 'X')
        {
            cout << "Plyer 1 wins" << endl;
            return false;
        }
        if(arr[0][2] == 'O')
        {
            cout << "Plyer 2 wins" << endl;
            return false;
        }
    }
   
    return true;
}

bool input_check(int i, int j , char arr[4][4])
{
    if(arr[i-1][j-1] == 'O' || arr[i-1][j-1] == 'X' || i > 3 || j > 3)
    {
        cout << "Invalid Move try again" << endl;
        return true;  
    }
    return false;
   
}


int main()
{
    char arr[4][4] ;
   
    bool flag = true;
    bool flag2 = true;
    while(flag == true)
    {
        define(arr);
        print(arr);
        int t = 0;
        int r;
        int c;
        while(flag2 == true)
        {  
            while(true)
            {
                cout << "Player 1 enter your move, Your variable is X : " << endl;
                cout << "Enter the row : ";
                cin >> r;
                cout << "Enter the column : ";
                cin >> c;
                if(!input_check(r, c ,arr))
                    {
                        break;
                    }
            }
           
            arr[r-1][c-1] = 'X';
            t++;
           
            print(arr);
            flag2 = condition(arr);
           
            if(t == 9)
            {
                cout << "Game tied :" << endl;
                break;
            }
           
            if(flag2 == false)
            {
                break;
            }
            while(true)
            {
                cout << "Player 2 enter your move, Your variable is O : " << endl;
                cout << "Enter the row : ";
                cin >> r;
                cout << "Enter the column : ";
                cin >> c;
                if(!input_check(r, c ,arr))
                    {
                        break;
                    }
            }
           
            arr[r-1][c-1] = 'O';
            t++;
            print(arr);
           
            flag2 = condition(arr);
           
            if(t == 9)
            {
                cout << "Game tied :" << endl;
                break;
            }
        }
       
        cout << "DO you wnat to play again enter y for yes and n for no : " << endl;
        char in;
        cin >> in;
        if(in == 'y')
        {
            flag = true;
            flag2 = true;
        }
        else
        {
            flag = false;
        }
       
       
       
    }
   
   
   
     
   

    return 0;
}