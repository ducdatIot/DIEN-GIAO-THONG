/*******************************************************************************
* File Name: analog_5.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_analog_5_H) /* Pins analog_5_H */
#define CY_PINS_analog_5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "analog_5_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} analog_5_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   analog_5_Read(void);
void    analog_5_Write(uint8 value);
uint8   analog_5_ReadDataReg(void);
#if defined(analog_5__PC) || (CY_PSOC4_4200L) 
    void    analog_5_SetDriveMode(uint8 mode);
#endif
void    analog_5_SetInterruptMode(uint16 position, uint16 mode);
uint8   analog_5_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void analog_5_Sleep(void); 
void analog_5_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(analog_5__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define analog_5_DRIVE_MODE_BITS        (3)
    #define analog_5_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - analog_5_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the analog_5_SetDriveMode() function.
         *  @{
         */
        #define analog_5_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define analog_5_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define analog_5_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define analog_5_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define analog_5_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define analog_5_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define analog_5_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define analog_5_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define analog_5_MASK               analog_5__MASK
#define analog_5_SHIFT              analog_5__SHIFT
#define analog_5_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in analog_5_SetInterruptMode() function.
     *  @{
     */
        #define analog_5_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define analog_5_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define analog_5_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define analog_5_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(analog_5__SIO)
    #define analog_5_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(analog_5__PC) && (CY_PSOC4_4200L)
    #define analog_5_USBIO_ENABLE               ((uint32)0x80000000u)
    #define analog_5_USBIO_DISABLE              ((uint32)(~analog_5_USBIO_ENABLE))
    #define analog_5_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define analog_5_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define analog_5_USBIO_ENTER_SLEEP          ((uint32)((1u << analog_5_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << analog_5_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_5_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << analog_5_USBIO_SUSPEND_SHIFT)))
    #define analog_5_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << analog_5_USBIO_SUSPEND_DEL_SHIFT)))
    #define analog_5_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(analog_5__PC)
    /* Port Configuration */
    #define analog_5_PC                 (* (reg32 *) analog_5__PC)
#endif
/* Pin State */
#define analog_5_PS                     (* (reg32 *) analog_5__PS)
/* Data Register */
#define analog_5_DR                     (* (reg32 *) analog_5__DR)
/* Input Buffer Disable Override */
#define analog_5_INP_DIS                (* (reg32 *) analog_5__PC2)

/* Interrupt configuration Registers */
#define analog_5_INTCFG                 (* (reg32 *) analog_5__INTCFG)
#define analog_5_INTSTAT                (* (reg32 *) analog_5__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define analog_5_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(analog_5__SIO)
    #define analog_5_SIO_REG            (* (reg32 *) analog_5__SIO)
#endif /* (analog_5__SIO_CFG) */

/* USBIO registers */
#if !defined(analog_5__PC) && (CY_PSOC4_4200L)
    #define analog_5_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define analog_5_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define analog_5_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define analog_5_DRIVE_MODE_SHIFT       (0x00u)
#define analog_5_DRIVE_MODE_MASK        (0x07u << analog_5_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins analog_5_H */


/* [] END OF FILE */
