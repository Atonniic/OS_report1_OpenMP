#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main() {
    int N;
    //set ค่าผลรวมทั้งหมด = 0, ค่าเฉลี่ย
    unsigned int sumOfAllNumber = 0, average;

    //รับจำนวนของตัวเลข( N )
    scanf( "%d", &N );

    //malloc จองพื้นที่เพื่อเก็บตัวเลขที่ input เข้ามา
    unsigned *numbers= ( unsigned * )malloc( N * sizeof( unsigned ) );

    //for loop รับตัวเลข แล้วนำไปเก็บในพื้นที่จองไว้( number )
    for ( int i = 0; i < N; i++ ) {
        scanf( "%u", &numbers[ i ] );
    }

    //for loop นำตัวเลขทั้งหมดบวกกัน เพื่อหาผลรวม
    for ( int i = 0; i < N; i++ ) {
        sumOfAllNumber += numbers[ i ];
    }

    //คำนวณ ค่าเฉลี่ย = ผลรวมของตัวเลขทั้งหมด / จำนวนของตัวเลข 
    average = sumOfAllNumber / N;
    printf( "%u", average );

    //free *คืนพื้นที่ที่จองไว้ 
    free( numbers );

    //จบการทำงาน
    return 0;
}