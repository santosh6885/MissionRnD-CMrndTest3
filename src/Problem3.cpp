/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>;
#include <stdio.h>
# define MAXA 50
struct enode *s[MAXA];
int topa = -1;
void pusha(struct enode *);
struct enode * popa();
//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

/*
Helper Functions are optional to write 
*/
//Helper Functions Start
int isOperator(char *data){
	char check = data[0];
	if (check == '+' || check == '-' || check == '*')
		return check;
	else 
		return 0;
}
int isOperand(char *data){
	char ch = data[0];
	int i,num=0;
	if (ch >= 48 && ch <= 57)
	{
		for (i = 0; data[i]; i++){
			if (ch >= 48 && ch <= 57){
				num = (data[i] - '0') + num;
				num = num * 10;
			}
		}
		num = num / 10;
		return num;
	}
	else
		return -1;
}
int getOperand(char *data){
	//converts data string to an integer "123" => 123
	return 0;
}
//Helper Functions end
int solve_tree(struct enode *root){
	int prevop=-1, nexttop=-1,res=0,flag = 1;
	char ope = 0;

	if (root == NULL)
		return -1;
	while (1){
		while (root){

			pusha(root);
			root = root->left;

		}
		if (topa == -1)
			break;
		root = popa();
		if (ope==0)
			ope = isOperator(root->data);
		if (flag == 1){
			prevop = isOperand(root->data);
			flag = 0;
		}
		else
			nexttop = isOperand(root->data);
		
		if (ope != 0 && nexttop !=-1){
			if (res == 0){
				if (ope == '+'){
					res = prevop + nexttop;
				}
				else if (ope == '-'){
					res = prevop - nexttop;
				}
				else if (ope == '*'){
					res = prevop * nexttop;
				}
			}
			else {
				if (ope == '+'){
					res = res + nexttop;
				}
				else if (ope == '-'){
					res = res - nexttop;
				}
				else if (ope == '*'){
					res = res * nexttop;
				}
			}
			ope = 0;
			nexttop = -1;
		}


		root = root->right;
	}
	return res;

    //return -1;
}
void pusha(struct enode * x){
	topa++;
	s[topa] = (struct enode *)malloc(sizeof(struct enode *));
	s[topa] = x;

}
struct enode * popa(){
	struct enode *x;
	x = s[topa];
	topa--;
	return x;

}
