#include <stdio.h>
#include <stdlib.h>

//堆：完全二叉树的顺序存储——数组
//已知根节点的下标：root
//左子树的下标：root*2+1；
//右子树的下标：root*2+2；

//已知孩子的下标：child
//双亲的下标：parent=（child-1）/2；

//判定一个节点是否在：看结点的下标是否越界

//堆化：向下调整
//条件：只有一个位置不满足堆的性质
//找到根、左孩子、右孩子中最小的值与根交换
//直到走到叶子节点或者满足堆的性质为止

//小堆：根《左，根《右
//传参：数组、数组长度、有问题的元素下标
void adjustDown(int* arr,int size,int index) {
	while (1) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int min = left;
		//如果是叶子节点就不用调整
		if (left >= size-1) {
			break;
		}
		//有右孩子：找出左右孩子中较小的值
		//没有右孩子：较小的值就是左孩子
		if (right<size - 1 && arr[left]>arr[right]) {
			//更新较小的值的下标
			min = right;
		}
		//如果有问题的下标已经小于左右孩子中最小的那一个了，
		//表明以满足堆的性质，可以退出
		if (arr[index] <= arr[min]) {
			break;
		}

		//开始进行交换
		int temp = arr[index];
		arr[index] = arr[min];
		arr[min] = temp;
		
		//更新index的值，进行循环判断下去
		index = min;
	}

}

//递归版本
void adjustDownRe(int *arr, int size, int index) {
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = left;
	
	if (left >= size) {
		return;
	}
	//最小孩子的下标就是min
	if (arr[index] <= arr[min]) {
		return;
	}

	//判断有无右子树
	if (right<size&&arr[left]>arr[right]) {
		min = right;
	}

	//交换
	int temp = arr[index];
	arr[index] = arr[min];
	arr[min] = temp;

	adjustDownRe(arr, size, min);
}

//建堆:小堆
void createHeap(int* arr, int size) {
	//左子树是堆，右子树是堆，向下调整即可
	for (int i = 0; i < size; ++i) {
		adjustDown(arr, size, i);
	}

}



int main() {
	//int arr[] = { 1,4,2,3,5,7,9,10 };
	//int size = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < size; ++i) {
	//	printf("%d  ", arr[i]);
	//}
	//printf("\n\n");
	//adjustDown(arr, size, 1);
	int arr[] = { 2,8,1,5,3,7,6,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	createHeap(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d  ", arr[i]);
	}
	system("pause");
	return 0;
}