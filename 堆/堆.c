#include <stdio.h>
#include <stdlib.h>

//�ѣ���ȫ��������˳��洢��������
//��֪���ڵ���±꣺root
//���������±꣺root*2+1��
//���������±꣺root*2+2��

//��֪���ӵ��±꣺child
//˫�׵��±꣺parent=��child-1��/2��

//�ж�һ���ڵ��Ƿ��ڣ��������±��Ƿ�Խ��

//�ѻ������µ���
//������ֻ��һ��λ�ò�����ѵ�����
//�ҵ��������ӡ��Һ�������С��ֵ�������
//ֱ���ߵ�Ҷ�ӽڵ��������ѵ�����Ϊֹ

//С�ѣ������󣬸�����
//���Σ����顢���鳤�ȡ��������Ԫ���±�
void adjustDown(int* arr,int size,int index) {
	while (1) {
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int min = left;
		//�����Ҷ�ӽڵ�Ͳ��õ���
		if (left >= size-1) {
			break;
		}
		//���Һ��ӣ��ҳ����Һ����н�С��ֵ
		//û���Һ��ӣ���С��ֵ��������
		if (right<size - 1 && arr[left]>arr[right]) {
			//���½�С��ֵ���±�
			min = right;
		}
		//�����������±��Ѿ�С�����Һ�������С����һ���ˣ�
		//����������ѵ����ʣ������˳�
		if (arr[index] <= arr[min]) {
			break;
		}

		//��ʼ���н���
		int temp = arr[index];
		arr[index] = arr[min];
		arr[min] = temp;
		
		//����index��ֵ������ѭ���ж���ȥ
		index = min;
	}

}

//�ݹ�汾
void adjustDownRe(int *arr, int size, int index) {
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = left;
	
	if (left >= size) {
		return;
	}
	//��С���ӵ��±����min
	if (arr[index] <= arr[min]) {
		return;
	}

	//�ж�����������
	if (right<size&&arr[left]>arr[right]) {
		min = right;
	}

	//����
	int temp = arr[index];
	arr[index] = arr[min];
	arr[min] = temp;

	adjustDownRe(arr, size, min);
}

//����:С��
void createHeap(int* arr, int size) {
	//�������Ƕѣ��������Ƕѣ����µ�������
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