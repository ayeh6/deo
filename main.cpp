#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct node
{
	node * leftChild;
	node * rightChild;
	double rate;
	char contains;
	string code;
};

string arr [6];
vector<node> nodeArray;

node getMin()
{
	double temp = (double) 9999999;
    	vector<node>::iterator i1,pos;
    	for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
	{
		if(temp>(*i1).rate)
		{
			pos = i1;
			temp = (*i1).rate;
		}
	}

node tempNode = (*pos);
nodeArray.erase(pos);

return tempNode;

}
                     
node getTree()
{

while(!nodeArray.empty())
{       
 	node * tempNode = new node;   
      	node * tempNode1 = new node;
 	node * tempNode2 = new node;
      	*tempNode1 = getMin();
 	*tempNode2 = getMin();
 
 	tempNode->leftChild = tempNode1;
 	tempNode->rightChild = tempNode2;
 	tempNode->rate = tempNode1->rate+tempNode2->rate;
 	nodeArray.push_back(*tempNode);

 	if(nodeArray.size() == 1)
 	{
 		break;
 	}
}

	return nodeArray[0];

}

void find(node * temproot, string s)
{
   	node * root1 = new node;
   	root1 = temproot;
  
   	root1->code = s;
   
	if(root1 == NULL)
   	{
  
   	}
   
	else if(root1->leftChild == NULL && root1->rightChild == NULL)
   	{
  		int temp = (root1 -> contains) - 65;
		arr[temp] = (root1->code);
   	}
   
	else
   	{
 
      		root1->leftChild->code = s.append("0");
 		s.erase(s.end()-1);
 
		root1->rightChild->code = s.append("1");
	 	s.erase(s.end()-1);

      		find(root1->leftChild,s.append("0"));
 
		s.erase(s.end()-1);
      
		find(root1->rightChild,s.append("1"));
 		
		s.erase(s.end()-1);
	}
   
}

void getCode()
{
	int size = 6;
	double tempDouble;
	string tempString = "";

	for(int i = 0;i<size;i++)
	{
		node tempNode;
		char tempString = 'A' + i;
		cin>>tempDouble;


		tempNode.rate = tempDouble;
		tempNode.contains = tempString;
		tempNode.leftChild = NULL;
		tempNode.rightChild = NULL;
		nodeArray.push_back(tempNode);
	}

	node root = getTree();

	find(&root, "");

}

int main()
{
	getCode();
	for (int i = 0; i<6; i++)
	{
		cout << (char)(i+65) << ":" <<arr[i] << endl;
	}
	return 0;
}
