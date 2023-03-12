#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<sstream>
using namespace std;

char usrp = '0', var, ulp = 201, mp = 205, urp = 187, llp = 200, lrp = 188, vp = 186, 
		 sp = ' ';

string choice= "",
	   name= "",
	   out= "",
	   out1= "";

float equip[25][25];
int destroy[25];
int armor[25][25];

//Player Booleans
bool pturn=false,
	 pcrit=false,
	 meleecheck=false,
	 pcountercheck=false,
	 kimax=false,
	 focuskiused= false,
	 multipunchtech=true,
	 mpunchused=false,
     multikicktech=true,
	 mkickused=false,
     sensekitech=true,
     zanzokentech=true,
	 blocktech=true,
	 barriertech=true,
	 block=false,
	 barrier=false,
	 zanzo=false,
     solarflaretech=true,
	 solarflareused=false,
	 sf=false, 
	 tired=false,
	 saiyanArmorB=true,
	 saiyanArmorA=true,
	 saiyanArmorE=true,
	 wcloth15=true,
	 wcloth25=true,
	 wcloth50=true,
	 wcloth75=true,
	 wcloth100=true;

//Computer Booleans
bool ccrit=false,
	 ccountercheck=false,
	 ckimaxbool=false,
	 compfocuskiused=false,
	 ctired=false,
	 compsolarflaretech=true,
	 compsolarflareused=false,
	 compzanzotech=true,
	 compzanzo=false,
	 compblocktech=true,
	 compmultipunchtech=true,
	 compmpunchused=false,
	 compmultikicktech=true,
	 compmkickused=false,
	 compbarriertech=true,
	 compbarrier= false;

//Player Integers	
int	plvl=1,
	php=50,
	pki=15,
	psp=0,
	str=0,
	stm=0, 
	dex=0,
	spd=0, 
	wis=0,
	strmax=str,
	stmmax=stm,
	dexmax=dex,
	spdmax=spd,
	wismax=wis,
	x=0,
	y=0,
	count=0,
	check=0,
	pint=0,
	patk=0,
	pdod=0,
	pdmg=0,
	pbean=2,
	strbns=(str-12)/2,
	stmbns=(stm-12)/2, 
	dexbns=(dex-12)/2,
	spdbns=(spd-12)/2,
	wisbns=(wis-12)/2,
	intbns=(spdbns+wisbns)/2,
	intbnsmax=intbns,
	dexbnsmax=0,
	spdbnsmax=0,	
	apr=(spd+dex)/12,
	aprmax=apr,
	phpmod=(stmbns*8)+(plvl*10),
	pkimod=(wisbns*2)+(plvl*5),
	nhpmod=(((stm-12)/2)*(plvl+1))*5+(plvl+1)*15,
	nkimod=(((wis-12)/2)*(plvl+1))+(plvl+1)*5,
	phpmax=0,
	pkimax=0,
	pl=((php+(pki*2))+((wis+stm)*3))*(pow(str+spd,1.5))/50*plvl,
	xp=0,
	nxtxp=150,
	zeni=0,
	barrierhp=0,
	parmorhp=0,
	basicarmorhp,
	advancedarmorhp,
	elitearmorhp,
	wtxp=0,
	strxp=0,
	stmxp=0,
	dexxp=0,
	spdxp=0,
	wisxp=0,
	punchxp=0,
	doubleaxehandlexp=0,
	elbowxp=0,
	headbuttxp=0,
	kickxp=0,
	kneexp=0,
	roundhousexp=0,
	kiblastxp=0,
	dondonpaxp=0,
	sensekixp=0,
	blockxp=0,
	focuskixp=0,
	multipunchxp=0,
	multikickxp=0,
	solarflarexp=0,
	zanzokenxp=0,
	barrierxp=0,
	rnd=0,
	aprc=0,
	mpc=0,
	mpcc=0,
	mkc=0,
	mkcc=0,
	sfc=0,
	cc=0,
	dhold=0;

//Computer Integers
int	clvl=1, 
	chp=50, 
	cki=15,
	csp=0, 
	cstr=0, 
	cstm=0, 
	cdex=0,
	cspd=0, 
	cwis=0,
	cwismax=0,
	cint=0,
	catk=0,
	cdod=0,
	cdmg=0,
	cbean=2,
	cmpc=0,
	cmkc=0,
	csfc=0,
	cstrbns=(cstr-12)/2, 
	cstmbns=(cstm-12)/2, 
	cdexbns=(cdex-12)/2, 
	cwisbns=(cwis-12)/2,
	cspdbns=(cspd-12)/2,
	cintbns=(cdexbns+cwisbns)/2,
	capr=(cspd+cdex)/10,
	chpmod=(cstmbns*8)+(clvl*10),
	ckimod=(cwisbns*2)+(clvl*5),
	cpl=((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl,
	cplmax=0,
	chpmax=0,
	ckimax=0,
	cblock=0,
	compbarrierhp=0,
	carmorhp=0,
	compRestChoice=0,
	compKiChoice=0,
	compBeanChoice=0,
	compZanzoChoice=0,
	compBarrierChoice=0,
	compmPunchChoice=0,
	compmKickChoice=0;

void charcreation();
void unique();
void initiate();
void pstatus();
void pause();
void mainmenu();
void computerturn();
void playerturn();
void menu();
void charscreen();
void stattraining();
void meleeattacks();
void kiattacks();
void abilities();
void killscreen();
void senseki();
void validity();
void playerheader();
void defense();
void zanzoken();

int main()
{

unsigned seed = time(0); 
srand(seed);

	if(choice == "restart" || choice != "continue")
		charcreation();

	if(choice == "k" || choice == "continue")
		charscreen();

	{
	chpmax=chp;
	ckimax=cki; 
	cstr=(8 + rand() % 10)+(clvl)+(clvl/2); 
	cstm=(7 + rand() % 10)+(clvl)+(clvl/2);
	cdex=(6 + rand() % 10)+(clvl)+(clvl/2);
	cwis=(8 + rand() % 10)+(clvl)+(clvl/2);
	cspd=(7 + rand() % 10)+(clvl)+(clvl/2);
	cwismax=cwis;
	cstrbns=(cstr-12)/2;
	cspdbns=(cspd-12)/2; 
	cstmbns=(cstm-12)/2; 
	cdexbns=(cdex-12)/2; 
	cwisbns=(cwis-12)/2;
	csp=cstm;
	capr=(cspd+cdex)/12;
	cintbns=(cspdbns+cwisbns)/2;
	chpmod=(cstmbns*8)+(clvl*10);
	ckimod=(cwisbns*2)+(clvl*5);
	chp=chp+chpmod;
	cki=cki+ckimod;
	chpmax=chp;
	ckimax=cki;
	cpl = ((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;
	cplmax = cpl;
	}

	if(php <= 0)
	{
	xp = 0;
	plvl = 1;
	clvl = 1;
	}

	choice = "null";

	if(choice == "null")
	{
	system("CLS");
	rnd = 0;
	cout << "\t\t!!You have engaged in battle!!\n\n";
	pstatus();

		if(sensekitech)
			senseki();

	cout << "\n\n<<Initive will now begin!>>";
		
	pause();
	}

	if(php > 0 && chp > 0)
	do
	{
		do																
		{
			if(php > 0 && chp > 0)//											INITIVE/RESET
			{
			cint = (1 + rand() % 20)+cintbns;
			pint = (1 + rand() % 20)+intbns;
			choice = "null";
			solarflareused = false;
			compsolarflareused=false;
			focuskiused = false;
			compfocuskiused=false;
			cc = 0;

				if(sf)
					pint+= 20;
			}
		}
		while(cint == pint);
		
		rnd++;//											 				    ROUND COUNTER
		
		if(cint > pint)//		  												COMPUTER WINS INITIVE
		{
		system("CLS");
		cout << "\t\t\tRound " << rnd << "!" << endl << endl;
		cout << "You have LOST the initive!\n"
			 << "Your opponent rushes towards you!\n\n";
		pstatus();

		pause();
		computerturn();
		playerturn();		
		}

		else if(pint > cint)//												PLAYER WINS INITIVE
		{		
		system("CLS");
		cout << "\t\t\tRound " << rnd << "!" << endl << endl;
		cout << "You have WON the initive!\n"
			 << "You plant your feet firmly in the ground and size up your enemy.\n\n";
		pstatus();

			if(sensekitech)
				senseki();

		pause();
		playerturn();
		computerturn();
		}
	}
	while(php > 0 && chp > 0);			

}
/******************************************************************************/
/******************************COMPUTER TURN***********************************/
/******************************************************************************/
void computerturn()
{

	for(aprc = 0; aprc < capr; aprc++)
	{
	compRestChoice = 	(1 + rand() % 4);
	compBeanChoice = 	(1 + rand() % 30);
	compKiChoice = 		(1 + rand() % 10);
	compZanzoChoice = 	(1 + rand() % 10);
	compBarrierChoice = (1 + rand() % 15);
	compmPunchChoice =  (1 + rand() % 10);
	compmKickChoice =   (1 + rand() % 10);

		if(php <= 0 || chp <= 0)
			killscreen();

		else if(sf)
		{
	
			if(sfc == capr)
			{
			system("CLS");
			cout << "Your opponent staggers as they are blinded by Solar Flare for " << capr << " turns!";
			sf=false;
			sfc = 0;
			pause();
			return;
			}

			else
			{
 
				do
				{
				system("CLS");
				sfc--;
				aprc++;
	
					if(aprc == capr)
					{
						if(sfc == 0)
							sf=false;
						
					cout << "Your opponent staggers as they are blinded by Solar Flare for " << capr << " turns!";
					pause();
					return;
					}	
				}
				while(aprc <= sfc);
			}

		cout << "Your opponent staggers as they are blinded by Solar Flare for " << aprc << " turns!\n\n";
		sf = false;
		aprc--;
		}

		else if(chp <= (chpmax*(0.40)) && cbean > 0 && compBeanChoice == 30)
		{
		system("CLS");
		cout << "Your opponent smiles and laughs histarically as they reach into a pouch\n" 
			 <<	"and retrives a small bean. They place the bean in their mouth, and with one\n"
			 << "crunch they spring into a readied stance full of vitality!\n\n"
			 << "Hooded Namekian: \"How did you ever expect to beat me...!?\"";
		cbean--;
		chp = chpmax;
		csp = cstm;
		cpl = ((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;

			if(sensekitech)
				senseki();
		}

		else if(csp <= (cstm*.25) && compRestChoice < 4)
		{
		system("CLS");
		cout << "Your opponent's head lowers. Breathing deeply, they consider their next move.\n"
			 << "Your opponent has taken a moment to catch their breath.";
		csp+= static_cast<int>(cstm*(.35));

			if(sensekitech)
				senseki();
		}

		else if(cki >= (ckimax*(.75)) && !ckimaxbool && compKiChoice == 5 && !compfocuskiused|| cki <= (ckimax*(.3)) && compKiChoice == 5 && !compfocuskiused)
		{
		system("CLS");
		cout << "Your opponent lets out a low bellow as a white aura suddenly errupts\n"
			 << "around them! Your oppopnent has taken a moment to channel their ki!";
		cki = cki + pow(1+rand()%3,2)*clvl+clvl*2;
		compfocuskiused=true;
	
			if(cki >= ckimax*(1.25))
			{
			cki = ckimax*(1.25)+1;
			cout << "\n\n<<Your opponent's aura intensifies, gravel begins to raise from the ground!>>";
			}
	
		cpl = ((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;

			if(sensekitech)
				senseki();
		}

		else if(cki > 4 && compZanzoChoice == 10 && compzanzotech && !compzanzo && !ckimaxbool)
		{
		system("CLS");
		aprc--;
		compzanzo = true;
		cout << "Your opponent's body phases in and out of sight as ki rushes through\n" 
			 << "their muscles!";
		}

		else if(cki > (15 + (clvl)) && compBarrierChoice == 15 && compbarriertech && !compbarrier && !compzanzo)
		{
		system("CLS");
		compbarrierhp= (13 + (clvl*2));
		cki-= (14 + (clvl));
		compbarrier= true;
		cout << "Your opponent's eyes flicker white as they launch their arms above their head.\n"
			 << "As they pull their arm's in, a smooth white aura envlopes their body tightly.\n\n"
			 << "Your opponent has shielded their body with a Ki Barrier!";
		}

		else if(compmPunchChoice == 5 && compmpunchused == false)
		{
		system("CLS");
			mpcc= ((2 + clvl/3) + rand() % (2 + (clvl/2)));
			csp-= (3+(clvl/2));
		cout << "Your opponent's arms and fists become a blur as they release a\n" 
			 << "volley of [" << mpcc << "] punches in your direction!";
		compmpunchused = true;
		pause();

			for(mpc = 0; mpc < mpcc; mpc++)
			{
			system("CLS");
			cout << "Your opponent rushes towards you with a Punch attack!\n\n";
			catk = (1 + rand() % 20) + cdexbns + 0;					
			pdod = (1 + rand() % 20) + dexbns + 0;
		
				if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns)//	COMPUTER MILTIPUNCH HIT
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
					 	cout << cdexbns << ") = [" << catk << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << pdod << "]";	
				cdmg = (1 + rand() % 10)+cstrbns;
	
				cout << endl;
				defense();
				}
			
				else if(catk == 20+cdexbns && pdod != 20+dexbns)//				COMPUTER MULTIPUNCH CRITICAL
				{
				cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns << endl;
				cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
				cdmg = (1 + rand() % 10);
				cdmg = (cdmg * 2)+cstrbns;
				ccrit= true;
	
				defense();
				}
							
				else if(pdod == 20+dexbns && catk == 20+cdexbns)
				{
				cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
				cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
				cout << "\nYou dodge your opponent's Punch attack.";
				}
		
				else if(pdod >= catk && pdod != 20+dexbns)//  					PLAYER DODGES MULTIPUNCH 
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
					 	cout << cdexbns << ") = [" << catk << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << pdod << "]" << endl;
				cout << "\nYou dodge your opponent's Punch attack.";
				}
			
				else//											   				PLAYER COUNTERS MULTIPUNCH
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
				cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
				cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
				punchxp++;
				cc = (1 + rand() % 7);
	
					if(cc == 1)
					{
					pdmg = (1 + rand() % 4);
					cout << "You duck under the Punch and quickly jumps into the air.\n"
						 << "Your opponent's eyes open wide as you slam your fists into\n"
						 << "their shoulder with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					pdmg = (1 + rand() % 6);
					cout << "You quickly move your head away from the Punch and grab your\n"
						 << "opponent's head. You Headbutt your opponent before they can recover!";
					}
					else if(cc == 3)
					{
					pdmg = (1 + rand() % 8);
					cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
						 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
					}
					else if(cc == 4)
					{
					pdmg = (1 + rand() % 10);
					cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
						 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
					}
					else if(cc == 5)
					{
					pdmg = (1 + rand() % 6)+(1 + rand() % 6);
					cout << "Your instincts take over as you gracefully duck the Punch.\n"
						 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
					}
					else if(cc == 6)
					{
					pdmg = (1 + rand() % 8)+(1 + rand() % 8);
					cout << "Your instincts take over as you gracefully duck the Punch.\n"
						 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
					}
					else if(cc == 7)
					{
					pdmg = (1 + rand() % 10)+(1 + rand() % 10);
					cout << "Your keen instincts take over as you gracefully duck the Punch and\n"
						 << "spin quickly. Your spin gains momentum and finishes up-side their head.\n" 
						 << "You feel your opponent's neck quiver as your Round House Kick connects!";
					}

				pcountercheck= true;
				defense();
				}

				zanzoken();
			
				if(out != "")
				{
				cout << out;
				out = "";
				}
			
				if(php <=0 || chp <=0)
				{
				pause();
				killscreen();
				}

				if(mpc+1 != mpcc)
					pause();
			}
		
		cc = 0;	
		}

		else if(compmKickChoice == 5 && compmkickused == false)
		{
		system("CLS");
			mkcc= ((2 + clvl/3) + rand() % (2 + (clvl/2)));
			csp-= (4+(clvl/2));
		cout << "Your opponent's legs and feet become a blur as they release a\n" 
			 << "volley of [" << mkcc << "] kicks in your direction!";
		compmkickused = true;
		pause();

			for(mkc = 0; mkc < mkcc; mkc++)
			{
			system("CLS");
			cout << "Your opponent sprints towards you, extending their leg for a Kick attack!\n\n";
			catk = (1 + rand() % 20) + cdexbns + 0;					
			pdod = (1 + rand() % 20) + dexbns + 4;
		
				if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns+4)//	COMPUTER MULTIKICK
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
					 	cout << cdexbns << ") = [" << catk << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << " (+4) (";
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << pdod << "]" << endl;
				cdmg = (1 + rand() % 8)+(1 + rand() % 8)+cstrbns;
	
				defense();
				}
			
				else if(catk == 20+cdexbns && pdod != 20+dexbns+4)//  		 	COMPUTER MULTIKICK CRITICAL
				{
				cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << endl;
				cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
				cdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cdmg = (cdmg * 2)+cstrbns;
				ccrit= true;
	
				defense();
				}
							
				else if(pdod == 20+dexbns+4 && catk == 20+cdexbns)
				{
				cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
				cout << "Your attack dodge roll.....: [" << pdod-dexbns-4 << "]" << endl;
				cout << "\nYou dodge the opponent's Kick attack.";
				}
		
				else if(pdod >= catk && pdod != 20+dexbns+4)//  	 			PLAYER DODGES MULTIKICK
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
					 	cout << cdexbns << ") = [" << catk << "]" << endl;
				cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << " (+4) (";
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << pdod << "]" << endl;
				cout << "\nYou dodge the opponent's Kick attack.";
				}
			
				else//											    			PLAYER COUNTERS MULTIKICK
				{
				cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
				cout << "Your attack dodge roll.....: [" << pdod-dexbns-4 << "]" << endl;
				cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
				kickxp++;
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					pdmg = (1 + rand() % 4);
					cout << "You push away the opponent's Kick and then quickly jump into the air.\n"
						 << "Your opponent's eyes open wide as you slam your fists into\n"
						 << "their shoulder with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					pdmg = (1 + rand() % 6);
					cout << "You quickly jump above the Kick attack and grab your opponent's head.\n"
						 << "You Headbutt your opponent before they can recover!";
					}
					else if(cc == 3)
					{
					pdmg = (1 + rand() % 8);
					cout << "You analyze your opponent and push their Kick away, placing them off-balance.\n"
						 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
					}
					else if(cc == 4)
					{
					pdmg = (1 + rand() % 10);
					cout << "You analyze your opponent and push their Kick away, placing them off-balance.\n"
						 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
					}
					else if(cc == 5)
					{
					pdmg = (1 + rand() % 6)+(1 + rand() % 6);
					cout << "Your instincts take over as you gracefully dodge the Kick attack.\n"
						 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
					}
					else if(cc == 6)
					{
					pdmg = (1 + rand() % 8)+(1 + rand() % 8);
					cout << "Your instincts take over as you gracefully dodge the Kick attack.\n"
						 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
					}
					else if(cc == 7)
					{
					pdmg = (1 + rand() % 10)+(1 + rand() % 10);
					cout << "Your keen instincts take over as you gracefully dodge the Kick attack and\n"
						 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
						 << "You feel your opponent's neck quiver as your Round House Kick connects!";
					}

				pcountercheck= true;
				defense();
				}

				zanzoken();

				if(out != "")
				{
				cout << out;
				out = "";
				}

				if(php <=0 || chp <= 0)
				{
				pause();
				killscreen();
				}

				if(mkc+1 != mkcc)
					pause();
			}

		cc = 0;		
		}

		else//																	COMPUTER DECIDE ROLL
		{

			if(ckimaxbool && !compzanzo)
				cc = (8 + rand() % 2);
	
			else if(cki > 9)
				cc = (1 + rand() % 9);

			else if(cki > 4 && cki < 10)
				cc = (1 + rand() % 8);

			else
				cc = (1 + rand() % 7);

			if(cc < 8 && compzanzo)
				cki-= (clvl+4);

			if(zanzo)
			{
			pki-=5;
			zanzokenxp++;

				if(pki < 5)
				{
				dexbns = dexbnsmax;
				spdbns = spdbnsmax;
				zanzo = false;
				out += "\n\n<<Your body phases back into sight, your Zanzoken has stopped!>>";
				}
			}
		}			

		if(cc == 1)//												 			COMPUTER PUNCH
		{
		system("CLS");
		cout << "Your opponent rushes towards you with a Punch attack!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 0;					
		pdod = (1 + rand() % 20) + dexbns + 0;
		csp--;
	
			if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns)//		COMPUTER PUNCH HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;

			cdmg= ((1+(clvl/2)) + rand() % ((9+(clvl/1))));
			cdmg+= cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns && pdod != 20+dexbns)//					COMPUTER PUNCH CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg= ((1+(clvl/2)) + rand() % ((9+(clvl/1))));
			cdmg*= 2;
			cdmg+= cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns && catk == 20+cdexbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\nYou dodge your opponent's Punch attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns)//  						PLAYER DODGES PUNCH 
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge your opponent's Punch attack.";
			}
		
			else//												   				PLAYER COUNTERS PUNCH
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			punchxp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You duck under the Punch and quickly jumps into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly move your head away from the Punch and grab your\n"
					 << "opponent's head. You Headbutt your opponent before they can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts take over as you gracefully duck the Punch.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts take over as you gracefully duck the Punch.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully duck the Punch and\n"
					 << "spin quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 2)//												  		COMPUTER ELBOW
		{
		system("CLS");
		cout << "Your opponent rushes towards you with an Elbow!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 2;					
		pdod = (1 + rand() % 20) + dexbns + 0;
		csp--;
	
			if(catk > pdod && catk != 20+cdexbns+2 && pdod != 20+dexbns)//		COMPUTER ELBOW HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-2 << " (+2) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 8)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns+2 && pdod != 20+dexbns)// 				COMPUTER ELBOW CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-2 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 8);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns && catk == 20+cdexbns+2)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-2 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\nYou dodge the opponent's Elbow attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns)//  					 	PLAYER DODGES ELBOW 
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-2 << " (+2) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Elbow attack.";
			}
		
			else//									 		   					PLAYER COUNTERS ELBOW
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-2 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			elbowxp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You duck under the Elbow and quickly jumps into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly move your head away from the Elbow and grab your opponent's head.\n"
					 << "You Headbutt your opponent before he can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You cross your opponent's arm with your own, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts takes over as you gracefully duck the Elbow.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts takes over as you gracefully duck the Elbow.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully duck the Elbow and\n"
					 << "spin quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 3)//											   			COMPUTER HEADBUTT
		{
		system("CLS");
		cout << "Your opponent thrusts their head towards yours trying to Headbutt!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 4;					
		pdod = (1 + rand() % 20) + dexbns + 0;
		csp--;
	
			if(catk > pdod && catk != 20+cdexbns+4 && pdod != 20+dexbns)//	    COMPUTER HEADBUTT HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-4 << " (+4) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 6)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns+4 && pdod != 20+dexbns)// 			    COMPUTER HEADBUTT CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-4 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 6);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns && catk == 20+cdexbns+4)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-4 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\nYou dodge the opponent's Headbutt attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns)//  			  			PLAYER DODGES HEADBUTT 
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-4 << " (+4) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Headbutt attack.";
			}
		
			else//									 							PLAYER COUNTERS HEADBUTT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-4 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			headbuttxp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You jump away from the Headbutt attack and then quickly into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly jerk your head away from the Headbutt and grab your opponent's head.\n"
					 << "You Headbutt your opponent before he can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You push your opponent's head away, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You push your opponent's head away, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts take over as you gracefully dodge the Headbutt attack.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts take over as you gracefully dodge the Headbutt attack.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully dodge the Headbutt attack and\n"
					 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 4)//											    		COMPUTER DOUBLE AXE HANDLE
		{
		system("CLS");
		cout << "Your opponent jolts into the air behind you, coming down quick with\n"
			 << "a Double Axe Handle attack!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 6;					
		pdod = (1 + rand() % 20) + dexbns + 0;
		csp = csp-2;
	
			if(catk > pdod && catk != 20+cdexbns+6 && pdod != 20+dexbns)//		COMPUTER DOUBLE AXE HANDLE HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-6 << " (+6) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 4)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns+6 && pdod != 20+dexbns)//  				COMPUTER DOUBLE AXE HANDLE CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-6 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 4);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns && catk == 20+cdexbns+6)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-6 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\nYou dodge the opponent's Double Axe Handle attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns)//  	 					PLAYER DODGES DOUBLE AXE HANDLE 
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-6 << " (+6) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns << " (+0) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Double Axe Handle attack.";
			}
		
			else//								   								PLAYER COUNTERS DOUBLE AXE HANDLE
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-6 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			doubleaxehandlexp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You duck away from the Double Axe Handle attack and then quickly into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly avoid the Double Axe Handle attack and grab your opponent's head.\n"
					 << "You Headbutt your opponent before he can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You turn towards your opponent and displace their weight.\n"
					 << "Your eyes sharply spot an opening, as you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You turn towards your opponent and displace their weight.\n"
					 << "Your opponent staggers briefly, as you swing across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Instinct takes over as you gracefully avoid the Double Axe Handle attack.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Instinct takes over as you gracefully avoid the Double Axe Handle attack.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Keen instincts take over as you gracefully avoid the Double Axe Handle attack and\n"
					 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 5)//									  			   		COMPUTER KNEE
		{
		system("CLS");
		cout << "Your opponent sprints towards you, jumping at you with a Knee attack!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 0;					
		pdod = (1 + rand() % 20) + dexbns + 2;
		csp--;
	
			if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns+2)//		COMPUTER KNEE HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-2 << " (+2) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 6)+(1 + rand() % 6)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns && pdod != 20+dexbns+2)//  				COMPUTER KNEE CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-2 << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 6)+(1 + rand() % 6);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns+2 && catk == 20+cdexbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-2 << "]" << endl;
			cout << "\nYou dodge the opponent's Knee attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns+2)//  	 				PLAYER DODGES KNEE 
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-2 << " (+2) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Knee attack.";
			}
		
			else//											    				PLAYER COUNTERS KNEE
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-2 << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			kneexp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You push away the opponent's Knee and then quickly jump into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly jump above the Knee attack and grab your opponent's head.\n"
					 << "You Headbutt your opponent before he can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You push their Knee away, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "Snapping at your opponent, you push their Knee away, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts take over as you gracefully dodge the Knee attack.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts take over as you gracefully dodge the Knee attack.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully dodge the Knee attack and\n"
					 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 6)//									  			   		COMPUTER KICK
		{
		system("CLS");
		cout << "Your opponent sprints towards you, extending their leg for a Kick attack!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 0;					
		pdod = (1 + rand() % 20) + dexbns + 4;
		csp = csp-2;
	
			if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns+4)//		COMPUTER KICK HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << " (+4) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 8)+(1 + rand() % 8)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns && pdod != 20+dexbns+4)//  		 		COMPUTER KICK CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 8)+(1 + rand() % 8);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns+4 && catk == 20+cdexbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-4 << "]" << endl;
			cout << "\nYou dodge the opponent's Kick attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns+4)//  	 				PLAYER DODGES KICK
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-4 << " (+4) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Kick attack.";
			}
		
			else//											    				PLAYER COUNTERS KICK
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-4 << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			kickxp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You push away the opponent's Kick and then quickly jump into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly jump above the Kick attack and grab your opponent's head.\n"
					 << "You Headbutt your opponent before they can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You analyze your opponent and push their Kick away, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You analyze your opponent and push their Kick away, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts take over as you gracefully dodge the Kick attack.\n"
					 << "Your eyes sharply spot an opening, and you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts take over as you gracefully dodge the Kick attack.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully dodge the Kick attack and\n"
					 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}		

		else if(cc == 7)//									   					COMPUTER ROUND HOUSE KICK
		{
		system("CLS");
		cout << "Your opponent spins their body around for a whirling Round House Kick attack!\n\n";
		catk = (1 + rand() % 20) + cdexbns + 0;					
		pdod = (1 + rand() % 20) + dexbns + 6;
		csp = csp-2;
	
			if(catk > pdod && catk != 20+cdexbns && pdod != 20+dexbns+6)//		COMPUTER ROUND HOUSE KICK HIT
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-6 << " (+6) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 10)+(1 + rand() % 10)+cstrbns;

			defense();
			}
		
			else if(catk == 20+cdexbns && pdod != 20+dexbns+6)//  		    	COMPUTER ROUND HOUSE KICK CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-6 << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 10)+(1 + rand() % 10);
			cdmg = (cdmg * 2)+cstrbns;
			ccrit= true;

			defense();
			}
						
			else if(pdod == 20+dexbns+6 && catk == 20+cdexbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cdexbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-6 << "]" << endl;
			cout << "\nYou dodge the opponent's Round House Kick attack.";
			}
	
			else if(pdod >= catk && pdod != 20+dexbns+6)//  	  				PLAYER DODGES ROUND HOUSE KICK
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << " (+0) (";
				if(cdexbns >= 0)
					cout << "+";
				 	cout << cdexbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-dexbns-6 << " (+6) (";
				if(dexbns >= 0)
					cout << "+";
					cout << dexbns << ") = [" << pdod << "]" << endl;
			cout << "\nYou dodge the opponent's Round House Kick attack.";
			}
		
			else//								    							PLAYER COUNTERS ROUND HOUSE KICK
			{
			cout << "Your opponent's attack roll: " << catk-cdexbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-dexbns-6 << "]" << endl;
			cout << "\n<<You swiftly dodge the attack and return with a COUNTER!>>\n\n";
			roundhousexp++;
			cc = (1 + rand() % 7);

				if(cc == 1)
				{
				pdmg = (1 + rand() % 4);
				cout << "You jump away from the opponent's Round House Kick and quickly into the air.\n"
					 << "Your opponent's eyes open wide as you slam your fists into\n"
					 << "their shoulder with a Double Axe Handle attack!";
				}
				else if(cc == 2)
				{
				pdmg = (1 + rand() % 6);
				cout << "You quickly jump above the Round House Kick and grab your opponent's head.\n"
					 << "You Headbutt your opponent before he can recover!";
				}
				else if(cc == 3)
				{
				pdmg = (1 + rand() % 8);
				cout << "You push the Round House Kick away, placing them off-balance.\n"
					 << "Your eyes sharply spot an opening, and you thrust your Elbow into their side!";
				}
				else if(cc == 4)
				{
				pdmg = (1 + rand() % 10);
				cout << "You push the Round House Kick away, placing them off-balance.\n"
					 << "Your opponent staggers briefly, you pummel across their face with a Punch!";
				}
				else if(cc == 5)
				{
				pdmg = (1 + rand() % 6)+(1 + rand() % 6);
				cout << "Your instincts take over as you gracefully dodge the Round House Kick.\n"
					 << "Your eyes sharply spot an opening, as you dig your Knee into their stomach!";
				}
				else if(cc == 6)
				{
				pdmg = (1 + rand() % 8)+(1 + rand() % 8);
				cout << "Your instincts take over as you gracefully dodge the Round House Kick.\n"
					 << "You quickly spring back, jump forward and Kick into your opponent's chest!";
				}
				else if(cc == 7)
				{
				pdmg = (1 + rand() % 10)+(1 + rand() % 10);
				cout << "Your keen instincts take over as you gracefully dodge the Round House Kick and\n"
					 << "spin around quickly. Your spin gains momentum and finishes up-side their head.\n" 
					 << "You feel your opponent's neck quiver as your Round House Kick connects!";
				}

			pcountercheck= true;
			defense();
			}
		}

		else if(cc == 8)//														COMPUTER KI BLAST
		{
		system("CLS");
		cout << "Your opponent's hands glow as they move in your direction.\n"
			 << "He grunts and smiles as he releases a beam of energy towards you!\n\n";
		cki = cki - 5;
		catk = (1 + rand() % 20) + cwisbns + 0;					
		pdod = (1 + rand() % 20) + spdbns + 8;
	
			if(catk > pdod && catk != 20+wisbns && pdod != 20+spdbns+8)//		COMPUTER KI BLAST HIT
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << " (+0) (";
				if(cwisbns >= 0)
					cout << "+";
				 	cout << cwisbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-8 << " (+8) (";
				if(spdbns >= 0)
					cout << "+";
					cout << spdbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 15)+(1 + rand() % 10)+cwisbns;

			defense();
			}
		
			else if(catk == 20+cwisbns && pdod != 20+spdbns+8)//   	    		COMPUTER KI BLAST CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cwisbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-8 << endl;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>\n\n";
			cdmg = (1 + rand() % 15)+(1 + rand() % 10);
			cdmg = (cdmg * 1.5)+cwisbns;
			ccrit= true;

			cout << "\n\nYou are immersed in a MASSIVE EXPLOSION!!\n\n";
			defense();
			}
						
			else if(pdod == 20+spdbns+8 && catk == 20+cwisbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cwisbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-spdbns-8 << "]" << endl;
			cout << "\nYou slap away your opponent's Ki Blast and watch as it explodes.";
			}
	
			else if(pdod >= catk && pdod != 20+spdbns+8)//  	           		PLAYER DODGES KI BLAST
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << " (+0) (";
				if(cwisbns >= 0)
					cout << "+";
				 	cout << cwisbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-8 << " (+8) (";
				if(spdbns >= 0)
					cout << "+";
					cout << spdbns << ") = [" << pdod << "]" << endl;
			cout << "\nYour opponent's Ki Blast whizzes past you!";
			}
		
			else//								    		               		PLAYER COUNTERS KI BLAST
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-spdbns-8 << "]" << endl;
			cout << "\n<<You effortlessly side-step the beam attack!>>";
			kiblastxp++;
			}
	
		}

		else if(cc == 9)//														COMPUTER MASENKO
		{
		system("CLS");
		cout << "Your opponent jumps back and stares you up and down, smirking malisciously.\n"
			 << "His hands begin to collect massive amounts of KI!\n"
			 << "He places his hands to his forehead and yells.\n"
			 << "Hooded Namekian: \"MASENKO...\"\n"
			 << "Hooded Namekian: \"HAAAAAA...!!\"\n\n"
			 << "Your opponent aims his hands towards you, releasing a massive energy blast!!\n\n";
		cki = cki - 10;
		catk = (1 + rand() % 20) + cwisbns + 0;					
		pdod = (1 + rand() % 20) + spdbns + 10;

			if(catk > pdod && catk != 20+cwisbns && pdod != 20+dexbns+10)//		COMPUTER MASENKO HIT
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << " (+0) (";
				if(cwisbns >= 0)
					cout << "+";
				 	cout << cwisbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-10 << " (+10) (";
				if(spdbns >= 0)
					cout << "+";
					cout << spdbns << ") = [" << pdod << "]" << endl;
			cdmg = (1 + rand() % 25)+(1 + rand() % 10)+cwisbns;

			defense();
			}
		
			else if(catk == 20+cwisbns && pdod != 20+spdbns+10)//   			COMPUTER MASENKO CRITICAL
			{
			cout << "Your opponent's attack roll: [" << catk-cwisbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-10;
			cout << "\n\n<<Your opponent has landed a CRITICAL hit!>>";
			cdmg = (1 + rand() % 15)+(1 + rand() % 10);
			cdmg = (cdmg * 1.5)+cwisbns;
			ccrit= true;

			cout << "\n\nYou are immersed in a MASSIVE EXPLOSION!!\n";
			defense();
			}
						
			else if(pdod == 20+spdbns+10 && catk == 20+cwisbns)
			{
			cout << "Your opponent's attack roll: [" << catk-cwisbns-0 << "]" << endl;
			cout << "Your attack dodge roll.....: [" << pdod-spdbns-10 << "]" << endl;
			cout << "\nYou slap away your opponent's Masenko attack and watch as it explodes.";
			}
	
			else if(pdod >= catk && pdod != 20+spdbns+10)//  	            	PLAYER DODGES MASENKO
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << " (+0) (";
				if(cwisbns >= 0)
					cout << "+";
				 	cout << cwisbns << ") = [" << catk << "]" << endl;
			cout << "Your attack dodge roll.....: " << pdod-spdbns-10 << " (+10) (";
				if(spdbns >= 0)
					cout << "+";
					cout << spdbns << ") = [" << pdod << "]" << endl;
			cout << "\nYour opponent's Masenko attack whizzes past you.";
			}
		
			else//								    	     					PLAYER COUNTERS MASENKO
			{
			cout << "Your opponent's attack roll: " << catk-cwisbns-0 << endl;
			cout << "Your attack dodge roll.....: [" << pdod-spdbns-10 << "]" << endl;
			cout << "\n<<You effortlessly side-step the Masenko attack!>>";
			}	
		}

		if(cki < 5 && compzanzo)
		{
		compzanzo = false;
		out+= "\n\n<<Your opponent's body phases back into sight!>>";
		}

		{
			if(cki >= (ckimax)*(1.25))
				ckimaxbool = true;		

			else			
				ckimaxbool = false;			

			if(csp <= 0)		
				ctired = true;		

			else
				ctired = false;

		}
		
		if(ctired)
		{
		cdexbns = ((cdex-12)/2)+(csp*(.50));
		cwisbns = ((cwis-12)/2)+(csp*(.50));
		cstmbns = ((cstm-12)/2)+(csp*(.50));
		cstrbns = ((cstr-12)/2)+(csp*(.50));
		cspdbns = ((cspd-12)/2)+(csp*(.50));

			if(csp < cstm*(-.85))
			{
			cout << "\n\n<<Your opponent flinches, their body is suffering from FATIGUE!!>>";
			chp-= static_cast<int>(chpmax*(.05));
			}

			else if(csp >= cstm*(-.5))
				cout << "\n\n<<You notice your opponent is TIRED!>>";	

			if(compzanzo)
			{
			cdexbns+= (clvl+1);
			cspdbns+= (clvl+1);
			}

			else
			{
			cdexbns= ((cdex-12)/2);
			cspdbns= ((cspd-12)/2);
			}

			if(ckimaxbool)
				cwisbns+= 2;
	
			else
				cwisbns= ((cwis-12)/2);
		}	

		else
		{
		cdexbns = ((cdex-12)/2);
		cwisbns = ((cwis-12)/2);
		cstmbns = ((cstm-12)/2);
		cstrbns = ((cstr-12)/2);
		cspdbns = ((cspd-12)/2);

			if(compzanzo)
			{
			cdexbns+= (clvl+1);
			cspdbns+= (clvl+1);
			}

			else
			{
			cdexbns= ((cdex-12)/2);
			cspdbns= ((cspd-12)/2);
			}

			if(ckimaxbool)
				cwisbns+= 2;
	
			else
				cwisbns= ((cwis-12)/2);
		}

		if(php <= 0 || chp <= 0)
		{
		pause();
		killscreen();
		}

		if(out != "")
		{
		cout << out;
		out = "";
		}

	cc = 0;
	cout << "\n\n[APR " << capr << "]\n" << "[HP " << chp << "/" << chpmax << "]\n" << "[BH " << compbarrierhp << "]\n" << "[KI " << cki << "/" << ckimax << "]\n" << "[SP " << csp << "/" << cstm << "]";
	pause();
	}

return;
}












































/******************************************************************************/
/******************************PLAYER TURN*************************************/
/******************************************************************************/


















































void playerturn()
{

	pturn = true;

	for(aprc = 0; aprc < apr; aprc++)
	{		

		if(chp <= 0 || php <= 0)
			killscreen();
					
		else if(choice == "null")//     				 		PLAYER TURN
		{	
		playerheader();
		validity();

			if(choice == "rest")
			{
			system("CLS");
			cout << "You slowly lower your head and breathe deep, considering your next move.\n"
				 << "As you take a moment to collect your self your body feels a bit invigorated!\n\n";
			psp+= static_cast<int>(stm*(.35));
			cout << "You have gained [" << static_cast<int>(stm*(.35)) << "] SP!";

				if(psp >= stm)
					psp = stm;
			}
	
			if(choice == "senzubean" && pbean > 0)
			{
			system("CLS");
			cout << "You smile at your opponent while you dip your hand into a pouch.\n"
				 << "You quickly toss a Senzu Bean into your mouth, as you bite down\n"
				 << "You feel your body suddenly become fully invigorated!\n\n"
				 << "You have been fully healed!!\n\n";
			pbean--;
			php = phpmax;
			psp = stm;

			pstatus();
			}

			if(choice == "focuski" && kimax == false)
			{		
			system("CLS");
			cout << "You clench your fists and grit your teeth as you let out a powerful yell!\n"
				 << "Your feet begin to sink into the ground as a blue aura explodes around you.\n"
				 << "You feel ki arise from deep within you!";
			cc = (pow(1+rand()%3,2)*plvl+plvl*2);
			pki+=cc;
			focuskixp++;
			focuskiused= true;

			cout << "\n\nYou have collected [" << cc << "] Ki!\n\n";

				if(pki >= (pkimax*(1.25+focuskixp/100*.10)))
				{
				pki = (pkimax*(1.25+focuskixp/100*.10)+1);
				cout << "<<Your aura flickers intensly, your body has reached it's MAX KI!>>\n\n";
				}
			
			pstatus();
			}
		
			if(choice == "zanzoken" && zanzokentech && pki > (4+zanzokenxp/100))
			{
			aprc--;

				if(zanzo == false)
				{
				zanzo = true;
				cout << "\n<<Your body phases in and out of sight as ki rushes through your muscles!>>";
				}

				else if(zanzo)
				{
				zanzo = false;
				cout << "\n<<Your body phases back into sight as you slow down!>>";
				}
			
			}

			if(choice == "barrier")
			{
			system("CLS");
			pki-= ((barrierxp/100*10)+15);
			barrierhp= ((barrierxp/100*10)+15);
			barrier= true;

				if(pkimax >= (((1+barrierxp/100)*10)+15))
					barrierxp++;

				if(barrierhp >= (barrierxp/100*10)+15)
					barrierhp = ((barrierxp/100*10)+15);	

			cout << "You thrust your arms out as you focus your mind intensly.\n"
				 << "As you concentrate a soft blue aura slowly envolpes your body.\n"
				 << "You feel a barrier of ki set in place, shielding your body!\n\n"
				 << "Barrier Hp: +(" << ((barrierxp/100*10)+15) << ")\n\n";

			pstatus();
			}

			if(choice == "punch")//												PLAYER PUNCH
			{
			system("CLS");
			cout << "You throw a punch at your opponent!\n\n";
			psp--;
			punchxp+= 2;
			patk = (1 + rand() % 20) + dexbns + 0;					
			cdod = (1 + rand() % 20) + cdexbns + 0;

				if(patk > cdod && patk != 20+dexbns)//						    PLAYER PUNCH HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]";
				pdmg = ((punchxp/200 + 1) + rand() % (10 + (((punchxp+100)/200) - (punchxp/200))));
				meleecheck= true;
				cout << "\n\nYour Punch attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns && cdod != 20+cdexbns)// 	   			PLAYER PUNCH CRITICAL
				{
				punchxp++;
				cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((punchxp/200 + 1) + rand() % (10 + (((punchxp+100)/200) - (punchxp/200))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Punch lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns && patk == 20+dexbns)
				{
				cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;
				cout << "\nYour opponent has dodged your Punch attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns)//  	   				COMPUTER DODGES PUNCH 
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Punch attack.";
				}
			
				else//											 				COMPUTER COUNTERS PUNCH
				{
				cout << "Your attack roll..........: " << patk-dexbns << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;		
				cout << "\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent ducks under the Punch and quickly jumps into the air. Your eyes\n"
						 << "open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent quickly moves their head away from the Punch and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Elbow\n"
						 << "thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Punch.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Knee dig\n"
						 << "into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Punch.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as you hear your Punch whiz by your opponent.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			else if(choice == "elbow")//										PLAYER ELBOW
			{
			system("CLS");
			cout << "You race towards your opponent with an Elbow attack!\n\n";
			psp--;
			elbowxp+=2;
			patk = (1 + rand() % 20) + dexbns + 2;					
			cdod = (1 + rand() % 20) + cdexbns + 0;
		
				if(patk > cdod && patk != 20+dexbns+2)//						PLAYER ELBOW HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-2 << " (+2) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]";			
				pdmg = ((elbowxp/200 + 1) + rand() % (8 + (((elbowxp+100)/200) - (elbowxp/200))));
				meleecheck= true;
				cout << "\n\nYour Elbow attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns+2 && cdod != 20+cdexbns)// 			PLAYER ELBOW CRITICAL
				{
				elbowxp++;
				cout << "Your attack roll..........: [" << patk-dexbns-2 << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((elbowxp/200 + 1) + rand() % (8 + (((elbowxp+100)/200) - (elbowxp/200))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Elbow lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns && patk == 20+dexbns+2)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-2 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;
				cout << "\nYour opponent has dodged your Elbow attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns)//  			   		COMPUTER DODGES ELBOW 
				{
				cout << "Your attack roll..........: " << patk-dexbns-2 << " (+2) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Elbow attack.";
				}
			
				else//											 				COMPUTER COUNTERS ELBOW
				{
				cout << "Your attack roll..........: " << patk-dexbns-2 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;		
				cout << "\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent ducks under the Elbow and quickly jumps into the air. Your eyes\n"
						 << "open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent quickly moves their body away from the Elbow and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Elbow\n"
						 << "thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Elbow attack.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Knee dig\n"
						 << "into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Elbow attack.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as you hear your Elbow whiz by your opponent.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			if(choice == "headbutt")//									 		PLAYER HEADBUTT
			{
			system("CLS");
			cout << "You thrust towards your opponent with a Headbutt attack!\n\n";
			psp--;
			headbuttxp++;
			patk = (1 + rand() % 20) + dexbns + 4;					
			cdod = (1 + rand() % 20) + cdexbns + 0;
		
				if(patk > cdod && patk != 20+dexbns+4)//						PLAYER HEADBUTT HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-4 << " (+4) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]";			
				pdmg = ((headbuttxp/200 + 1) + rand() % (6 + (((headbuttxp+100)/200) - (headbuttxp/200))));
				meleecheck= true;
				cout << "\n\nYour Headbutt attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns+4 && cdod != 20+cdexbns)// 			PLAYER HEADBUTT CRITICAL
				{
				headbuttxp++;
				cout << "Your attack roll..........: [" << patk-dexbns-4 << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((headbuttxp/200 + 1) + rand() % (6 + (((headbuttxp+100)/200) - (headbuttxp/200))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Headbutt lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns && patk == 20+dexbns+4)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-4 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;
				cout << "\nYour opponent has dodged your Headbutt attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns)//  					COMPUTER DODGES HEADBUTT 
				{
				cout << "Your attack roll..........: " << patk-dexbns-4 << " (+4) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Headbutt attack.";
				}
			
				else//										  					COMPUTER COUNTERS HEADBUTT
				{
				cout << "Your attack roll..........: " << patk-dexbns-4 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;		
				cout << "\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent jumps over your Headbutt thrust and quickly into the air. Your eyes\n"
						 << "open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent jerks their head away from the Headbutt and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent pushes your Headbutt attack away, forcing you off-balance.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Elbow thrust\n"
						 << "into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cdexbns/2);
					cout << "Your opponent pushes your Headbutt attack away, forcing you off-balance.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Headbutt attack.\n"
						 << "Their eyes sharply spot an opening, suddenly you feel their Knee dig\n"
						 << "into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Headbutt attack.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as your Headbutt completely misses your opponent.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			if(choice == "doubleaxehandle")//									PLAYER DOUBLE AXE HANDLE
			{
			system("CLS");
			cout << "You jump up and over towards your opponent, coming down fiercly with\n"
				 << "both fists in a Double Axe Handle attack!\n\n";
			psp -= 2;
			doubleaxehandlexp+= 2;
			patk = (1 + rand() % 20) + dexbns + 6;					
			cdod = (1 + rand() % 20) + cdexbns + 0;
		
				if(patk > cdod && patk != 20+dexbns+6)//						PLAYER DOUBLE AXE HANDLE HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-6 << " (+6) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]";			
				pdmg = ((doubleaxehandlexp/200 + 1) + rand() % (4 + (((doubleaxehandlexp+100)/200) - (doubleaxehandlexp/200))));
				meleecheck= true;
				cout << "\n\nYour Double Axe Handle attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns+6 && cdod != 20+cdexbns)//    		PLAYER DOUBLE AXE HANDLE CRITICAL
				{
				doubleaxehandlexp++;	
				cout << "Your attack roll..........: [" << patk-dexbns-6 << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((doubleaxehandlexp/200 + 1) + rand() % (4 + (((doubleaxehandlexp+100)/200) - (doubleaxehandlexp/200))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Double Axe Handle lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns && patk == 20+dexbns+6)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-6 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;
				cout << "\nYour opponent has dodged your Double Axe Handle attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns)//  					COMPUTER DODGES DOUBLE AXE HANDLE 
				{
				cout << "Your attack roll..........: " << patk-dexbns-6 << " (+6)" << " (+" << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0)" << " (+" << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Double Axe Handle attack.";
				}
			
				else//								 							COMPUTER COUNTERS DOUBLE AXE HANDLE
				{
				cout << "Your attack roll..........: " << patk-dexbns-6 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]";		
				cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent ducks under your Double Axe Handle and quickly jumps into the air.\n"
						 << "Your eyes open, their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent dashes away from the Double Axe Handle and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent turns to you pushing your Double Axe Handle attack away.\n"
						 << "forcing you off-balance. Their eyes sharply fix to an opening under you.\n"
						 << "suddenly you feel their Elbow thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent turns to you pushing your Double Axe Handle attack away.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as your opponent gracefully avoids your Double Axe Handle attack.\n"
						 << "Their eyes sharply fix to an opening under you, suddenly you feel their Knee\n"
						 << "dig into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince your opponent gracefully avoids your Double Axe Handle attack.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as your Double Axe Handle completely misses your target.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			if(choice == "knee")//										     	PLAYER KNEE
			{
			system("CLS");
			cout << "You jump towards your opponent, shuffling your leg for a Knee attack!\n\n";
			psp--;
			kneexp++;
			patk = (1 + rand() % 20) + dexbns + 0;					
			cdod = (1 + rand() % 20) + cdexbns + 2;
		
				if(patk > cdod && patk != 20+dexbns)//							PLAYER KNEE HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-2 << " (+2) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;			
				pdmg = ((kneexp/200 + 2) + rand() % (11 + (((kneexp+100)/200) - (kneexp/200))));
				meleecheck= true;
				cout << "\nYour Knee attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns && cdod != 20+cdexbns+2)//   			PLAYER KNEE CRITICAL
				{
				kneexp++;	
				cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-2;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((kneexp/200 + 2) + rand() % (11 + (((kneexp+100)/200) - (kneexp/200))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Knee lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns+2 && patk == 20+dexbns)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-0 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-2 << "]" << endl;
				cout << "\nYour opponent has dodged your Knee attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns+2)//  				COMPUTER DODGES KNEE
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-2 << " (+2) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Knee attack.";
				}
			
				else//								 			  				COMPUTER COUNTERS KNEE
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-2 << "]";		
				cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent dashes away from your Knee and quickly jumps into the air.\n"
						 << "Your eyes open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent dashes away from the Knee attack and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Knee attack away.\n"
						 << "forcing you off-balance. Their eyes sharply fix to an opening under you.\n"
						 << "suddenly you feel their Elbow thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Knee attack away.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoids your Knee attack.\n"
						 << "Their eyes sharply fix to an opening under you, suddenly you feel their Knee\n"
						 << "dig into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoids your Knee.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as your Knee attack completely misses your target.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			if(choice == "kick")//										     	PLAYER KICK
			{
			system("CLS");
			cout << "You jump towards your opponent, shuffling your leg for a Kick attack!\n\n";
			psp -= 2;
			kickxp++;
			patk = (1 + rand() % 20) + dexbns + 0;					
			cdod = (1 + rand() % 20) + cdexbns + 4;
		
				if(patk > cdod && patk != 20+dexbns)//							PLAYER KICK HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-4 << " (+4) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;		
				pdmg = ((kickxp/200*2 + 2) + rand() % (15 + (((kickxp+100)/200) - (kickxp/200*2))));
				meleecheck= true;
				cout << "\nYour Kick attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns && cdod != 20+cdexbns+4)//   			PLAYER KICK CRITICAL
				{
				kickxp++;	
				cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-4;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((kickxp/200*2 + 2) + rand() % (15 + (((kickxp+100)/200) - (kickxp/200*2))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Kick lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns+4 && patk == 20+dexbns)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-0 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-4 << "]" << endl;
				cout << "\nYour opponent has dodged your Kick attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns+4)//  				COMPUTER DODGES KICK
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-4 << " (+4) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Kick attack.";
				}
			
				else//								 			  				COMPUTER COUNTERS KICK
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-4 << "]";		
				cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent dashes away from your Kick and quickly jumps into the air.\n"
						 << "Your eyes open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent dashes away from the Kick attack and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
						 << "forcing you off-balance. Their eyes sharply fix to an opening under you.\n"
						 << "suddenly you feel their Elbow thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Kick attack.\n"
						 << "Their eyes sharply fix to an opening under you, suddenly you feel their Knee\n"
						 << "dig into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Kick.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as your Kick attack completely misses your target.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense();
				}
			}		
		
			if(choice == "roundhouse")//										PLAYER ROUND HOUSE KICK
			{
			system("CLS");
			cout << "You spin around, hurling toward your opponent for a Round House Kick attack!\n\n";
			psp -= 2;
			roundhousexp++;
			patk = (1 + rand() % 20) + dexbns + 0;					
			cdod = (1 + rand() % 20) + cdexbns + 6;
		
				if(patk > cdod && patk != 20+dexbns)//							PLAYER ROUND HOUSE KICK HIT
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-6 << " (+6) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;			
				pdmg = ((roundhousexp/200*2 + 2) + rand() % (19 + (((roundhousexp+100)/200) - (roundhousexp/200*2))));
				meleecheck= true;
				cout << "\n\nYour Round House Kick attack lands, you have hit your target!!";
				defense();
				}
			
				else if(patk == 20+dexbns && cdod != 20+cdexbns+6)//   			PLAYER ROUND HOUSE KICK CRITICAL
				{
				roundhousexp++;	
				cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-6;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = ((roundhousexp/200*2 + 2) + rand() % (19 + (((roundhousexp+100)/200) - (roundhousexp/200*2))));
				pcrit = true;
				meleecheck= true;
				cout << "\n\nYour Round House Kick lands solid, you have hit your target!!";
				defense();
				}
							
				else if(cdod == 20+cdexbns+6 && patk == 20+dexbns)
				{
				cout << "Your attack roll..........: [" << patk-dexbns-0 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-6 << "]" << endl;
				cout << "\nYour opponent has dodged your Round House Kick attack.";
				}
		
				else if(cdod >= patk && cdod != 20+cdexbns+6)//  				COMPUTER DODGES ROUND HOUSE KICK
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
					if(dexbns >= 0)
						cout << "+";
						cout << dexbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cdexbns-6 << " (+6) (";
					if(cdexbns >= 0)
						cout << "+";
						cout << cdexbns << ") = [" << cdod << "]" << endl;
				cout << "\nYour opponent has dodged your Round House Kick attack.";
				}
			
				else//								  							COMPUTER COUNTERS ROUND HOUSE KICK
				{
				cout << "Your attack roll..........: " << patk-dexbns-0 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cdexbns-6 << "]";		
				cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
				cc = (1 + rand() % 7);

					if(cc == 1)
					{
					cdmg = (1 + rand() % 4)+(cstrbns/2);
					cout << "Your opponent dashes away from your Kick and quickly jumps into the air.\n"
						 << "Your eyes open wide as their fists slam into your back with a Double Axe Handle attack!";
					}
					else if(cc == 2)
					{
					cdmg = (1 + rand() % 6)+(cstrbns/2);
					cout << "Your opponent dashes away from the Kick attack and grabs your head.\n"
						 << "Your opponent then Headbutts you forcefully before you can recover!";
					}
					else if(cc == 3)
					{
					cdmg = (1 + rand() % 8)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
						 << "forcing you off-balance. Their eyes sharply fix to an opening under you.\n"
						 << "suddenly you feel their Elbow thrust into your side!";
					}
					else if(cc == 4)
					{
					cdmg = (1 + rand() % 10)+(cstrbns/2);
					cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
						 << "You staggers briefly, they then pummel you across your face with a Punch!";
					}
					else if(cc == 5)
					{
					cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Kick attack.\n"
						 << "Their eyes sharply fix to an opening under you, suddenly you feel their Knee\n"
						 << "dig into your stomach!";
					}
					else if(cc == 6)
					{
					cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
					cout << "You wince as you notice your opponent gracefully avoid your Kick.\n"
						 << "They quickly spring back, then jump forward Kicking deep into your chest!";
					}
					else if(cc == 7)
					{
					cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
					cout << "Your mind runs blank as your Kick attack completely misses your target.\n"
						 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
						 << "up-side your head. You feel your opponent's foot quake your head\n"
						 << "and neck as their Round House Kick connects!";
					}

				ccountercheck= true;
				defense(); 
				}
			}		
		
			if(choice == "grab")
			{
			system("CLS");
			cout << "You quickly jump towards your opponent with your arms open wide.\n"
				 << "You zero in on your opponent as you try to wrap your arms tightly\n"
				 << "around their body!\n\n";
			psp -= 2;
			patk = (1 + rand() % 20) + ((str+dex+spd)/4);					
			cdod = (1 + rand() % 20) + ((cstr+cdex+cspd)/4) + 5;

				if(patk > cdod)
				{
				cout << "Your attack roll..........: " << patk-((str+dex+spd)/4) << " (+0) ("; 
					if(((str+dex+spd)/4) >= 0)
						cout << "+";
						cout << ((str+dex+spd)/4) << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-((cstr+cdex+cspd)/4)-5 << " (+5) (";
					if(((cstr+cdex+cspd)/4) >= 0)
						cout << "+";
						cout << ((cstr+cdex+cspd)/4) << ") = [" << cdod << "]" << endl;
				}

				if(cdod > patk)
				{
		
				}
			}

			if(choice == "kiblast" && pki > 4)//								PLAYER KI BLAST
			{
			system("CLS");
			cout << "Your hands glow blue as you collect ki and form it into a small ball.\n"
				 << "You fix your eyes onto your opponent as you hurl the Ki Blast!\n\n";
			pki = pki - 5;
			kiblastxp++;
			patk = (1 + rand() % 20) + wisbns + 0;					
			cdod = (1 + rand() % 20) + cspdbns + 8;
		
				if(patk > cdod && patk != 20+wisbns)//							PLAYER KI BLAST HIT
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-8 << " (+8) (";
					if(cspdbns >= 0)
						cout << "+";
						cout << cspdbns << ") = [" << cdod << "]";		
				pdmg = (1 + rand() % 15)+(1 + rand() % 10);

				cout << "\n\nYour Ki Blast lands, a small explosion errupts on your target!!";
				defense();
				}
			
				else if(patk == 20+wisbns && cdod != 20+cspdbns+8)//   			PLAYER KI BLAST CRITICAL
				{
				kiblastxp++;
				cout << "Your attack roll..........: [" << patk-wisbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-8;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = (1 + rand() % 15)+(1 + rand() % 10);
				pcrit = true;
				
				cout << "\n\nYour Ki Blast lands a direct hit, a huge explosion errupts on your target!!";
				defense();
				}
							
				else if(cdod == 20+cspdbns+8 && patk == 20+wisbns)
				{
				cout << "Your attack roll..........: [" << patk-wisbns-0 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cspdbns-8 << "]";
				cout << "\n\nYour opponent slaps the Ki Blast away, you hear it explode in the distance.";
				}
		
				else if(cdod >= patk && cdod != 20+cspdbns+8)//  				COMPUTER DODGES KI BLAST
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-8 << " (+8) (";
					if(cspdbns >= 0)
						cout << "+";
						cout << cspdbns << ") = [" << cdod << "]";
				cout << "\n\nYour Ki Blast whizzes past your target and explodes off on the horizon.";
				}
			
				else//								  		 					COMPUTER COUNTERS KI BLAST
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cspdbns-8 << "]";		
				cout << "\n\n<<Your opponent effortlessly side-steps your Ki Blast!>>";
				}

			cout << "\n\nYour current KI: " << pki << "/" << pkimax;
			}
		
			if(choice == "dondonpa" && pki > 9)//								PLAYER DONDONPA
			{
			system("CLS");
			cout << "An intense blue aura of ki suddenly envlopes your hands. You look up and beam\n"
				 << "a sharp look towards your opponent. You grab your wrist and throw your\n"
				 << "arms up. As you point your hand to your opponent a scream leaves from\n"
				 << "the pit of your stomach.\n"
				 << "You bellow: \"DONDONPA...!!\"\n\n"
				 << "Your eyes shimmer as a massive ki wave explodes from your hands!\n\n";
			pki = pki - 10;
			dondonpaxp++;
			patk = (1 + rand() % 20) + wisbns + 0;					
			cdod = (1 + rand() % 20) + cspdbns + 10;
		
				if(patk > cdod && patk != 20+wisbns)//							PLAYER DONDONPA HIT
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-10 << " (+10) (";
					if(cspdbns >= 0)
						cout << "+";
						cout << cspdbns << ") = [" << cdod << "]";		
				pdmg = (1 + rand() % 25)+(1 + rand() % 10);

				cout << "\n\nYour Dondonpa lands! A dark, sparking explosion errupts on your target!!";
				defense();
				}
			
				else if(patk == 20+wisbns && cdod != 20+cspdbns+10)//   		PLAYER DONDONPA CRITICAL
				{
				dondonpaxp++;
				cout << "Your attack roll..........: [" << patk-wisbns << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-10;
				cout << "\n\n<<You have landed a CRITICAL hit!>>";
				pdmg = (1 + rand() % 25)+(1 + rand() % 10);
				pcrit = true;

				cout << "\n\nYour Dondonpa lands a direct hit, a HUGE explosion errupts on your target!!";
				defense();
				}
							
				else if(cdod == 20+cspdbns+10 && patk == 20+wisbns)
				{
				cout << "Your attack roll..........: [" << patk-wisbns-0 << "]" << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cspdbns-10 << "]";
				cout << "\n\nYour opponent slaps the Dondonpa away, you hear it explode in the distance.";
				}
		
				else if(cdod >= patk && cdod != 20+cspdbns+10)//  				COMPUTER DODGES DONDONPA
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cspdbns-10 << " (+10) (";
					if(cspdbns >= 0)
						cout << "+";
						cout << cspdbns << ") = [" << cdod << "]";
				cout << "\n\nYour Dondonpa whizzes past your target and explodes off on the horizon.";
				}
			
				else//								  		 					COMPUTER COUNTERS DONDONPA
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << endl;
				cout << "Your opponent's dodge roll: [" << cdod-cspdbns-10 << "]";		
				cout << "\n\n<<Your opponent effortlessly side-steps your Dondonpa attack!>>";
				}
	
			cout << "\n\nYour current KI: " << pki << "/" << pkimax;
			}

			if(choice == "multipunch" && multipunchtech)//						PLAYER MULTI-PUNCH
			{
			system("CLS");
			    mpcc = ((2 + multipunchxp/200) + rand() % (2 + multipunchxp/100));//											(1d2+1)
				psp -= (3 + ((multipunchxp/100 + multipunchxp/200)));

			cout << "You focus in on your opponent as you release a volley of punches!\n"
				 << "Your arms and fists become a blur as you release [" << mpcc << "] punches!";
			mpunchused = true;
			multipunchxp++;
			pause();

				for(mpc = 0; mpc < mpcc; mpc++)
				{
				multipunchxp++;
				system("CLS");
				cout << "You throw a punch at your opponent!\n\n";
				patk = (1 + rand() % 20) + dexbns + 0;					
				cdod = (1 + rand() % 20) + cdexbns + 0;
			
					if(patk > cdod && patk != 20+dexbns)//						PLAYER MULTI-PUNCH HIT
					{
					cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
						if(dexbns >= 0)
							cout << "+";
							cout << dexbns << ") = [" << patk << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
						if(cdexbns >= 0)
							cout << "+";
							cout << cdexbns << ") = [" << cdod << "]";
					pdmg = ((punchxp/200 + 1) + rand() % (10 + (((punchxp+100)/200) - (punchxp/200))));
					meleecheck= true;
					cout << "\n\nYour Punch attack lands, you have hit your target!!";
					defense();
					}
				
					else if(patk == 20+dexbns && cdod != 20+cdexbns)// 	   		PLAYER MULTI-PUNCH CRITICAL
					{
					multipunchxp++;
					cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns;
					cout << "\n\n<<You have landed a CRITICAL hit!>>";
					pdmg = ((punchxp/200 + 1) + rand() % (10 + (((punchxp+100)/200) - (punchxp/200))));;
					pcrit = true;
					meleecheck= true;
					cout << "\n\nYour Punch lands solid, you have hit your target!!";
					defense();
					}
								
					else if(cdod == 20+cdexbns && patk == 20+dexbns)
					{
					cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
					cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]" << endl;
					cout << "\nYour opponent has dodged your Punch attack.";
					}
			
					else if(cdod >= patk && cdod != 20+cdexbns)//  	   			COMPUTER DODGES MULTI-PUNCH 
					{
					cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
						if(dexbns >= 0)
							cout << "+";
							cout << dexbns << ") = [" << patk << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns-0 << " (+0) (";
						if(cdexbns >= 0)
							cout << "+";
							cout << cdexbns << ") = [" << cdod << "]" << endl;
					cout << "\nYour opponent has dodged your Punch attack.";
					}
				
					else//											 			COMPUTER COUNTERS MULTI-PUNCH
					{
					cout << "Your attack roll..........: " << patk-dexbns << endl;
					cout << "Your opponent's dodge roll: [" << cdod-cdexbns << "]";		
					cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n";
					cc = (1 + rand() % 7);
	
						if(cc == 1)
						{
						cdmg = (1 + rand() % 4)+(cstrbns/2);
						cout << "Your opponent ducks under the Punch and quickly jumps into the air. Your eyes\n"
							 << "open wide as their fists slam into your back with a Double Axe Handle attack!";
						}
						else if(cc == 2)
						{
						cdmg = (1 + rand() % 6)+(cstrbns/2);
						cout << "Your opponent quickly moves their head away from the Punch and grabs your head.\n"
							 << "Your opponent then Headbutts you forcefully before you can recover!";
						}
						else if(cc == 3)
						{
						cdmg = (1 + rand() % 8)+(cstrbns/2);
						cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
							 << "Their eyes sharply spot an opening, suddenly you feel their Elbow\n"
							 << "thrust into your side!";
						}
						else if(cc == 4)
						{
						cdmg = (1 + rand() % 10)+(cstrbns/2);
						cout << "Your opponent crosses their arm with yours, forcing you off-balance.\n"
							 << "You staggers briefly, they then pummel you across your face with a Punch!";
						}
						else if(cc == 5)
						{
						cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
						cout << "You wince as you notice your opponent gracefully avoid your Punch.\n"
							 << "Their eyes sharply spot an opening, suddenly you feel their Knee dig\n"
							 << "into your stomach!";
						}
						else if(cc == 6)
						{
						cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
						cout << "You wince as you notice your opponent gracefully avoid your Punch.\n"
							 << "They quickly spring back, then jump forward Kicking deep into your chest!";
						}
						else if(cc == 7)
						{
						cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
						cout << "Your mind runs blank as you hear your Punch whiz by your opponent.\n"
							 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
							 << "up-side your head. You feel your opponent's foot quake your head\n"
							 << "and neck as their Round House Kick connects!";
						}

					ccountercheck= true;
					defense();
					}

					zanzoken();

					if(chp <=0)
					{
					pause();
					killscreen();
					}

					if(mpc+1 != mpcc)
						pause();
				}
			}

			if(choice == "multikick" && multikicktech)//						PLAYER MULTI-KICK
			{

				mkcc = ((2 + multikickxp/200) + rand() % (2 + multikickxp/100));//											(1d2+1)
				psp -= (4 + ((multikickxp/100 + multikickxp/200)));

			system("CLS");
			cout << "You focus in on your opponent as you release a multi-kick!\n"
				 << "Your legs and feet become a blur as you release [" << mkcc << "] kicks!";
			mkickused = true;
			multikickxp++;
			pause();

				for(mkc = 0; mkc < mkcc; mkc++)
				{
				multikickxp++;
				system("CLS");
				cout << "You jump towards your opponent, shuffling your leg for a Kick attack!\n\n";
				patk = (1 + rand() % 20) + dexbns + 0;					
				cdod = (1 + rand() % 20) + cdexbns + 4;

					if(patk > cdod && patk != 20+dexbns)//						PLAYER MULTIKICK HIT
					{
					cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
						if(dexbns >= 0)
							cout << "+";
							cout << dexbns << ") = [" << patk << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns-4 << " (+4) (";
						if(cdexbns >= 0)
							cout << "+";
							cout << cdexbns << ") = [" << cdod << "]" << endl;		
					pdmg = ((kickxp/200*2 + 2) + rand() % (15 + (((kickxp+100)/200) - (kickxp/200*2))));
					meleecheck= true;
					cout << "\nYour Kick attack lands, you have hit your target!!";
					defense();
					}
				
					else if(patk == 20+dexbns && cdod != 20+cdexbns+4)//   		PLAYER MULTIKICK CRITICAL
					{
					multikickxp++;
					cout << "Your attack roll..........: [" << patk-dexbns << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns-4;
					cout << "\n\n<<You have landed a CRITICAL hit!>>";
					pdmg = ((kickxp/200*2 + 2) + rand() % (15 + (((kickxp+100)/200) - (kickxp/200*2))));;
					pcrit = true;
					meleecheck= true;
					cout << "\nYour Kick lands solid, you have hit your target!!";
					defense();
					}
								
					else if(cdod == 20+cdexbns+4 && patk == 20+dexbns)
					{
					cout << "Your attack roll..........: [" << patk-dexbns-0 << "]" << endl;
					cout << "Your opponent's dodge roll: [" << cdod-cdexbns-4 << "]" << endl;
					cout << "\nYour opponent has dodged your Kick attack.";
					}
			
					else if(cdod >= patk && cdod != 20+cdexbns+4)//  			COMPUTER DODGES MULTIKICK
					{
					cout << "Your attack roll..........: " << patk-dexbns-0 << " (+0) ("; 
						if(dexbns >= 0)
							cout << "+";
							cout << dexbns << ") = [" << patk << "]" << endl;
					cout << "Your opponent's dodge roll: " << cdod-cdexbns-4 << " (+4) (";
						if(cdexbns >= 0)
							cout << "+";
							cout << cdexbns << ") = [" << cdod << "]" << endl;		
					cout << "\nYour opponent has dodged your Kick attack.";
					}
				
					else//								 			  			COMPUTER COUNTERS MULTKICK
					{
					cout << "Your attack roll..........: " << patk-dexbns-0 << endl;
					cout << "Your opponent's dodge roll: [" << cdod-cdexbns-4 << "]";		
					cout << "\n\n<<Your opponent swiftly dodges the attack and returns with a COUNTER!>>\n\n";
					cc = (1 + rand() % 7);
	
						if(cc == 1)
						{
						cdmg = (1 + rand() % 4)+(cstrbns/2);
						cout << "Your opponent dashes away from your Kick and quickly jumps into the air.\n"
							 << "Your eyes open wide as their fists slam into your back with a Double Axe Handle attack!";
						}
						else if(cc == 2)
						{
						cdmg = (1 + rand() % 6)+(cstrbns/2);
						cout << "Your opponent dashes away from the Kick attack and grabs your head.\n"
							 << "Your opponent then Headbutts you forcefully before you can recover!";
						}
						else if(cc == 3)
						{
						cdmg = (1 + rand() % 8)+(cstrbns/2);
						cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
							 << "forcing you off-balance. Their eyes sharply fix to an opening under you.\n"
							 << "suddenly you feel their Elbow thrust into your side!";
						}
						else if(cc == 4)
						{
						cdmg = (1 + rand() % 10)+(cstrbns/2);
						cout << "Your opponent turns to you, pushing your Kick attack aside.\n"
							 << "You staggers briefly, they then pummel you across your face with a Punch!";
						}
						else if(cc == 5)
						{
						cdmg = (1 + rand() % 6)+(1 + rand() % 6)+(cstrbns/2);
						cout << "You wince as you notice your opponent gracefully avoid your Kick attack.\n"
							 << "Their eyes sharply fix to an opening under you, suddenly you feel their Knee\n"
							 << "dig into your stomach!";
						}
						else if(cc == 6)
						{
						cdmg = (1 + rand() % 8)+(1 + rand() % 8)+(cstrbns/2);
						cout << "You wince as you notice your opponent gracefully avoid your Kick.\n"
							 << "They quickly spring back, then jump forward Kicking deep into your chest!";
						}
						else if(cc == 7)
						{
						cdmg = (1 + rand() % 10)+(1 + rand() % 10)+(cstrbns/2);
						cout << "Your mind runs blank as your Kick attack completely misses your target.\n"
							 << "Your opponent spins quickly. Their spin gains momentum and finishes\n" 
							 << "up-side your head. You feel your opponent's foot quake your head\n"
							 << "and neck as their Round House Kick connects!";
						}

					ccountercheck= true;
					defense(); 
					}

					zanzoken();

					if(chp <=0)
					{
					pause();
					killscreen();
					}

					if(mkc+1 != mkcc)
						pause();
				}
			}

			if(choice == "solarflare" && solarflaretech)//						PLAYER SOLAR FLARE
			{
			system("CLS");										
			cout << "You open your hands wide and place them next to your face.\n"
				 << "You quickly close your eyes as you scream,\"SOLAR FLARE!\"\n\n"
				 << "An intense explosion of pure ki illuminates towards your opponent!\n\n";
			solarflareused = true;
			pki = (pki - (10 + ((solarflarexp/100)*5)));
			solarflarexp++;
			patk = (1 + rand() % 20) + wisbns + 0;					
			cdod = (1 + rand() % 20) + cintbns + 5;

				if(patk > cdod)//												PLAYER SOLAR FLARE HIT
				{
				sfc = ((1 + solarflarexp/200) + rand() % (2 + solarflarexp/100));

				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cintbns-5 << " (+5) (";
					if(cintbns >= 0)
						cout << "+";
						cout << cintbns << ") = [" << cdod << "]";
				cout << "\n\nYour burst of dense light soaks into your opponent's retnas!\n";
				cout << "Your opponent has been blinded for [" << sfc << "] actions!";
				sf = true;		
				}
			
				else//  														COMPUTER DODGES SOLAR FLARE
				{
				cout << "Your attack roll..........: " << patk-wisbns-0 << " (+0) ("; 
					if(wisbns >= 0)
						cout << "+";
						cout << wisbns << ") = [" << patk << "]" << endl;
				cout << "Your opponent's dodge roll: " << cdod-cintbns-5 << " (+5) (";
					if(cintbns >= 0)
						cout << "+";
						cout << cintbns << ") = [" << cdod << "]";
				cout << "\n\nYour opponent shuts his eyes almost instinctivly, your Solar Flare\n"
					 << "was ineffective!";
				}

			cout << "\n\nYour current KI: " << pki << "/" << pkimax;		
			}

			{
				if(pki >= (pkimax*(1.25+focuskixp/100*.10)))
					kimax = true;
	
				else
					kimax = false;
	
				if(psp <= 0)
					tired = true;

				else
					tired = false;

			}

			if(compzanzo && choice != "multipunch" && choice != "multikick" && choice != "solarflare" && choice != "barrier" && choice != "rest" && choice != "senzubean" && choice != "focuski")
			{
			cki-= (clvl+4);
				
				if(cki < 5)
				{
				compzanzo = false;
				cout << "\n\n<<Your opponent's body phases back into sight!>>";
				cdexbns = ((cdex-12)/2);
				cspdbns = ((cspd-12)/2);
				}	
			}

			if(zanzo)
			{
				
				if(pki < 5)
				{
				zanzo = false;
				cout << "\n\n<<Your body phases back into sight, your Zanzoken has stopped!>>";
				}

				else if(choice != "multipunch" && choice != "multikick" && choice != "kiblast" && choice != "dondonpa" && choice != "solarflare" && choice != "barrier" && choice != "rest" && choice != "senzubean" && choice != "focuski")
				{

					if(choice != "zanzoken")
					{
					zanzokentech++;
					pki-=5;

						if(pki < 5)
						{
						zanzo = false;
						cout << "\n\n<<Your body phases back into sight, your Zanzoken has stopped!>>";
						}
					}

				}

			}

			if(tired)
			{
			dexbns = ((dex-12)/2)+(psp*(.50));
			wisbns = ((wis-12)/2)+(psp*(.50));
			stmbns = ((stm-12)/2)+(psp*(.50));
			strbns = ((str-12)/2)+(psp*(.50));
			spdbns = ((spd-12)/2)+(psp*(.50));
	
				if(psp >= stm*(-.5) && choice != "rest")
					cout << "\n\n<<Your body and mind weaken, you are TIRED!>>";	
		
				if(psp < stm*(-.85) && choice != "rest")
				{
				cout << "\n\n<<Your body has reached it's limit and begins to shut down!!>>\n\n";
				php-= static_cast<int>(phpmax*(.05));
				cout << "You have lost [" << static_cast<int>(phpmax*(.05)) << "] hp from FATIGUE!!\n\n";
				pstatus();
				}
			
				if(zanzo)
				{
				dexbns += (zanzokenxp/100+2);
				spdbns += (zanzokenxp/100+2);
				}

				if(kimax)
					wisbns += (focuskixp/100+2);			
			}
			
			else
			{
	
				initiate();

				if(zanzo)
				{
				dexbns += (zanzokenxp/100+2);
				spdbns += (zanzokenxp/100+2);
				}

				else
				{
				dexbns = ((dex-12)/2);
				spdbns = ((spd-12)/2);	
				}

				if(kimax)
					wisbns += (focuskixp/100+2);

				else
					wisbns = ((wis-12)/2);
			}

			if(chp <= 0 || php <= 0)
			{
			pause();
			killscreen();
			}

		}

		if(out != "")
		{
		cout << out;
		out = "";
		}

	cc = 0;
	cout << "\n\n[APR " << capr << "]\n" << "[HP " << chp << "/" << chpmax << "]\n" << "[BH " << compbarrierhp << "]\n" << "[KI " << cki << "/" << ckimax << "]\n" << "[SP " << csp << "/" << cstm << "]";
	choice = "null";
	pause();		
	}

pturn = false;
choice = "null";
return;
}

void menu()
{

	do
	{
		system("CLS");
		cout << "\t\t\t\t *Menu*" << endl << endl
			 << "\t\t\t  " << ulp << setw(19) << setfill(mp) << urp << endl
		     << "\t\t\t  " << vp << setw(19) << setfill(sp) << vp << endl
			 << "\t\t\t  " << vp << setw(18) << left << " 1. Character" << vp << endl
			 << "\t\t\t  " << vp << setw(18) << " 2. Inventory" << vp << endl
			 << "\t\t\t  " << vp << setw(18) << " 3. Training" << vp << endl
			 << "\t\t\t  " << vp << setw(18) << "" << vp << endl
			 << "\t\t\t  " << vp << setw(18) << " 'X' -- Exit" << vp << endl
			 << "\t\t\t  " << vp << setw(19) << right << setfill(sp) << vp << endl
			 << "\t\t\t  " << llp << setw(19) << setfill(mp) << lrp << endl << endl << setfill(sp)
			 << "What would you like to do? ";
		usrp = toupper(getch());

		if(usrp == '1')
			charscreen();

		if(usrp == '2')
		{
	
			do
			{
				system("CLS");
				cout << "\t\t\t     *Inventory*" << endl << endl
					 << "\t\t\t  " << ulp << setw(17) << setfill(mp) << urp << endl
				     << "\t\t\t  " << vp << setw(17) << setfill(sp) << vp << endl
					 << "\t\t\t  " << vp << setw(16) << left << " 1. Items" << vp << endl
					 << "\t\t\t  " << vp << setw(16) << " 2. Clothing" << vp << endl
					 << "\t\t\t  " << vp << setw(16) << " 3. Armor" << vp << endl
					 << "\t\t\t  " << vp << setw(16) << " 4. Accessories" << vp << endl
					 << "\t\t\t  " << vp << setw(16) << "" << vp << endl
					 << "\t\t\t  " << vp << setw(16) << " 'X' -- Back" << vp << endl
					 << "\t\t\t  " << vp << setw(17) << right << setfill(sp) << vp << endl
					 << "\t\t\t  " << llp << setw(17) << setfill(mp) << lrp << endl << endl << setfill(sp)
					 << "\nWhat would you like to do? ";
				usrp = toupper(getch());

				if(usrp == '1')
				{
				system("CLS");
				cout << "\t\t\t*Items*\n\n";
	
					if(pbean > 0)
					cout << pbean << " Senzu Bean(s)";
	
				pause();
				}
	
				else if(usrp == '2')
				{
					usrp = 0;

					do
					{
	
					system("CLS");
					cout << "\t\t\t*Clothing*";
				
						if(usrp > count - 1 + '0' || usrp < '0')
						{
							if(usrp == 'D' && dhold < check)
								usrp = check - 1;
							else if(usrp == 'D' && dhold == check)
								usrp = '0';
							else
								usrp = check;
						}
				
						if(usrp == '0')
						{
							str=strmax;
							stm=stmmax;
							dex=dexmax;
							spd=spdmax;
							wis=wismax;
							wtxp = 0;
							initiate();
						}
				
						cout << "\n\nYour STR is now " << str << endl;
						cout << "Your DEX is now " << dex << endl;
						cout << "Your SPD is now " << spd << endl;
						cout << "Your stat xp bonus is now +" << wtxp << endl << endl;
						
						check = 0;
						count = 1;
				
						if(wcloth15)
						{			
							cout << count++ << ") Weighted Clothing x15";	
				
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
				
					    if(wcloth25)
						{	
							cout << count++ << ") Weighted Clothing x25";
				
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
				
						if(wcloth50)
						{	
							cout << count++ << ") Weighted Clothing x50";
						
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
						
						if(wcloth75)
						{	
							cout << count++ << ") Weighted Clothing x75";
						
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}

						if(wcloth100)
						{	
							cout << count++ << ") Weighted Clothing x100";
						
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}

						if(count == 1)
							cout << "No Items!\n";
					
						x = 0;
						
						if(wcloth15)
						{
							equip[x][0] = 1.15;
							equip[x++][1] = 1;
						}	
				
						if(wcloth25)
						{
							equip[x][0] = 1.25;
							equip[x++][1] = 2;
						}
				
						if(wcloth50)
						{
							equip[x][0] = 1.5;
							equip[x++][1] = 3;
						}

						if(wcloth75)
						{
							equip[x][0] = 1.75;
							equip[x++][1] = 4;
						}

						if(wcloth100)
						{
							equip[x][0] = 2;
							equip[x++][1] = 5;
						}
						
						if(var > usrp)
							cout << "\nNot a valid number!\n";

						cout << "\nPick # to Equip -- Press '0' to Unequip\n"
							 << "\n<Press 'D' for Destroy Menu -- Press 'X' to Exit>: ";
						usrp = toupper(getch());

						var = usrp;	

						if(usrp == 'D')
						{
	
							cout << "\n\nWhich item would you like to Destroy? ";
							usrp = getch();
				
							dhold = usrp;

							x = 0;

							if(wcloth15)
								destroy[x++] = 1;
							if(wcloth25)
								destroy[x++] = 1;
							if(wcloth50)
								destroy[x++] = 1;
							if(wcloth75)
								destroy[x++] = 1;
							if(wcloth100)
								destroy[x++] = 1;

							destroy[usrp - 49] = 0;

							x = 0;

							if(wcloth15 && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Weighted Clothing x15? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());

								if(usrp == 'Y')
								{
									wcloth15 = false;
									x++;
								}

							}
							if(wcloth15)
								x++;

							if(wcloth25 && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Weighted Clothing x25? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());

								if(usrp == 'Y')
								{
									wcloth25 = false;
									x++;
								}
							}
							if(wcloth25)
								x++;

							if(wcloth50 && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Weighted Clothing x50? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());

								if(usrp == 'Y')
								{
									wcloth50 = false;
									x++;
								}
							}
							if(wcloth50)
								x++;
							
							if(wcloth75 && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Weighted Clothing x75? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());

								if(usrp == 'Y')
								{
									wcloth75 = false;
									x++;
								}
							}
							if(wcloth75)
								x++;
				
							if(wcloth100 && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Weighted Clothing x100? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());

								if(usrp == 'Y')
								{
									wcloth100 = false;
									x++;
								}
							}
							if(wcloth100)
								x++;									 
							
							usrp = 'D';
							var = 0;
						}

						x = 0;
					
						while(x < count - 1)
						{
							if(usrp == x + '1')
							{
								str=strmax;
								stm=stmmax;
								dex=dexmax;
								spd=spdmax;
								wis=wismax;
								wtxp = 0;
								initiate();

								str /= equip[x][0];
								dex /= equip[x][0];
								spd /= equip[x][0];
								wtxp = equip[x][1];

								initiate();		
							}
				
							x++;	
						}
				
					}
					while(usrp != 'X');
	
					usrp = 0;

				}

				else if(usrp == '3')
				{
			
					usrp = 0;

					do
					{
	
						system("CLS");	
						cout << "\t\t\t*Armor*";

						if(usrp > count - 1 + '0' || usrp < '0')
						{
							if(usrp == 'D' && dhold < check)
								usrp = check - 1;
							else if(usrp == 'D' && dhold == check)
								usrp = '0';
							else
								usrp = check;
						}
				
						if(usrp == '0')
						 	parmorhp = 0;
				
						cout << "\n\nArmor HP = [" << parmorhp << "]" << endl << endl;
						
						check = 0;
						count = 1;
				
						if(saiyanArmorB)
						{			
							cout << count++ << ") Basic Saiyan Armor";	
				
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
				
					    if(saiyanArmorA)
						{	
							cout << count++ << ") Advanced Saiyan Armor";
				
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
				
						if(saiyanArmorE)
						{	
							cout << count++ << ") Elite Saiyan Armor";
						
							if(usrp == count - 1 + '0')
							{
								cout << " [Equiped]";
								check = usrp;
							}
				
							cout << endl;
						}
	
						if(count == 1)
							cout << "No Items!\n";
					
						x = 0;
						
						if(saiyanArmorB && parmorhp == 0)
							armor[x++][0] = 25;
						else if(saiyanArmorB && parmorhp > 0 && parmorhp < 25)
							armor[x++][0] = parmorhp;
				
						if(saiyanArmorA && parmorhp == 0)
							armor[x++][0] = 50;

						if(saiyanArmorE && parmorhp == 0)
							armor[x++][0] = 75;
						
						if(var > usrp)
							cout << "\nNot a valid number!\n";
	
						cout << "\nPick # to Equip -- Press '0' to Unequip\n"
							 << "\n<Press 'D' for Destroy Menu -- Press 'X' to Exit>: ";
						usrp = toupper(getch());
	
						var = usrp;	
	
						if(usrp == 'D')
						{
	
							cout << "\n\nWhich item would you like to Destroy? ";
							usrp = getch();
				
							dhold = usrp;
	
							x = 0;
	
							if(saiyanArmorB)
								destroy[x++] = 1;
							if(saiyanArmorA)
								destroy[x++] = 1;
							if(saiyanArmorE)
								destroy[x++] = 1;
	
							destroy[usrp - 49] = 0;
	
							x = 0;
	
							if(saiyanArmorB && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Basic Saiyan Armor? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());
	
								if(usrp == 'Y')
								{
									saiyanArmorB = false;
									x++;
								}
	
							}
							if(saiyanArmorB)
								x++;
	
							if(saiyanArmorA && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Advanced Saiyan Armor? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());
	
								if(usrp == 'Y')
								{
									saiyanArmorA = false;
									x++;
								}
							}
							if(saiyanArmorA)
								x++;
	
							if(saiyanArmorE && destroy[x] == 0)
							{
								cout << "\n\nAre you sure, Destroy Elite Saiyan Armor? (Y/N): ";
								while(usrp != 'Y' && usrp != 'N')
									usrp = toupper(getch());
	
								if(usrp == 'Y')
								{
									saiyanArmorE = false;
									x++;
								}
							}
							if(saiyanArmorE)
								x++;									 
							
							usrp = 'D';
							var = 0;
						}
	
						x = 0;
					
						while(x < count - 1)
						{
							if(usrp == x + '1')
							{
//								parmorhp = 0;
								parmorhp = armor[x][0];
							}
				
							x++;	
						}

					}
					while(usrp != 'X');

					usrp = 0;

				}

				else if(usrp == '4')
				{
				system("CLS");
				cout << "\t\t\t*Accesories*";

				pause();
				}

			}
			while(usrp != 'X');

			usrp = 0;

		}

		if(usrp == '3')
		{
			do
			{
				system("CLS");
				cout << "\t\t\t       *Training*" << endl << endl
					 << "\t\t\t  " << ulp << setw(20) << setfill(mp) << urp << endl
				     << "\t\t\t  " << vp << setw(20) << setfill(sp) << vp << endl
					 << "\t\t\t  " << vp << setw(19) << left << " 1. Stat Training" << vp << endl
					 << "\t\t\t  " << vp << setw(19) << " 2. Melee Attacks" << vp << endl
					 << "\t\t\t  " << vp << setw(19) << " 3. Ki Attacks" << vp << endl
					 << "\t\t\t  " << vp << setw(19) << " 4. Abilities" << vp << endl
					 << "\t\t\t  " << vp << setw(19) << "" << vp << endl
					 << "\t\t\t  " << vp << setw(19) << " 'X' -- Back" << vp << endl
					 << "\t\t\t  " << vp << setw(20) << right << setfill(sp) << vp << endl
					 << "\t\t\t  " << llp << setw(20) << setfill(mp) << lrp << endl << endl << setfill(sp)
					 << "\nWhat would you like to do? ";
				usrp = toupper(getch());

				if(usrp == '1')
					stattraining();

				else if(usrp == '2')
					meleeattacks();

				else if(usrp == '3')
					kiattacks();

				else if(usrp == '4')
					abilities();

			}
			while(usrp != 'X');

			usrp = 0;
		}

	}
	while(usrp != 'X');	

return;
}

void stattraining()
{

	system("CLS");
	cout << "School of Training: "
		 << "\nCurrent Symbol Worn: "
		 << "\nCurrent Stat XP Modifer: +" << wtxp
		 << "\n\nCore Stat" << setw(17) << "XP %" << setw(12) << "Bonus"
		 << "\n---------" << setw(17) << "----" << setw(12) << "-----"
		 << "\n\nSTR" << setw(22) << strxp % 100 << "%" << setw(10) << "[+" << (strxp/100) << "]"
		 << "\n\nSTM" << setw(22) << stmxp % 100 << "%" << setw(10) << "[+" << (stmxp/100) << "]"
		 << "\n\nDEX" << setw(22) << dexxp % 100 << "%" << setw(10) << "[+" << (dexxp/100) << "]"
		 << "\n\nSPD" << setw(22) << spdxp % 100 << "%" << setw(10) << "[+" << (spdxp/100) << "]"
		 << "\n\nWIS" << setw(22) << wisxp % 100 << "%" << setw(10) << "[+" << (wisxp/100) << "]";

		pause();
	
}

void meleeattacks()
{
	
	system("CLS");
	cout << "Melee Attacks" << setw(34) << "XP %\n"
		 << "-------------" << setw(35) << "----\n\n"
		 << "Double Axe Handle [LVL: " << (doubleaxehandlexp/100)+1 << "]" << setw(19) << doubleaxehandlexp % 100 << "%\n"
		 <<	"Strike +6" << endl << "Dodge  +0" << endl
		 << "Damage 1d" << (4 + (((doubleaxehandlexp+100)/200)));
			if(doubleaxehandlexp > 199)
				cout << "+" << (doubleaxehandlexp/200);
	cout <<	"\n\nHeadbutt          [LVL: " << (headbuttxp/100)+1 << "]" << setw(19) << headbuttxp % 100 << "%\n"
		 <<	"Strike +4" << endl << "Dodge  +0" << endl
		 << "Damage 1d" << (6 + (((headbuttxp+100)/200)));
			if(headbuttxp > 199)
				cout << "+" << (headbuttxp/200);
	cout <<	"\n\nElbow             [LVL: " << (elbowxp/100)+1 << "]" << setw(19) << elbowxp % 100 << "%\n"
		 <<	"Strike +2" << endl << "Dodge  +0" << endl
		 << "Damage 1d" << (8 + (((elbowxp+100)/200)));
			if(elbowxp > 199)
				cout << "+" << (elbowxp/200);
	cout << "\n\nPunch             [LVL: " << (punchxp/100)+1 << "]" << setw(19) << punchxp % 100 << "%\n"
		 <<	"Strike +0" << endl << "Dodge  +0" << endl
		 << "Damage 1d" << (10 + (((punchxp+100)/200)));
			if(punchxp > 199)
				cout << "+" << (punchxp/200);
	cout <<	"\n\nKnee              [LVL: " << (kneexp/100)+1 << "]" << setw(19) << kneexp % 100 << "%\n"
		 <<	"Strike +0" << endl << "Dodge  +2" << endl
		 << "Damage 2d" << (6 + (((kneexp+100)/200)));
			if(kneexp > 199)
				cout << "+" << (kneexp/200)*2;
	cout << "\n\nKick              [LVL: " << (kickxp/100)+1 << "]" << setw(19) << kickxp % 100 << "%\n"
		 <<	"Strike +0" << endl << "Dodge  +4" << endl
		 << "Damage 2d" << (8 + (((kickxp+100)/200)));
			if(kickxp > 199)
				cout << "+" << (kickxp/200)*2;
	cout << "\n\nRound House Kick  [LVL: " << (roundhousexp/100)+1 << "]" << setw(19) << roundhousexp % 100 << "%\n"
		 <<	"Strike +0" << endl << "Dodge  +6" << endl
		 << "Damage 2d" << (10 + (((roundhousexp+100)/200)));
			if(roundhousexp > 199)
				cout << "+" << (roundhousexp/200)*2;

	if(multipunchtech)
	{
	cout << "\n\nMulti-Punch       [LVL: " << (multipunchxp/100)+1 << "]" << setw(19) << multipunchxp % 100 << "%"
		 << "\nPunches: 2d" << (2 + multipunchxp/100);
			if(multikickxp > 199)
				cout << "+" << (multipunchxp/200)*2;
	cout << "\nStm Cost: " << (3 + ((multipunchxp/100 + multipunchxp/200)));
	}		 

	if(multikicktech)
	{	
	cout << "\n\nMulti-Kick        [LVL: " << (multikickxp/100)+1 << "]" << setw(19) << multikickxp % 100 << "%"
		 << "\nKicks: 2d" << (2 + multikickxp/100);
			if(multikickxp > 199)
				cout << "+" << (multikickxp/200)*2;
	cout << "\nStm Cost: " << (4 + ((multikickxp/100 + multikickxp/200)));
	}

	pause();
	
}

void kiattacks()
{
	system("CLS");
	cout << "Ki Attacks" << setw(34) << "XP %\n"
		 << "----------" << setw(35) << "----\n\n"
		 << "Ki Blast" << setw(28) << "[LVL: " << (kiblastxp/100)+1 << "]" << setw(4) << kiblastxp % 100 << "%\n"
		 << "The most basic of ki discharge attacks.\n"
		 << "Ki Cost: " << 5 << endl
		 << "Damage : 2d" << 10 << endl << endl
		 << "Dondonpa" << setw(28) << "[LVL: " << (dondonpaxp/100)+1 << "]" << setw(4) << dondonpaxp % 100 << "%";

	pause();
}

void abilities()
{
	system("CLS");
	cout << "Abilities" << setw(34) << "XP %\n"
		 << "---------" << setw(35) << "----\n\n"
		 << "Focus Ki                [LVL: " << (focuskixp/100)+1 << "]" << setw(9) << focuskixp % 100 << "%\n";

		if(sensekitech)
			cout << "Sense Ki     (passive)  [LVL: " << (sensekixp/100)+1 << "]" << setw(9) << sensekixp % 100 << "%\n";

		if(blocktech)
			cout << "Block        (passive)  [LVL: " << (blockxp/100)+1 << "]" << setw(9) << blockxp % 100 << "%\n";

		if(solarflaretech)
			cout << "Solar Flare             [LVL: " << (solarflarexp/100)+1 << "]" << setw(9) << solarflarexp % 100 << "%\n";

		if(zanzokentech)
			cout << "Zanzoken                [LVL: " << (zanzokenxp/100)+1 << "]" << setw(9) << zanzokenxp % 100 << "%\n";

		if(barriertech)
			cout << "Barrier                 [LVL: " << (barrierxp/100)+1 << "]" << setw(9) << barrierxp % 100 << "%";

	pause();
}

void killscreen()
{
	
	if(chp <= 0)//											  					COMPUTER DEATH
	{
	barrierhp = 0;
	compbarrierhp =0;
	barrier = false;
	compbarrier = false;
	zanzo = false;
	compzanzo = false;
	kimax = false;
	mpunchused = false;
	mkickused = false;
	compmpunchused = false;
	compmkickused = false;
	dexbns = ((dex-12)/2);
	spdbns = ((spd-12)/2);
	wisbns = ((wis-12)/2);
	php = phpmax;
	pki = pkimax;
	psp = stm;
	pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
	chp=chpmax;
	cki=ckimax;
	csp=cstm;
	cwisbns = ((cwis-12)/2);
	cpl=((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;
	xp+= (cplmax/6);

		if(xp >= nxtxp)
		{
		plvl++;
		str++;
		dex++;
		spd++;
		stm++;
		wis++;

		wismax = wis;

		dexbns = (dex-12)/2;
		wisbns = (wis-12)/2;
		stmbns = (stm-12)/2;
		strbns = (str-12)/2;
		spdbns = (spd-12)/2;
		
			if(stmbns < 0)
				stmbns = -2;	

		phpmod = (stmbns*8)+(plvl*10);
		pkimod = (wisbns*2)+(plvl*5);

		php = (php + phpmod);
		pki = (pki + pkimod);
		phpmax = php;
		pkimax = pki;
	
		psp = stm;
		apr = (dex+spd)/12;
		
		nhpmod = (stmbns*8)+((plvl+1)*10);
		nkimod = (wisbns*2)+((plvl+1)*5);
		intbns = (spdbns+wisbns)/2;
		
		pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;

		clvl++;

		cwismax=cwis;

		cstrbns=(cstr-12)/2;
		cspdbns=(cspd-12)/2; 
		cstmbns=(cstm-12)/2; 
		cdexbns=(cdex-12)/2; 
		cwisbns=(cwis-12)/2;
		csp=cstm;
		capr=(cspd+cdex)/12;
		cintbns=(cspdbns+cwisbns)/2;
		chpmod =(cstmbns*8)+(clvl*10);
		ckimod =(cwisbns*2)+(clvl*5);
		chp=chp+chpmod;
		cki=cki+ckimod;
		chpmax=chp;
		ckimax=cki;
		cpl=((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;
		}

		do 
		{
		system("CLS");

			if(xp >= nxtxp)
			{
			nxtxp = nxtxp + (plvl*200);
			cout << "LEVEL UP !!\n\n"
				 << "You are now level " << plvl << "!\n\n";

				if(plvl == 2)
				{
				multipunchtech = true;
				sensekitech = true;
				cout << "You have leraned the Multi-Punch Technique!\n";
				cout << "You have learned the Sense Ki Ability!\n\n";
				}

				else if(plvl == 3)
				{
				multikicktech = true;
				zanzokentech = true;
				cout << "You have leraned the Multi-Kick Technique!\n";
				cout << "You have learned the Zanzoken Ability!\n\n";
				}

				else if(plvl == 4)
				{
				solarflaretech = true;
				cout << "You have leraned the Solar Flare Technique!\n";
				}

				else if(plvl == 5)
				{
				
				}
			}

		cout << "You have killed The Hooded Namekian in " << rnd << " round(s)!!\n\n"
			 << "You gained " << (cplmax/6) << " experience!\n"
			 << "Your current experience: " << xp << "/" << nxtxp;
	
		cc = (1 + rand() % 100);
				if(cc > 95)
				{
				cout << "\n\n<<Your opponent dropped a Senzu Bean!>>";
				pbean++;
				}
	
		cc = (1 + rand() % 25);
		zeni += cc;
		cout << "\n\nYou gained " << cc << " Zeni!";
	   	cout << "\n\nWould you like to continue? ";
		cin  >> choice;

			if(choice == "no")
				exit(0);

			if(choice == "yes")
			{
			choice = "continue";
			main();
			}
		}
		while(choice != "yes" && choice != "no");	
	}
	
	else//											    				PLAYER DEATH
	{
	barrierhp = 0;
	compbarrierhp =0;
	barrier = false;
	compbarrier = false;
	zanzo = false;
	compzanzo = false;
	kimax = false;
	mpunchused = false;
	mkickused = false;
	dexbns = ((dex-12)/2);
	spdbns = ((spd-12)/2);
	wisbns = ((wis-12)/2);
	php = phpmax;
	pki = pkimax;
	psp = stm;
	pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
	chp=chpmax;
	cki=ckimax;
	csp=cstm;
	cwisbns = ((cwis-12)/2);
	cpl=((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl;

		do
		{
		system("CLS");
	    cout << "You have been killed in round " << rnd << "!!\n"
			 << "GAME OVER!\n\n"
			 << "Would you like to play again? ";
		cin	 >> choice;
		
			if(choice == "no")
				exit(0);

			else if(choice == "yes")
			{
			choice = "restart";
			main();
			}
		}
		while(choice != "yes" && choice != "no");
	}
}

void pause()
{

	cout << endl << endl;

	while(usrp != 32)
	{
		cin.clear();
		cout << "(Press SPACE to continue) . . . ";
		usrp = toupper(getch());
		cout << endl;
	}

	system("CLS");
	usrp = 0;
	return;
}

void senseki()
{
	
	cpl = (((chp+(cki*2))+((cwis+cstm)*3))*(pow(cstr+cspd,1.5))/50*clvl);
	cc = (1 + rand() % 100)+((sensekixp/100)*10);

	cout << "\n\nYou attempt to sense your opponent's Power Level!\n";

	if(cc > 75)
	{
		cout << "Your attempt succeded! [" << cpl << "]";		
		sensekixp++;
	}

	else
		cout << "Your attempt failed!";	
}

void validity()
{

	do
	{
		if(choice == "barrier" && pki < 15 || choice == "zanzoken" && pki < (5+zanzokenxp/100) || choice == "kiblast" && pki <= 4 || choice == "dondonpa" && pki <= 9 || choice == "solarflare" && pki <= 9)
		{
			out = "\n\nYou don't have enough Ki!";
			choice = "";
		}
								
		else if(choice == "focuski" && kimax)
		{
			out =  "\n\nYour body can't handle the strain of any more ki!";
			choice = "";
		}
													
		else if(choice == "senzubean" && pbean == 0)
		{
			out = "\n\nYou don't have any Senzu Beans!";
			choice = "";
		}

		else if(choice == "solarflare" && solarflareused == true || choice == "focuski" && focuskiused)
		{
			out = "\n\nYou may only use this technique once per round!";
			choice = "";
		}
																											
		else if(choice == "multipunch" && mpunchused == true || choice == "multikick" && mkickused == true)
		{
			out = "\n\nYou may only use this attack once per fight!";
			choice = "";
		}
											
		else if(choice == "barrier" && barrierhp == ((barrierxp/100*10)+15))
		{
			out = "\n\nYour ki barrier is at it's max!";
			choice = "";
		}

		else if(choice == "rest" && psp >= stm)
		{
			out = "\n\nYour body is fully rested!";
			choice = "";
		}	
										
		else if(choice == "barrier" && barriertech == false || choice == "solarflare" && solarflaretech == false || choice == "multipunch" && multipunchtech == false || choice == "multikick" && multikicktech == false || choice == "zanzoken" && zanzokentech == false)
		{
			out = "\n\nYou don't know this technique!";				
			choice = "";
		}

		else if(choice != "barrier" && choice != "zanzoken" && choice != "rest" && choice != "solarflare" && choice != "multikick" && choice != "multipunch" && choice != "menu" && choice != "flee" && choice != "punch" && choice != "elbow" && choice != "headbutt" && choice != "doubleaxehandle" && choice != "kick" && choice != "knee" && choice != "roundhouse" && choice != "kiblast" && choice != "dondonpa" && choice != "senzubean" && choice != "focuski")
			playerheader();
	
		else
			return;						
	}
	while(choice == "barrier" && pki < 15 || choice == "barrier" && barrierhp == ((barrierxp/100*10)+15) || choice == "barrier" && barriertech == false || choice == "rest" && psp >= stm || choice == "solarflare" && pki <= 9 || choice == "solarflare" && solarflareused == true || choice == "solarflare" && solarflaretech == false || choice == "kiblast" && pki < 5 || choice == "dondonpa" && pki < 10 || choice == "senzubean" && pbean == 0 || choice == "focuski" && kimax || choice == "focuski" && focuskiused|| choice == "multipunch" && mpunchused == true || choice == "multipunch" && multipunchtech == false || choice == "multikick" && mkickused == true || choice == "multikick" && multikicktech == false || choice == "zanzoken" && pki < (5+zanzokenxp/100) || choice == "zanzoken" && zanzokentech == false || choice != "barrier" && choice != "zanzoken" && choice != "rest" && choice != "solarflare" && choice != "multikick" && choice != "multipunch" && choice != "menu" && choice != "flee" && choice != "punch" && choice != "elbow" && choice != "headbutt" && choice != "doubleaxehandle" && choice != "kick" && choice != "knee" && choice != "roundhouse" && choice != "kiblast" && choice != "dondonpa" && choice != "senzubean" && choice != "focuski");

return;
}

void playerheader()
{
	do
	{

		system("CLS");
		cout << "\t\t\tRound " << rnd << "!" << endl << endl;
		cout << "It's your turn! (Action " << aprc+1 << " of " << apr << ")" << endl << endl;
		pstatus();

		if(choice == "list")
		{
			cout << "\n\n" << ulp << urp << setw(30) << setfill(mp) << ulp << urp;
			cout << out;
			cout << "\n\n" << llp << lrp << setw(30) << setfill(mp) << llp << lrp;
		}

		else
			cout << out;

		out = "";
		cout << "\n\nWhat would you like to do? ";
		cin >> choice;		
		
		if(choice == "menu")
			menu();
		
		if(choice != "menu")
			cc++;

		if(cc > 0 && choice != "menu" && choice != "list")
			out = "\n\nInvalid input!";

		if(choice == "list")
		{
			out += "\n\n   Known Offensive Techniques:"
				   "\n\n   doubleaxehandle"
				   "\n   elbow"
				   "\n   headbutt"
				   "\n   punch"
				   "\n   kick"
				   "\n   knee"
				   "\n   roundhouse"
				   "\n   kiblast"
				   "\n   dondonpa";

			if(multipunchtech)
				out += "\n   multipunch";
			if(multikicktech)
				out += "\n   multikick";
			if(solarflaretech)
				out += "\n   solarflare";

			out += "\n\n   Known Defensive Techniques:"
					"\n\n   focuski"
					"\n   rest";

			if(barriertech)
				out += "\n   barrier";
			if(zanzokentech)
				out += "\n   zanzoken";
		
		}

	}
	while(choice == "menu" || choice == "list" || choice != "barrier" && choice != "zanzoken" && choice != "rest" && choice != "solarflare" && choice != "multikick" && choice != "multipunch" && choice != "menu" && choice != "flee" && choice != "punch" && choice != "elbow" && choice != "headbutt" && choice != "doubleaxehandle" && choice != "kick" && choice != "knee" && choice != "roundhouse" && choice != "kiblast" && choice != "dondonpa" && choice != "senzubean" && choice != "focuski");

	out = "";
	cc = 0;

return;
}

void defense()
{

	if(pturn && !ccountercheck || pcountercheck)
	{

		cc = pdmg;	

		if(pcrit && meleecheck)
			pdmg*= 2;

		else if(pcrit && !meleecheck)
			pdmg*= 1.5;

		if(pcountercheck)
			pdmg+= (strbns/2);

		else if(meleecheck)
			pdmg+= strbns;

		else
			pdmg+= wisbns;
			
		if(pdmg < 0)
			pdmg = 0;

		if(compblocktech && !pcrit && !pcountercheck)
		{
		cblock = (1 +rand() % 100) + (clvl*2);
		
			if(cblock > 75)
			{
			cout << "\n\n<<Your opponent BLOCKED the attack!>>";
			pdmg/=2;
			blockxp++;
			}
		}

		if(compbarrier)
		{
			if(pdmg <= compbarrierhp)
				compbarrierhp -= pdmg;

			else
			{
			compbarrierhp -= pdmg;
			chp += compbarrierhp;
			compbarrierhp = 0;
			}
			
			if(compbarrierhp == 0)
			{
			compbarrier = false;
			out+= "\n\n<<Your opponent's Barrier fades away!>>";
			}
		}

		else if(carmorhp > 0 && cblock <= 75)
		{
		pdmg/=2;
		chp-= pdmg;
		carmorhp-= pdmg;
	
			if(carmorhp < (carmorhp*.50))
				out+= "\n\n<<You have CRACKED your opponent's armor!>>";
			
			if(carmorhp <= 0)
			{
			chp+= carmorhp;
			out+= "\n\n<<Your opponent's armor has BROKEN!>>";
			}
		}

		else
			chp -= pdmg;

		if(pcountercheck)
			cout << "\n\nYou have hit your target!!";

	cout << "\n\nYour damage roll: " << cc << " (";

		if(pcrit && meleecheck)
			cout << "x2) ("; 

		else if(pcrit && !meleecheck)
			cout << "x1.5) ("; 

		if(meleecheck)
		{
		strxp+= wtxp;
		dexxp+= wtxp;
		spdxp+= wtxp;
		stmxp+= (wtxp/2);	

			if(strbns >= 0)
				cout << "+";
		cout << strbns << ")";
		}

		else if(pcountercheck)
		{
			if((strbns/2) >= 0)
				cout << "+";
		cout << (strbns/2) << ")";
		}

		else
		{
			if(wisbns >= 0)
				cout << "+";
		cout << wisbns << ")";	
		}

		if(cblock > 75)
			cout << " (/2)";

	cout <<	" = [" << pdmg << "]" << endl
 		 << "Your opponent has taken " << pdmg << " damage!!";
	}

	else if(!pturn || ccountercheck)
	{
		if(cdmg < 0)
			cdmg = 0;

		cc = cdmg;

		if(blocktech && !ccrit && !ccountercheck && cdmg != 1)
		{
			cblock = (1 +rand() % (100 + ((blockxp/100)*(10))));
		
				if(cblock > 75)
				{
					cout << "\n<<You have BLOCKED the attack!>>\n";
					blockxp++;
					cdmg/=2;
				}
		}
	
		if(barrier)
		{
			if(cdmg <= barrierhp)
				barrierhp-= cdmg;
			
			else
			{
				barrierhp-= cdmg;

					if(parmorhp > 0)
					{
						if(cdmg == 1)
						{
							parmorhp-= cdmg;
							out += "\n\n<<Your opponent clips your armor as your Ki Barrier fades away!>>";
						}
						
						else
						{
							barrierhp/= 2;
							php+= barrierhp;
							parmorhp+= barrierhp;
						}
					}				
		
					else
						php+= barrierhp;
	
				barrierhp= 0;
			}
	
			if(barrierhp == 0)
			{
				barrier = false;
					
					if(out != "\n\n<<Your opponent clips your armor as your Ki Barrier fades away!>>")
						out += "\n\n<<Your Ki Barrier fades away!>>";
			}		
		}
	
		else if(parmorhp >= 0 && cblock <= 75)
		{
			if(cdmg == 1 && parmorhp != 0 && barrier == false)
				parmorhp-= cdmg;
			
			else
			{	
				cdmg/=2;
				php-= cdmg;
				parmorhp-= cdmg;
			}
			
			if(parmorhp < (parmorhp*.50))
				out+= "\n\n<<Your armor is cracked!>>";
			
			if(parmorhp <= 0)
			{
				php += parmorhp;
				out += "\n\n<<Your armor has broken!>>";
			}
		}
	
		else
			php -= cdmg;

	cout << "\nYou have been hit!!\n\n"
		 << "Your opponent's damage roll: [" << cc << "]\n"
		 << "You have taken " << cdmg << " damage!!\n\n"
		 << "Your current HP: " << php << "/" << phpmax;

		if(parmorhp > 0)
			cout << " [" << parmorhp << "]";

		if(barrier && barrierhp > 0)
			cout << " (" << barrierhp << ")";
	}

cc = 0;
cblock = 0;
pcrit = false;
ccrit = false;
meleecheck = false;
pcountercheck=false;
ccountercheck=false;

return;
}

void charcreation()
{
	
	do
	{
		plvl= 1;
		php = 50;
		pki = 15; 
		xp = 0;
		phpmax = php;
		pkimax = pki;
	
		str = (7 + rand() % 10);
		stm = (7 + rand() % 10);
		dex = (7 + rand() % 10);
		wis = (7 + rand() % 10);
		spd = (7 + rand() % 10);
	
		strmax=(str+(strxp/100));
		stmmax=(stm+(stmxp/100));
		dexmax=(dex+(dexxp/100));
		spdmax=(spd+(spdxp/100));
		wismax=(wis+(wisxp/100));
		
		dexbns = (dex-12)/2;
		wisbns = (wis-12)/2;
		stmbns = (stm-12)/2;
		strbns = (str-12)/2;
		spdbns = (spd-12)/2;
	
			if(stmbns < 0)
				stmbns = -2;	
	
		dexbnsmax = dexbns;
		spdbnsmax = spdbns;
	
		phpmod = (stmbns*8)+(plvl*10);
		pkimod = (wisbns*2)+(plvl*5);
	
		php = php+phpmod;
		pki = pki+pkimod;
		phpmax = php;
		pkimax = pki;
	
		psp = stm;
		apr = (dex+spd)/12;
		
		nhpmod = (stmbns*8)+((plvl+1)*10);
		nkimod = (wisbns*2)+((plvl+1)*5);
		intbns = (spdbns+wisbns)/2;
	
		pl=((php+(pki*2))+((wis+stm)*3))*(pow(str+spd,1.5))/50*plvl;
		
		system("CLS");
		cout << "HUMAN MARTIAL ARTIST\n";
		cout << "LVL: " << plvl << endl << endl;
		cout << "HP: " << php << "/" << phpmax << endl;
		cout << "KI: " << pki << "/" << pkimax << endl;
		cout << "SP: " << psp << "/" << stm << endl;
		cout << "APR: " << apr << endl << endl;
		cout << "WIS: " << wis << endl;
		cout << "STM: " << stm << endl;
		cout << "STR: " << str;
	
		cout << "\nDEX: " << dex;
		cout << "\nSPD: " << spd;
		cout << "\n\nWith current stats: " << endl;
		cout << "-------------------" << endl;
		cout << "+" << nhpmod << " HP nxt LVL" << endl;
		cout << "+" << nkimod << " KI nxt LVL" << endl << endl;
	
		if(intbns >= 0)
			cout << "+"; 
			cout << intbns << " INITIVE\n";
		
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE ATTACK";

		if(zanzo)
			cout << " (+" << (zanzokenxp/100+2) << ")";				
	
		cout << endl;
	
		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI ATTACK";

		if(kimax)
			cout << "    (+" << (focuskixp/100+2) << ")";
	
		cout << endl;

		if(strbns >= 0)
			cout << "+";
			cout << strbns << " MELEE DMG\n";

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI DMG";

		if(kimax)
			cout << "       (+" << (focuskixp/100+2) << ")";
	
		cout << endl;
	
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE DODGE";

		if(zanzo)
			cout << "  (+" << (zanzokenxp/100+2) << ")";	
	
		cout << endl;
	
		if(spdbns >= 0)
			cout << "+";
			cout << spdbns << " KI DODGE";

		if(zanzo)
			cout << "     (+" << (zanzokenxp/100+2) << ")";
	
		cout << "\n\nPower Level: " << pl << endl << endl;
	
		cout << "Re-roll or Keep? <R/K>: ";
		choice = getch();

		if (choice != "r" && choice != "k")
		{
			do
			{
			cout << "Press 'R' or 'K'! ";
			choice = getch();
			cout << "\nRe-roll or Keep? <R/K>: ";
			}
			while (choice != "r" && choice != "k");
		}	
	}
	while(choice == "r" && choice != "k");

	cout << "\n\nWhat would you like to name your character? ";
	cin >> name;

}

void initiate()
{
	
	str+=(strxp/100);
	stm+=(stmxp/100);
	dex+=(dexxp/100);
	spd+=(spdxp/100);
	wis+=(wisxp/100);
	
	dexbns = (dex-12)/2;
	wisbns = (wis-12)/2;
	stmbns = (stm-12)/2;
	strbns = (str-12)/2;
	spdbns = (spd-12)/2;
	intbns = ((spdbns+wisbns)/2);
	apr = ((dex+spd)/12);

		if(stmbns < 0)
			stmbns = -2;

		if(apr < 1)
			apr = 1;

	pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
}

void charscreen()
{
	
	system("CLS");
	cout << "\t\tYour *Dragon Ball ";
cout << "Z";

cout << ": Legends* Character\n\n";
	cout << name << endl;
	cout << "HUMAN MARTIAL ARTIST\n";
	cout << "LVL: " << plvl << endl;
	cout << "XP: " << xp << "/" << nxtxp << endl << endl;
	cout << "HP: " << php << "/" << phpmax;

		if(parmorhp > 0)
			cout << " [" << parmorhp << "]";
	
		if(barrier && barrierhp > 0)
			cout << " (" << barrierhp << ")";

	cout << "\nKI: " << pki << "/" << pkimax << endl;
	cout << "SP: " << psp << "/" << stm << endl;
	cout << "APR: " << apr << endl << endl;
	cout << "WIS: " << wis;
		if(wis < wismax)
			cout << " (-" << (wismax-wis) << ")";
		if(wis > wismax)
			cout << " (+" << (wis-wismax) << ")";
	cout << "\nSTM: " << stm;
		if(stm < stmmax)
			cout << " (-" << (stmmax-stm) << ")";
		if(stm > stmmax)
			cout << " (+" << (stm-stmmax) << ")";
	cout << "\nSTR: " << str;
		if(str < strmax)
			cout << " (-" << (strmax-str) << ")";
		if(str > strmax)
			cout << " (+" << (str-strmax) << ")";
	cout << "\nDEX: " << dex;
		if(dex < dexmax)
			cout << " (-" << (dexmax-dex) << ")";
		if(dex > dexmax)
			cout << " (+" << (dex-dexmax) << ")";
	cout << "\nSPD: " << spd;
		if(spd < spdmax)
			cout << " (-" << (spdmax-spd) << ")";
		if(spd > spdmax)
			cout << " (+" << (spd-spdmax) << ")";

	cout << "\n\nWith current stats: " << endl;
	cout << "-------------------" << endl;
	cout << "+" << nhpmod << " HP nxt LVL" << endl;
	cout << "+" << nkimod << " KI nxt LVL" << endl << endl;

		if(intbns >= 0)
			cout << "+"; 
			cout << intbns << " INITIVE\n";
		
		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE ATTACK";

		if(zanzo)
			cout << " (+" << (zanzokenxp/100+2) << ")";				

	cout << endl;

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI ATTACK";

		if(kimax)
			cout << "    (+" << (focuskixp/100+2) << ")";

	cout << endl;

		if(strbns >= 0)
			cout << "+";
			cout << strbns << " MELEE DMG\n";

		if(wisbns >= 0)
			cout << "+";
			cout << wisbns << " KI DMG";

		if(kimax)
			cout << "       (+" << (focuskixp/100+2) << ")";

	cout << endl;

		if(dexbns >= 0)
			cout << "+";
			cout << dexbns << " MELEE DODGE";

		if(zanzo)
			cout << "  (+" << (zanzokenxp/100+2) << ")";	

	cout << endl;

		if(spdbns >= 0)
			cout << "+";
			cout << spdbns << " KI DODGE";

		if(zanzo)
			cout << "     (+" << (zanzokenxp/100+2) << ")";	

	pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;
	cout << "\n\nYour current Power Level: " << pl;
	cout << "\nZeni: $" << zeni;

	pause();
	
}

void pstatus()
{
	
pl = ((php+(pki*2))+((wis+stm)*3))*(pow(str+dex,1.5))/50*plvl;

cout << ulp << urp << setw(25) << setfill(mp) << ulp << urp << endl
	 << vp << vp << endl
	 << vp << vp << "   HP: " << php << "/" << phpmax;

	if(parmorhp > 0)
		cout << " [" << parmorhp << "]";

	if(barrier && barrierhp > 0)
		cout << " (" << barrierhp << ")";

cout << endl << vp << vp << "   KI: " << pki << "/" << pkimax
	 << endl << vp << vp << "   SP: " << psp << "/" << stm
	 << endl << vp << vp
	 << endl << vp << vp << "   Power Level: " << pl
	 << endl << vp << vp << endl
	 << llp << lrp << setw(25) << setfill(mp) << llp << lrp;

}

void zanzoken()
{

	if(zanzo)
	{
		
		if(pki > 5)
		{
			zanzokentech++;
			pki -= 5;
		}

		else
		{
			zanzo = false;
			cout << "\n\n<<Your body phases back into sight, your Zanzoken has stopped!>>";
		}
		
	}

	if(compzanzo)
	{
	
		if(pki > (4 + clvl))
			cki -= (4 + clvl);
		
		else
		{
			compzanzo = false;
			cout << "\n\n<<Your opponent's body phases back into sight!>>";
			cdexbns = ((cdex-12)/2);
			cspdbns = ((cspd-12)/2);
		}

	}
	
}

void unique()
{

	system("CLS");
	cc = (1 + rand() % 100);
	
	cout << "Your character's UNIQUE roll: [" << cc << "]" << endl << endl;

	if(cc < 6)
	{
	
	}

	else if(cc > 5 && cc <= 10)
	{
	
	}

	else if(cc > 10 && cc <= 15)
	{
	
	}

	else if(cc > 15 && cc <= 20)
	{
	
	}

	else if(cc > 20 && cc <= 25)
	{
	
	}

	else if(cc > 25 && cc <= 30)
	{
	
	}

	else if(cc > 30 && cc <= 35)
	{
	
	}

	else if(cc > 35 && cc <= 40)
	{
	
	}

	else if(cc > 40 && cc <= 45)
	{
	
	}

	else if(cc > 45 && cc <= 50)
	{
	
	}

	else if(cc > 50 && cc <= 55)
	{
	
	}

	else if(cc > 55 && cc <= 60)
	{
	
	}

	else if(cc > 60 && cc <= 65)
	{
	
	}

	else if(cc > 65 && cc <= 70)
	{
	
	}

	else if(cc > 70 && cc <= 75)
	{
	
	}

	else if(cc > 75 && cc <= 80)
	{
	
	}

	else if(cc > 80 && cc <= 85)
	{
	
	}

	else if(cc > 85 && cc <= 90)
	{
	
	}

	else if(cc > 90 && cc <= 95)
	{
	
	}

	else if(cc > 95 && cc <= 99)
	{
	
	}

	else if(cc == 100)
	{
	
	}

}
