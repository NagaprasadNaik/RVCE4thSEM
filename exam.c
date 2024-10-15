//1
// #include<stdio.h>
// #include<stdlib.h>

// int count=0;

// void merge(int b[], int p, int c[], int q, int a[]) {
//     int i = 0, j = 0, k = 0;
//     while (i < p && j < q) {
//           count++;   //because comparison is Basic Operation
//         if (b[i] <= c[j]) {
//             a[k++] = b[i++];
//         } else {
//             a[k++] = c[j++];
//         }
//     }
//     while (i < p) {
//         a[k++] = b[i++];
//     }
//     while (j < q) {
//         a[k++] = c[j++];
//     }
// }
// int mergesort(int a[],int n){
// 	if(n>1){
// 	   count++;
// 		int mid=n/2;
// 		int b[mid];
// 		int c[n-mid];
// 		for (int i = 0; i < mid; i++) {
//             b[i] = a[i];
//         }
//         for (int i = mid; i < n; i++) {
//             c[i - mid] = a[i];
//         }
// 		mergesort(b,mid);
// 		mergesort(c,n-mid);
// 		merge(b,mid,c,n-mid,a);
// 	}
// }
// int main(){
// 	int n, c1,c2,c3;
// 	int a[4000],b[4000],c[4000];
// 	printf("Enter no of array elements:\n");
// 	scanf("%d",&n);
// 	int arr[n];
// 	printf("enter array elements:\n");
// 	int r;
// 	for(int i=0;i<n;i++){
// 		scanf("%d",&r);
// 		arr[i]=r;
// 	}
// 	mergesort(arr,n);
// 	for(int m=0;m<n;m++)
// 		printf("%d\t",arr[m]);
		
	
// 	printf("\n Total basic operations: %d\n",count);
	
// 	printf("\nSize\t Ascend Descend  Random\n");
// 	for(int i=4;i<=2048; i=i*2)
// 	{
// 	    for(int j=0;j<i;j++)
// 	    {
// 	       a[j]=j;
// 	       b[j]=i-j;
// 	       c[j]=rand();
	       
// 	       count=0;
// 	       mergesort(a,i);
// 	       c1=count;
	       
// 	       count=0;
// 	       mergesort(b,i);
// 	       c2=count;
	       
// 	       count=0;
// 	       mergesort(c,i);
// 	       c3=count;
//         }     
//         printf("%d\t %d\t %d\t %d\n", i,c1,c2,c3);	       
// 	}
// }





//2
// #include <stdio.h>
// #include <stdlib.h>

// int partition(int A[], int l, int r){
//     int pivot = A[l];
//     int i = l + 1;
//     int j = r;

//     while (1) {
//         while (i <= r && A[i] <= pivot) 
//             i++;
//         while (j >= l && A[j] > pivot) 
//             j--;

//         if (i < j) {
//             int temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         } else {
//             int temp = A[j];
//             A[j] = A[l];
//             A[l] = temp;
//             return j;
//         }
//     }
// }

// void quicksort(int A[], int l, int r){
//     if(l < r){
//         int s = partition(A, l, r);
//         quicksort(A, l, s-1);
//         quicksort(A, s+1, r);
//     }
// }

// int main(){
//     int n, a;
//     printf("Enter the size of an array\n");
//     scanf("%d", &n);
//     // int arr[5] = {100, 7, 2, 9, 1};
//     int arr[n];
//     int l=0, r=n-1;
//     printf("Enter the array elememts: \n");
//     for(int i=0; i<n; i++){
//         scanf("%d", &a);
//         arr[i] = a;
//     }
//     printf("Array elements ");
//     for(int i=0; i<n; i++){
//         printf("%d ", arr[i]);
//     }
//     quicksort(arr, 0, n-1);
//     printf("\nArray elements ");
//     for(int i=0; i<n; i++){
//         printf("%d ", arr[i]);
//     }
// }



//3
// #include <stdio.h>
// #include <stdlib.h>
// #define size 100


// void heapify(int a[], int n){
//     int i, j, v, k, heap;
//     for(i=n/2; i>=1; i--){
//         k=i; 
//         v=a[i];
//         heap = 0;
//         while(!heap && 2*k<=n){
//             j=2*k;
//             if(j<n){//right child exists
//                 if(a[j] < a[j+1]){
//                     j = j+1;
//                 }
//             }
//             if (v >= a[j])
//             {
//                 heap = 1;
//             }else{
//                 a[k] = a[j];
//                 k = j;
//             }
//         }
//         a[k] = v;
//     }
// }

// void heapSort(int a[], int n){
//     heapify(a, n);
//     for(int i=n; i>1; i--){
//         int ele = a[1];
//         a[1] = a[i];
//         a[i] = ele;
//         heapify(a, i-1);
//     }
// }

// int main(){
//     int a[size], n, ch, ele;

//     //heap creation
//     printf("Enter n \n");
//     scanf("%d", &n);
//     for(int i=1; i<=n; i++){
//         printf("Enter element : \n");
//         scanf("%d", &a[i]);
//     }
//     heapify(a, n);

//     while(1){
//         printf("Enter 1-Insert, 2-Delete, 3-Display, 4-Sort 5-Exit : ");
//         scanf("%d", &ch);

//         switch (ch)
//         {
//         case 1:
//             if( n < size){
//                 printf("Enter the element to insert : \n");
//                 scanf("%d", &ele);
//                 a[++n] = ele;
//                 heapify(a, n);
//                 break;
//             }else{
//                 printf("Priority queue is full!");
//                 break;
//             }
//         case 2: if(n > 0){
//                     ele = a[1];
//                     a[1] = a[n];
//                     n--;
//                     heapify(a, n);
//                     printf("Deleted element is %d\n", ele);
//                     break;
//             }else{
//                 printf("Priority queue is empty!");
//                 break;
//             }
//         case 3:
//             printf("Heap is ");
//             for(int i=1; i<=n; i++){
//                 printf("%d ", a[i]);
//             }
//             printf("\n");
//             break;
//         case 4:
//             heapSort(a, n);
//             break;
//         default:
//             exit(0);
//         }
//     }
//     return 0;
// }




//4
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// int table[1000];
// void ShiftTableComputation(char p[])
// {
//     int m,i,j;
//     m=strlen(p);
//     for (i=0;i<1000;i++)
//         table[i]=m;
//     for (j=0;j<=m-2;j++)
//         table[p[j]]=m-1-j;
// }

// int HPoolStringMatching(char p[],char t[])
// {
//     int m,n,i,k;
//     //Shift Table Computation
//     ShiftTableComputation(p);
//     m=strlen(p);
//     n=strlen(t);
//     i=m-1;
//     while (i<=n-1)
//     {
//         k=0;
//         while ((k<=m-1) && t[i-k]==p[m-1-k])
//             k++;
//         if (k==m)
//             return i-m+1;
//         else
//             i=i+table[t[i]];
//     }
//     return -1;
// }

// int main()
// {
//     char str[100],ptr[100];
//     int res;
//     printf("Enter the text:");
//     scanf("%s",str);
//     printf("Enter pattern:");
//     scanf("%s",ptr);
//     res=HPoolStringMatching(ptr,str);
//     if (res==-1)
//         printf("Not found");
//     else
//         printf("Pattern found at position %d",res+1);
// }




//5
// #include<stdio.h>
// #include<stdlib.h>
// // capacity is taken as m
// int max(int a,int b)
// {
//     return (a>b?a:b);
// }
// void Knapsack(int n,int m, int w[20],int V[20][20],int p[20])
// {
//     int i,j;
//     for (i=0;i<=n;i++)
//     {
//         for (j=0;j<=m;j++)
//         {
//             if (i==0||j==0)
//             {
//                 V[i][j]=0;
//             }
//             else if (j < w[i]) 
//             {
//                 V[i][j]=V[i-1][j];
//             }
//             else
//             {
//                 V[i][j]=max(V[i-1][j], p[i]+V[i-1][j-w[i]]);
//             }
//             printf("%d\t",V[i][j]);
//         }
//         printf("\n");
//     }
// }

// void ItemsOfOptimal(int n,int m,int w[20],int V[20][20])
// {
//     int i,j;
 
//     if (V[n][m]==0)
//     {
//         printf("Not possible!");
//         return;
//     }
//     printf("Optimal solution is :%d\n",V[n][m]);
//     i=n;
//     j=m;
//     printf("Objects selected: ");
//     while (i!=0 && j!=0)
//     {
//         if (V[i][j]!=V[i-1][j])
//         {
//             printf("\n%d",i);
//             j=j-w[i];
//         }
//         i=i-1;
//     }
//     printf("\n");
// }

// int main()
// {
//     int m,n,i,j,p[20],w[20],v[20][20];
//     printf("Enter no. of objects:");
//     scanf("%d",&n);
//     printf("Enter weight of %d objects:",n);
//     for (i=1;i<=n;i++)
//     scanf("%d",&w[i]);
//     printf("Enter Profits/values:");
//     for (i=1;i<=n;i++)
//     scanf("%d",&p[i]);
//     printf("Enter capacity:");
//     scanf("%d",&m);
//     Knapsack(n,m,w,v,p);
//     ItemsOfOptimal(n,m,w,v);
// }



//6
// #include <stdio.h>
// #include <stdlib.h>
// int w[10]; // denotes set s
// int x[10]; // boolean array which tells if ele is part of subset or not
// int d;     // max value recieves when ele is added in the subset
// void sumSubset(int s, int k, int r)
// {
//     int i;
//     static int b = 1; // number of subsets
//     x[k] = 1;
//     if (w[k] + s == d)
//     {
//         printf("\nSubset %d) ", b++);
//         for (i = 1; i <= k; i++)
//             if (x[i] == 1)
//                 printf("%d\t", w[i]);
//     }
//     else if (s + w[k] + w[k + 1] <= d)
//         sumSubset(s + w[k], k + 1, r - w[k]);
//     if ((s + r - w[k] >= d) && (s + w[k + 1] <= d))
//     {
//         x[k] = 0;
//         sumSubset(s, k + 1, r - w[k]);
//     }
// }
// int main()
// {
//     int n, i, sum = 0;
//     printf("\nSUBSET PROBLEM\n");
//     printf("\nEnter the number of elements - ");
//     scanf("%d", &n);
//     printf("\nEnter the elements (in increasing order) - ");
//     for (i = 1; i <= n; i++)
//     {
//         scanf("%d", &w[i]);
//         sum += w[i];
//     }
//     printf("\nEnter the subset max value required - ");
//     scanf("%d", &d);
//     if (sum < d || w[1] > d)
//     {
//         printf("\nNo subsets possible!!\n");
//         exit(0);
//     }
//     sumSubset(0, 1, sum);
//     // 0-s 1-k sum-r
//     return (0);
// }



//7
// #include <stdio.h>
// #include <stdlib.h>
// int x[20];
// // k->row i->column
// int place(int k, int i)
// {
//     int j;
//     for (j = 1; j <= k - 1; j++)
//     {
//         if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
//             return 0;
//     }
//     return 1;
// }
// void printQueen(int n)
// {
//     int i, j;
//     static int count = 1;
//     printf("\n\nSolution %d is- \n\n", count++);
//     for (i = 1; i <= n; ++i)
//         printf("\t%d", i);
//     for (i = 1; i <= n; ++i)
//     {
//         printf("\n\n%d", i);
//         for (j = 1; j <= n; ++j) // for nxn board
//         {
//             if (x[i] == j)
//                 printf("\tQ"); // queen at i,j position
//             else
//                 printf("\t-"); // empty slot
//         }
//     }
// }
// void NQueen(int k, int n)
// {
//     int i;
//     for (i = 1; i <= n; i++)
//     {
//         if (place(k, i))
//         {
//             x[k] = i;
//             if (k == n)
//             {
//                 printQueen(n);
//             }
//             else
//                 NQueen(k + 1, n);
//         }
//     }
// }
// int main()
// {
//     int n;
//     printf("\nN-QUEEN PROBLEM\n");
//     printf("\nEnter the number of queens to be placed - ");
//     scanf("%d", &n);
//     if (n == 2 || n == 3 || n == 0)
//         printf("\nNo solutions possible!!");
//     else
//         NQueen(1, n);
//     return (0);
// }

//8

// #include<stdio.h>
// #include<stdlib.h>

// int j = 0, pop[10], v[10], recStack[10];  // Added recStack to track the current path

// void dfs(int source, int n, int a[10][10]) {
//     int i, k, top = -1, stack[10];
//     v[source] = 1;         // Mark node as visited
//     recStack[source] = 1;   // Mark node as part of the recursion stack

//     stack[++top] = source + 1;
//     while (top != -1) {
//         for (k = 0; k < n; k++) {
//             if (a[source][k] == 1 && recStack[k] == 1) {
//                 // If we find an edge to a node that is already in the recursion stack, it means there is a cycle
//                 printf("Topological order not possible - Cycle detected\n");
//                 exit(0);
//             }
//             else if (a[source][k] == 1 && v[k] == 0) {
//                 // If the node is unvisited, visit it
//                 v[k] = 1;
//                 recStack[k] = 1;
//                 stack[++top] = k + 1;
//                 source = k;
//                 k = -1;  // Reset to start scanning adjacency list of the new source
//             }
//         }
//         // Finished exploring all adjacent nodes for the current source
//         pop[j++] = source + 1;
//         top--;
//         recStack[source] = 0;  // Remove the node from the current path (recursion stack)
//         if (top != -1)
//             source = stack[top] - 1;
//     }
// }

// void topo(int n, int a[10][10]) {
//     int i, k;
//     for (i = 0; i < n; i++) {
//         v[i] = 0;
//         recStack[i] = 0;  // Initialize recursion stack array
//     }

//     for (k = 0; k < n; k++) {
//         if (v[k] == 0)
//             dfs(k, n, a);
//     }
// }

// int main() {
//     int n, a[10][10];
//     printf("Enter number of vertices\n");
//     scanf("%d", &n);

//     printf("Enter graph\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &a[i][j]);
//         }
//     }

//     topo(n, a);

//     // Print topological sort result
//     for (int i = n - 1; i >= 0; i--) {
//         printf("%d\t", pop[i]);
//     }

//     return 0;
// }


//9
// #include <stdio.h>

// void BFS(int graph[10][10], int visited[10], int n, int start) {
//     int queue[10], front = 0, rear = 0;
//     int i;

//     // Start by visiting the start node
//     visited[start] = 1;
//     queue[rear++] = start;

//     while (front < rear) {
//         int current = queue[front++];
        
//         // Check all adjacent nodes
//         for (i = 1; i <= n; i++) {
//             if (graph[current][i] == 1 && !visited[i]) {
//                 visited[i] = 1;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

// int isConnected(int graph[10][10], int n) {
//     int visited[10] = {0};
    
//     // Start BFS from the first node (index 0)
//     BFS(graph, visited, n, 1);

//     // Check if all nodes were visited
//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             return 0; // Not all nodes were visited, so the graph is not connected
//         }
//     }
//     return 1; // All nodes were visited, so the graph is connected
// }

// int main() {
//     int n, i, j;
//     int graph[10][10];

//     printf("Enter the number of nodes in the graph: ");
//     scanf("%d", &n);

//     printf("Enter the adjacency matrix:\n");
//     for (i = 1; i <= n; i++) {
//         for (j = 1; j <= n; j++) {
//             scanf("%d", &graph[i][j]);
//         }
//     }

//     if (isConnected(graph, n)) {
//         printf("The graph is connected.\n");
//     } else {
//         printf("The graph is not connected.\n");
//     }

//     return 0;
// }



//10

// #include <stdio.h>
// #include <stdlib.h>

// int min(int a, int b){
//     if(a < b)
//         return a;
//     else
//         return b;
// }

// int floyd(int D[10][10], int n){
//     for(int i=1; i <= n; i++){
//         for(int j=1; j<=n; j++){
//             for(int k=1; k<=n; k++){
//                 D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
//             }
//         }
//     }
// }

// int main(){
//     int n, D[10][10];
//     printf("Enter the number of nodes\n");
//     scanf("%d",&n);

//     printf("Enter the weighted matrix\n");
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n; j++){
//             scanf("%d", &D[i][j]);
//         }
//     }
//     floyd(D, n);
    
//     printf("All shortest path : \n");
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n; j++){
//             printf("%d ", D[i][j]);
//         }
//         printf("\n");
//     }
// }


//11
// #include <stdio.h>
// #include <stdlib.h>

// void dijkstras(int n, int cost[10][10], int s, int dist[10]){

//     int i, v, count=1, min, visited[10];
//     for(i=1; i<=n; i++){
//         visited[i] = 0;
//         dist[i] = cost[s][i];
//     }
//     visited[s] = 1;
//     dist[s] = 0;
//     while(count<=n){
//         min=999;
//         for(i=1; i<=n; i++){
//             if(dist[i]<min && visited[i]==0){
//                 min=dist[i];
//                 v=i;
//             }
//         }
//         visited[v] = 1;
//         count++;
//         for(i=1; i<=n; i++){
//             if(dist[i]>dist[v]+cost[v][i]){
//                 dist[i] = dist[v]+cost[v][i];
//             }
//         }
//     }
// }

// int main(){

//     int i, j, n, s, cost[10][10], dist[10];
//     printf("Enter the no of nodes: ");
//     scanf("%d", &n);
//     printf("\n Read cost matrix\n");
//     for(i=1; i<=n; i++){
//         for(j=1; j<=n; j++){
//             scanf("%d", &cost[i][j]);
//             if(cost[i][j] == 0)
//                 cost[i][j]==999;
//         }
//     }
//     printf("\n Read source vertex: ");
//     scanf("%d", &s);
//     dijkstras(n, cost, s, dist);
//     printf("\n Shortest path from %d is: \n", s);
//     for(i=1; i<=n; i++){
//         if(s!=i)
//             printf("%d -> %d = %d", s, i, dist[i]);
//         printf("\n");
//     }  
//     return 0;
// }


//12
// #include <stdio.h>
// #include <stdlib.h>


// void prims(int n, int cost[10][10]){
//     int i, j, min, mincost = 0, u = 0, v = 0, ne=1;
//     int visited[10]={0}; 

//     visited[1] = 1;  // Start from the first node
//     printf("\nThe edges considered for MST are\n");

//     while(ne < n){
//         min = 999;

//         for(i = 1; i <= n; i++){
//             if(visited[i]){
//                 for(j = 1; j <= n; j++){
//                     if(cost[i][j] < min && visited[j]==0){
//                         min = cost[i][j];
//                         u = i;
//                         v = j;
//                     }
//                 }
//             }
//         }

//         if(visited[u]==0 || visited[v]==0){
//             printf("Edge %d (%d, %d) = %d\n", ne++, u, v, min);
//             mincost += min;
//             visited[v] = 1;
//         }

//         // Mark the edge as visited by setting its cost to INF
//         cost[u][v] = cost[v][u] = 999;
//     }

//     printf("Cost of MST is %d\n", mincost);
// }

// int main(){
//     int i, j, n, cost[10][10];

//     printf("Enter the number of nodes: \n");
//     scanf("%d", &n);

//     printf("Enter the adjacency matrix:\n");
//     for(i = 1; i <= n; i++){
//         for(j = 1; j <= n; j++){
//             scanf("%d", &cost[i][j]);
//             if(cost[i][j] == 0)
//                 cost[i][j] = 999;  // Replace 0 with INF to indicate no edge
//         }
//     }

//     prims(n, cost);
//     return 0;
// }
