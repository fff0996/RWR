#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, int **argv){

//geneList
	FILE *wholeGene = NULL;
	wholeGene=fopen(argv[1],"r");
	if(wholeGene == NULL){
		printf("there is no file");
		return 0;
	}
	
	int *geneList;
	geneList	= (int*)malloc(sizeof(int));
	int geneNum=0;
	
	int gene;
	while(0<fscanf(wholeGene,"%d",&gene)){
		geneList = (int*)realloc(geneList,(geneNum+1)*sizeof(int));
		geneList[geneNum] = gene;
		geneNum++;
	}
	fclose(wholeGene);
	//printf("%d",geneNum);

//make network;
        int i,j;
        double** network;
        network =(double**)malloc(sizeof(double*)*geneNum);
        for(i=0;i<geneNum;i++){
           network[i]=(double*)malloc(sizeof(double)*geneNum);
        }
	//double network[geneNum][geneNum];
	
	//int i,j;
	for(i=0;i<geneNum;i++){
		for(j=0;j<geneNum;j++){
			network[i][j]=0;
		}
	}

// print network
/*	for(i=0;i<geneNum;i++){
 	   for(j=0;j<geneNum;j++){
 	        printf("%lf",network[i][j]);
 	   }
 	   printf("\n");
 	 }
 	 printf("\n");
*/ 
//network score
	FILE *net = NULL;

	net = fopen(argv[2],"r");
	if(net == NULL){
		printf("there is no file");
		return 0;
	}

	int gene_a;
	int gene_b;
	double score;
	
	while(0<fscanf(net,"%d %d %lf",&gene_a,&gene_b,&score)){
		
		int indexA = -1;
		int indexB = -1;
	//	printf ("%d %d %lf\n",gene_a,gene_b,score);
		for(i=0;i<geneNum;i++){
			if(gene_a == geneList[i]){
				indexA = i;
			}
			if(gene_b == geneList[i]){
				indexB = i;
			}
		}
                
		network[indexA][indexB]=score;
		network[indexB][indexA]=score;

	}
	fclose(net);
	

// print network
/*
  for(i=0;i<geneNum;i++){
     for(j=0;j<geneNum;j++){
         printf("%lf",network[i][j]);
     }
     printf("\n");
   }
   printf("\n");
*/ 
// nomalize
	for(i=0;i<geneNum;i++){
		double sum=0;
		for(j=0;j<geneNum;j++){
			sum += network[j][i];
		}
		if(sum != 0){
			for(j=0;j<geneNum;j++){
				network[j][i] /= sum;
			}
		}
	}
	

// print network
/*
  for(i=0;i<geneNum;i++){
     for(j=0;j<geneNum;j++){
        printf("%lf",network[i][j]);
     }
     printf("\n");
  }
  printf("\n");
*/
 
	double *V;
	V = (double*)malloc(sizeof(double)*geneNum);
	for(i=0;i<geneNum;i++){
		V[i]=0;
	}

	FILE *geneset1 = fopen(argv[3],"r");
	if(geneset1 == NULL){
		printf("there is no file(geneset1)\n");
		return 0;
	}
	double diseaseNum;
	while(0<fscanf(geneset1,"%d %lf",&gene,&diseaseNum)){
		for(i=0;i<geneNum;i++){
			if(geneList[i]==gene){
				V[i]=1;	
				break;
			}
		}
	}
	fclose(geneset1);
// print V	
/*
 * for(i=0;i<geneNum;i++){
 *      prntf("lf\n", V[i]);
 * }
 * printf("\n");
 */
// U UOld
	double *U;
	U = (double*)malloc(sizeof(double)*geneNum);
	for(i=0;i<geneNum;i++){
		U[i]=V[i];
	}
	
	double *UOld;
	UOld = (double*)malloc(sizeof(double)*geneNum);
	for(i=0;i<geneNum;i++){
		UOld[i]=0;
	}
//
	double gapU=0;
	for(i=0;i<geneNum;i++){
		gapU += (U[i]-UOld[i]);
	}
	gapU = (gapU >0) ? (gapU): (gapU*(-1));

	double restart ;
	restart = atof(argv[4]);
	
	while(gapU>=0.000001){
	/*	for(i=0;i<geneNum;i++){
			printf("%e\t",U[i]);
		}
		printf("\n");
        */
		for(i=0;i<geneNum;i++){
			UOld[i]=U[i];
		}
		for(i=0;i<geneNum;i++){
			U[i]=0;
			for(j=0;j<geneNum;j++){
				U[i] += network[i][j]*UOld[j];
			}
			U[i] *= (1-restart);
			U[i] += (restart*V[i]);
		}
		gapU=0;
		for(i=0;i<geneNum;i++){
			double gap = (U[i]-UOld[i]);
			gap = (gap > 0)?(gap):(gap*(-1));
			gapU += gap;
		}
		gapU = (gapU >0) ? (gapU): (gapU*(-1));
	}
	
	for(i=0;i<geneNum;i++){
                
		printf("%e\n",U[i]);
	}
	printf("\n");

	free(geneList);
	free(V);
	free(U);
	free(UOld);
        for( i=0;i<geneNum;i++){
            free(network[i]);
        }
        free(network);
	
	return 0;
}



















										
