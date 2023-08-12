#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    int N;
    //set ค่าผลรวมทั้งหมด = 0, ค่าเฉลี่ย
    unsigned int sumOfAllNumber = 0, average;

    //Thread
    //set จำนวน thread ที่ใช้ = 4
    int numOfThread = 4;

    //malloc จองพื้นที่เพื่อเก็บผลรวมภายใน thread
    unsigned int *sumOfEachThread = ( unsigned int * )malloc( numOfThread * sizeof( unsigned int ) );

    //รับจำนวนของตัวเลข( N )
    scanf( "%d", &N );

    //malloc จองพื้นที่เพื่อเก็บตัวเลขที่ input เข้ามา
    unsigned *numbers= ( unsigned * )malloc( N * sizeof( unsigned ) );

    //for loop รับตัวเลข แล้วนำไปเก็บในพื้นที่จองไว้( number )
    for ( int i = 0; i < N; i++ ) {
        scanf( "%u", &numbers[ i ] );
    }

    //OpenMP
    #pragma omp parallel num_threads( numOfThread )
    {
        //set ค่าผลรวมของแต่ละ thread = 0
        sumOfEachThread[ omp_get_thread_num() ] = 0;

        //for loop นำตัวเลขที่อยู่ใน thread นั้น มาบวกกัน
        #pragma omp for
        for ( int i = 0; i < N; i++ ) {
            sumOfEachThread[ omp_get_thread_num() ] += numbers[ i ];
        }
    }

    //for loop นำผลรวมของแต่ละ thread มาบวกกัน
    for ( int i = 0; i < numOfThread; i++ ) {
        sumOfAllNumber += sumOfEachThread[ i ];
    }

    //คำนวณ ค่าเฉลี่ย = ผลรวมของตัวเลขทั้งหมด / จำนวนของตัวเลข 
    average = sumOfAllNumber / N;
    printf( "%u", average );

    //free *คืนพื้นที่ที่จองไว้ 
    free( numbers );

    //จบการทำงาน
    return 0;
}
