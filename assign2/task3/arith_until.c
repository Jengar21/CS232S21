/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

//circle_calculation() function
//its return type is void
//and, it doesn't take any parameters
void circle_calculation(){
    //Declaration of float variables
    float r, c, a;
    
    //Taking radius(in mm) as input from the user
    printf("Enter radius (in mm):\n");
    scanf("%f",&r);
    
    //if user enters 0 as radius
    //then, printing "Exit"
    //and, returning from the function
    if(r == 0){
        printf("Exit\n");
        //returning using return statement
        return ;
    }
    
    //if user does not enters 0 
    //then, this else block will be executed
    else{
         a = PI * r * r;
         
         c = 2 * PI * r;
         
         c = c/25.4;
         
         a = a/645.16;

        printf("Circle's area is %3.2f (sq in).\n",a);
        
        //Printing the circumference
        printf("Its circumference is %3.2f (in).\n",c);
        
        //Calling the function circle_calculation() recursively
        circle_calculation();
    }
}

//main() function
int main()
{
    //Calling the circle_calculation() function
    circle_calculation();

    return 0;
}
