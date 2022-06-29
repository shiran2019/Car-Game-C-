// Game Name - Taxi Driver

// Group Members -  IM/2019/026 - D.M.T.W. Ariyarathne
// 					IM/2019/094 - H.P.S. Gandhira
// 					IM/2019/068 - Shiran Madhuwantha
// 					IM/2019/112 - Sandushi Weraduwa









#include <iostream>								// include c++ libraries
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>


using namespace std;
													//declare global variables to use in functions
bool exitgame;
bool roadmove;
int randome = 0;
int carX;
int carY;
int memory;
int highscore = 0;
int score;
int enemyX[5];
int enemyY[5] = {-8,-18,-28,-38,-48};   								// enemy car starting y cordinate
int enemyposX[5] = {4,14,24,34,44};										// paths that enemy cars can come
int level;


HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;																// get x coordinate
	coord.Y = y;																// get y coordinate
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);			// create cursor position in x,y coordinates
}




int menu();

void ShowConsoleCursor(bool showFlag){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 									// set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
	
}

void startup(){
		exitgame = false;												// assign "false" to "exitgame" variable
		
		carX = 24;														// fix x,y cordinate for car in start game
		carY = 17;
		score = 0;														// assign 0 to "score" variable in every time game starts.
    
    SetConsoleTextAttribute(out, 12) ;
    gotoxy( 60, 2);cout<<"----------";
    SetConsoleTextAttribute(out, 6) ;
	gotoxy( 60, 3);cout<<"TAXI DRIVER";	
	SetConsoleTextAttribute(out, 12) ;								
	gotoxy( 60, 4);cout<<"----------";
	SetConsoleTextAttribute(out, 15) ;
	gotoxy( 60, 8);cout<<"Control ";
	gotoxy( 60, 9);cout<<"-------- ";
	SetConsoleTextAttribute(out, 9) ;
	gotoxy( 60, 10);cout<<" A Key - Left";
	gotoxy( 60, 11);cout<<" D Key - Right";
	gotoxy( 60,12);cout<<" W Key - Up";
	gotoxy( 60, 13);cout<<" S Key - Down"; 
	SetConsoleTextAttribute(out, 15) ;
		gotoxy(60,17); cout << "Your score :" ;							// print "your score" in console
		gotoxy(60,18); cout << "High score :" << highscore ;			// print high score in console
		gotoxy(60,19); cout << "Level : " << level;
	


		
		
}

void layout() {																								// create road in console window(line 90 -141 )
	if(roadmove){
		
	 SetConsoleTextAttribute(out, 10) ;
	gotoxy(0,0); cout <<  "##         |         |         |         |         ##" ;							// draw road
	gotoxy(0,1); cout <<  "##                                                 ##" ;							// use if else function to get live effect for road
	gotoxy(0,2); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,3); cout <<  "##                                                 ##" ;
	gotoxy(0,4); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,5); cout <<  "##                                                 ##" ;
	gotoxy(0,6); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,7); cout <<  "##                                                 ##" ;
	gotoxy(0,8); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,9); cout <<  "##                                                 ##" ;
	gotoxy(0,10);cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,11); cout << "##                                                 ##" ;
	gotoxy(0,12); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,13); cout << "##                                                 ##" ;
	gotoxy(0,14); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,15); cout << "##                                                 ##" ;
	gotoxy(0,16); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,17); cout << "##                                                 ##" ;
	gotoxy(0,18); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,19); cout << "##                                                 ##" ;
	gotoxy(0,20); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,21); cout << "##                                                 ##" ;
	roadmove = false;
	 SetConsoleTextAttribute(out, 15) ;
	}

	else{
	 SetConsoleTextAttribute(out, 10) ;
	gotoxy(0,0); cout <<  "##                                                 ##" ;
	gotoxy(0,1); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,2); cout <<  "##                                                 ##" ;
	gotoxy(0,3); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,4); cout <<  "##                                                 ##" ;
	gotoxy(0,5); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,6); cout <<  "##                                                 ##" ;
	gotoxy(0,7); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,8); cout <<  "##                                                 ##" ;
	gotoxy(0,9); cout <<  "##         |         |         |         |         ##" ;
	gotoxy(0,10); cout << "##                                                 ##" ;
	gotoxy(0,11); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,12); cout << "##                                                 ##" ;
	gotoxy(0,13); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,14); cout << "##                                                 ##" ;
	gotoxy(0,15); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,16); cout << "##                                                 ##" ;
	gotoxy(0,17); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,18); cout << "##                                                 ##" ;
	gotoxy(0,19); cout << "##         |         |         |         |         ##" ;
	gotoxy(0,20); cout << "##                                                 ##" ;
	gotoxy(0,21); cout << "##         |         |         |         |         ##" ;
	roadmove = true;
	 SetConsoleTextAttribute(out, 15) ;
	}
}






void car(){
	 SetConsoleTextAttribute(out, 14) ;	
	gotoxy(carX,carY);   cout <<" + + ";    					// draw car using  x, y cordinates
	gotoxy(carX,carY+1); cout <<"*| |*";
	gotoxy(carX,carY+2); cout <<"|+++|";
	gotoxy(carX,carY+3); cout <<"*| |*";
     SetConsoleTextAttribute(out, 15) ;	
}


void controll(){
	if(kbhit()){													// identify key press
		char ch = getch();											// get keybord input  to  "ch" variable


			if( ch=='a' || ch=='A' ){								// check input			
				if( carX > 6 ){										// check car in moveable range
					carX -= 10;										// change x, y coordinate to move(control) car using a,s,w,d(line 159 - 187)
				}
			}
			if( ch=='d' || ch=='D' ){
				if( carX < 36 ){
					carX += 10;
				}
			}
			if( ch=='w' || ch=='W' ){
				if( carY > 1 ){
					carY -= 2;
				}
			}
			if( ch=='s' || ch=='S' ){
				if( carY < 17 ){
					carY += 2 ;
				}
			}
			
			
	}
}



void instructions(){
																	// print instructions in console window
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Avoid Cars by moving left or right. ";
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'w' to move up";
	cout<<"\n Press 's' to down";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void gameover(){
	
			system("cls");

			enemyY[0] = {-8};							// reset enemy Y cordinates
			enemyY[1] = {-18};
			enemyY[2] = {-28};
			enemyY[3] = {-38};
			enemyY[4] = {-48};

			cout<<endl;
			 SetConsoleTextAttribute(out, 12) ;	
			cout<<"\t\t--------------------------"<<endl;   		// print game detais
			cout<<"\t\t-------- Game Over -------"<<endl;
			cout<<"\t\t--------------------------\n"<<endl;
			 SetConsoleTextAttribute(out, 15) ;
			cout<<"\t\t----High score--------- " << highscore << endl; 							// print highsocre
			cout<<"\t\t----Your Score--------- " << score << endl << endl;                      // print your score 
			SetConsoleTextAttribute(out, 11) ;					                                                               	
			cout<<"\t\tPress any key to go back to menu.";
			getch();												
			system("cls");																		
			menu();																				// return to game menu again
	
}



int enemy(){
	
	
	for(int i = 0; i<5 ; i++){
		memory = i;

		int v = rand() % 5 + 0;										// 	decide enemy car's path in randome way

		if(randome == 0){
			enemyX[0] = {enemyposX[1]};								// use enemyX to decide gap of enemy cars in same path (line 240 - 271) by assign value for enemyX array
			enemyX[1] = {enemyposX[3]};
			enemyX[2] = {enemyposX[0]};
			enemyX[3] = {enemyposX[2]};
			enemyX[4] = {enemyposX[4]};
			randome = v;
		}

		if (randome == 1){
			enemyX[4] = {enemyposX[1]};
			enemyX[3] = {enemyposX[3]};
			enemyX[2] = {enemyposX[0]};
			enemyX[1] = {enemyposX[2]};
			enemyX[0] = {enemyposX[4]};
			randome = v;
		}

		if (randome == 2){
			enemyX[1] = {enemyposX[1]};
			enemyX[0] = {enemyposX[3]};
			enemyX[4] = {enemyposX[0]};
			enemyX[3] = {enemyposX[2]};
			enemyX[2] = {enemyposX[4]};
			randome = v;
		}
		if (randome == 3){
			enemyX[1] = {enemyposX[4]};
			enemyX[0] = {enemyposX[2]};
			enemyX[4] = {enemyposX[1]};
			enemyX[3] = {enemyposX[0]};
			enemyX[2] = {enemyposX[3]};
			randome = v;
		}

		

	

		if(enemyY[i] >= 0){	
			 SetConsoleTextAttribute(out, 12) ;												// draw enemy car in 5 paths randomly using cordinates 
			gotoxy(enemyX[memory],enemyY[i]);   cout <<"*| |*";						
			gotoxy(enemyX[memory],enemyY[i]+1); cout <<"|***|";
			gotoxy(enemyX[memory],enemyY[i]+2); cout <<"*| |*";
			gotoxy(enemyX[memory],enemyY[i]+3); cout <<" *** ";
			 SetConsoleTextAttribute(out, 15) ;	
		}
         
         
         if(carY-enemyY[i] >= -4 && carY-enemyY[i] <= 3 ){							// decide car and enemy car range and the logic of collision
         	if(carX-enemyX[i] >= -4 && carX-enemyX[i] <= +4){
			 
		
				
				if(highscore < score){												// check your score vs highscore
						highscore = score;			
				}
			
			system("cls");
				
			
			gameover();																//call "gameover" function
			}

		}

		if(enemyY[i] > 17){
			gotoxy(enemyX[memory],enemyY[i]);   cout <<"     ";
			gotoxy(enemyX[memory],enemyY[i]+1); cout <<"     ";
			gotoxy(enemyX[memory],enemyY[i]+2); cout <<"     ";
			gotoxy(enemyX[memory],enemyY[i]+3); cout <<"     ";
			enemyY[i] =  -20;
			score ++;



		

			gotoxy(60,19); cout << "Level : " << level ;
			gotoxy(60,17); cout << "Your score : " << score ;
		}
			
		enemyY[i]++;
		}
	return 0;	
}




void play(){
	


	system("cls");									//  clear console window

	ShowConsoleCursor(false);						//	hide cursor in console window
    system("pause");
			
	system("cls");									

	level = 1;

	startup();										// call "startup" function

	while(!exitgame){
		layout();									// call "layout" function to draw road
		car();										// call "car" function
		enemy();									// call "enemy" function
		controll();									// call "controll" function to control car


	if( score < 50 )	{							// level up and increase code running speed
				Sleep(80);									// decide code running speed
				level = 1;
			
}
			if( (score >= 50) && (score < 100) ){				// level up and increase code running speed
				Sleep(70);									// decide code running speed
				level = 2;
			}
			if( (score >= 100) && (score < 150) ){			// level up and increase code running speed
				Sleep(60);									// decide code running speed
				level = 3;
			}
			if( score >= 150 ){								// level up and increase code running speed
				Sleep(40);									// decide code running speed
				level = 4;
			}
					}

}




int menu(){

	do{
		system("cls");														// clear console window
        SetConsoleTextAttribute(out, 6) ;
		gotoxy(10,3); cout<<"                        __________________";
		gotoxy(10,4); cout<<"                      _/ ||                ~-_";
		gotoxy(10,5); cout<<"                    ,/   /       /~-       /  ~-_  ________----------/";
		gotoxy(10,6); cout<<"  -----------------/-----------------|-------------------____________/";
		gotoxy(10,7); cout<<" O--------------  /               ~~^ |      TAXI DRIVER            | ~|";
		gotoxy(10,8); cout<<" }======{--------|____________________|_____________________________|  |";
		gotoxy(10,9); cout<<" |===== / /~~~| | |                   |         ____________________|-~";
		gotoxy(10,10); cout<<"  |----|  |___/ ||--------------------'----------|  |____/ //";
		gotoxy(10,11); cout<<" ______`.______.`________________________________`._______.`____________";
        SetConsoleTextAttribute(out, 15) ;

        SetConsoleTextAttribute(out, 12) ;	
		gotoxy(10,14); cout<<" -------------------------- "; 
		SetConsoleTextAttribute(out, 6) ;
		gotoxy(10,15); cout<<" |      Taxi Driver        | ";
		 SetConsoleTextAttribute(out, 12) ;
		gotoxy(10,16); cout<<" --------------------------";
		SetConsoleTextAttribute(out, 11) ;	
		gotoxy(10,19); cout<<"1. Start Game";								//  print menu
		gotoxy(10,20); cout<<"2. Instructions";	 
		gotoxy(10,21); cout<<"3. Quit";
		SetConsoleTextAttribute(out, 15) ;
		gotoxy(10,23); cout<<"Select option: ";
        



		char op = getche();													//  get continues input for "op" variable
		


		if( op=='1'){														// select input from "op" variable

			play();															// call " play function "
			
		}
		else if( op=='2'){ 

			instructions();													// call "instruction function"

		}
		else if( op=='3') {

			system("cls");													//  clear console window
			exit(0);														//  exit game

		}

		
		
	}while(1);			// run game until exit game 
	return 0;
}



int main(){
	
	menu();  // call menu function to open game

}
