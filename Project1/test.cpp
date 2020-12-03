/////////////////////////////////////
//// ���α׷� ���� : ���� �˰��� ����ð� ��
//// �ۼ��� : 20164143 �ڰ���
//// ������� : 2020.12.03
/////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//
//#define SIZE 100
//
//char** sorted;         // �������Ŀ��� ����� �迭
//
////////////////��������///////////////
//void selection_sort(int count, char** copy) {
//    int i, j, least;
//    char temp[SIZE];
//
//    for (i = 0; i < count - 1; i++) {
//        least = i;
//        for (j = i + 1; j < count; j++) {         // �ּҰ� Ž��
//            if (strcmp(copy[j], copy[least]) > 0)
//                least = j;
//            strcpy(temp, copy[j]);
//            strcpy(copy[j], copy[least]);
//            strcpy(copy[least], temp);
//        }
//    }
//}
//////////////////////////////////////
//
////////////////��������///////////////
//void insertion_sort(int count, char** copy) {
//    int i, j;
//    char key[SIZE];
//
//    for (i = 1; i < count; i++) {
//        strcpy(key, copy[i]);
//        for (j = i - 1; j >= 0 && strcpy(copy[j], key) > 0; j--)
//            strcpy(copy[j + 1], copy[j]);         // ���ڵ��� ������ �̵�
//        strcpy(copy[j + 1], key);
//    }
//}
//////////////////////////////////////
//
////////////////��������///////////////
//void bubble_sort(int count, char** copy) {
//    int i, j;
//    char buffer[SIZE];
//
//    int length;
//
//    for (i = count - 1; i > 0; i--)
//        for (j = 0; j < i; j++)
//            if (strcmp(copy[j], copy[j + 1]) > 0) {// �� �� ���ڵ带 ���� �� ��ü
//                strcpy(buffer, copy[j]);
//                strcpy(copy[j], copy[j + 1]);
//                strcpy(copy[j + 1], buffer);
//            }
//}
//////////////////////////////////////
//
/////////////////������////////////////
//// gap ��ŭ ������ ��ҵ��� ���� ����
//// ������ ������ first���� last
//void inc_insertion_sort(char** copy, int first, int last, int gap) {
//    int i, j;
//    char key[SIZE];
//
//    for (i = first + gap; i <= last; i = i + gap) {
//        strcpy(key, copy[i]);
//        for (j = i - gap; j >= first && strcmp(key, copy[j]) < 0; j = j - gap)
//            strcpy(copy[j + gap], copy[j]);
//        strcpy(copy[j + gap], key);
//    }
//}
//
//void shell_sort(int count, char** copy) {
//    int i, gap;
//    for (gap = count / 2; gap > 0; gap = gap / 2) {
//        if ((gap % 2 == 0)) gap++;
//        for (i = 0; i < gap; i++)            // �κ� ����Ʈ�� ������ gap
//            inc_insertion_sort(copy, i, count - 1, gap);
//    }
//}
//////////////////////////////////////
//
////////////////�պ�����///////////////
//// i�� ���ĵ� ���� �迭�� ���� �ε���
//// j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
//// k�� ���ĵ� ����Ʈ�� ���� �ε���
//void merge(char** copy, int left, int mid, int right) {
//    int i, j, k, l;
//    int length;
//    i = left; j = mid + 1, k = left;
//
//    // ���� ���ĵ� �迭�� �պ�
//    while (i <= mid && j <= right) {
//        if (strcmp(copy[i], copy[j]) < 0)
//            strcpy(sorted[k++], copy[i++]);
//        else
//            strcpy(sorted[k++], copy[j++]);
//    }
//
//    if (i > mid)      // �����ִ� ���ڵ��� �ϰ� ����
//        for (l = j; l <= right; l++)
//            strcpy(sorted[k++], copy[l]);
//
//    else            // �����ִ� ���ڵ��� �ϰ� ����
//        for (l = i; l <= mid; l++)
//            strcpy(sorted[k++], copy[l]);
//
//    // �迭 sorted[]�� ����Ʈ�� �迭 copy[]�� �纹��
//    for (l = left; l <= right; l++)
//        strcpy(copy[l], sorted[l]);
//}
//
//void merge_sort(char** copy, int left, int right) {
//    int mid;
//    if (left < right) {
//        mid = (left + right) / 2;         // ����Ʈ�� �յ� ����
//        merge_sort(copy, left, mid);      // �κ� ����Ʈ ����
//        merge_sort(copy, mid + 1, right);   // �κ� ����Ʈ ����
//        merge(copy, left, mid, right);      // �պ�
//    }
//}
//////////////////////////////////////
//
/////////////////������////////////////
//int partition(char** copy, int left, int right) {
//    char pivot[SIZE], temp[SIZE];
//    int low, high;
//
//    low = left;
//    high = right + 1;
//    strcpy(pivot, copy[left]);
//
//
//    do {
//        do
//            low++;
//        while (low <= right && strcmp(copy[low], pivot) < 0);
//
//        do
//            high--;
//        while (high >= left && strcmp(copy[high], pivot) > 0);
//
//        if (low < high) {
//            strcpy(temp, copy[low]);
//            strcpy(copy[low], copy[high]);
//            strcpy(copy[high], temp);
//        }
//    } while (low < high);
//
//    strcpy(temp, copy[left]);
//    strcpy(copy[left], copy[high]);
//    strcpy(copy[high], temp);
//
//    return high;
//}
//
//void quick_sort(char** copy, int left, int right) {
//    int q;
//    if (left < right) {
//        q = partition(copy, left, right);
//        quick_sort(copy, left, q - 1);
//        quick_sort(copy, q + 1, right);
//    }
//}
//////////////////////////////////////
//
////////////////��������///////////////
//typedef struct {
//    char** heap;
//    int heap_size;
//}HeapType;
//
//HeapType* create() {
//    return (HeapType*)malloc(sizeof(HeapType));         // ���� ����
//}
//
//void init(HeapType* h, int count) {
//    h->heap_size = 0;                           // size �ʱ�ȭ
//    h->heap = (char**)malloc(sizeof(char*) * count);   // �Ҵ���� ũ�⸸ŭ ���� �Ҵ�
//}
//
//void insert_max_heap(HeapType* h, char* item) {
//    int i;
//    i = ++(h->heap_size);
//
//    while ((i != 1) && (strcmp(item, h->heap[i / 2]) > 0)) {
//        h->heap[i] = h->heap[i / 2];
//        i /= 2;
//    }
//    h->heap[i] = item;
//}
//
//char* delete_max_heap(HeapType* h) {
//    int parent, child;
//    char item[SIZE], temp[SIZE];
//
//    strcpy(item, h->heap[1]);
//    strcpy(temp, h->heap[(h->heap_size)--]);
//    parent = 1;
//    child = 2;
//    while (child <= h->heap_size) {
//        if ((child < h->heap_size) && strcmp(h->heap[child], h->heap[child + 1]) < 0)
//            child++;
//        if (strcmp(temp, h->heap[child]) >= 0) break;
//
//        strcpy(h->heap[parent], h->heap[child]);
//        parent = child;
//        child *= 2;
//    }
//    strcpy(h->heap[parent], temp);
//    return item;
//}
//
//void heap_sort(char* copy[], int count) {
//    int i;
//    HeapType* h;
//
//    h = create();
//    init(h, count);
//    for (i = 0; i < count; i++)
//        insert_max_heap(h, copy[i]);
//    for (i = (count - 1); i >= 0; i--)
//        strcpy(copy[i], delete_max_heap(h));
//    free(h);
//}
//////////////////////////////////////
//
/////////////�迭 ���� �Լ�////////////
//void copy_list(char** origin, char** copy, int count) {
//    int i;
//    for (i = 0; i < count; i++) {
//        strcpy(copy[i], origin[i]);
//    }
//}
//////////////////////////////////////
//
//int main(void) {
//    FILE* fp;
//    int i, j, length;
//    int count = 0;
//    clock_t start, finish;
//    double duration;
//    char buffer[SIZE];
//
//    char** origin, ** copy;
//
//    fp = fopen("text.txt", "r");
//
//    if (fp == NULL) {
//        printf("File Not Found!\n");
//        return 0;
//    }
//
//    while (!feof(fp)) {
//        fscanf(fp, "%s", buffer);
//        count++;
//    }
//
//    rewind(fp);
//
//    origin = (char**)malloc(sizeof(char*) * count);
//    copy = (char**)malloc(sizeof(char*) * count);
//    sorted = (char**)malloc(sizeof(char*) * count);
//
//    i = 0;
//    while (!feof(fp)) {
//        fscanf(fp, "%s", buffer);
//
//        length = strlen(buffer);
//
//        origin[i] = (char*)malloc(sizeof(char) * SIZE);
//        copy[i] = (char*)malloc(sizeof(char) * SIZE);
//        sorted[i] = (char*)malloc(sizeof(char) * SIZE);
//
//        strcpy(origin[i], buffer);
//        strcpy(copy[i], buffer);
//        i++;
//    }
//
//    printf("\n\n");
//
//    //////////////��������///////////////
//    start = clock();
//    insertion_sort(count, copy);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("�������� �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    //////////////��������///////////////
//    start = clock();
//    selection_sort(count, copy);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("�������� �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    //////////////��������///////////////
//    start = clock();
//    bubble_sort(count, copy);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("�������� �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    ///////////////������////////////////
//    start = clock();
//    shell_sort(count, copy);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("������ �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    ///////////////������////////////////
//    start = clock();
//    quick_sort(copy, 0, count - 1);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("������ �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    //////////////�պ�����///////////////
//    start = clock();
//    merge_sort(copy, 0, count - 1);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("�պ����� �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    copy_list(origin, copy, count);
//    ////////////////////////////////////
//
//    //////////////��������///////////////
//    start = clock();
//    heap_sort(copy, count);
//    finish = clock();
//    duration = (double)(finish - start);
//    printf("�������� �ҿ�ð� : %lf��\n", duration / CLOCKS_PER_SEC);
//    ////////////////////////////////////
//
//    for (i = 0; i < count; i++) {
//        free(origin[i]);
//        free(copy[i]);
//    }
//
//    free(origin);
//    free(copy);
//
//    fclose(fp);
//    return 0;
//}