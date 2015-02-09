/*
 * main.cpp
 *
 *  Created on: 2013-2-25
 *      Author: Hao Zou
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <List>
#include <deque>
#include <map>
using namespace std;
typedef struct LinkNode{
	int data;
	LinkNode *next;
	LinkNode(const int& data):data(data),next(NULL){}
}LinkNode;

typedef struct Node{
	int data;
	Node *next;
	Node(const int& data):data(data),next(NULL){}
}Node;

typedef struct DoubleLink{
	int data;
	DoubleLink *next;
	DoubleLink *prev;
	DoubleLink(const int& data):data(data),next(NULL),prev(NULL){}
}DoubleLink;
struct BSTNode{
    int value;
    BSTNode *left;
    BSTNode *right;
    BSTNode(const int& value): value(value), left(NULL),right(NULL){}
};
enum NODE_TYPE{
	COMPLETED,
	UNCOMPLETED
};
#define MAX_NUM 26
typedef struct TrieNode{
	enum NODE_TYPE type;
	int index;
	TrieNode* child[MAX_NUM];
	TrieNode()
	{
		this->index = -1;
		this->type = UNCOMPLETED;
		int i;
		for (i = 0; i < MAX_NUM; i++)
			this->child[i] = NULL;
	}
}TrieNode;


typedef struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode(const int& value): value(value),left(NULL),right(NULL){}
}TreeNode;
//Implement an algorithm to determine if a string has all unique characters.
//What if you can not use additional data structures?
bool isUnique(string str)
{
	int check = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		int tmp = str[i] - 'a';
		if ((check & (1 << tmp)) > 0)
			return false;
		check |= (1 << tmp);
	}
	return true;
}
//Write code to reverse a C-Style String.
//(C-String means that ��abcd�� is represented as five characters,
//		including the null character.)
char* my_strrev(char *str)
{
	char *tmp = new char[strlen(str)+1];
	strcpy(tmp,str);
	char *rev = tmp;
	char *end = tmp + strlen(str) - 1;

	for (;end > tmp;end--,tmp++)
	{
		*end ^= *tmp;
		*tmp ^= *end;
		*end ^= *tmp;
	}
	return rev;
}
//Design an algorithm and write code to remove the duplicate characters in a string
//without using any additional buffer. NOTE: One or two additional variables are fine.
//An extra copy of the array is not.
void removedup(char str[])
{

	if (str == NULL) return;
	int len = strlen(str) + 1;

	int i,j;
	int tail = 1;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < tail; j++)
			if (str[i] == str[j]) break;
		if (tail == j)
			str[tail++] = str[i];
	}
	str[tail] = 0;
}
// with additional memory
void removedup2(char str[])
{

	if(str==NULL) return;
	int len=strlen(str)+1;
	if(len<2)return;

	bool hit[256];
	memset(hit,false,sizeof(hit));
	hit[str[0]] = true;
	int tail=1;//save unique char
	for(int i=1;i<len;i++)
	{
		if(!hit[str[i]])
		{
			str[tail]=str[i];
			tail++;
			hit[str[i]] = true;
		}
	}
	str[tail]=0;
}
//Write a method to decide if two strings are anagrams or not.
int is_anagram(char *s1, char *s2)
{
	int letters[52];
	int num1 = 0, num2 = 0;
	memset(letters,0,sizeof(letters));
	while(*s1)
	{

		if (*s1 - 'a' >= 0 && *s1 - 'a'< 26)
		{
			if (letters[*s1 - 'a'] == 0)
				++num1;
			++letters[*s1 - 'a'];
		}
		if (*s1 - 'A' >= 0 && *s1 - 'A'< 26)
		{
			if (letters[26+*s1 - 'A'] == 0)
				++num1;
			++letters[26+*s1 - 'A'];
		}
		s1++;
	}
	while(*s2)
	{

		if (*s2 - 'a' >= 0 && *s2 - 'a'< 26)
		{
			if (letters[*s2 - 'a'] == 0)
			{
				return 0;
			}
			--letters[*s2 - 'a'];
			if (letters[*s2 - 'a'] == 0)
			{
				++num2;
			}
		}
		if (*s2 - 'A' >= 0 && *s2 - 'A'< 26)
		{
			if (letters[26+*s2 - 'A'] == 0)
			{
				return 0;
			}
			--letters[26+*s2 - 'A'];
			if (letters[26+*s2 - 'A'] == 0)
			{
				++num2;
			}
		}
		s2++;
	}
	if (num2 == num1)
		return 1;
	return 0;
}
//��һ��int���飬ÿ��int�ķ�Χ����1��10000���ҳ���С�Ĳ����ڵ������array={3,1,4} return 2  �������˼�����������
int find_min(int a[],int len)
{
	int b[10000];
	int min = 100001;
	memset(b,0,10000);
	for (int i = 0; i < 10000; i++)
	{
		if (i < len)
		{
			b[a[i]-1] = 1;
		}

	}
	for (int i = 0; i < len; i++)
	{
		cout<<b[i]<<endl;
		if (b[i] == 0 && i+1 < min)
		{
			min = i+1;
		}
	}
	return min;
}
// find the minimum kth numbers of n array
int findkth(int a[], int left, int right, int k)
{
	return 1;
}
//quicksort
int partition(int a[],int left, int right)
{
	int pivot_index = left;
	int pivot = a[pivot_index];
	a[pivot_index] = a[right];
	a[right] = pivot;

	for (int i = left; i < right; i++)
	{
		if (a[i] < pivot)
		{
			int tmp = a[pivot_index];
			a[pivot_index] = a[i];
			a[i] = tmp;
			pivot_index++;
		}
	}
	a[right] = a[pivot_index];
	a[pivot_index] = pivot;
	return pivot_index;
}
void quicksort(int a[], int left, int right)
{
	if (left < right)
	{

		int pivot_index = partition(a, left,right);
		quicksort(a,left,pivot_index - 1);
		quicksort(a,pivot_index+1,right);
	}
}
vector<int> merge_two_array(vector<int> a, vector<int> b)
{
	vector<int> result = vector<int>();
	unsigned int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] <= b[j])
			result.push_back(a[i++]);
		else
			result.push_back(b[j++]);
	}
	while (i < a.size())
	{
		result.push_back(a[i++]);
	}
	while (j < a.size())
	{
		result.push_back(b[j++]);
	}
	return result;
}
static void merge(int a[],int left, int mid,int right)
{
	int tmp[right-left+1];
	int i = left, j = mid+1,k = left;
	for (k = left; k <= right; k++)
		tmp[k] = a[k];
	k = left;
	while(i <= mid && j <= right)
	{

		if (tmp[i] <= tmp[j])
		{
			a[k++] = tmp[i];
			i++;
		}
		else
		{
			a[k++] = tmp[j];
			j++;
		}
	}
	while(i <= mid)
	{
		a[k++] = tmp[i++];
	}
	while(j <= right)
	{
		a[k++] = tmp[j++];
	}

}
void merge_sort(int a[],int left,int right)
{
	if (left >= right) return;

	int mid = (left+right) / 2;
	merge_sort(a,left,mid);
	merge_sort(a,mid+1,right);

	merge(a,left,mid,right);
}
vector<int> intersection(vector<int> a, vector<int> b)
{
	vector<int> result = vector<int>();
	unsigned int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i] < b[j]) i++;
		else if (a[i] > b[j]) j++;
		else
		{
			result.push_back(a[i]);
			i++;
			j++;
		}
	}
	return result;
}
//Write code to remove duplicates from an unsorted linked list.
//FOLLOW UP
//How would you solve this problem if a temporary buffer is not allowed?
int del_dup(LinkNode **root)
{
	LinkNode *cur = *root;
	if (!cur) return 1;
	set<int> setkey;
	setkey.insert(cur->data);
	while (cur->next)
	{
		if (setkey.count(cur->next->data))
		{
			LinkNode *tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
		}
		else
		{
			setkey.insert(cur->data);
			cur = cur->next;
		}
	}
	return 1;
}
// without other structrual
int del_dup2(LinkNode *root)
{

	LinkNode *current = root;
	if (!current) return 1;
	LinkNode *tail = current->next;
	while (current->next)
	{
		LinkNode *previous = root;
		while(previous != tail)
		{
			if (previous->data == current->next->data)
			{
				LinkNode *tmp = current->next;
				current->next = tmp->next;
				delete tmp;
				break;
			}
			previous = previous->next;
		}
		if (tail == previous)
		{
			current = current->next;
			tail = tail->next;
		}
	}
	return 1;
}
//Implement an algorithm to find the nth to last element of a singly linked list.
LinkNode* nthtolast(LinkNode *node, int n)
{
	if (!node || n < 1) return NULL;
	LinkNode *runner = node;
	LinkNode *chaser = node;
	for (int i = 0; i < n; i++)
	{
		if (runner == NULL)
			return NULL;
		runner = runner->next;
	}
	while(runner)
	{
		chaser = chaser->next;
		runner = runner->next;
	}
	return chaser;
}
//find middle element of the linklist
LinkNode* middle(LinkNode* node)
{
	if (!node) return node;
	LinkNode* runner = node->next;
	LinkNode* chaser = node;

	while(runner)
	{
		runner = runner->next;
		if (runner != NULL && runner != chaser)
		{
			chaser = chaser->next;
			runner = runner->next;
		}
		if (runner == chaser)
		{
			return NULL;
		}
	}
	return chaser;
}
//Given a circular linked list, implement an algorithm which
//returns node at the beginning of the loop.
LinkNode* findBeginning(LinkNode *node)
{
	LinkNode *runner = node;
	LinkNode *chaser = node;
	//find meeting point
	while (runner->next)
	{
		chaser = chaser->next;
		runner = runner->next->next;
		if (runner == chaser)
		{
			break;
		}
	}
	// error check, not cycle
	if (runner->next == NULL)
	{
		return NULL;
	}

	chaser = node;
	while (chaser != runner)
	{
		chaser = chaser->next;
		runner = runner->next;
	}
	return runner;
}
// reverse the sinlge linklist
int reverse(LinkNode **head)
{
	LinkNode *node = *head;
	LinkNode *next_node = NULL;
	LinkNode *newhead = NULL;
	while (node)
	{
		next_node = node->next;
		node->next = newhead;
		newhead = node;
		node = next_node;
	}
	//(*head)->next = NULL;
	*head = newhead;
//	cout<<head->data<<" "<<head->next->data<<endl;
	return 1;
}
// reverse the double linklist
int dreverse(DoubleLink **head)
{
	DoubleLink *node = *head;
	DoubleLink *next_node = NULL;
	DoubleLink *newhead = NULL;
	while (node)
	{
		next_node = node->next;
		node->next = newhead;
		node->prev = next_node;
		newhead = node;
		node = next_node;

	}
	*head = newhead;
	return 1;
}
//Implement a function to check if a tree is balanced.
//For the purposes of this question, a balanced tree is
//defined to be a tree such that no two leaf nodes differ
//in distance from the root by more than one.
static int max_depth(TreeNode* node)
{
	if (node == NULL) return 0;

	return 1 + max(max_depth(node->left),max_depth(node->right));
}

static int min_depth(TreeNode* node)
{
	if (node == NULL) return 0;

	return 1 + min(min_depth(node->left),min_depth(node->right));
}

bool isAVL (TreeNode *node)
{
	if (max_depth(node) - min_depth(node) > 1)
		return false;
	return true;
}
//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
TreeNode* addtoTree(int a[],int start, int end)
{
	if (end < start)
		return NULL;
	int mid = (start + end) / 2;
	TreeNode *node = new TreeNode(a[mid]);
	node->left = addtoTree(a,start,mid - 1);
	node->right = addtoTree(a, mid+1,end);
	return node;
}
// is binary tree?
bool isBinaryTree(TreeNode *root, int min, int max)
{
	TreeNode *node = root;
	bool flag = false;

	if (node == NULL) return true;

	if (node->value <= min || node->value >= max) return false;

	flag = isBinaryTree(node->left,min, node->value)
			&& isBinaryTree(node->right, node->value, max);

	return flag;
}
// the mirror of binary tree
void mirror(TreeNode *root)
{
	if(!root)
		return;

	TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	mirror(root->left);
	mirror(root->right);

}
//Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.
//Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
TreeNode* common_father(TreeNode* root, TreeNode *node1,TreeNode *node2)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root == node1)
	{
		return node1;
	}
	if (root == node2)
	{
		return node2;
	}
	TreeNode* left = common_father(root->left,node1,node2);
	TreeNode* right = common_father(root->right,node1,node2);
	if (left != NULL && right != NULL)
	{
		return root;
	}
	if (left != NULL) return left;
	if (right != NULL) return right;

	return NULL;
}

//Given a binary search tree, design an algorithm which creates a linked list of all
//the nodes at each depth (eg, if you have a tree with depth D, you��ll have D linked lists).
void findlevel(TreeNode *node)
{
	deque<TreeNode*> store;
	  int left_num;
	  if(!node)
	    return;
	  store.push_back(node);
	  while(!store.empty()) {
	    left_num = store.size(); // ��ǰ��Ľڵ���
	    while(left_num-- > 0) {
	    	TreeNode* tmp = store.front();
	      store.pop_front();
	      cout << tmp->value << " ";
	      if(tmp->left)
	        store.push_back(tmp->left);
	      if(tmp->right)
	        store.push_back(tmp->right);
	    }
	    cout << endl;
	  }


}
vector<int> find_sum(int a[],int length,int sum)
{
	int head = 0;
	int tail = length - 1;
	vector<int> result = vector<int>();
	while (head < tail)
	{
		int tmp = a[head] + a[tail];
		if (tmp < sum)
			head++;
		else if (tmp > sum)
			tail--;
		else
		{
			result.push_back(a[head]);
			result.push_back(a[tail]);
			head++;
			tail--;
		}
	}
	return result;
}
void list_test()
{
	Node *node = new Node(20);
	list<Node*> l = list<Node*>(5,node);

	for (list<Node*>:: iterator it = l.begin(); it!=l.end();it++)
	{
		cout<<(*it)->data<<endl;
	}

	map<int,int> m;
	m[1] = 1;
}
bool insert(int value,BSTNode*& node)
{
	if (node == NULL)
	{
		node  = new BSTNode(value);
		return true;
	}
	else if(value < (node)->value)
	{
		insert(value,(node->left));
	}
	else if(value > (node)->value)
	{
		insert(value,(node)->right);
	}
	else
	{
		cout<<"already exits"<<endl;
		return false;
	}
}
bool Is_palindrome(char *str)
{
	int i = 0, j = strlen(str) - 1;
	while (i < j)
	{
//		cout<<str[i]<<" "<<str[j]<<endl;
		if (str[i] != str[j])
		{

			return false;
		}
		i++;
		j--;
	}
	return true;
}
void sift_down(int a[], int start, int n)
{
	int i = start, j = 2 * i + 1;
	int tmp = a[i];
	while (j < n)
	{
		if (j+1 < n && a[j] > a[j+1]) j++;
		if (tmp <= a[j]) break;
		else
		{
			a[i] = a[j];
			i = j;
			j = 2*i + 1;
		}
	}
	a[i] = tmp;
}
void sift_up(int a[], int start)
{
	int j = start, i = (j - 1) / 2;
	int tmp = a[j];
	while (j > 0)
	{
		if (tmp >= a[j]) break;
		else
		{
			a[j] = a[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	a[j] = tmp;
}
void min_heap(int a[],int n)
{
	int cur_pos = (n - 2) / 2;
	while (cur_pos >= 0)
	{
		sift_down(a, cur_pos, n);
		cur_pos--;
	}
}
typedef struct SibingNode{
	int data;
	SibingNode *right;
	SibingNode *left;
	SibingNode *sibling;
	SibingNode(const int& data): data(data),right(NULL),left(NULL),sibling(NULL){}
}SibingNode;

void siblings(SibingNode *root)
{
	deque<SibingNode *> queue;
	SibingNode *node = root;
	queue.push_back(node);
	while(!queue.empty())
	{
		node = queue.front();
		SibingNode *first = node;
		queue.pop_front();
		while(!queue.empty())
		{
			node->sibling = queue.front();
			node = node->sibling;
			queue.pop_front();
		}
		node->sibling = NULL;
		node = first;
		while(node)
		{
			if (node->left)
				queue.push_back(node->left);
			if (node->right)
				queue.push_back(node->right);
			node = node->sibling;
		}

	}
}
int main(int argc, char **argv)
{
	string str = "abcd";
	cout<<"is unique:"<<isUnique(str)<<endl;
	char cstr[10] = "abcdacdba";
	cout<<"reverse is:"<<my_strrev(cstr)<<endl;

	cout<<"is anagram:"<<is_anagram("abc[]dD","abcd[D]D")<<endl;
	removedup2(cstr);
	cout<<"remove dup:"<<cstr<<endl;
	LinkNode *first , *current;
	current = new LinkNode(1);
	first = current;
	for (int i = 0; i < 10; i++)
	{
		current->next = new LinkNode(i+2);
		current = current->next;
	}
	current->next = new LinkNode(3);
	current->next->next = new LinkNode(3);
	current->next->next->next = new LinkNode(3);


	del_dup2(first);
	cout<<"del_dup2"<<endl;
	for (current = first;current != NULL; current = current->next)
		cout<<current->data;
	cout<<endl;

	LinkNode *nnode = nthtolast(first,1);
	cout<<"n to last"<<endl;
	for (current = nnode;current != NULL; current = current->next)
		cout<<current->data;
	cout<<endl;
	nnode = middle(first);
	cout<<"find middle: "<<nnode->data<<endl;

	int array[] = {10,9,8,7,6,5,4,3,2,1};
	quicksort(array,0,9);
	cout<<"quick sort:"<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<array[i];
	}
	cout<<endl;
	vector<int> result = find_sum(array,10,5);
	cout<<"find_sum:"<<endl;
	for(unsigned int i = 0; i < result.size(); i++)
	{
		cout<<result[i];
	}
	cout<<endl;
	merge_sort(array,0,9);
	cout<<"merge sort:"<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<array[i];
	}
	cout<<endl;
	//list_test();
	BSTNode *root = NULL;
	insert(10,root);
	insert(20,root);
	cout<<root->value<<endl;
	cout<<root->right->value<<endl;
	cout<<"is palindrome??:"<<Is_palindrome("momm")<<endl;

	cout<<"min_heap:"<<endl;
	int heap[] = {9,8,7,6,5,4,3,2,1,14,15};
	min_heap(heap,11);
	for (int i = 0; i < 11; i++)
		cout<<heap[i];
	cout<<endl;


	SibingNode *r = new SibingNode(1);
	cout<<"siblings:"<<endl;
	r->left = new SibingNode(2);
	r->right = new SibingNode(3);
	r->left->left = new SibingNode(4);
	r->left->right = new SibingNode(5);
	r->right->left = new SibingNode(6);
	r->right->right = new SibingNode(7);

	siblings(r);
	cout<<r->left->right->sibling->data<<endl;

	deque<int> que;
	que.push_back(1);
	que.push_back(2);
	que.push_back(3);
	que.push_back(4);
	return 1;
}




