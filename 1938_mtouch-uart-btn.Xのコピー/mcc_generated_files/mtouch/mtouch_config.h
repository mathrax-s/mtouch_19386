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
#ifndef MTOUCH_CONFIG_H
#define MTOUCH_CONFIG_H

#include <stdint.h>
#include <stdbool.h>
#include "mtouch_sensor.h"
#include "mtouch_button.h"
#include "mtouch_slider.h"

/*
 * =======================================================================
 * Application / Configuration Settings
 * =======================================================================
 */
    #define MTOUCH_SENSORS          10u
    #define MTOUCH_BUTTONS          10u
    #define MTOUCH_SLIDERS          2u
    #define MTOUCH_DEBUG_COMM_ENABLE      1u

    /* 
     * =======================================================================
     * Sensor Parameters
     * =======================================================================
     */

    /*
     *  Defines the scan interval (milliseconds)
     *  Range - 1 to 255
     */
    #define MTOUCH_SCAN_INTERVAL    5u      //unit ms
    
 
    /*** Sensor_AN12 ***/
    #define MTOUCH_S0_ADCON0_SENSOR              ( 0xc<<2 | 0x1 )
    #define MTOUCH_S0_REF_ADCON0                 ( 0x0<<2 | 0x1 )
    #define MTOUCH_S0_LAT                        LATB
    #define MTOUCH_S0_TRIS                       TRISB
    #define MTOUCH_S0_PIN                        0
    #define MTOUCH_S0_REF_LAT                    LATA
    #define MTOUCH_S0_REF_PIN                    0
    #define MTOUCH_S0_GUARD_LAT                  LATA
    #define MTOUCH_S0_GUARD_PIN                  5
    #define MTOUCH_S0_PRECHARGE_TIME             32u
    #define MTOUCH_S0_ACQUISITION_TIME           16u
    #define MTOUCH_S0_SWITCH_TIME                0u
    #define MTOUCH_S0_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S0_OVERSAMPLING               32u
    /*** Sensor_AN10 ***/
    #define MTOUCH_S1_ADCON0_SENSOR              ( 0xa<<2 | 0x1 )
    #define MTOUCH_S1_REF_ADCON0                 ( 0xc<<2 | 0x1 )
    #define MTOUCH_S1_LAT                        LATB
    #define MTOUCH_S1_TRIS                       TRISB
    #define MTOUCH_S1_PIN                        1
    #define MTOUCH_S1_REF_LAT                    LATB
    #define MTOUCH_S1_REF_PIN                    0
    #define MTOUCH_S1_GUARD_LAT                  LATA
    #define MTOUCH_S1_GUARD_PIN                  5
    #define MTOUCH_S1_PRECHARGE_TIME             32u
    #define MTOUCH_S1_ACQUISITION_TIME           16u
    #define MTOUCH_S1_SWITCH_TIME                0u
    #define MTOUCH_S1_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S1_OVERSAMPLING               32u
    /*** Sensor_AN8 ***/
    #define MTOUCH_S2_ADCON0_SENSOR              ( 0x8<<2 | 0x1 )
    #define MTOUCH_S2_REF_ADCON0                 ( 0xa<<2 | 0x1 )
    #define MTOUCH_S2_LAT                        LATB
    #define MTOUCH_S2_TRIS                       TRISB
    #define MTOUCH_S2_PIN                        2
    #define MTOUCH_S2_REF_LAT                    LATB
    #define MTOUCH_S2_REF_PIN                    1
    #define MTOUCH_S2_GUARD_LAT                  LATA
    #define MTOUCH_S2_GUARD_PIN                  5
    #define MTOUCH_S2_PRECHARGE_TIME             32u
    #define MTOUCH_S2_ACQUISITION_TIME           16u
    #define MTOUCH_S2_SWITCH_TIME                0u
    #define MTOUCH_S2_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S2_OVERSAMPLING               32u
    /*** Sensor_AN9 ***/
    #define MTOUCH_S3_ADCON0_SENSOR              ( 0x9<<2 | 0x1 )
    #define MTOUCH_S3_REF_ADCON0                 ( 0x8<<2 | 0x1 )
    #define MTOUCH_S3_LAT                        LATB
    #define MTOUCH_S3_TRIS                       TRISB
    #define MTOUCH_S3_PIN                        3
    #define MTOUCH_S3_REF_LAT                    LATB
    #define MTOUCH_S3_REF_PIN                    2
    #define MTOUCH_S3_GUARD_LAT                  LATA
    #define MTOUCH_S3_GUARD_PIN                  5
    #define MTOUCH_S3_PRECHARGE_TIME             32u
    #define MTOUCH_S3_ACQUISITION_TIME           16u
    #define MTOUCH_S3_SWITCH_TIME                0u
    #define MTOUCH_S3_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S3_OVERSAMPLING               32u
    /*** Sensor_AN11 ***/
    #define MTOUCH_S4_ADCON0_SENSOR              ( 0xb<<2 | 0x1 )
    #define MTOUCH_S4_REF_ADCON0                 ( 0x9<<2 | 0x1 )
    #define MTOUCH_S4_LAT                        LATB
    #define MTOUCH_S4_TRIS                       TRISB
    #define MTOUCH_S4_PIN                        4
    #define MTOUCH_S4_REF_LAT                    LATB
    #define MTOUCH_S4_REF_PIN                    3
    #define MTOUCH_S4_GUARD_LAT                  LATA
    #define MTOUCH_S4_GUARD_PIN                  5
    #define MTOUCH_S4_PRECHARGE_TIME             32u
    #define MTOUCH_S4_ACQUISITION_TIME           16u
    #define MTOUCH_S4_SWITCH_TIME                0u
    #define MTOUCH_S4_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S4_OVERSAMPLING               32u
    /*** Sensor_AN13 ***/
    #define MTOUCH_S5_ADCON0_SENSOR              ( 0xd<<2 | 0x1 )
    #define MTOUCH_S5_REF_ADCON0                 ( 0xb<<2 | 0x1 )
    #define MTOUCH_S5_LAT                        LATB
    #define MTOUCH_S5_TRIS                       TRISB
    #define MTOUCH_S5_PIN                        5
    #define MTOUCH_S5_REF_LAT                    LATB
    #define MTOUCH_S5_REF_PIN                    4
    #define MTOUCH_S5_GUARD_LAT                  LATA
    #define MTOUCH_S5_GUARD_PIN                  5
    #define MTOUCH_S5_PRECHARGE_TIME             32u
    #define MTOUCH_S5_ACQUISITION_TIME           16u
    #define MTOUCH_S5_SWITCH_TIME                0u
    #define MTOUCH_S5_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S5_OVERSAMPLING               32u
    /*** Sensor_AN3 ***/
    #define MTOUCH_S6_ADCON0_SENSOR              ( 0x3<<2 | 0x1 )
    #define MTOUCH_S6_REF_ADCON0                 ( 0xd<<2 | 0x1 )
    #define MTOUCH_S6_LAT                        LATA
    #define MTOUCH_S6_TRIS                       TRISA
    #define MTOUCH_S6_PIN                        3
    #define MTOUCH_S6_REF_LAT                    LATB
    #define MTOUCH_S6_REF_PIN                    5
    #define MTOUCH_S6_GUARD_LAT                  LATA
    #define MTOUCH_S6_GUARD_PIN                  5
    #define MTOUCH_S6_PRECHARGE_TIME             32u
    #define MTOUCH_S6_ACQUISITION_TIME           16u
    #define MTOUCH_S6_SWITCH_TIME                0u
    #define MTOUCH_S6_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S6_OVERSAMPLING               32u
    /*** Sensor_AN2 ***/
    #define MTOUCH_S7_ADCON0_SENSOR              ( 0x2<<2 | 0x1 )
    #define MTOUCH_S7_REF_ADCON0                 ( 0x3<<2 | 0x1 )
    #define MTOUCH_S7_LAT                        LATA
    #define MTOUCH_S7_TRIS                       TRISA
    #define MTOUCH_S7_PIN                        2
    #define MTOUCH_S7_REF_LAT                    LATA
    #define MTOUCH_S7_REF_PIN                    3
    #define MTOUCH_S7_GUARD_LAT                  LATA
    #define MTOUCH_S7_GUARD_PIN                  5
    #define MTOUCH_S7_PRECHARGE_TIME             32u
    #define MTOUCH_S7_ACQUISITION_TIME           16u
    #define MTOUCH_S7_SWITCH_TIME                0u
    #define MTOUCH_S7_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S7_OVERSAMPLING               32u
    /*** Sensor_AN1 ***/
    #define MTOUCH_S8_ADCON0_SENSOR              ( 0x1<<2 | 0x1 )
    #define MTOUCH_S8_REF_ADCON0                 ( 0x2<<2 | 0x1 )
    #define MTOUCH_S8_LAT                        LATA
    #define MTOUCH_S8_TRIS                       TRISA
    #define MTOUCH_S8_PIN                        1
    #define MTOUCH_S8_REF_LAT                    LATA
    #define MTOUCH_S8_REF_PIN                    2
    #define MTOUCH_S8_GUARD_LAT                  LATA
    #define MTOUCH_S8_GUARD_PIN                  5
    #define MTOUCH_S8_PRECHARGE_TIME             32u
    #define MTOUCH_S8_ACQUISITION_TIME           16u
    #define MTOUCH_S8_SWITCH_TIME                0u
    #define MTOUCH_S8_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S8_OVERSAMPLING               32u
    /*** Sensor_AN0 ***/
    #define MTOUCH_S9_ADCON0_SENSOR              ( 0x0<<2 | 0x1 )
    #define MTOUCH_S9_REF_ADCON0                 ( 0x1<<2 | 0x1 )
    #define MTOUCH_S9_LAT                        LATA
    #define MTOUCH_S9_TRIS                       TRISA
    #define MTOUCH_S9_PIN                        0
    #define MTOUCH_S9_REF_LAT                    LATA
    #define MTOUCH_S9_REF_PIN                    1
    #define MTOUCH_S9_GUARD_LAT                  LATA
    #define MTOUCH_S9_GUARD_PIN                  5
    #define MTOUCH_S9_PRECHARGE_TIME             32u
    #define MTOUCH_S9_ACQUISITION_TIME           16u
    #define MTOUCH_S9_SWITCH_TIME                0u
    #define MTOUCH_S9_DISCON_TIME                3u
    /*-----------------------------------------------------------------------------*/
    #define MTOUCH_S9_OVERSAMPLING               32u
    #define MTOUCH_SENSOR_ACTIVE_THRESHOLD               100u  

    /* 
     * =======================================================================
     * Button Parameters
     * =======================================================================
     */

    #define MTOUCH_BUTTON_READING_GAIN              ((uint8_t)4u)
    #define MTOUCH_BUTTON_BASELINE_GAIN             ((uint8_t)4u)
    #define MTOUCH_BUTTON_BASELINE_INIT             ((mtouch_button_baselinecounter_t)16u)
    #define MTOUCH_BUTTON_BASELINE_RATE             ((mtouch_button_baselinecounter_t)64u)
    #define MTOUCH_BUTTON_BASELINE_HOLD             ((mtouch_button_baselinecounter_t)1024u)
    #define MTOUCH_BUTTON_NEGATIVEDEVIATION         ((mtouch_button_statecounter_t)8u)
    #define MTOUCH_BUTTON_PRESSTIMEOUT              ((mtouch_button_statecounter_t)500u)
    #define MTOUCH_BUTTON_DEBOUNCE_COUNT            (4u)

    #define MTOUCH_BUTTON_SENSOR_Slider1_Seg0             Sensor_AN13
    #define MTOUCH_BUTTON_SENSOR_Slider1_Seg1             Sensor_AN0
    #define MTOUCH_BUTTON_SENSOR_Slider1_Seg2             Sensor_AN1
    #define MTOUCH_BUTTON_SENSOR_Slider1_Seg3             Sensor_AN2
    #define MTOUCH_BUTTON_SENSOR_Slider1_Seg4             Sensor_AN3
    #define MTOUCH_BUTTON_SENSOR_Slider2_Seg0             Sensor_AN11
    #define MTOUCH_BUTTON_SENSOR_Slider2_Seg1             Sensor_AN9
    #define MTOUCH_BUTTON_SENSOR_Slider2_Seg2             Sensor_AN8
    #define MTOUCH_BUTTON_SENSOR_Slider2_Seg3             Sensor_AN10
    #define MTOUCH_BUTTON_SENSOR_Slider2_Seg4             Sensor_AN12

    #define MTOUCH_BUTTON_THRESHOLD_Slider1_Seg0          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider1_Seg1          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider1_Seg2          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider1_Seg3          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider1_Seg4          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider2_Seg0          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider2_Seg1          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider2_Seg2          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider2_Seg3          25u
    #define MTOUCH_BUTTON_THRESHOLD_Slider2_Seg4          25u
    
    #define MTOUCH_BUTTON_SCALING_Slider1_Seg0            1u
    #define MTOUCH_BUTTON_SCALING_Slider1_Seg1            1u
    #define MTOUCH_BUTTON_SCALING_Slider1_Seg2            1u
    #define MTOUCH_BUTTON_SCALING_Slider1_Seg3            1u
    #define MTOUCH_BUTTON_SCALING_Slider1_Seg4            1u
    #define MTOUCH_BUTTON_SCALING_Slider2_Seg0            1u
    #define MTOUCH_BUTTON_SCALING_Slider2_Seg1            1u
    #define MTOUCH_BUTTON_SCALING_Slider2_Seg2            1u
    #define MTOUCH_BUTTON_SCALING_Slider2_Seg3            1u
    #define MTOUCH_BUTTON_SCALING_Slider2_Seg4            1u

    #define MTOUCH_BUTTON_HYSTERESIS_Slider1_Seg0     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider1_Seg1     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider1_Seg2     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider1_Seg3     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider1_Seg4     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider2_Seg0     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider2_Seg1     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider2_Seg2     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider2_Seg3     HYST_50_PERCENT
    #define MTOUCH_BUTTON_HYSTERESIS_Slider2_Seg4     HYST_50_PERCENT
    

    /* 
     * =======================================================================
     * Slider Parameters
     * =======================================================================
     */

  /**  Config:  Slider1 **/
    /* Slider Type <0-65534>
     * Type of the slider
     * Range: MTOUCH_TYPE_SLIDER or MTOUCH_TYPE_WHEEL
     */
    #define Slider1_TYPE                  MTOUCH_TYPE_SLIDER 
    /* Start Segment <0-65534>
     * Start Segment of the slider
     * Range: 0 to 65534
     */
    #define Slider1_START_SEGMENT         Slider1_Seg0    
    /* Number of Channel <0-255>
     * Number of Channels for the slider
     * Range: 0 to 255
     */
    #define Slider1_NUM_SEGMENTS          5u
    /*  Position Resolution 
     *  Full scale position resolution reported
     *  RESOL_2_BIT - RESOL_12_BIT
     */
    #define Slider1_RESOLUTION            7
    /*  Position Deadband Percentage
     *  Full scale position deadband Percentage
     *  DB_NONE - DB_15_PERCENT
     */
    #define Slider1_DEADBAND              2
    /* Position Hysteresis <0-255>
     * The minimum travel distance to be reported after contact or direction change
     */
    #define Slider1_POS_HYST              5u
    /* Contact Threshold <0-65534>
     * The minimum contact size measurement for persistent contact tracking.
     * Contact size is the sum of neighbouring Segments touch deltas forming the touch contact.
     * By default, contact Threshold parameter should be set equal to threshold value of the underlying keys.
     * Then the parameter has to be tuned based on the actual contact size of the touch when moved over the slider.
     */
    #define Slider1_THRESHOLD             100u


  /**  Config:  Slider2 **/
    /* Slider Type <0-65534>
     * Type of the slider
     * Range: MTOUCH_TYPE_SLIDER or MTOUCH_TYPE_WHEEL
     */
    #define Slider2_TYPE                  MTOUCH_TYPE_SLIDER 
    /* Start Segment <0-65534>
     * Start Segment of the slider
     * Range: 0 to 65534
     */
    #define Slider2_START_SEGMENT         Slider2_Seg0    
    /* Number of Channel <0-255>
     * Number of Channels for the slider
     * Range: 0 to 255
     */
    #define Slider2_NUM_SEGMENTS          5u
    /*  Position Resolution 
     *  Full scale position resolution reported
     *  RESOL_2_BIT - RESOL_12_BIT
     */
    #define Slider2_RESOLUTION            7
    /*  Position Deadband Percentage
     *  Full scale position deadband Percentage
     *  DB_NONE - DB_15_PERCENT
     */
    #define Slider2_DEADBAND              2
    /* Position Hysteresis <0-255>
     * The minimum travel distance to be reported after contact or direction change
     */
    #define Slider2_POS_HYST              5u
    /* Contact Threshold <0-65534>
     * The minimum contact size measurement for persistent contact tracking.
     * Contact size is the sum of neighbouring Segments touch deltas forming the touch contact.
     * By default, contact Threshold parameter should be set equal to threshold value of the underlying keys.
     * Then the parameter has to be tuned based on the actual contact size of the touch when moved over the slider.
     */
    #define Slider2_THRESHOLD             100u





#endif // MTOUCH_CONFIG_H
/**
 End of File
*/
