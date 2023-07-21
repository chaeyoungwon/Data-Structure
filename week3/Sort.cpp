#include <iostream>
#include <time.h>
#define size 10 // �迭�� ũ�⸦ ���Ƿ� �����
using namespace std;

void MergeSort(int*& arr, int low, int high);
void Merge(int*& arr, int low, int mid, int high);
void QuickSort(int*& arr, int low, int high);
int Partition(int*& arr, int low, int high); // �Լ� ���� ����

void MergeSort(int*& arr, int low, int high) {
	if (low < high) { // ����Ʈ�� ���̰� 0, 1�� �ƴ� ���
		int mid = (low + high) / 2; // �߰� ��ġ���� ����
		MergeSort(arr, low, mid); // mid�� �������� ���� ����Ʈ ����
		MergeSort(arr, mid + 1, high); // ���� ����Ʈ ����
		Merge(arr, low, mid, high); // ���ĵ� �迭 2���� �պ�
	}
}

void Merge(int *&arr, int low, int mid, int high) { // �迭 �պ��� ���� �Լ�
	int *U = new int[size]; // ���ο� �迭 ���� ����, ���ĵ� ����Ʈ�� �ǹ�
	int i=low, k = low, j = mid + 1; // i: ���ĵ� ���� ����Ʈ�� �ε���, j: ���ĵ� ������ ����Ʈ�� �ε��� 
	while (i <= mid && j <= high) { // ����, ������ ����Ʈ�� �ε����� ���� �Ѱ迡 ������ ������ �ݺ�
		if (arr[i] > arr[j]) { // ���� ����Ʈ�� ���Ұ� Ŭ ���
			U[k++] = arr[j++]; // ������ ����Ʈ�� ���Ҹ� ���ο� �迭�� ���� �ֱ�
			//k: ���ĵ� ����Ʈ�� �ε���
			
		}
		else { // ������ ����Ʈ�� ���Ұ� Ŭ ���
			U[k++] = arr[i++]; // ���� ����Ʈ�� ���Ҹ� ���ο� �迭�� ���� �ֱ�
		}
	}
	if (i > mid) { // ������ ������ ��� �����Ͽ� ���ο� �迭�� �ֱ�
		while (j <= high) {
			U[k++] = arr[j++];
		}
	}
	else { // ������ ������ ��� �����Ͽ� ���ο� �迭�� �ֱ�
		while (i <= mid)
			U[k++] = arr[i++];
	}
	
	for (int i = low; i <= high; i++) // ���ĵ� �迭�� ����Ʈ�� ���� arr�� �������ֱ�
		arr[i] = U[i];

	delete[] U; // ���� ������ �迭 ����
}

void QuickSort(int*& arr, int low, int high) {
	if (low < high) { // ����Ʈ�� ���̰� 0, 1�� �ƴ� ���
		int pivot = Partition(arr, low, high); // Partition �Լ��� ��ȯ�ϴ� ���� pivot�� ����
		QuickSort(arr,low, pivot - 1); // ���, pivot�� �������� ���� ����Ʈ�� ���� �Լ� ����
		QuickSort(arr, pivot + 1, high); // ���, pivot�� �������� ���� ����Ʈ�� ���� �Լ� ����
	}
}

int Partition(int*& arr, int low, int high) {
	int pivot_item = arr[high]; // pivot_item�� ���� ������ �������� ����
	int i = low - 1; // �迭�� ���� ���� ã�� �ε��� ���� �ǹ�

	for (int j = low; j <= high - 1; j++) { // pivot�� ������ ��� ��� ��ȸ 
		if (arr[j] <= pivot_item) { //pivot���� �迭 ��Ұ� �۰ų� ���� ���
			i++; // �ε��� �� ������Ű��
			int temp = arr[i]; // �迭 �ε��� ���� i�� j�� ��Ҹ� ���� �ٲ��ֱ�
			arr[i] = arr[j]; // pivot�� �������� ���� ������ �迭�� �������� �̵�
			arr[j] = temp;
		}
	}

	int temp = arr[i + 1]; // �迭 �ε��� ���� low�� high�� ��Ҹ� ���� �ٲ��ֱ�
	arr[i + 1] = arr[high]; // �迭 �ε��� ���� i+1�� ���� pivot�� ������ ��ġ 
	arr[high] = temp;

	return i + 1; // pivot�� ��ġ�� �ε��� ��ȯ
}


void Print(int arr[]) { // �迭�� ���ҵ��� ����ϴ� �Լ�
	for (int j = 0; j < size; j++)
		cout << arr[j] << " "; // �迭�� ũ�⸸ŭ �ݺ��Ͽ� ���� ���
	cout << endl;
}

int main() {
	srand(time(NULL));// �������� �迭 ���Ҹ� �ޱ� ���� ���

	int arr[size]; // �迭 ���� 
	int* ref = arr; // �����Ϳ� ���� ������ �Ű������� �ޱ� ���� ����
	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 100) + 1; // �迭�� �������� ���� ä���, ���⼭�� 1~100 ������ ���� ����

	
	Print(arr);// ������ �迭 ���
	MergeSort(ref, 0, size-1); // �պ�����
	Print(arr);// �պ������� �迭 ���

	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 100) + 1;

	Print(arr);// ������ �迭 ���
	QuickSort(ref, 0, size-1); // ������
	Print(arr);// �������� �迭 ���
}