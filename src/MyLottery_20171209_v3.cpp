#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <windows.h>
	
int main()
 {
  	// �}�][100][6]���G���}�C�Ӧs��100�`�j�ֳz�m���A�C�`6�Ӹ��X(1~49)
	// �C�`�H�����ͪ����X�����୫�ơC 
	int MyLottery[100][6]; //�s��q���üƲ��ͪ�ñ�� 
	int MyLotteryCSV[100][6]; //�s��qCSV�ɮ�Ū�J��ñ�� 
	//int WinningNumber[7] = {1, 12, 13, 37, 41, 43, 49}; // �����}�����X�A�̫�X���S�O�� 
	int WinningNumber[7];
	// Using current time to randomize and try to regenerate the random numbers
    srand(time(NULL));
    
    // ���ͶüơA��JMyLottery 
	for (int j = 0; j < 100; j++)
	 {
	 	for(int k = 0; k < 6; k++)
		 {
	 		MyLottery[j][k]= (rand()%49) + 1;
	 		for (int i = 0; i < k; i++) //�ˬd�O�_�����Ƹ� 
			 {
				if(MyLottery[j][k] == MyLottery[j][i])
				 {
				 	k--;
					break;
			 	 }
			   
			 } 
		 }
	 }
	
	system("CLS");
	printf("\n#=#=#=#=#=#=#=# �q���︹�G100�`��ñ�� START #=#=#=#=#=#=#=#=#\n");
	for(int j = 0; j < 100; j++)
	 {
	 	printf("\n�� %03d �` �G ", j+1);
	  	for (int k = 0; k < 6; k++)
		 {
	  		printf("[%2d] ", MyLottery[j][k]);
	  		Sleep(1);

		 }
		printf("\n");
	 } 
	printf("\n#=#=#=#=#=#=#=# �q���︹�G100�`��ñ�� END #=#=#=#=#=#=#=#\n");
	printf("\n");
	
	// �N100�`���X�g�JMyLottery.csv��
	printf("\n�}�l�N100�`ñ���s�JMyLottery.csv�ɮ�\n");
	system("pause");
	FILE *fp;
	char fname[120]="MyLottery.csv";
	if( fopen(fname,"rb+")==NULL )    // File does not exist
	 {  printf("\nWarning: File %s does not exist!",fname);
	    // Create the file
	    if( (fp=fopen(fname,"wb"))==NULL )
	     {	printf("\nError: File creation error!");
		 }
		else 
		 {  printf("\nFile %s created successfully...",fname);
			fclose(fp);
		 }
	 }		 

	if( (fp=fopen(fname,"w+"))!=NULL )
	 {  
	 	for( int j = 0; j < 100; j++ )
  	     {        
			fprintf(fp,"%d,%d,%d,%d,%d,%d\n", 
			MyLottery[j][0], MyLottery[j][1], MyLottery[j][2],
			MyLottery[j][3], MyLottery[j][4], MyLottery[j][5]);
		    printf("�s�J��%2d�`>>", j+1);
		    Sleep(1);

	     }
	    fclose(fp);
	 	printf("\n�@�ʪ`���w�s�J%s\n", fname);
	 }
	else
	 {	
		printf("\nError: There should be very critical problem(s) in your file system!");
	 } 
	 
	printf("\n�A�qMyLottery.csv�N100�`ñ��Ū�J�s��MyLotteryCSV\n");
	system("pause");
		 
	//�qCSVŪ�J100�`���X 
	//FILE *fp;
	//char fname[120]="MyLottery.CSV";
	if( fopen(fname,"rb+")==NULL )    // File does not exist
	 {  printf("\nWarning: File %s does not exist!",fname);
	        // Create the file
	    if( (fp=fopen(fname,"wb"))==NULL )
	     {	
		 	printf("\nError: File creation error!");
		 }
		 else 
		 {  
		 	printf("\nFile %s created successfully...",fname);
			fclose(fp);
		 }
	 }	

	int tempstring0, tempstring1, tempstring2, tempstring3, tempstring4, tempstring5;
	if( (fp=fopen(fname,"r"))!=NULL )
	 {  
	 	printf("==================================");
	 	int j = 0;
		while((fscanf(fp, "%d,%d,%d,%d,%d,%d", 
							&tempstring0, &tempstring1, &tempstring2, 
							&tempstring3, &tempstring4, &tempstring5))!=EOF)
		 {
			MyLotteryCSV[j][0] = tempstring0;
			MyLotteryCSV[j][1] = tempstring1;
			MyLotteryCSV[j][2] = tempstring2;
			MyLotteryCSV[j][3] = tempstring3;
			MyLotteryCSV[j][4] = tempstring4;
			MyLotteryCSV[j][5] = tempstring5;
			j = j + 1;
		 }
		fclose(fp);
	 }
	else
	 {  
		printf("\nError: There should be very critical problem(s) in your file system!");
	 } 
 
	printf("\n#=#=#=#=#=#=#=# �qMyLottery.csvŪ�X��100�`ñ�� START #=#=#=#=#=#=#=#=#\n");
	// Then you print it by using nested loops
	for(int j = 0; j < 100; j++)
	 {
	 	printf("\n�� %03d �` �G", j+1);
	  	for (int k = 0; k < 6; k++)
		 {
	  		printf("[%2d]  ", MyLotteryCSV[j][k]);
	  		Sleep(1);
	  	 }
		printf("\n");
	 } 
	printf("\n#=#=#=#=#=#=#=# �qMyLottery.csvŪ�X��100�`ñ�� END #=#=#=#=#=#=#=#\n");
	printf("\n");
	
	// ���qCSV��Ū�X��ñ���Ʀr�O�_�O����s�J�����X 
	printf("���ұqCSV��Ū�X���C�`ñ���X�O�_����q���üƲ��ͪ��︹�O?\n");
	for(int j = 0; j < 100; j++)
	 {
	 	for(int k = 0; k < 6; k++)
	 	 {
	 	 	if(MyLotteryCSV[j][k] != MyLottery[j][k])
	 	 		printf("\n!!!�q�ɮ�Ū�J��ñ���P�q���︹���P���ˬd�{��!!!\n");
		 }
	 }
	printf("\nYES! �Ҧ��qCSV��Ū�X���C�`ñ���X����q���üƲ��ͪ��︹\n");
	
	// �}�l��� 
	char draw;
	printf("\n#=#=#=#=#=#=#=# �����}����T #=#=#=#=#=#=#=#\n");
	for(int i = 0; i < 6; i++)
	 {
	 	printf("�п�J������%2d�Ӽ����G", i+1);
		scanf("%d", &WinningNumber[i]);
	 }
	
	printf("\n***�z��J�������G%2d, %2d, %2d, %2d, %2d, %2d\n", 
			WinningNumber[0], WinningNumber[1], WinningNumber[2],
			WinningNumber[3], WinningNumber[4], WinningNumber[5]);
	printf("\n�п�J�������S�O���G");
	scanf("%d", &WinningNumber[6]);
	printf("\n***�z��J���S�O���G%2d\n", WinningNumber[6]);

	printf("\n#=#=#=#=#=#=#=# �����}����T #=#=#=#=#=#=#=#\n");
	
	printf("\n");
	  
	printf("\n#=#=#=#=#=#=#=# �}�l��� START #=#=#=#=#=#=#=# \n");
	printf("\n�վ�n�߱���A�����@��}�l\n");
	printf("\n");
	system("pause");
	
	int WinningPrizes = 0;
	int count = 0;
	for(int j = 0; j < 100; j++)
	 {
	   	int x = 0;
	    int y = 0;
		printf("\n�� %3d �`������G�G", j+1);
	  	for(int k = 0; k < 6; k++)
	  	 {
	  	    if (MyLotteryCSV[j][k] == WinningNumber[6])
				y = 1;
	  		for(int i = 0; i < 6; i++)
	  	 	 {
	  			if(MyLotteryCSV[j][k] == WinningNumber[i]) 
	  		  	 	x = x + 1;
		 	 }
		 }
		if(x == 6)
		 {
		 	
			printf("\033[01;33m���߱z���Y���A�W�o����: 163,352,383��\033[0m\n"); 
		 	WinningPrizes = WinningPrizes + 163352383;
		 	count = count + 1;
		 	Sleep(1000);
		 }
		  	
		else if(x == 5 & y == 1)
		 {
		  	printf("\033[01;33m���߱z���L���A�W�o����: 3,314,120��\033[0m\n");
		 	WinningPrizes = WinningPrizes + 3314120;
		 	count = count + 1;
		 	Sleep(500);
		 }
		 
		else if(x == 5)
		 {
		  	printf("\033[01;33m���߱z���Ѽ��A�o����: 65,827��\033[0m\n");
		 	WinningPrizes = WinningPrizes + 65827;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 4 & y == 1)
		 {
		  	printf("\033[01;33m���߱z���v���A�o����: 10,579��\033[0m\n");
		 	WinningPrizes = WinningPrizes + 10579;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 4)
		 {
		  	printf("\033[01;33m���߱z������A�W�o����: 2,000��\033[0m\n");
		 	WinningPrizes = WinningPrizes + 2000;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 3 & y == 1)
		 {
		  	printf("\033[01;33m���߱z�������A�W�o����: 1,000��\033[0m\n");
		   	WinningPrizes = WinningPrizes + 1000;
		 	count = count + 1;
		 	Sleep(500);
		 }
		
		else if(x == 2 & y == 1)
		 {
		  	printf("\033[01;33m���߱z���m���A�o����: 400��\033[0m\n");
		  	WinningPrizes = WinningPrizes + 400;
		 	count = count + 1;
		 	Sleep(500);
		 }
		
		else if(x == 3)
		 {
		  	printf("\033[01;33m���߱z�������A�o����: 400��\033[0m\n");
		  	WinningPrizes = WinningPrizes + 400;
		 	count = count + 1;
		 	Sleep(500);

		 }
		
		else if(x < 3)
		 	printf("�ܿ�ѡA�o�`ñ����ݢ�t\n");
			Sleep(100);
		} 
	  
	printf("\n!!!�����`�@��%2d�`�o��\n", count);
	printf("\n!!!�����`�@Ĺ�o�����G%d��\n", WinningPrizes);
	if(WinningPrizes < 5000)
		printf("\n\033[01;31m���^����v���n�A��ĳ�z�������L�󦳧Q�γ~�C\033[0m\n");
	else
		printf("\n\033[01;33m�z�a�A�z���a���j�ֳz�N��½�F\033[0m\n");
  
	printf("\n#=#=#=#=#=#=#=#  �������  END #=#=#=#=#=#=#=#\n");


     
	// system("pause");
	// system("dir /s /p");
	return 0;
 }
