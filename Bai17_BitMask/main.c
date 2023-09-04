/*
*File: main.c
*Author: Nguyen Gia Phuc
*Date: 29/08/2023
*Description: Practice Bit Maskg
*/
#include <stdio.h>
#include <stdint.h>

uint8_t Bag = 0;

typedef enum{
    AO = 1 << 0,
    QUAN = 1 << 1,
    VAY = 1 << 2,
    DAM = 1 << 3,
    NHAN = 1 << 4,
    VONG_TAY = 1 << 5,
    GIAY = 1 << 6,
    TUI = 1 << 7,
}Do_dung_ca_nhan;

void Add_gio_hang(uint8_t *GIO_HANG, Do_dung_ca_nhan item){
    *GIO_HANG |= item;
}

void Show_item(uint8_t GIO_HANG){
    printf("\nTrong gio hang co: ");
    for(int i = 0; i<8; i++){
        switch (i)
        {
        case 0:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nAO");
            break;
        case 1:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nQUAN");
            break;
        case 2:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nVAY");
            break;
        case 3:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nDAM");
            break;
        case 4:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nNHAN");
            break;
        case 5:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nVONG TAY");
            break;
        case 6:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nGIAY");
            break;
        case 7:
            if (((GIO_HANG >> i) & 0X01) == 0X01) printf("\nTUI");
            break;
        default:
            break;
        }
    }
}

void Check_item(uint8_t GIO_HANG){ 
    uint8_t item_need_to_check;  
    uint8_t demand;
    printf("\nDo you want to check any item ?");
    printf("\nPlease press 1 if you want or else press 0: ");scanf("%d",&demand);
    if(demand){
        printf("\n0.A0 1.QUAN 2.VAY 3.DAM 4.NHAN 5.VONG TAY 6.GIAY 7.TUI");
        printf("\nPlease enter the ID of item you want to check: ");
        scanf("%d",&item_need_to_check);
        switch (item_need_to_check)
        {
        case 0:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nAO: CO");
            else printf("\nAO: KHONG CO");
            break;
        case 1:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nQUAN: CO");
            else printf("\nQUAN: KHONG CO");
            break;
        case 2:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nVAY: CO");
            else printf("\nVAY: KHONG CO");
            break;
        case 3:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nDAM: CO");
            else printf("\nDAM: KHONG CO");
            break;
        case 4:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nNHAN: CO");
            else printf("\nNHAN: KHONG CO");
            break;
        case 5:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nVONG TAY: CO");
            else printf("\nVONG TAY: KHONG CO");
            break;
        case 6:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nGIAY: CO");
            else printf("\nGIAY: KHONG CO");
            break;
        case 7:
            if (((GIO_HANG >> item_need_to_check) & 0X01) == 0X01) printf("\nTUI: CO");
            else printf("\nTUI: KHONG CO");
            break;
        default:
            break;
        }
    }
}

int main(int argc, char const *argv[])
{  
    Add_gio_hang(&Bag,AO|QUAN|VAY);
    Check_item(Bag);
    Show_item(Bag);
    return 0;
}
