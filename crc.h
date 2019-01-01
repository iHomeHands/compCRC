#pragma once
#ifndef CRC_H_INCLUDED
    #define CRC_H_INCLUDED

    #include <stdint.h>

/*! \file crc.h
Интерфейс модуля расчёта контрольно суммы.
*/

//!
enum {
    CRC_ERROR = 0,
    CRC_OK
};

//! Указатель на функцию чтения байта из Flash памяти.
typedef uint8_t (*TReadFlash)(uint32_t Adr);

/*! Вычисление контрольной суммы блока памяти в ОЗУ
\param Buffer Блок памяти
\param Size Размер
*/
uint16_t CRC16(void *Buffer, uint16_t Size);

/*! Проверить контрольную сумму блока памяти RAM.
Проверяет контрольную сумму блока памяти RAM, расположенную в последних двух байтах
этого блока.
\param Buffer Блок памяти
\param Size Размер блока вместе с контрольной суммой.
\return CRC_OK, если контрольная сумма блока собпадает; CRC_ERROR, если контрольная сумма блока не
        совпадает.
*/
uint8_t CheckCRC16(void *Buffer, uint16_t Size);

/*! Добавить контрольную сумму к блоку памяти RAM.
Добавляет в последние два байта блока памяти контрольную сумму предыдущий
Size-2 байтов блока.
\param Buffer Блок памяти
\param Size Размер блока вместе с контрольной суммой.
*/
void AddCRC16(void *Buffer, uint16_t Size);

//!
uint16_t CRC16byStep(void *Buffer, uint16_t Size, uint16_t StartCRC16);

//!
uint16_t CRC16byStepFromFunctionRead(uint32_t Adr, uint32_t Size, uint16_t StartCRC16, TReadFlash ReadFlash);

//!
uint32_t CRC32byStep(void *Buffer, uint16_t Size, uint32_t StartCRC32, uint8_t isEndStep);

//!
uint32_t CRC32byStepFromFunctionRead(uint32_t Adr, uint32_t Size, uint32_t StartCRC32, TReadFlash ReadFlash, uint8_t isEndStep);

#endif
