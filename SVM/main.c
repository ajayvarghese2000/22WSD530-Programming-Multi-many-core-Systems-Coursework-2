#include <stdio.h>
#include <stdlib.h>

// Used to measure program execution time
#include <time.h>

float set_vers_svs[ 16 ][2] = {
        { 1.9 ,  0.2 },
        { 3.3 ,  1.0 },
};
float set_vers_alphas[ 2 ] = {
         0.8,
         -0.8,
};
float set_vers_bias =  3.169231 ;
float set_virg_svs[ 16 ][2] = {
        { 1.9 ,  0.2 },
        { 4.5 ,  1.7 },
};
float set_virg_alphas[ 2 ] = {
         0.2,
         -0.2,
};
float set_virg_bias =  2.163152 ;
float versi_virg_svs[ 16 ][2] = {
        { 4.7 ,  1.4 },
        { 4.5 ,  1.5 },
        { 4.9 ,  1.5 },
        { 4.6 ,  1.5 },
        { 4.7 ,  1.6 },
        { 4.7 ,  1.4 },
        { 4.8 ,  1.8 },
        { 4.9 ,  1.5 },
        { 5.1 ,  1.9 },
        { 4.5 ,  1.7 },
        { 5.1 ,  2.0 },
        { 5.3 ,  1.9 },
        { 5.0 ,  2.0 },
        { 5.0 ,  1.5 },
        { 4.9 ,  2.0 },
        { 4.9 ,  1.8 }
};
float versi_virg_alphas[ 16 ] = {
         1.0,
         0.2,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         1.0,
         -1.0,
         -1.0,
         -1.0,
         -0.2,
         -1.0,
         -1.0,
         -1.0,
         -1.0,
};
float versi_virg_bias =  10.54 ;

float svm_compute(float sample[], int n_svs, float svs[][2], float alphas[], float bias){
	
	int i = 0;
	float acc_sum = 0;

	for(i = 0 ; i < n_svs ; i++){

		acc_sum += ((sample[0] * svs[i][0] + sample[1]*svs[i][1])*alphas[i]);

	}

	return acc_sum + bias;
}


float samples[150][2] = {
        { 1.4 , 0.2 },
        { 1.4 , 0.2 },
        { 1.3 , 0.2 },
        { 1.5 , 0.2 },
        { 1.4 , 0.2 },
        { 1.7 , 0.4 },
        { 1.4 , 0.3 },
        { 1.5 , 0.2 },
        { 1.4 , 0.2 },
        { 1.5 , 0.1 },
        { 1.5 , 0.2 },
        { 1.6 , 0.2 },
        { 1.4 , 0.1 },
        { 1.1 , 0.1 },
        { 1.2 , 0.2 },
        { 1.5 , 0.4 },
        { 1.3 , 0.4 },
        { 1.4 , 0.3 },
        { 1.7 , 0.3 },
        { 1.5 , 0.3 },
        { 1.7 , 0.2 },
        { 1.5 , 0.4 },
        { 1.0 , 0.2 },
        { 1.7 , 0.5 },
        { 1.9 , 0.2 },
        { 1.6 , 0.2 },
        { 1.6 , 0.4 },
        { 1.5 , 0.2 },
        { 1.4 , 0.2 },
        { 1.6 , 0.2 },
        { 1.6 , 0.2 },
        { 1.5 , 0.4 },
        { 1.5 , 0.1 },
        { 1.4 , 0.2 },
        { 1.5 , 0.1 },
        { 1.2 , 0.2 },
        { 1.3 , 0.2 },
        { 1.5 , 0.1 },
        { 1.3 , 0.2 },
        { 1.5 , 0.2 },
        { 1.3 , 0.3 },
        { 1.3 , 0.3 },
        { 1.3 , 0.2 },
        { 1.6 , 0.6 },
        { 1.9 , 0.4 },
        { 1.4 , 0.3 },
        { 1.6 , 0.2 },
        { 1.4 , 0.2 },
        { 1.5 , 0.2 },
        { 1.4 , 0.2 },
        { 4.7 , 1.4 },
        { 4.5 , 1.5 },
        { 4.9 , 1.5 },
        { 4.0 , 1.3 },
        { 4.6 , 1.5 },
        { 4.5 , 1.3 },
        { 4.7 , 1.6 },
        { 3.3 , 1.0 },
        { 4.6 , 1.3 },
        { 3.9 , 1.4 },
        { 3.5 , 1.0 },
        { 4.2 , 1.5 },
        { 4.0 , 1.0 },
        { 4.7 , 1.4 },
        { 3.6 , 1.3 },
        { 4.4 , 1.4 },
        { 4.5 , 1.5 },
        { 4.1 , 1.0 },
        { 4.5 , 1.5 },
        { 3.9 , 1.1 },
        { 4.8 , 1.8 },
        { 4.0 , 1.3 },
        { 4.9 , 1.5 },
        { 4.7 , 1.2 },
        { 4.3 , 1.3 },
        { 4.4 , 1.4 },
        { 4.8 , 1.4 },
        { 5.0 , 1.7 },
        { 4.5 , 1.5 },
        { 3.5 , 1.0 },
        { 3.8 , 1.1 },
        { 3.7 , 1.0 },
        { 3.9 , 1.2 },
        { 5.1 , 1.6 },
        { 4.5 , 1.5 },
        { 4.5 , 1.6 },
        { 4.7 , 1.5 },
        { 4.4 , 1.3 },
        { 4.1 , 1.3 },
        { 4.0 , 1.3 },
        { 4.4 , 1.2 },
        { 4.6 , 1.4 },
        { 4.0 , 1.2 },
        { 3.3 , 1.0 },
        { 4.2 , 1.3 },
        { 4.2 , 1.2 },
        { 4.2 , 1.3 },
        { 4.3 , 1.3 },
        { 3.0 , 1.1 },
        { 4.1 , 1.3 },
        { 6.0 , 2.5 },
        { 5.1 , 1.9 },
        { 5.9 , 2.1 },
        { 5.6 , 1.8 },
        { 5.8 , 2.2 },
        { 6.6 , 2.1 },
        { 4.5 , 1.7 },
        { 6.3 , 1.8 },
        { 5.8 , 1.8 },
        { 6.1 , 2.5 },
        { 5.1 , 2.0 },
        { 5.3 , 1.9 },
        { 5.5 , 2.1 },
        { 5.0 , 2.0 },
        { 5.1 , 2.4 },
        { 5.3 , 2.3 },
        { 5.5 , 1.8 },
        { 6.7 , 2.2 },
        { 6.9 , 2.3 },
        { 5.0 , 1.5 },
        { 5.7 , 2.3 },
        { 4.9 , 2.0 },
        { 6.7 , 2.0 },
        { 4.9 , 1.8 },
        { 5.7 , 2.1 },
        { 6.0 , 1.8 },
        { 4.8 , 1.8 },
        { 4.9 , 1.8 },
        { 5.6 , 2.1 },
        { 5.8 , 1.6 },
        { 6.1 , 1.9 },
        { 6.4 , 2.0 },
        { 5.6 , 2.2 },
        { 5.1 , 1.5 },
        { 5.6 , 1.4 },
        { 6.1 , 2.3 },
        { 5.6 , 2.4 },
        { 5.5 , 1.8 },
        { 4.8 , 1.8 },
        { 5.4 , 2.1 },
        { 5.6 , 2.4 },
        { 5.1 , 2.3 },
        { 5.1 , 1.9 },
        { 5.9 , 2.3 },
        { 5.7 , 2.5 },
        { 5.2 , 2.3 },
        { 5.0 , 1.9 },
        { 5.2 , 2.0 },
        { 5.4 , 2.3 },
        { 5.1 , 1.8 }
};

typedef enum{
    SET = 0, VERS, VIRG
} final_classes_t;

final_classes_t classify(float vals[]){

    int flower[3] = {0, 0, 0};

    if(vals[0] > 0){
        flower[0] += 1;
    }
    else{
        flower[1] += 1;
    }

    if(vals[1] > 0){
        flower[0] += 1;
    }
    else{
        flower[2] += 1;
    }
    if(vals[2] > 0){
        flower[1] += 1;
    }
    else{
        flower[2] += 1;
    }

    int i;
    int final_class = 0;
    int vote_count = flower[0];
    for(i = 1 ; i < 3 ; i++){

        if(flower[i] > vote_count){
            vote_count = flower[i];
            final_class = i;
        }

    }

    return final_class;

}

int main(){

    // Start timer
    struct timespec start, finish;
    clock_gettime( CLOCK_REALTIME, &start );

    float results[3];
	for(int i = 0 ; i < 150 ; i++){
		
        results[0] = svm_compute(samples[i], 2, set_vers_svs, set_vers_alphas, set_vers_bias);
        results[1] = svm_compute(samples[i], 2, set_virg_svs, set_virg_alphas, set_virg_bias);
        results[2] = svm_compute(samples[i], 16, versi_virg_svs, versi_virg_alphas, versi_virg_bias);

        printf("%3d: ", i);
		printf("%5f, ", results[0]);
		printf("%5f, ", results[1]);
		printf("%5f\n", results[2]);
        printf("Final class -> %d\n", classify(results));
	
	}
	
    clock_gettime(CLOCK_REALTIME, &finish);
    printf("%ld\r\n", (finish.tv_sec - start.tv_sec) * 1000000000 + (finish.tv_nsec - start.tv_nsec));

    // Dump time taken to a csv file
    FILE *fp;
    fp = fopen("time_original.csv", "a");
    fprintf(fp, "%ld\n", (finish.tv_sec - start.tv_sec) * 1000000000 + (finish.tv_nsec - start.tv_nsec));

}