/*
    MICROCHIP SOFTWARE NOTICE AND DISCLAIMER:

    You may use this software, and any derivatives created by any person or
    entity by or on your behalf, exclusively with Microchip's products.
    Microchip and its subsidiaries ("Microchip"), and its licensors, retain all
    ownership and intellectual property rights in the accompanying software and
    in all derivatives hereto.

    This software and any accompanying information is for suggestion only. It
    does not modify Microchip's standard warranty for its products.  You agree
    that you are solely responsible for testing the software and determining
    its suitability.  Microchip has no obligation to modify, test, certify, or
    support the software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE APPLY TO THIS SOFTWARE, ITS INTERACTION WITH MICROCHIP'S
    PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT, WILL MICROCHIP BE LIABLE, WHETHER IN CONTRACT, WARRANTY, TORT
    (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), STRICT LIABILITY,
    INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF
    ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWSOEVER CAUSED, EVEN IF
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
    FORESEEABLE.  TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S TOTAL
    LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED
    THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR
    THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF
    THESE TERMS.
*/
#include <xc.h>
#include "mtouch_sensor_scan.h"

/**
* @prototype    void MTOUCH_CVD_ScanA_0
*
* @description  CVD scanA for sensor 0
*               - name:                         Sensor_AN12
*               - pin:                          RB0
*               - analog channel:               AN12
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_0(void)
{
    /* Initialize Precharge Source - Assigned I/O RA0 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S0_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S0_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S0_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S0_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    _delay(MTOUCH_S0_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S0_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S0_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S0_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S0_LAT) " & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_0
*
* @description    CVD scanB for sensor 0
*                - name:                         Sensor_AN12
*                - pin:                          RB0
*                - analog channel:               AN12
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_0(void)
{
    /* Initialize Precharge Source - Assigned I/O RA0 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S0_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S0_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S0_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S0_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S0_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S0_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S0_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    _delay(MTOUCH_S0_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S0_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S0_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S0_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S0_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S0_LAT) " & 0x7F, " ___mkstr(MTOUCH_S0_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S0_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_1
*
* @description  CVD scanA for sensor 1
*               - name:                         Sensor_AN10
*               - pin:                          RB1
*               - analog channel:               AN10
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_1(void)
{
    /* Initialize Precharge Source - Assigned I/O RB0 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S1_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S1_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S1_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S1_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S1_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S1_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S1_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S1_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S1_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S1_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S1_PIN));
    _delay(MTOUCH_S1_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S1_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S1_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S1_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S1_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S1_LAT) " & 0x7F, " ___mkstr(MTOUCH_S1_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S1_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_1
*
* @description    CVD scanB for sensor 1
*                - name:                         Sensor_AN10
*                - pin:                          RB1
*                - analog channel:               AN10
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_1(void)
{
    /* Initialize Precharge Source - Assigned I/O RB0 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S1_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S1_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S1_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S1_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S1_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S1_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S1_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S1_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S1_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S1_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S1_PIN));
    _delay(MTOUCH_S1_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S1_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S1_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S1_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S1_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S1_LAT) " & 0x7F, " ___mkstr(MTOUCH_S1_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S1_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_2
*
* @description  CVD scanA for sensor 2
*               - name:                         Sensor_AN8
*               - pin:                          RB2
*               - analog channel:               AN8
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_2(void)
{
    /* Initialize Precharge Source - Assigned I/O RB1 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S2_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S2_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S2_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S2_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S2_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S2_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S2_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S2_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S2_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S2_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S2_PIN));
    _delay(MTOUCH_S2_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S2_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S2_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S2_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S2_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S2_LAT) " & 0x7F, " ___mkstr(MTOUCH_S2_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S2_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_2
*
* @description    CVD scanB for sensor 2
*                - name:                         Sensor_AN8
*                - pin:                          RB2
*                - analog channel:               AN8
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_2(void)
{
    /* Initialize Precharge Source - Assigned I/O RB1 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S2_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S2_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S2_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S2_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S2_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S2_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S2_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S2_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S2_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S2_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S2_PIN));
    _delay(MTOUCH_S2_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S2_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S2_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S2_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S2_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S2_LAT) " & 0x7F, " ___mkstr(MTOUCH_S2_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S2_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_3
*
* @description  CVD scanA for sensor 3
*               - name:                         Sensor_AN9
*               - pin:                          RB3
*               - analog channel:               AN9
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_3(void)
{
    /* Initialize Precharge Source - Assigned I/O RB2 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S3_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S3_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S3_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S3_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S3_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S3_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S3_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S3_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S3_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S3_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S3_PIN));
    _delay(MTOUCH_S3_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S3_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S3_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S3_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S3_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S3_LAT) " & 0x7F, " ___mkstr(MTOUCH_S3_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S3_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_3
*
* @description    CVD scanB for sensor 3
*                - name:                         Sensor_AN9
*                - pin:                          RB3
*                - analog channel:               AN9
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_3(void)
{
    /* Initialize Precharge Source - Assigned I/O RB2 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S3_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S3_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S3_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S3_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S3_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S3_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S3_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S3_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S3_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S3_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S3_PIN));
    _delay(MTOUCH_S3_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S3_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S3_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S3_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S3_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S3_LAT) " & 0x7F, " ___mkstr(MTOUCH_S3_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S3_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_4
*
* @description  CVD scanA for sensor 4
*               - name:                         Sensor_AN11
*               - pin:                          RB4
*               - analog channel:               AN11
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_4(void)
{
    /* Initialize Precharge Source - Assigned I/O RB3 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S4_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S4_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S4_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S4_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S4_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S4_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S4_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S4_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S4_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S4_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S4_PIN));
    _delay(MTOUCH_S4_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S4_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S4_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S4_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S4_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S4_LAT) " & 0x7F, " ___mkstr(MTOUCH_S4_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S4_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_4
*
* @description    CVD scanB for sensor 4
*                - name:                         Sensor_AN11
*                - pin:                          RB4
*                - analog channel:               AN11
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_4(void)
{
    /* Initialize Precharge Source - Assigned I/O RB3 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S4_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S4_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S4_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S4_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S4_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S4_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S4_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S4_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S4_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S4_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S4_PIN));
    _delay(MTOUCH_S4_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S4_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S4_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S4_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S4_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S4_LAT) " & 0x7F, " ___mkstr(MTOUCH_S4_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S4_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_5
*
* @description  CVD scanA for sensor 5
*               - name:                         Sensor_AN13
*               - pin:                          RB5
*               - analog channel:               AN13
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_5(void)
{
    /* Initialize Precharge Source - Assigned I/O RB4 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S5_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S5_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S5_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S5_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S5_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S5_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S5_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S5_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S5_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S5_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S5_PIN));
    _delay(MTOUCH_S5_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S5_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S5_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S5_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S5_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S5_LAT) " & 0x7F, " ___mkstr(MTOUCH_S5_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S5_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_5
*
* @description    CVD scanB for sensor 5
*                - name:                         Sensor_AN13
*                - pin:                          RB5
*                - analog channel:               AN13
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_5(void)
{
    /* Initialize Precharge Source - Assigned I/O RB4 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S5_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S5_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S5_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S5_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S5_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S5_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S5_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S5_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S5_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S5_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S5_PIN));
    _delay(MTOUCH_S5_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S5_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S5_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S5_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S5_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S5_LAT) " & 0x7F, " ___mkstr(MTOUCH_S5_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S5_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_6
*
* @description  CVD scanA for sensor 6
*               - name:                         Sensor_AN3
*               - pin:                          RA3
*               - analog channel:               AN3
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_6(void)
{
    /* Initialize Precharge Source - Assigned I/O RB5 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S6_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S6_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S6_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S6_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S6_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S6_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S6_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S6_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S6_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S6_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S6_PIN));
    _delay(MTOUCH_S6_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S6_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S6_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S6_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S6_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S6_LAT) " & 0x7F, " ___mkstr(MTOUCH_S6_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S6_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_6
*
* @description    CVD scanB for sensor 6
*                - name:                         Sensor_AN3
*                - pin:                          RA3
*                - analog channel:               AN3
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_6(void)
{
    /* Initialize Precharge Source - Assigned I/O RB5 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S6_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S6_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S6_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S6_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S6_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S6_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S6_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S6_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S6_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S6_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S6_PIN));
    _delay(MTOUCH_S6_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S6_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S6_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S6_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S6_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S6_LAT) " & 0x7F, " ___mkstr(MTOUCH_S6_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S6_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_7
*
* @description  CVD scanA for sensor 7
*               - name:                         Sensor_AN2
*               - pin:                          RA2
*               - analog channel:               AN2
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_7(void)
{
    /* Initialize Precharge Source - Assigned I/O RA3 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S7_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S7_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S7_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S7_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S7_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S7_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S7_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S7_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S7_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S7_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S7_PIN));
    _delay(MTOUCH_S7_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S7_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S7_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S7_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S7_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S7_LAT) " & 0x7F, " ___mkstr(MTOUCH_S7_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S7_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_7
*
* @description    CVD scanB for sensor 7
*                - name:                         Sensor_AN2
*                - pin:                          RA2
*                - analog channel:               AN2
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_7(void)
{
    /* Initialize Precharge Source - Assigned I/O RA3 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S7_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S7_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S7_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S7_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S7_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S7_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S7_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S7_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S7_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S7_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S7_PIN));
    _delay(MTOUCH_S7_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S7_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S7_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S7_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S7_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S7_LAT) " & 0x7F, " ___mkstr(MTOUCH_S7_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S7_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_8
*
* @description  CVD scanA for sensor 8
*               - name:                         Sensor_AN1
*               - pin:                          RA1
*               - analog channel:               AN1
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_8(void)
{
    /* Initialize Precharge Source - Assigned I/O RA2 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S8_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S8_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S8_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S8_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S8_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S8_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S8_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S8_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S8_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S8_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S8_PIN));
    _delay(MTOUCH_S8_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S8_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S8_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S8_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S8_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S8_LAT) " & 0x7F, " ___mkstr(MTOUCH_S8_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S8_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_8
*
* @description    CVD scanB for sensor 8
*                - name:                         Sensor_AN1
*                - pin:                          RA1
*                - analog channel:               AN1
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_8(void)
{
    /* Initialize Precharge Source - Assigned I/O RA2 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S8_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S8_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S8_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S8_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S8_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S8_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S8_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S8_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S8_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S8_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S8_PIN));
    _delay(MTOUCH_S8_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S8_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S8_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S8_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S8_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S8_LAT) " & 0x7F, " ___mkstr(MTOUCH_S8_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S8_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanA_9
*
* @description  CVD scanA for sensor 9
*               - name:                         Sensor_AN0
*               - pin:                          RA0
*               - analog channel:               AN0
*               - reference type:               MTOUCH_OPTION_REFTYPE_IO
*               - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanA_9(void)
{
    /* Initialize Precharge Source - Assigned I/O RA1 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S9_REF_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S9_REF_LAT) "& 0x7F," ___mkstr(MTOUCH_S9_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S9_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S9_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S9_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S9_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S9_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S9_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S9_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S9_PIN));
    _delay(MTOUCH_S9_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bsf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S9_GUARD_PIN));


    /* Settling Delay */
    _delay(MTOUCH_S9_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S9_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S9_LAT));
    asm("bsf            " ___mkstr(MTOUCH_S9_LAT) " & 0x7F, " ___mkstr(MTOUCH_S9_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S9_PIN));

}

/**
* @prototype    void MTOUCH_CVD_ScanB_9
*
* @description    CVD scanB for sensor 9
*                - name:                         Sensor_AN0
*                - pin:                          RA0
*                - analog channel:               AN0
*                - reference type:               MTOUCH_OPTION_REFTYPE_IO
*                - guard type:                   MTOUCH_OPTION_GUARDTYPE_IO
*
*/
void MTOUCH_CVD_ScanB_9(void)
{
    /* Initialize Precharge Source - Assigned I/O RA1 */
    asm("BANKSEL        " ___mkstr(MTOUCH_S9_REF_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S9_REF_LAT) " & 0x7F," ___mkstr(MTOUCH_S9_REF_PIN));

    /* Begin Precharge Stage */
    asm("BANKSEL        ADCON0");
    asm("movlw          " ___mkstr(MTOUCH_S9_REF_ADCON0));
    asm("movwf          ADCON0 & 0x7F");

    /* Precharge Delay */
    _delay(MTOUCH_S9_PRECHARGE_TIME);


    /* Prepare FSR0 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S9_TRIS));
    asm("movwf          FSR0L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S9_TRIS));
    asm("movwf          FSR0H & 0x7F");

    /* Prepare FSR1 for Settling Phase */
    asm("movlw LOW      " ___mkstr(MTOUCH_S9_GUARD_LAT));
    asm("movwf          FSR1L & 0x7F");
    asm("movlw HIGH     " ___mkstr(MTOUCH_S9_GUARD_LAT));
    asm("movwf          FSR1H & 0x7F");

    /* Begin Settling Stage: Connect */
    asm("movlw          " ___mkstr(MTOUCH_S9_ADCON0_SENSOR));
    asm("bsf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S9_PIN));
    _delay(MTOUCH_S9_SWITCH_TIME);
    asm("movwf          ADCON0 & 0x7F");
    asm("bcf            INDF1 & 0x7F, " ___mkstr(MTOUCH_S9_GUARD_PIN));



    /* Settling Delay */
    _delay(MTOUCH_S9_ACQUISITION_TIME);

    /* Begin Conversion */
    asm("BANKSEL        ADCON0");
    asm("bsf            ADCON0 & 0x7F, 1");

    /* Disconnection Delay */
    _delay(MTOUCH_S9_DISCON_TIME);

    /* Exit Logic - Output Low */
    asm("BANKSEL        " ___mkstr(MTOUCH_S9_LAT));
    asm("bcf            " ___mkstr(MTOUCH_S9_LAT) " & 0x7F, " ___mkstr(MTOUCH_S9_PIN));
    asm("bcf            INDF0 & 0x7F, " ___mkstr(MTOUCH_S9_PIN));

}

