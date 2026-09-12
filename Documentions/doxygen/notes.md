so basicly doxygen is a way of comenting to make it easzier for everyone to understand the code better
to use it use these commands

documentaion 
```
@brief — short one-line summary of a function/class
@details (or just a blank line after brief) — extended description
@param — describes a function parameter, e.g. @param x the input value
@param[in] / @param[out] / @param[in,out] — specifies parameter direction
@return (or @returns) — describes what a function returns
@retval — describes a specific return value and its meaning
@throw / @exception — documents an exception the function may throw
```
orgainzation
```
@file — documents the current file (name, purpose)
@author — names the author of the code
@date — documents the date of creation/modification
@version — states the version number
@since — notes which version introduced this feature
@deprecated — marks something as deprecated, with optional reason
@todo — flags a pending task
@bug — flags a known bug
@warning — highlights something the user must be careful about
@note — adds a side note or extra tip
```

these are no not used as much but still maybe used later:-

Grouping / structure
```
@defgroup — defines a named group/module for related items
@ingroup — adds an item to an existing group
@addtogroup — reopens a group to add more members
@namespace — documents a namespace
@class — documents a class explicitly
@struct — documents a struct explicitly
@enum — documents an enum
@var — documents a variable
```
Cross-referencing
```
@see — points to related functions/docs
@ref — creates a link/reference to another documented item
@relates — links a non-member function to a class's documentation
```
Code examples
```
@code / @endcode — wraps a block of example code
@example — marks a file as an example source, shown in the Examples page
```
Formatting
```
@a — italicizes the next word (for emphasis, e.g. variable names in text)
@b — bolds the next word
@c — formats the next word as inline code/typewriter font
```

any comennting from now on will be done in this way 

so at start of any file

/** 
* @file        
uart_driver.h 
* @brief     UART driver interface. 
* @details  Provides initialization and communication APIs for UART peripheral. 
* @version 1.0.0 
* @author   <DeveloperName> <Email> 
* @date      2025-08-24 
*  @copyright Copyright (c) 2025 , Gestell Company 
*/

then in each function in interface 

/** 
* @fn         
UART_Send 
* @brief     Sends data over UART. 
* @details  Update the tx Buffer with data will be Sent and Waiting until Data Transimate  
* @param  data Pointer to the data buffer. 
* @param length Number of bytes to send. 
* @return int  this function return Value to indicate the Status for Tx Operation  
* @retval   this  function return 0 if success, -1 if error 
* @warning UART_Init() must be called before this function. 
*/ 
int UART_Send(const uint8_t *data, uint16_t length); 

then for macors , enums , structs too

and remeber to use these more often 

@todo → For pending tasks. 
@deprecated → For old APIs that should not be used. 
@bug → For known issues. 
@note → For important usage notes.

