#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define err_exit(MESSAGE) ( \
	perror(MESSAGE),		\
	exit(1)					\
)

struct ListNode {
    int val;
    struct ListNode *next;
};
 
#define BASE_NUM 10

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  
      if (l1 == NULL || l2 == NULL) {
        return NULL;
      }
  
      int sumOfAandB = 0;
      int remainder = 0;   //餘數
      bool createNewNodeFlag = false;
      
      //Create curNode  
      struct ListNode* curNode = (struct ListNode*) malloc(sizeof(struct ListNode));
      curNode->val = 0;
      curNode->next = NULL;
      //For return
      struct ListNode* returnListNode = curNode;
  
      while (l1 != NULL || l2 != NULL || createNewNodeFlag) {
        
        //STEP.1 Cal
        createNewNodeFlag = false;
        sumOfAandB = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + remainder;
        printf("sumOfAandB is %d\n", sumOfAandB);
        
        //STEP.2 decide to create NewNode
        //forward next one
        if(l1 != NULL)
          l1 = l1->next;
        if(l2 != NULL)
          l2 = l2->next;
        if (l1 != NULL || l2 != NULL) {
          createNewNodeFlag = true;
        }
        
        if (sumOfAandB > BASE_NUM) {
          createNewNodeFlag = true;
          curNode->val = sumOfAandB % BASE_NUM;
          remainder = 1;
        } else if (sumOfAandB == BASE_NUM) {
          createNewNodeFlag = true;
          curNode->val = 0;
          remainder = 1;
        } else if (sumOfAandB < BASE_NUM) {
          curNode->val = sumOfAandB % BASE_NUM;
          remainder = 0;
        }
        
        //STEP.3 Create the NewNode
        if (createNewNodeFlag) {
           curNode->next = (struct ListNode*) malloc(sizeof(struct ListNode));
           curNode = curNode->next;
           //Reset 
           curNode->val = 0;
           curNode->next = NULL; //be noticed
        } 
      }
  
     return returnListNode;
}

int main(void)
{
	printf("Please copy it to https://leetcode.com/problems/add-two-numbers/description/\n");
	return 0;
}
