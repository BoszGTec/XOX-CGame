#include <stdio.h>
#include <stdlib.h>

int botp(){
	int bot=rand()%10;
	return bot;
}

int checkgamefull(char tdata[9],char ptype[2],int *gameover){
	int cti=0;
	for(int i=0;i<9;i++){
		if(tdata[i]=='x'|| tdata[i]=='o' ){cti=cti+1;}
	}
	
	if(cti==9){
		*gameover=3;
	}
}


int checkgame(char tdata[9],char ptype[2],int *gameover)
{
	int wintype[8][3]= {
		{0,1,2},{3,4,5},{6,7,8},
		{0,3,6},{1,4,7},{2,5,8},
		{0,4,8},{2,4,6}
	};
	int Wwin=0,p1=0,p2=0;
	
	for(int y=0; y<8; y++) {

		
		p1=0; 
		p2=0;
		for(int x=0; x<3; x++) {
			
		if(tdata[wintype[y][x]]==ptype[0]) {p1+=1;}
		if(tdata[wintype[y][x]]==ptype[1]) {p2+=1;}
		
		}//{}'s for(2)
		if(p1>=3) {y=8;p1=3;}
		if(p2>=3) {y=8;p2=3;}

	}

	
	if(p1>=3) {
		*gameover=1;
	} 
	else if(p2>=3) {
		*gameover=2;
	}
	else{
	  checkgamefull(tdata,ptype,&*gameover);
	}
	*gameover=*gameover;

}

int gentable(char tdata[9],char ptype[2])
{
	int i=0;
	for(int y=0; y<3; y++) {
		printf("  ");
		for(int x=0; x<3; x++) {
			printf("%c",tdata[i]);
			i++;
			if(x<2) {
				printf(" | ");
			}

		}
		if(y<2) {
			printf("\n ____________\n");
		}
	}

}

int titlegame(){
	system("color b");
	char a[6][100]={{"██╗  ██╗ ██████╗ ██╗  ██╗     ██████╗ ██████╗  █████╗ ███╗   ███╗███████╗\n"},
			{"╚██╗██╔╝██╔═══██╗╚██╗██╔╝    ██╔════╝██╔════╝ ██╔══██╗████╗ ████║██╔════╝"},
			{" ╚███╔╝ ██║   ██║ ╚███╔╝     ██║     ██║  ███╗███████║██╔████╔██║█████╗  \n"},
			{" ██╔██╗ ██║   ██║ ██╔██╗     ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝    \n"},
			{"██╔╝ ██╗╚██████╔╝██╔╝ ██╗    ╚██████╗╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗+\n"},
			{"╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n"}};


	for(int i=0;i<=6;i++){
		for(int ii=0;a[i][ii]!=0;ii++){
			printf("%c",a[i][ii]);
		}
		printf("\n");
	}
	printf("By bossgeeg123456\n");
                                                                         
}


main()
{
	titlegame();
	char tdata[9]   = {'1','2','3',
	                   '4','5','6',
	                   '7','8','9'
	                  };
	char ptype[2]= {'x','o'} , p1type;
	int gameover=0,p1,gamemode,p2;
	
	int qcuser=0;
	while(qcuser==0){
		printf("Mode [1]1player [2]2player \n>>");
		scanf("%d",&gamemode);
		if(gamemode==1 || gamemode==2){qcuser=1;}
	}


	qcuser=0;
	while(qcuser==0){
		printf("Choose [x] or [o] \n>>");
		scanf("%s",&ptype[0]);
		if(ptype[0]=='x' || ptype[0]=='o'){qcuser=1;}
	}


	if(ptype[0]=='x') {
		ptype[1]='o';
	} else {
		ptype[1]='x';
	}

	system("color a");
	system("cls");
	gentable(tdata,ptype);

	while(gameover==0) {
		qcuser=0;
		while(qcuser==0){
			system("color a");
			printf("\np1>>");
			scanf("%d",&p1);
			system("cls");
			if(tdata[p1-1]!='x' && tdata[p1-1]!='o'){
				tdata[p1-1]=ptype[0];
				gentable(tdata,ptype);
				qcuser=1;
			}
			else{
				gentable(tdata,ptype);
				printf("\nWrong Position :");
			}
			
		}
		
		checkgame(tdata,ptype,&gameover);
			
		if(gamemode==2 && gameover==0) {
			qcuser=0;
			while(qcuser==0){
				system("color 1");
				printf("\np2>>");
				scanf("%d",&p2);
				system("cls");
				
				if(tdata[p2-1]!='x' && tdata[p2-1]!='o'){
					tdata[p2-1]=ptype[1];
					gentable(tdata,ptype);
					qcuser=1;
				}
				else{
					gentable(tdata,ptype);
					printf("\nWrong Position :");
				}
				
			}//{}'s while

			checkgame(tdata,ptype,&gameover);
		}//{}'s if
		
		else if(gamemode==1 && gameover==0) {
			qcuser=0;
			while(qcuser==0){
				system("color 4");
				system("cls");
				p2=botp();
				
				if(tdata[p2]!='x' && tdata[p2]!='o'){
					tdata[p2]=ptype[1];
					gentable(tdata,ptype);
					qcuser=1;
				}
				else{
					gentable(tdata,ptype);
					printf("\nWrong Position :");
				}
				
			}//{}'s while

			checkgame(tdata,ptype,&gameover);
		}//{}'s if
		
		if(gameover==1 && gamemode!=1){
			printf("\nP1win");
		}
		if(gameover==1 && gamemode==1){
			printf("\nYou Win");
		}
		else if(gameover==2 && gamemode!=1){
			printf("\nP2win");
		}
		else if(gameover==2 && gamemode==1){
			printf("\nYou Lose");
		}
		else if(gameover==3){
			printf("\nDraw");
		}
		
		
	}

	

}
