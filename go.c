#include<stdio.h>
#include"graph.h"

void hyouji(int,int,int);

main (void)
{
	int yoko=0,tate=0;
	int x1=95,y1,x2,y2;

	int masu[19][19] = {{0},{0}};
	int bmasu[19][19] = {{0},{0}};

	initGraph();		//縦線についての記述
	while (560>=x1){
		x2=x1;
		y1=15;
		y2=465;
		drawLine(x1,y1,x2,y2,BLUE);	
		x1+=25;
	}
	y1=15;
	while (480>=y1){	//横線についての記述
		y2=y1;
		x1=95;
		x2=545;
		drawLine(x1,y1,x2,y2,BLUE);
		y1+=25;
	}
	drawCircle(50,400,30,BLACK);
	drawString(30,420,"END",RED);

	int a,c=0,x=0,y=0,xa,ya;
	while(1){ 		//クリックされたときの処理
		do{
			getClickPoint(&x,&y);
				if (x>=50 && x<=110 && y>=370 && y<=430){
					closeGraph();
				}
				xa=(x-82.5)/25;
				x=xa*25+95;
	
				ya=(y-2.25)/25;
				y=ya*25+15;
		}while(masu[xa][ya]==1 || masu[xa][ya]==2 || x<=82.5 || x>=557.5 || y<=2.25 || y>=427.5);
		if (c%2){
			masu[xa][ya]=1;
			a=1;
		}else{
			masu[xa][ya]=2;
			a=2;
		}
		if (a==1){
			printf("masu[%d][%d]=白\n",xa,ya);
		}else{
			printf("masu[%d][%d]=黒\n",xa,ya);
		}
		
		//表示
		if (a==1){
			fillCircle(x,y,10,WHITE);
			drawCircle(x,y,10,BLACK);
		}else{
			fillCircle(x,y,10,BLACK);
		}
								//勝敗判定
		int roop=0;					//x軸についての評価
		while(roop<=4){
			int xhyouka=1;	
			int xi=0;
			int xx;
			xx = xa-roop;
			while(xi<=4){				//5個のかたまり	
				printf("masu[%3d][%3d]=%d ",xx+xi,ya,masu[xx+xi][ya]);
				xhyouka *= masu[xx+xi][ya];
				xi++;
			}
			printf("xhyouka=%d",xhyouka);
			if (xhyouka==1)
				printf("白の勝ち");
			if (xhyouka==32)
				printf("黒の勝ち");
			puts("");
			roop++;
		}
		roop=0;						//y軸についての評価
		while(roop<=4){
			int yhyouka=1;
			int yi=0;
			int yy;
			yy = ya-roop;
			while(yi<=4){
				printf("masu[%3d][%3d]=%d ",xa,yy+yi,masu[xa][yy+yi]);
				yhyouka *= masu[xa][yy+yi];
				yi++;
			}
			printf("yhyouka=%d",yhyouka);
			if (yhyouka==1)
				printf("白の勝ち");
			if (yhyouka==32)
				printf("黒の勝ち");
			puts("");
			roop++;
		}
		roop=0;						//斜めの評価
		while(roop<=4){
			int naname=1;
			int na=0;
			int xna,yna;
			xna = xa-roop;
			yna = ya-roop;
			while(na<=4){
				printf("masu[%3d][%3d]=%d ",xna+na,yna+na,masu[xna+na][yna+na]);
				naname *= masu[xna+na][yna+na];
				na++;
			}
			printf("naname=%d",naname);
			if (naname==1)
				printf("白の勝ち");
			if (naname==32)
				printf("黒の勝ち");
			puts("");
			roop++;
		}
		roop=0;
		while(roop<=4){
			int naname2=1;
			int na2=0;
			int xna2,yna2;
			xna2 = xa-roop;
			yna2 = ya+roop;
			while(na2<=4){
				printf("masu[%3d][%3d]=%d ",xna2-na2,yna2-na2,masu[xna2+na2][yna2-na2]);
				naname2 *= masu[xna2+na2][yna2-na2];
				na2++;
			}
			printf("naname2=%d",naname2);
			if (naname2==1)
				printf("白の勝ち");
			if (naname2==32)
				printf("黒の勝ち");
			puts("");
			roop++;
		}
		c++;
	}
}
