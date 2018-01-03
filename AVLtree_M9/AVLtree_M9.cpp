#include "stdafx.h"

struct Node
{
	Node* clpLeftNode;
	Node* clpRightNode;

	int Data;
};

// 선언
int searchDepth(Node* param);
Node* Rebalance(Node* param);
void Insert(Node** param, int data);
void AVLInsert(Node** param, int data);

Node* RotateLL(Node* param);
Node* RotateLR(Node* param);
Node* RotateRR(Node* param);
Node* RotateRL(Node* param);

////////////////////////////////////////////////////

// 깊이 구하기
int searchDepth(Node* param)
{
	int myDepth = 0;

	if(param != nullptr)
	{
		int leftDepth = searchDepth(param->clpLeftNode);
		int rightDepth = searchDepth(param->clpRightNode);

		myDepth = std::max(leftDepth, rightDepth) + 1;
	}

	return myDepth;
}

//-밸런스수치구하기
int searchBal(Node* param)
{
	//밸런스수치 = 깊이구하기(Node->왼) - 깊이구하기(Node->오른)
	int balance = searchDepth(param->clpLeftNode) - searchDepth(param->clpRightNode);

	return balance;
}

Node* Rebalance(Node* param)
{
	int Balance = searchBal(param);

	//1. 노드 밸런스값  1 보다 크다.
	//왼쪽으로 쏠렸음.
	if (Balance > 1)
	{
		if (searchBal(param->clpLeftNode) > 0)
		{
			//1.1 노드의 왼노드 밸런스가 0 보다 크다
			//LL 상태

			//Node* balancedNode = RotateLL(Node);
		}
		else
		{
			//1.2 위 상황이 아니면
			//LR 상태

			//Node* balancedNode = RotateLR(Node);
		}
	}
	else 
	{
		//2. 노드 밸런스값 - 1 보다 작다
		//오른쪽으로 쏠렸음

		if (searchBal(param->clpRightNode) < 0)
		{
			//2.1 노드의 오른노드가 0 보다 작다
			//RR 상태

			//Node* balancedNode = RotateRR(Node);
		}
		else
		{
			//2.2 위 상황이 아니면
			//RL 상태

			//Node* balancedNode = RotateRL(Node);
		}
	}

	//회전 후 새로 올라온 노드를 리턴 해줌.
	// TODO : balancedNode
	return nullptr;
}

//* 삽입과정

//가장 일반적인 방법은 Insert 시 Root 노드부터 재귀 함수로
//삽입 위치를 찾아서 들어간다.

// 일반 트리의 재귀 Insert 함수 예시.
void Insert(Node** param, int data)
{
	// Node 를 이중 포인터로 받는 이유는 ?	
	// 부모를 가르키는 포인터가 없기에
	// Parent->Left, Parent->Right 를 변경 할 방법이 없음.
	// 그래서 Parent->Left/Right 자체의 주소값을 받아서 이를
	// 직접 변경하기 위함.

	//////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////

	//1. 끝 위치를 찾았다면 노드 생성 후 연결
	//인자 **Node 는 &(Parent->Left / Right) 이므로
	//*Node = 신규노드;  코드로 부모의 left, right 에 연결이 가능 함.

	//2. 값이 작다면 왼쪽으로 Insert(&노드->왼) 재귀

	//3. 값이 크다면 오른쪽으로 Insert(&노드->오른) 재귀

	//////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////
};

// AVL 트리를 위한 Insert 
void AVLInsert(Node** param, int data)
{
	//1. 끝 위치를 찾았다면 노드 생성 후 연결

	//	들어가서 특정 위치에 노드를 넣었다면 그 위치부터 
	// 재귀함수가 풀려 돌아가는 순서로 balance 함수를 모두 호출함.

	//2. 값이 작다면 왼쪽으로 AVLInsert(&노드->왼) 재귀
	//*param = Rebalance(노드);

	//3. 값이 크다면 오른쪽으로 AVLInsert(&노드->오른) 재귀
	//*param = Rebalance(노드);

	//insert 재귀 후 돌아오는 길에 balance 함수를 넣어서
	//끝단에 노드를 추가하고 돌아오는 길마다 밸런스를 조절 함.
}

int main()
{





    return 0;
}