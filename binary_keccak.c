#include "stdio.h"
#include "sha3.h"
#include "iota/conversion.h"

#include <time.h>

int BENCHMARK_TIMES = 1000000;

int run_hashing(void){
    // "This is some text." in tryte chars
    const unsigned char data[] = "This is some text. Blablibub.HAHAHLAuUED";
    unsigned char digest[384];

    SHA3_CTX ctx;
    sha3_384_Init(&ctx);
    sha3_Update(&ctx, data, sizeof(data) - 1);
    sha3_Final(&ctx, digest);

    /*for(int i = 0; i < 384/8; i++){
        printf("%02x", digest[i]);
    }
    printf("%c", '\n');
     */
    return 0;
}

int run_benchmark(void){
    for(int i = 0; i < BENCHMARK_TIMES; i++){
        run_hashing();
    }
    return 0;
}

int main(void){
    clock_t t;
    t = clock();
    run_benchmark();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("Hash text with Keccak %i times took %f seconds to execute \n", BENCHMARK_TIMES, time_taken);
}