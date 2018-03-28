/* 
 * File name: calc.c
 * Author: Edward Lee
 * CSCI 304, Davis
 * Date: 2 March 2018
 * Program Details: To create a program in C that can display values in various base 
 * representations.
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//void add (short *acc, char mode){}
//void subtract (short *acc, char mode){}

void convert_to_binary (short acc, char *bin){
  *(bin+16) = '\0';
  int shift = 0x10 << 1;
  while (shift >>= 1){
    *bin++ = !!(shift & acc) + '0';
  }
}
unsigned short get_binary_op (char *bin){
  short num_Dec = 0;
  int loc;
  char sign;
  

  if(bin[0] == '1'){
    sign = '-';
  }
  else{
    sign = '+';
  }

  printf(bin);

  for (loc = strlen(bin) -1; loc >= 1; loc--){
    num_Dec = num_Dec << 1;
    if (bin[loc] == '1'){
      num_Dec += 1;
    }
  }
  if (sign = '-'){
    num_Dec = num_Dec - 32768;
  }
  return num_Dec;
}





void print_acc (short acc){

    
    
    printf("\n****************************************\n"
           "* Accumulator:                         *\n");
    //printf("*   Binary  : %hd       *\n", acc); 
    printf("*   Hex     : %04hX                     *\n", acc); //doing the %0 does 
    printf("*   Octal   : %06ho                   *\n", acc);   //the conversions for you!
    printf("*   Decimal : %-10hd               *\n", acc);
    printf("****************************************\n"
           " \n");
}
           
char print_menu(){
   char temp[10];
   printf("Please select one of the following options:\n" //initialize menu
            "\n"
            "B  Binary Mode          &  AND with Accumulator          +  Add to Accumulator\n"
            "O  Octal Mode           |  OR  with Accumulator          -  Subtract from Accumulator\n"            
            "H  Hexadecimal Mode     ^  XOR with Accumulator          N  Negate Accumulator\n"
            "D  Decimal Mode         ~  Complement Accumulator\n" 
            "\n"
            "C  Clear Accumulator    <  Shift Accumulator Left\n"
            "S  Set Accumulator      >  Shift Accumulator Right\n"   
            "\n"
            "Q  Quit\n");
   
   printf("\nOption: ");
   scanf("\n%s", &temp);
   printf("%s", temp); //echo printing
   char cap_return = toupper(temp[0]);
   return cap_return;
}
short get_operand(char mode){
  
  short val;
  char converter[17];
  char *bin = converter;
  

  switch(mode){ //switches between the various cases octal, hex, decimal.
    
    case 'B':
      printf("\nEnter binary value: ");
      scanf("%s", bin);
      printf("%s", bin); //echo printing
      val = get_binary_op (bin);
      break;
    
    case 'O':
      printf("\nEnter octal value: ");
      scanf("%06ho\n", &val);
      printf("%ho",val); //echo printing
      break;
    
    case 'H':
      printf("\nEnter hex value: ");
      scanf("%04hX\n", &val); //capital X makes it so the hex alphabetical values are capital.
      printf("%hX", val); //echo printing
      break;
    
    case 'D':
      printf("\nEnter decimal value: ");
      scanf("%hd", &val);
      printf("%hd\n", val); //echo printing
      
    /*case '&':
    printf("\nEnter %")
      break
    case '|':
      break
    case '^':
      break
    case '~':
      break
    case '<':
      break
    case '>':
      break
    case '+':
      break
    case '-':
      break
    case 'N':
      break*/
    }

  
  return val;
  }
      
  
int main(){
  
  short acc = 0;
  print_acc(acc);
  char mode = 'D';
  char userInput;
  char *binary = NULL;
  print_acc(acc);

  
  while(userInput != 'Q'){ //keeps the loop until quit is designated
  userInput = print_menu();
  
    
    switch(userInput){ //switches between the various cases
    
    case 'B':
      mode = userInput;
      printf("Mode is Binary\n");
      print_acc(acc);
      userInput = print_menu();
      acc = get_operand(mode);
      print_acc(acc);
      break;



    case 'O':
      mode = userInput;
      printf("\nMode is Octal\n\n");
      print_acc(acc);
      userInput = print_menu();
      acc = get_operand(mode);
      print_acc(acc);
      break;
      
    case 'H':
      mode = userInput;
      printf("\nMode is Hexadecimal\n\n");
      print_acc(acc);
      userInput = print_menu();
      acc = get_operand(mode);
      print_acc(acc);
      break;
      
    case 'D':
      mode = userInput;
      printf("\nMode is Decimal\n\n");
      print_acc(acc);
      userInput = print_menu();
      acc = get_operand(mode);
      print_acc(acc);
      break;
      

    case 'C':
      acc = 0;
      mode = 'D';
      print_acc(acc);
      break;
      
    case 'S':
      if(userInput == 0)
      {
        mode = 'D';
      }
      acc = get_operand(mode);
      print_acc(acc);
      break;

    //case '<':
      //mode = userInput;
      
    case 'Q':
      if (strlen(&userInput) == 1){ //makes it so that the user input has to be 1 value or it won't exit
        exit(1);
    /*case '&':
      break
    case '|':
      break
    case '^':
      break
    case '~':
      break
    case '<':
      break
    case '>':
      break
    case '+':
      break
    case '-':
      break
    case 'N':
      break*/
      }
      else{
        printf("\n\nInvalid option: %c \n\n", userInput);
      }
      userInput = print_menu();
      break;
      
    default :
      printf("\n\nInvalid option: %c  \n\n", userInput);
      break;
    }
  }
}

   