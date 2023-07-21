#include <iostream>
#include <time.h>
#define size 10 // 배열의 크기를 임의로 잡아줌
using namespace std;

void MergeSort(int*& arr, int low, int high);
void Merge(int*& arr, int low, int mid, int high);
void QuickSort(int*& arr, int low, int high);
int Partition(int*& arr, int low, int high); // 함수 원형 선언

void MergeSort(int*& arr, int low, int high) {
	if (low < high) { // 리스트의 길이가 0, 1이 아닐 경우
		int mid = (low + high) / 2; // 중간 위치에서 분할
		MergeSort(arr, low, mid); // mid를 기준으로 앞쪽 리스트 정렬
		MergeSort(arr, mid + 1, high); // 뒤쪽 리스트 정렬
		Merge(arr, low, mid, high); // 정렬된 배열 2개를 합병
	}
}

void Merge(int *&arr, int low, int mid, int high) { // 배열 합병을 위한 함수
	int *U = new int[size]; // 새로운 배열 동적 선언, 정렬된 리스트를 의미
	int i=low, k = low, j = mid + 1; // i: 정렬된 왼쪽 리스트의 인덱스, j: 정렬된 오른쪽 리스트의 인덱스 
	while (i <= mid && j <= high) { // 왼쪽, 오른쪽 리스트의 인덱스가 각각 한계에 도달할 때까지 반복
		if (arr[i] > arr[j]) { // 왼쪽 리스트의 원소가 클 경우
			U[k++] = arr[j++]; // 오른쪽 리스트의 원소를 새로운 배열에 먼저 넣기
			//k: 정렬된 리스트의 인덱스
			
		}
		else { // 오른쪽 리스트의 원소가 클 경우
			U[k++] = arr[i++]; // 왼쪽 리스트의 원소를 새로운 배열에 먼저 넣기
		}
	}
	if (i > mid) { // 나머지 값들을 모두 복사하여 새로운 배열에 넣기
		while (j <= high) {
			U[k++] = arr[j++];
		}
	}
	else { // 나머지 값들을 모두 복사하여 새로운 배열에 넣기
		while (i <= mid)
			U[k++] = arr[i++];
	}
	
	for (int i = low; i <= high; i++) // 정렬된 배열의 리스트를 기존 arr로 복사해주기
		arr[i] = U[i];

	delete[] U; // 동적 선언한 배열 삭제
}

void QuickSort(int*& arr, int low, int high) {
	if (low < high) { // 리스트의 길이가 0, 1이 아닐 경우
		int pivot = Partition(arr, low, high); // Partition 함수가 반환하는 값을 pivot에 저장
		QuickSort(arr,low, pivot - 1); // 재귀, pivot을 기준으로 앞쪽 리스트에 대해 함수 실행
		QuickSort(arr, pivot + 1, high); // 재귀, pivot을 기준으로 뒤쪽 리스트에 대해 함수 실행
	}
}

int Partition(int*& arr, int low, int high) {
	int pivot_item = arr[high]; // pivot_item은 가장 오른쪽 끝값으로 설정
	int i = low - 1; // 배열의 작은 수를 찾는 인덱스 값을 의미

	for (int j = low; j <= high - 1; j++) { // pivot을 제외한 모든 요소 순회 
		if (arr[j] <= pivot_item) { //pivot보다 배열 요소가 작거나 같은 경우
			i++; // 인덱스 값 증가시키기
			int temp = arr[i]; // 배열 인덱스 값이 i와 j인 요소를 서로 바꿔주기
			arr[i] = arr[j]; // pivot을 기준으로 작은 값들은 배열의 왼쪽으로 이동
			arr[j] = temp;
		}
	}

	int temp = arr[i + 1]; // 배열 인덱스 값이 low와 high인 요소를 서로 바꿔주기
	arr[i + 1] = arr[high]; // 배열 인덱스 값이 i+1인 곳이 pivot의 적합한 위치 
	arr[high] = temp;

	return i + 1; // pivot이 위치한 인덱스 반환
}


void Print(int arr[]) { // 배열의 원소들을 출력하는 함수
	for (int j = 0; j < size; j++)
		cout << arr[j] << " "; // 배열의 크기만큼 반복하여 원소 출력
	cout << endl;
}

int main() {
	srand(time(NULL));// 무작위로 배열 원소를 받기 위해 사용

	int arr[size]; // 배열 선언 
	int* ref = arr; // 포인터에 대한 참조를 매개변수로 받기 위해 생성
	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 100) + 1; // 배열에 무작위로 원소 채우기, 여기서는 1~100 범위의 수를 받음

	
	Print(arr);// 무작위 배열 출력
	MergeSort(ref, 0, size-1); // 합병정렬
	Print(arr);// 합병정렬한 배열 출력

	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 100) + 1;

	Print(arr);// 무작위 배열 출력
	QuickSort(ref, 0, size-1); // 퀵정렬
	Print(arr);// 퀵정렬한 배열 출력
}