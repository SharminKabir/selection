    #include <stdio.h>
    #define MAX 10000000
    #define INF 99999999999999999

    int N,X[MAX],H[MAX],mat[MAX];

     int maximum(int a, int b);
      int minimum(int a, int b);

    int main()
    {
    	int i,j;

    	scanf("%d",&N);

    	for(i=0;i<N;i++)
            scanf("%d%d",&X[i],&H[i]);
    	for(i=1;i<N;i++)
            mat[i]=INF;
    	mat[0]=0;

    	for(i=1;i<N;i++){

    		for(j=i-1;j>=0;j--){
    			if(mat[j]!=INF && H[i]-H[j]<X[i]-X[j]){
    				mat[i] = minimum(mat[i],maximum(mat[j],(H[i]-H[j])*(H[i]-H[j])+(X[i]-X[j])*(X[i]-X[j])));
    			}
    		}

    	}
    	if(mat[N-1]!=INF)
            printf("%d",mat[N-1]);
    	else
            printf("-1");
        return 0;
    }


    int maximum(int a, int b){

    	if(a>=b) return a;
    	else return b;

    }

    int minimum(int a, int b){

    	if(a<=b) return a;
    	else return b;

    }

