#include "mbed.h"


Serial pc( USBTX, USBRX );
PwmOut PWM1(D6);
DigitalIn Ain(D7);
float i;
int j, sample=128,ADCdata[128];

int main() {

    PWM1.period(0.001);
    while(1){
        for(i=0; i<1 && j<sample; i=i+0.1){
            PWM1 = i;
            ADCdata[j]=Ain;
            j=j+1;
            wait(0.1);
        }
        for(i=1; i>0 && j<sample; i=i-0.1){
            PWM1=i;
            ADCdata[j]=Ain;
            j=j+1;
            wait(0.1);
        }
        
    }


    for (j = 0; j < sample; j++){

        pc.printf("%d\r\n", ADCdata[j]);

        wait(0.05);
    }


}