Pooja Shende
----------------------
**Product:** ConnectX

* **Bug Number:** 1
 * **Bug Name:** inBounds(int column, int row) returns incorrect result for the wrong value of coulmn number.

 * **Reported On:** 4/7/2016

 * **Description:** inBounds(int column, int row) checks whether the provided location is a valid space in the board. For board with height 'h' and width 'w' , if input parameter values for column and row lie between zero and 'w'/'h' respectively, then function should return true otherwise false. If input has wrong value of row irrespective of column value, function works correctly with false return value. However, if input has wrong column value and correct row value then function return true value which is incorrect behaviour of function.

 * **Steps to Reproduce Bug:** Write below code to reproduce the above error,  
`int main()  
{  
ConnectX c;  
int value=c.at(-3,2);  
if(value==-1)  
{  
cout<<"Invalid location";  
}  
else  
{  
   cout<<"Valid location";  
}  
}`

 * **Expected Result:** Invalid location

 * **Actual Result:** Valid location

