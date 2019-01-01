#pragma once
#ifndef CRC_H_INCLUDED
    #define CRC_H_INCLUDED

    #include <stdint.h>

/*! \file crc.h
��������� ������ ������� ���������� �����.
*/

//!
enum {
    CRC_ERROR = 0,
    CRC_OK
};

//! ��������� �� ������� ������ ����� �� Flash ������.
typedef uint8_t (*TReadFlash)(uint32_t Adr);

/*! ���������� ����������� ����� ����� ������ � ���
\param Buffer ���� ������
\param Size ������
*/
uint16_t CRC16(void *Buffer, uint16_t Size);

/*! ��������� ����������� ����� ����� ������ RAM.
��������� ����������� ����� ����� ������ RAM, ������������� � ��������� ���� ������
����� �����.
\param Buffer ���� ������
\param Size ������ ����� ������ � ����������� ������.
\return CRC_OK, ���� ����������� ����� ����� ���������; CRC_ERROR, ���� ����������� ����� ����� ��
        ���������.
*/
uint8_t CheckCRC16(void *Buffer, uint16_t Size);

/*! �������� ����������� ����� � ����� ������ RAM.
��������� � ��������� ��� ����� ����� ������ ����������� ����� ����������
Size-2 ������ �����.
\param Buffer ���� ������
\param Size ������ ����� ������ � ����������� ������.
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
