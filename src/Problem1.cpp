/*
Given a Binary Tree of N Nodes, which have unique values in the range of 
[0,N](Inclusive)  with one value(Node) missing in that sequence.
Return that missing value .

Example 1 : N=5 
   3
  / \
 4   1
    / \
   5   0
Missing Value is 2 ,Sequence is [0,1,2,3,4,5]

Example 2 : N=8
      2
     / \
    4   5
   / \ / \
  3  1 6  8
 /
0
Missing Value is 7 ,Sequence is [0,1,2,3,4,5,6,7,8]

Constaints : 
-10000<=N<=10000 [N will not be equal to 0]



Input :
Struct node Root Address
Output :
Return Missing Value .
Return -1 for NULL Inputs 

Note:
Dont Create an Extra Array/String ,or else your solution would receive 30% Cut in the Marks you got for this
question .

Difficulty : Easy
*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
# define MAX 20
struct node *s[MAX];
int top = -1;
void push(struct node *);
struct node * pop();

struct node{
	int data;
	struct node *left;
	struct node *right;
};


int get_missing_value(struct node *root,int n){
	int sum;
	if (root == NULL || n == 0)
		return -1;
	sum = n * ((n + 1) / 2);
	while (1){
		while (root){

			push(root);
			root = root->left;

		}
		if (top == -1)
			break;
		root = pop();
		sum = sum - root->data;
		root = root->right;
	}
	return sum;
   // return -1;
}
void push(struct node * x){
	top++;
	s[top] = (struct node *)malloc(sizeof(struct node *));
	s[top] = x;

}
struct node * pop(){
	struct node *x;
	x = s[top];
	top--;
	return x;

}