#include "dorca30_api.h"
#include "dorca30_function.h"
#include "global.h"
#include "./include/aes.h"
#include <string.h>
#include <stdio.h>
extern int cs;
void RSCreate01(void)
{
	int i = 0;
	int j = 0;
	int success =  1;
	unsigned char tx_data[64];
	unsigned char rx_data[64];

	memset(tx_data,0,64);
	memset(rx_data,0,64);

	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x03;
	tspi_interface(cs, ADDR_NOR_W,RG_AES_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x09;
	tspi_interface(cs, ADDR_NOR_W,RG_ST0_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x07;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_RNDGEN_USER         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(100);
	tx_data[0] = 0x04;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_RND_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(100);
	tspi_interface(cs, ADDR_NOR_R,RG_EEBUF320         , 0, 0, 0, 0, tx_data, rx_data, 32);
	tx_data[0] = 0x02;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x04;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_RND_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(100);
	tspi_interface(cs, ADDR_NOR_R,RG_EEBUF320         , 0, 0, 0, 0, tx_data, rx_data, 32);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_RND_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);



	// ---- Write IV ----


	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_AES_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	// ---- Write KEY ----
	tx_data[0] = 0x03;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(30);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x08;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x02;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(70);
	tspi_interface(cs, ADDR_NOR_R,RG_EEBUF320         , 0, 0, 0, 0, tx_data, rx_data, 32);
	tx_data[0] = 0x03;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(70);



	Delay_ms(8);

	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(50);
	tx_data[0] = 0x10;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	// AES ENC KEY SET
	tx_data[0] = 0x03;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(30);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	//set to RSCreate 
	tx_data[0] = 0x08;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x02;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(70);
	//RSCREATE_ENC2
	tx_data[0] = 0x03;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(70);
	Delay_ms(8);
	tx_data[0] = 0x01;
	tspi_interface(cs,ADDR_NOR_W, RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x01;
	tspi_interface(cs,ADDR_NOR_W, RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs,ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);

	tx_data[0] = 0x01;
	tspi_interface(cs,ADDR_NOR_W, RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x01;
	tspi_interface(cs,ADDR_NOR_W, RG_ST0_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs,ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(50);
	EndOperation();
	return ;
}

void RSCreate23(unsigned char *pUservalue32A,unsigned char *pUservalue32B)
{
	int i = 0;
	int j = 0;
	int success =  1;
	unsigned char tx_data[64];
	unsigned char rx_data[64];
	tx_data[0] = 0x09;
	tspi_interface(cs, ADDR_NOR_W,RG_ST0_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x07;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	//set to RSCreate
	tx_data[0] = 0x08;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x07;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);

	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	j = 31;
	for( i = 0;i < 32; i++)
	{
		tx_data[i] = pUservalue32A[j--];
	}
	tspi_interface(cs, ADDR_NOR_W,RG_EEBUF500         , 0, 0, 0, 0, tx_data, rx_data, 32);
	tx_data[0] = 0x20;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x04;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_ms(8);
	//Write time to EEPROM
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	/// set to RSCREATE_WR_EEP state for RS_x3

	tx_data[0] = 0x07;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	j = 31;
	for( i = 0;i < 32; i++)
	{
		tx_data[i] = pUservalue32B[j--];
	}
	tspi_interface(cs, ADDR_NOR_W,RG_EEBUF500         , 0, 0, 0, 0, tx_data, rx_data, 32);
	tx_data[0] = 0x30;
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x04;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_ms(8);
	//Write time to EEPROM
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST3_SYMCIP_RSCREATE_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST2_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	EndOperation();
	Delay_us(50);
	return;	
}


void RSSHAReadIdx(int index, unsigned char *out)
{

	int i = 0;
	int j = 0;
	int k = 0;
	int success =  1;
	unsigned char tx_data[64];
	unsigned char rx_data[64];
	unsigned char RS_RD_RND[4];
	unsigned char RS_RND_DATA[4];
	unsigned char Dummy_15BYTE[15];
	unsigned char Trail;
	unsigned char LEN[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xB8};
	Trail = 0x80;
	memset(RS_RD_RND,0,4);
	memset(RS_RND_DATA,0,4);
	memset(Dummy_15BYTE,0,15);
	tx_data[0] = 0x00 + (index << 4);
	tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x09;
	tspi_interface(cs, ADDR_NOR_W,RG_ST0_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x08;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	j = 7;
	for(i = 0; i <8; i++)
		tx_data[i] = LEN[j--];
	tx_data[8]	= Trail;
	j = 14;
	for(i = 9; i < 24; i++)
		tx_data[i] = Dummy_15BYTE[j--];
	j = 3;
	for(i = 24; i < 28; i++)
		tx_data[i] = RS_RND_DATA[j--];		
	j = 3;
	for(i = 28; i < 32; i++)
		tx_data[i] = RS_RD_RND[j--];		

	tspi_interface(cs, ADDR_NOR_W,RG_EEBUF400         , 0, 0, 0, 0, tx_data, rx_data, 32);
	Delay_us(100);
	tspi_interface(cs, ADDR_NOR_R,RG_ACCESS         , 0, 0, 0, 0, tx_data, rx_data, 1);
	Delay_us(100);
	tspi_interface(cs, ADDR_NOR_R,RG_EEBUF400         , 0, 0, 0, 0, tx_data, rx_data, 32);
	j = 31;
	for( i = 0; i < 32; i++)
		out[i] = rx_data[j--];
	tx_data[0] = 0x01;
	tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
	EndOperation();
	return;	

}


void RSDirectRead13(unsigned char *pRS, int index,unsigned char *UID_PW_PT)
{
	int i = 0;
	int j = 0;
	unsigned int inst = 0;
	int k = 0;
	int success =  1;
	unsigned char tx_data[64];
	unsigned char rx_data[64];
	unsigned char achCTPW[16];
	unsigned char temp_addr[2];

	AES_KEY aes128_ekey,aes128_dkey;	
	AES_set_encrypt_key(gAES_KEY_X1, 128, &aes128_ekey);
	AES_ecb_encrypt(UID_PW_PT, achCTPW, &aes128_ekey, AES_ENCRYPT);
	//for(i = 0; i < 4; i++)
	{	
		GetPermission(RG_PERM_UID_PASS,gUID_PW_PT,KEY_INDEX);
		printf("\r\n 	GetPermissionByPW(UID_PW_CT, RG_PERM_UID_PASS);");
		tx_data[0] = 0x09;
		tspi_interface(cs, ADDR_NOR_W,RG_ST0_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
		tx_data[0] = 0x00 + (index << 4);
		tspi_interface(cs, ADDR_NOR_W,RG_RSCREATE_CTRL         , 0, 0, 0, 0, tx_data, rx_data, 1);
		tx_data[0] = 0x09;
		tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE         , 0, 0, 0, 0, tx_data, rx_data, 1);
		tspi_interface(cs, ADDR_NOR_R,RG_EEBUF400         , 0, 0, 0, 0, tx_data, rx_data, 32);
		memset(tx_data,0,32);
		//		memcpy(RS,rx_data,32);
		reversebuffer(pRS, rx_data, 32);
		printf("\r\n RSx%d",index);
		PrintByte(rx_data,16);
		tspi_interface(cs, ADDR_NOR_W,RG_EEBUF400         , 0, 0, 0, 0, tx_data, rx_data, 32);		

		tx_data[0] = 0x01;
		tspi_interface(cs, ADDR_NOR_W,RG_ST1_SYMCIP_OPMODE		   , 0, 0, 0, 0, tx_data, rx_data, 1);	
		ReleasePermision();
		EndOperation();
	}		
	return;	
}

void GetRandomNumber(unsigned char *pOut)
{
	int toggle = 0;
	unsigned int i;
	int k = 0;
	int j = 0;
	int ii = 0;
	unsigned char inst = 0x00;
	unsigned char addr[2] = { 0x06, 0x04};
	unsigned char tx_data[64];
	unsigned char rx_data[64];
	unsigned char result[16];

	for( i=0; i<64; i++)
	{
		tx_data[i] = 0x00;
		rx_data[i] = 0x00;
	}
	tx_data[0] = 0x3;
	tspi_interface(cs, ADDR_NOR_W, RG_AES_CTRL, 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x8;
	tspi_interface(cs, ADDR_NOR_W, RG_ST0_OPMODE, 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0;
	tspi_interface(cs, ADDR_NOR_W, RG_RNDGEN_USER, 0, 0, 0, 0, tx_data, rx_data, 1);
	tx_data[0] = 0x2;
	tspi_interface(cs, ADDR_NOR_W, RG_ST1_RND_OPMODE, 0, 0, 0, 0, tx_data, rx_data, 1);
	delay_us(2);
	tx_data[0] = 0x00;	
	tspi_interface(cs, ADDR_NOR_R, RG_EEBUF320, 0, 0, 0, 0, tx_data, rx_data, 16);
	memcpy(pOut,rx_data,16);
	tx_data[0] = 0x00;
	tspi_interface(cs, ADDR_NOR_W, RG_ST1_RND_OPMODE, 0, 0, 0, 0, tx_data, rx_data, 1);

	EndOperation();
	return;	

}