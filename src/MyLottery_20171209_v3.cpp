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
  	// 開設[100][6]的二維陣列來存放100注大樂透彩卷，每注6個號碼(1~49)
	// 每注隨機產生的號碼都不能重複。 
	int MyLottery[100][6]; //存放電腦亂數產生的簽號 
	int MyLotteryCSV[100][6]; //存放從CSV檔案讀入的簽號 
	//int WinningNumber[7] = {1, 12, 13, 37, 41, 43, 49}; // 本期開獎號碼，最後碼為特別號 
	int WinningNumber[7];
	// Using current time to randomize and try to regenerate the random numbers
    srand(time(NULL));
    
    // 產生亂數，填入MyLottery 
	for (int j = 0; j < 100; j++)
	 {
	 	for(int k = 0; k < 6; k++)
		 {
	 		MyLottery[j][k]= (rand()%49) + 1;
	 		for (int i = 0; i < k; i++) //檢查是否為重複號 
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
	printf("\n#=#=#=#=#=#=#=# 電腦選號：100注的簽號 START #=#=#=#=#=#=#=#=#\n");
	for(int j = 0; j < 100; j++)
	 {
	 	printf("\n第 %03d 注 ： ", j+1);
	  	for (int k = 0; k < 6; k++)
		 {
	  		printf("[%2d] ", MyLottery[j][k]);
	  		Sleep(1);

		 }
		printf("\n");
	 } 
	printf("\n#=#=#=#=#=#=#=# 電腦選號：100注的簽號 END #=#=#=#=#=#=#=#\n");
	printf("\n");
	
	// 將100注號碼寫入MyLottery.csv檔
	printf("\n開始將100注簽號存入MyLottery.csv檔案\n");
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
		    printf("存入第%2d注>>", j+1);
		    Sleep(1);

	     }
	    fclose(fp);
	 	printf("\n一百注都已存入%s\n", fname);
	 }
	else
	 {	
		printf("\nError: There should be very critical problem(s) in your file system!");
	 } 
	 
	printf("\n再從MyLottery.csv將100注簽號讀入存於MyLotteryCSV\n");
	system("pause");
		 
	//從CSV讀入100注號碼 
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
 
	printf("\n#=#=#=#=#=#=#=# 從MyLottery.csv讀出的100注簽號 START #=#=#=#=#=#=#=#=#\n");
	// Then you print it by using nested loops
	for(int j = 0; j < 100; j++)
	 {
	 	printf("\n第 %03d 注 ：", j+1);
	  	for (int k = 0; k < 6; k++)
		 {
	  		printf("[%2d]  ", MyLotteryCSV[j][k]);
	  		Sleep(1);
	  	 }
		printf("\n");
	 } 
	printf("\n#=#=#=#=#=#=#=# 從MyLottery.csv讀出的100注簽號 END #=#=#=#=#=#=#=#\n");
	printf("\n");
	
	// 比對從CSV檔讀出的簽號數字是否是原先存入的號碼 
	printf("驗證從CSV檔讀出的每注簽號碼是否等於電腦亂數產生的選號呢?\n");
	for(int j = 0; j < 100; j++)
	 {
	 	for(int k = 0; k < 6; k++)
	 	 {
	 	 	if(MyLotteryCSV[j][k] != MyLottery[j][k])
	 	 		printf("\n!!!從檔案讀入的簽號與電腦選號不同請檢查程式!!!\n");
		 }
	 }
	printf("\nYES! 所有從CSV檔讀出的每注簽號碼等於電腦亂數產生的選號\n");
	
	// 開始對獎 
	char draw;
	printf("\n#=#=#=#=#=#=#=# 本期開獎資訊 #=#=#=#=#=#=#=#\n");
	for(int i = 0; i < 6; i++)
	 {
	 	printf("請輸入本期第%2d個獎號：", i+1);
		scanf("%d", &WinningNumber[i]);
	 }
	
	printf("\n***您輸入的獎號：%2d, %2d, %2d, %2d, %2d, %2d\n", 
			WinningNumber[0], WinningNumber[1], WinningNumber[2],
			WinningNumber[3], WinningNumber[4], WinningNumber[5]);
	printf("\n請輸入本期的特別號：");
	scanf("%d", &WinningNumber[6]);
	printf("\n***您輸入的特別號：%2d\n", WinningNumber[6]);

	printf("\n#=#=#=#=#=#=#=# 本期開獎資訊 #=#=#=#=#=#=#=#\n");
	
	printf("\n");
	  
	printf("\n#=#=#=#=#=#=#=# 開始對獎 START #=#=#=#=#=#=#=# \n");
	printf("\n調整好心情後，按任一鍵開始\n");
	printf("\n");
	system("pause");
	
	int WinningPrizes = 0;
	int count = 0;
	for(int j = 0; j < 100; j++)
	 {
	   	int x = 0;
	    int y = 0;
		printf("\n第 %3d 注對獎結果：", j+1);
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
		 	
			printf("\033[01;33m恭喜您中頭獎，獨得獎金: 163,352,383元\033[0m\n"); 
		 	WinningPrizes = WinningPrizes + 163352383;
		 	count = count + 1;
		 	Sleep(1000);
		 }
		  	
		else if(x == 5 & y == 1)
		 {
		  	printf("\033[01;33m恭喜您中貳獎，獨得獎金: 3,314,120元\033[0m\n");
		 	WinningPrizes = WinningPrizes + 3314120;
		 	count = count + 1;
		 	Sleep(500);
		 }
		 
		else if(x == 5)
		 {
		  	printf("\033[01;33m恭喜您中參獎，得獎金: 65,827元\033[0m\n");
		 	WinningPrizes = WinningPrizes + 65827;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 4 & y == 1)
		 {
		  	printf("\033[01;33m恭喜您中肆獎，得獎金: 10,579元\033[0m\n");
		 	WinningPrizes = WinningPrizes + 10579;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 4)
		 {
		  	printf("\033[01;33m恭喜您中伍獎，獨得獎金: 2,000元\033[0m\n");
		 	WinningPrizes = WinningPrizes + 2000;
		 	count = count + 1;
		 	Sleep(500);
		 }
		  	
		else if(x == 3 & y == 1)
		 {
		  	printf("\033[01;33m恭喜您中陸獎，獨得獎金: 1,000元\033[0m\n");
		   	WinningPrizes = WinningPrizes + 1000;
		 	count = count + 1;
		 	Sleep(500);
		 }
		
		else if(x == 2 & y == 1)
		 {
		  	printf("\033[01;33m恭喜您中柒獎，得獎金: 400元\033[0m\n");
		  	WinningPrizes = WinningPrizes + 400;
		 	count = count + 1;
		 	Sleep(500);
		 }
		
		else if(x == 3)
		 {
		  	printf("\033[01;33m恭喜您中普獎，得獎金: 400元\033[0m\n");
		  	WinningPrizes = WinningPrizes + 400;
		 	count = count + 1;
		 	Sleep(500);

		 }
		
		else if(x < 3)
		 	printf("很遺憾，這注簽號全摃龜\n");
			Sleep(100);
		} 
	  
	printf("\n!!!本期總共有%2d注得獎\n", count);
	printf("\n!!!本期總共贏得獎金：%d元\n", WinningPrizes);
	if(WinningPrizes < 5000)
		printf("\n\033[01;31m投資回收比率不好，建議您把錢做其他更有利用途。\033[0m\n");
	else
		printf("\n\033[01;33m哇靠，您光靠玩大樂透就賺翻了\033[0m\n");
  
	printf("\n#=#=#=#=#=#=#=#  結束對獎  END #=#=#=#=#=#=#=#\n");


     
	// system("pause");
	// system("dir /s /p");
	return 0;
 }
