/*
    ผู้ใช้กรอกข้อมูลพนักงานในบริษัท โดยจะกรอกข้อมูล ชื่อ, เงินเดือน, อายุการทำงาน ของแต่ละคน โดยเมื่อผู้ใช้กรอกตัว n จะถือเป็นการหยุดโปรแกรมและทำการแสดงข้อมูลเงินเดือนเฉลี่ยของพนักงานในบริษัท และเงินเดือนของทุกคนรวมกันที่ผู้บริหารต้องจ่าย และแสดงคนที่อายุงานเยอะที่สุดพร้อมระบุ ชื่อ เงินเดือน และอายุงาน ของคนๆ นั้น
    
    Test case:
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Yorn
        Salary (Bath/Month) : 
            15000
        Duration (Year) : 
            4
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Van
        Salary (Bath/Month) : 
            14550
        Duration (Year) : 
            2
        Do you want to Enter Employee Information? (y/n) : 
            y
        ----
        Employee Name : 
            Thane
        Salary (Bath/Month) : 
            22500
        Duration (Year) : 
            8
        Do you want to Enter Employee Information? (y/n) : 
            n
    Output:
        Average of Salary : 17,350.00 Bath
        Payment of every month : 52,050.00 Bath
        ----------------------------------------
        ** Most duration in this business **
        Name : Thane (8 Years)
        Salary : 22,500.00 Bath

*/

//TODO: #21 output money should in decimal format (eg. 120,200,340.42).

#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[50] ;
    double Salary ;
    int Duration ;
};

int main() {
    int n ;
    double totalSalary = 0 ;
    double maxDuration = 0 ;
    struct Employee maxDurationEmployee ;

    printf( "Do you want to Enter Employee Information? (y/n) : " ) ;
    char choice ;
    scanf( " %c" , &choice ) ;

    while ( choice == 'y' || choice == 'Y' ) {
        struct Employee emp ;

        printf( "----\n" ) ;
        printf( "Employee Name : " ) ;
        scanf( "%s" , emp.Name ) ;
        printf( "Salary (Bath/Month) : " ) ;
        scanf( "%lf" , &emp.Salary ) ;
        printf( "Duration (Year) : " ) ;
        scanf( "%d" , &emp.Duration ) ;

        totalSalary += emp.Salary ;
        if ( emp.Duration > maxDuration ) {
            maxDuration = emp.Duration ;
            maxDurationEmployee = emp; 
        }

        printf( "Do you want to Enter Employee Information? (y/n) : " ) ;
        scanf( " %c" , &choice ) ;
    }

    printf( "Average of Salary : %.2lf Bath\n", totalSalary / n ) ;
    printf( "Payment of every month : %.2lf Bath\n" , totalSalary * 12 ) ;
    printf( "----------------------------------------\n" ) ;
    printf( "** Most duration in this business **\n" ) ;
    printf( "Name : %s (%d Years)\n" , maxDurationEmployee.Name , maxDurationEmployee.Duration ) ;
    printf( "Salary : %.2lf Bath\n" , maxDurationEmployee.Salary ) ;

    return 0 ;
}
